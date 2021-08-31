double fmcfit(double *x, double *par)
{
  // the double gaussian function fitted from MC
  const double A1 = 376685.0;
  const double A2 = 653373.0;
  const double mean = 1.77555e-05;
  const double w1 = 0.00116543;
  const double w2 = 0.00325938;

  double xx = x[0];
  return A1*exp(-0.5*TMath::Power((xx-mean)/w1, 2)) + A2*exp(-0.5*TMath::Power((xx-mean)/w2, 2));
}

void testfit(){

  TFile* fData = new TFile("/data/users/fengyb/ClosureTest/TestClosure2/Result/histo-JetHT_CutSet1_v2_result_314_v0.root");
  TH1F* hData = (TH1F*)fData->Get("track_signedipXYP");

  // build the TF1 of MC
  TF1 *fmc = new TF1("fmc", fmcfit, -0.004, 0.004); 
  
  // build the smearing TF1
  TF1 *fsmear = new TF1("fsmear", "[0]*exp(-0.5*(x/[1])**2) + [2]*exp(-0.5*(x/[3])**2)", -0.012, 0.012);

  TF1Convolution *fconv = new TF1Convolution(fmc, fsmear, -0.012, 0.012); 
  fconv->SetRange(-0.012, 0.012);
  fconv->SetNofPointsFFT(1000);
  TF1 *fmcs = new TF1("fmcs", *fconv, -0.01, 0.01, fconv->GetNpar());
  fmcs->SetParameter(0, 500);
  //fmcs->SetParameter(1, 0.);
  fmcs->SetParameter(1, 0.0006);
  fmcs->SetParameter(2, 500);
  fmcs->SetParameter(3, 0.005);


  // plot
  const double sigma = 4e-3;
  hData->GetXaxis()->SetRangeUser( -sigma,   sigma);
  //hData->Scale(1.0/hData->Integral());
  //
  hData->Fit(fmcs, "SR");
  hData->Fit(fmcs, "SR");
  
  //hData->SetLineColor(1);
  //hData->GetXaxis()->SetRangeUser(-0.01, 0.01);
  //hData->SetMaximum(0.006);
  //hData->Draw();

  //TFile* fsave = new TFile("result_conv.root", "recreate");
  //hData->SetDirectory(0);
  //hData->SetName("track_signedipXYP_Data");
  //fmc->SetDirectory(0);
  //fmc->SetName("func_signedipXYP_MC");
  //fmc->Write();
  //fmcs->SetDirectory(0);
  //fmcs->SetName("func_signedipXYP_MCSmeared");
  //fmcs->Write();
}
