#include "AlphaFitter.h"

static AlphaFitter *alphafitterobj;

//
// Initialize
//
AlphaFitter::AlphaFitter(TH1F *dat, TH1F *mc_1, TH1F *mc_2)
:doSmear_(false)
{
  data = (TH1F*)dat->Clone("data");
  mc1 = (TH1F*)mc_1->Clone("mc1");
  mc2 = (TH1F*)mc_2->Clone("mc2");

  alphafitterobj = this;
}

double AlphaFitter::Fit_Function(const double *par)
{
  double value = 0.; 
  //int ifirstbin = data->FindBin(0.2);
  //int ilastbin = data->FindBin(0.999);
  // chisquare calculated from 0.2 to 0.9
  for(Int_t i=1; i<= data->GetNbinsX(); i++){
    double dif = data->GetBinContent(i) - par[0]*mc1->GetBinContent(i) - (1-par[0])*mc2->GetBinContent(i); 
    double err2 = data->GetBinError(i)*data->GetBinError(i) + mc1->GetBinError(i)*mc1->GetBinError(i)* par[0]* par[0] + mc2->GetBinError(i)*mc2->GetBinError(i) * (1-par[0]) * (1-par[0]);
    if( err2 ) value += TMath::Power(dif, 2)/err2;
    //else {
    //  std::cout << "Bin " << i << " with zero error" << std::endl;
    //}
  }
 
  return value;
}

void AlphaFitter::Get_ChiSquare(Int_t &npar, Double_t *gin, Double_t &f, Double_t *par, Int_t iflag)
{
  //calculate chisquare
  f = alphafitterobj->Fit_Function(par);
  return;
}

TMinuit* AlphaFitter::Launch_Fit( double pinit){
  TMinuit* ptMinuit = new TMinuit(1);  //initialize TMinuit with a maximum of 1 params
  //
  //  select verbose level:
  //    default :     (58 lines in this test)
  //    -1 : minimum  ( 4 lines in this test)
  //     0 : low      (31 lines)
  //     1 : medium   (61 lines)
  //     2 : high     (89 lines)
  //     3 : maximum (199 lines in this test)
  //
  ptMinuit->SetPrintLevel();
  // set the user function that calculates chi_square (the value to minimize)
  ptMinuit->SetFCN(AlphaFitter::Get_ChiSquare);

  Double_t arglist[10];
  Int_t ierflg = 0;

  arglist[0] = 1;
  ptMinuit->mnexcm("SET ERR", arglist ,1,ierflg);

  // Set starting values and step sizes for parameters
  ptMinuit->mnparm(0, "a1", pinit, 0.1, 0.0, 0.3,ierflg);

  // Now ready for minimization step
  arglist[0] = 50000;
  ptMinuit->mnexcm("MIGRAD", arglist ,1,ierflg);

  return ptMinuit;
}

//
// smear mc1 with gaussian
//
void AlphaFitter::SmearHisto(){
  //gRandom->SetSeed(0);
  gRandom = new TRandom3(0);
  for(Int_t i=1; i<data->GetNbinsX(); i++){
    double new1 = gRandom->Gaus( data->GetBinContent(i), data->GetBinError(i));
    std::cout << " bin number " << i << " original " << data->GetBinContent(i) << " new " << new1 << std::endl;
    data->SetBinContent(i, new1);
    //double new2 = gRandom->Gaus( mc1->GetBinContent(i), mc2->GetBinError(i));
    //mc2->SetBinContent(i, new2);
  }
}

void AlphaFitter::DoFit()
{

  if( doSmear_ ) {
    std::cout << " Smear the fitted histogram "<< data->GetTitle() << " ... " << std::endl;
    SmearHisto();
  }

  // normalize to get the shape
  mc1->Scale(1.0/mc1->Integral());
  mc2->Scale(1.0/mc2->Integral());
  data->Scale(1.0/data->Integral());

  TMinuit *ptMinuit = Launch_Fit(0.1);
  double fParamVal;
  double fParamErr;
  ptMinuit->GetParameter(0, fParamVal,fParamErr);

  std::cout << "\n" << " ********************* " << "\n";
  std::cout << " fit one more time, use the previous fitting result as initial par this time"<< "\n";
  std::cout << " *********************** " << "\n\n";
 
  // 2nd time fit, use the result from the 1st time as the initial value 
  ptMinuit = Launch_Fit(fParamVal);

  // Print results
  std::cout << "\nPrint results from minuit\n";
  ptMinuit->GetParameter(0, fParamVal,fParamErr);
  std::cout << "a1=" << setw(10) << fParamVal <<  " error " << setw(12) << fParamErr << "\n";
  std::cout << "a2=" << setw(10) << 1.0-fParamVal << " error "<< setw(12) << fParamErr << "\n";

  // if you want to access to these parameters, use:
  Double_t amin,edm,errdef;
  Int_t nvpar,nparx,icstat;
  ptMinuit->mnstat(amin,edm,errdef,nvpar,nparx,icstat);
  //void mnstat(Double_t &fmin, Double_t &fedm, Double_t &errdef, Int_t &npari, Int_t &nparx, Int_t &istat) 
  //*-*-*-*-*Returns concerning the current status of the minimization*-*-*-*-*
  //*-*      =========================================================
  //*-*       User-called
  //*-*          Namely, it returns:
  //*-*        FMIN: the best function value found so far
  //*-*        FEDM: the estimated vertical distance remaining to minimum
  //*-*        ERRDEF: the value of UP defining parameter uncertainties
  //*-*        NPARI: the number of currently variable parameters
  //*-*        NPARX: the highest (external) parameter number defined by user
  //*-*        ISTAT: a status integer indicating how good is the covariance
  //*-*           matrix:  0= not calculated at all
  //*-*                    1= approximation only, not accurate
  //*-*                    2= full matrix, but forced positive-definite
  //*-*                    3= full accurate covariance matrix
  //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
  std::cout << "\n";
  std::cout << " Minimum chi square = " << amin << "\n";
  std::cout << " Estimated vert. distance to min. = " << edm << "\n";
  std::cout << " Number of variable parameters = " << nvpar << "\n";
  std::cout << " Highest number of parameters defined by user = " << nparx << "\n";
  std::cout << " Status of covariance matrix = " << icstat << "\n";

  std::cout << "\n";
  ptMinuit->mnprin(1,amin);
  //*-*-*-*Prints the values of the parameters at the time of the call*-*-*-*-*
  //*-*    ===========================================================
  //*-*        also prints other relevant information such as function value,
  //*-*        estimated distance to minimum, parameter errors, step sizes.
  //*-*
  //*-*         According to the value of IKODE, the printout is:
  //*-*    IKODE=INKODE= 0    only info about function value
  //*-*                  1    parameter values, errors, limits
  //*-*                  2    values, errors, step sizes, internal values
  //*-*                  3    values, errors, step sizes, first derivs.
  //*-*                  4    values, parabolic errors, MINOS errors
  //*-*    when INKODE=5, MNPRIN chooses IKODE=1,2, or 3, according to ISW(2)
  //*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*

  //return EXIT_SUCCESS;

  // Get the fraction, error and chi2
  frac_mc1_ = fParamVal;
  err_mc1_ = fParamErr;
  chi2_ = amin;
}

double AlphaFitter::GetFraction()
{
  return frac_mc1_; 
}

double AlphaFitter::GetFractionError()
{
  return err_mc1_;
}

double AlphaFitter::GetChi2()
{
  return chi2_;
}

void AlphaFitter::SetSmear(bool dosmear)
{
   doSmear_ = dosmear;
}

void AlphaFitter::SaveResult( string ofilename)
{
  result = (TH1F*)mc1->Clone("result");
  for ( int i= 1; i<=mc1->GetNbinsX(); i++){
     result->SetBinContent(i, frac_mc1_*mc1->GetBinContent(i)+ (1-frac_mc1_)*mc2->GetBinContent(i));
     double err2 = frac_mc1_*frac_mc1_*mc1->GetBinError(i)*mc1->GetBinError(i) + (1-frac_mc1_)*(1-frac_mc1_)*mc2->GetBinError(i)*mc2->GetBinError(i) + (mc1->GetBinContent(i)*mc1->GetBinContent(i)+ mc2->GetBinContent(i)*mc2->GetBinContent(i))*err_mc1_*err_mc1_;
     result->SetBinError(i, TMath::Sqrt(err2));
  }

  TFile *myfile_save = new TFile( ofilename.c_str(), "RECREATE");
  mc1->SetDirectory(0);
  mc1->Write();
  mc2->SetDirectory(0);
  mc2->Write();
  data->SetDirectory(0);
  data->Write();
  myfile_save->Close();
}

void AlphaFitter::MakePlot( double frac1, bool showratio, string histoname)
{ 
  //***********************
  // make plots
  //***********************
  gStyle->SetOptStat(0);
  int W = 800;
  //int H = 600;
  int H = 800;
  TString canvName = "Fig_";
  TCanvas* canv = new TCanvas(canvName,canvName,50,50,W,H);
  // references for T, B, L, R
  float T = 0.08*H;
  //float B = 0.12*H;
  float L = 0.12*W;
  float R = 0.04*W;

  //canv = new TCanvas(canvName,canvName,50,50,W,H);
  canv->SetFillColor(0);
  canv->SetBorderMode(0);
  canv->SetFrameFillStyle(0);
  canv->SetFrameBorderMode(0);

  TPad* pad1 = new TPad("pad1", "", 0, 0.3, 1, 1);
  TPad* pad2 = new TPad("pad2", "", 0, 0, 1, 0.3);
  pad1->SetLeftMargin( L/W );
  pad1->SetRightMargin( R/W );
  pad1->SetTopMargin( T/H );
  pad1->SetBottomMargin(0.02);
  pad2->SetTopMargin(0.05);
  pad2->SetLeftMargin( L/W );
  pad2->SetRightMargin( R/W);
  pad2->SetBottomMargin(0.4);
  pad2->SetGridy(1);
  pad1->Draw();
  pad2->Draw();
  pad1->cd();
  pad1->SetLogy();

  TH1* h_nTrack = new TH1F("h_nTrack"," ",100,0,1);
  h_nTrack->GetXaxis()->SetNdivisions(6,5,0);
  //h_nTrack->GetXaxis()->SetTitle("alpha2DSig");
  //h_nTrack->GetXaxis()->SetTitleSize(0.05);
  h_nTrack->GetXaxis()->SetLabelSize(0.0);
  h_nTrack->GetYaxis()->SetNdivisions(6,5,0);
  h_nTrack->GetYaxis()->SetTitleOffset(1);
  h_nTrack->GetYaxis()->SetTitle("A.U.");
  h_nTrack->GetYaxis()->SetTitleSize(0.05);
  h_nTrack->SetMaximum(5.0);
  h_nTrack->SetMinimum(5e-4);
  h_nTrack->Draw("");

  float x1_l = 0.92;
  float y1_l = 0.90;

  float dx_l = 0.40;
  float dy_l = 0.28;
  float x0_l = x1_l-dx_l;
  float y0_l = y1_l-dy_l;

  TLegend *lgd = new TLegend(x0_l,y0_l,x1_l, y1_l);
  lgd->SetBorderSize(0); lgd->SetTextSize(0.06); lgd->SetTextFont(32); lgd->SetFillColor(0);

  data->SetLineColor(1);
  data->SetMarkerStyle(22);
  data->SetMarkerSize(2);
  data->Scale(1.0/data->Integral());
  data->Draw("Ep same");
  mc1->SetLineColor(2);
  mc1->Draw("same");
  mc2->SetLineColor(3);
  mc2->Draw("same");

  result = (TH1F*)mc1->Clone("result");
  for ( int i= 1; i<=mc1->GetNbinsX(); i++){
     result->SetBinContent(i, frac_mc1_*mc1->GetBinContent(i)+ (1-frac_mc1_)*mc2->GetBinContent(i));
     double err2 = frac_mc1_*frac_mc1_*mc1->GetBinError(i)*mc1->GetBinError(i) + (1-frac_mc1_)*(1-frac_mc1_)*mc2->GetBinError(i)*mc2->GetBinError(i) + (mc1->GetBinContent(i)*mc1->GetBinContent(i)+ mc2->GetBinContent(i)*mc2->GetBinContent(i))*err_mc1_*err_mc1_;
     result->SetBinError(i, TMath::Sqrt(err2));
  }

  result->SetLineColor(4);
  result->Draw("same");

  lgd->SetHeader(data->GetTitle());
  lgd->AddEntry(data, "data", "pel");
  lgd->AddEntry(mc1, "b jet", "pel");
  lgd->AddEntry(mc2, "light jet", "pel");
  lgd->AddEntry(result, "result", "pel");

  TLatex *txt = new TLatex(x0_l, y0_l-.5, Form("#chi^{2} = %.2f", chi2_));
  txt->SetTextSize(0.06);
  txt->SetTextFont(32);
  txt->SetTextColor(kBlack);

  pad1->Update();
  pad1->RedrawAxis();
  lgd->Draw();
  txt->Draw();
  pad1->Update();

  pad2->cd();
  TH1* h_ratio = new TH1F("h_ratio"," ",100,0,1);
  h_ratio->GetXaxis()->SetTitleSize(0.10);
  h_ratio->GetXaxis()->SetLabelSize(0.10);
  h_ratio->GetXaxis()->SetTitle("jet_csv");
  h_ratio->GetYaxis()->SetTitle("ratio");
  //h_ratio->GetYaxis()->SetTitle("sqrt(#chi^{2})");
  h_ratio->GetYaxis()->SetTitleSize(0.07);
  h_ratio->GetYaxis()->SetLabelSize(0.07);
  h_ratio->SetMaximum(2);
  h_ratio->SetMinimum(0.0);
  h_ratio->GetYaxis()->SetTitleOffset(0.5);
  h_ratio->GetYaxis()->SetNdivisions(4);
  h_ratio->Draw();
  TH1F* h2 = (TH1F*)result->Clone("h2");
  h2->Divide(data);
  for(int i=1; i<= mc1->GetNbinsX(); i++){
    if( data->GetBinContent(i) ){
      double err2 = result->GetBinError(i)*result->GetBinError(i)/(data->GetBinContent(i)*data->GetBinContent(i))+ TMath::Power(result->GetBinContent(i)*data->GetBinError(i)/(data->GetBinContent(i)*data->GetBinContent(i)), 2.0);
      h2->SetBinError(i, TMath::Sqrt(err2));
      /*
      double dif = data->GetBinContent(i) - frac_mc1_*mc1->GetBinContent(i) - (1-frac_mc1_)*mc2->GetBinContent(i);
      double err2 = data->GetBinError(i)*data->GetBinError(i) + mc1->GetBinError(i)*mc1->GetBinError(i)* frac_mc1_* frac_mc1_ + mc2->GetBinError(i)*mc2->GetBinError(i) * (1-frac_mc1_) * (1-frac_mc1_);
      if( err2 ) h2->SetBinContent(i, dif/TMath::Sqrt(err2));
      else h2->SetBinContent(i, 0.0);
      */
    }
  }
  h2->Draw("same");

  pad2->Update();

  canv->Update();

  time_t t = time(0);
  struct tm * now = localtime( & t );

  histoname += "_" +std::to_string(now->tm_mon+1) +std::to_string(now->tm_mday);
  canv->Print(("result/plot/"+histoname+".pdf").c_str());
  canv->Print(("result/cscript/"+histoname+".C").c_str());

  canv->Close();
  delete h_nTrack;
  delete h_ratio;
}
