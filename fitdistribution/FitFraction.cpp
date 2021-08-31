#include "FitFraction.h"

void fithisto(TH1F* data, TH1F* mc1, TH1F *mc2, double &frac, double &frac_err, string histoname, bool isData)
{
  AlphaFitter fittest(data, mc1, mc2);
  if( !isData ) fittest.SetSmear(true);
  fittest.DoFit();
  frac = fittest.GetFraction();
  frac_err = fittest.GetFractionError();  
  std::cout << "fraction is "<< frac << " error is "<< frac_err << std::endl;
  //fittest.SaveResult();
  if( !isData )
     fittest.MakePlot(frac, true, histoname+ "__MC");
  else
     fittest.MakePlot(frac, true, histoname+"__Data");
}

void GetDistribution(TFile *f1, string tpname, TH1F *hfrac, float binwidth[], int Nbins, bool isData)
{
  string nhisto[20];
  double frac[20], frac_err[20];
 
  for ( int i=1; i< Nbins-1; i++){
    nhisto[i] = "jet_csvReweight__nTrack" + std::to_string((int)binwidth[i-1]) + "to" + std::to_string((int)binwidth[i]-1);
  }

  nhisto[Nbins-1] = "jet_csvReweight__nTrack" + std::to_string((int)binwidth[Nbins-2]) + "to24" ;
  std::cout << " histoname " << nhisto[Nbins-1] << std::endl;

  //TH1F *mc1 = (TH1F*)f1->Get(("Dcsv/jet_csvReweight__MCBJet__"     + tpname ).c_str())->Clone(("mc1__jet_csvReweight__MCBJet__"+tpname).c_str());
  //TH1F *mc2 = (TH1F*)f1->Get(("Dcsv/jet_csvReweight__MCLightJet__" + tpname ).c_str())->Clone(("mc2__jet_csvReweight__MCLightJet__"+tpname).c_str());
  //TH1F *mc1 = (TH1F*)f1->Get("Dcsv/jet_csvReweight__MCBJet")->Clone(("mc1__jet_csvReweight__MCBJet__"+tpname).c_str());
  //TH1F *mc2 = (TH1F*)f1->Get("Dcsv/jet_csvReweight__MCLightJet")->Clone(("mc2__jet_csvReweight__MCLightJet__"+tpname).c_str());

  for( int i=1;  i< Nbins; i++){
    TH1F *data = NULL;
    if( !isData ){
      data = (TH1F*)f1->Get(("Dcsv/"+ nhisto[i]+ "__MC__" + tpname).c_str())->Clone(("data"+nhisto[i]).c_str());    
    }
    else{
      data = (TH1F*)f1->Get(("Dcsv/"+ nhisto[i]+ "__Data__" + tpname).c_str())->Clone(("data"+nhisto[i]).c_str());    
    }
    TH1F *mc1 = (TH1F*)f1->Get(("Dcsv/"+ nhisto[i] + "__MCBJet__" + tpname ).c_str())->Clone(("mc1__jet_csvReweight__MCBJet__"+nhisto[i]).c_str());
    TH1F *mc2 = (TH1F*)f1->Get(("Dcsv/"+ nhisto[i] + "__MCLightJet__" + tpname ).c_str())->Clone(("mc1__jet_csvReweight__MCLightJet__"+nhisto[i]).c_str());
    
    string title;
    if( i< Nbins-1 ){
      title = &(nhisto[i][9]);
    }
    else{
      title = "nTrack" + std::to_string((int)binwidth[Nbins-2]) + "toInf";
    }
    data->SetTitle(title.c_str());
    if( !isData ){
      fithisto(data, mc1, mc2, frac[i], frac_err[i], "MC/" + nhisto[i] + "__" + tpname, isData);
    }
    else{
      fithisto(data, mc1, mc2, frac[i], frac_err[i], "Data/" + nhisto[i] + "__" + tpname, isData);
    }
    std::cout << "finished fitting " << nhisto[i] << std::endl;
  }

  for( int i=1; i< Nbins; i++){
    hfrac->SetBinContent(i, frac[i]); 	  
    hfrac->SetBinError(i, frac_err[i]);
  }
}

void GetDistribution_Alpha3DSigM(TFile *f1, string tpname, TH1F *hfrac, float binwidth[], int Nbins, bool isData)
{
  string nhisto[20];
  double frac[20], frac_err[20];

  for ( int i=1; i< Nbins-1; i++){
    nhisto[i] = "jet_Alpha3DSigM__nTrack" + std::to_string((int)binwidth[i-1]) + "to" + std::to_string((int)binwidth[i]-1);
  }

  nhisto[Nbins-1] = "jet_Alpha3DSigM__nTrack" + std::to_string((int)binwidth[Nbins-2]) + "to24" ;
  std::cout << " histoname " << nhisto[Nbins-2] << std::endl;

  //TH1F *mc1 = (TH1F*)f1->Get(("DAlpha3DSigM/jet_Alpha3DSigM__MCBJet__"     + tpname ).c_str())->Clone(("mc1__jet_Alpha3DSigM__MCBJet__"+tpname).c_str());
  //TH1F *mc2 = (TH1F*)f1->Get(("DAlpha3DSigM/jet_Alpha3DSigM__MCLightJet__" + tpname ).c_str())->Clone(("mc2__jet_Alpha3DSigM__MCLightJet__"+tpname).c_str());
  TH1F *mc1 = (TH1F*)f1->Get("DAlpha3DSigM/jet_Alpha3DSigM__MCBJet")->Clone(("mc1__jet_Alpha3DSigM__MCBJet__"+tpname).c_str());
  TH1F *mc2 = (TH1F*)f1->Get("DAlpha3DSigM/jet_Alpha3DSigM__MCLightJet")->Clone(("mc2__jet_Alpha3DSigM__MCLightJet__"+tpname).c_str());
  for( int i=1;  i< Nbins; i++){
    TH1F *data = NULL;
    if( !isData ){
      data = (TH1F*)f1->Get(("DAlpha3DSigM/"+ nhisto[i]+ "__MC__" + tpname).c_str())->Clone(("data"+nhisto[i]).c_str());
    }
    else{
      data = (TH1F*)f1->Get(("DAlpha3DSigM/"+ nhisto[i]+ "__Data__" + tpname).c_str())->Clone(("data"+nhisto[i]).c_str());
    }
    string title = &(nhisto[i][9]);
    data->SetTitle(title.c_str());
    if( !isData ){
      fithisto(data, mc1, mc2, frac[i], frac_err[i], "MC/" + nhisto[i] + "__" + tpname, isData);
    }
    else{
      fithisto(data, mc1, mc2, frac[i], frac_err[i], "Data/" + nhisto[i] + "__" + tpname, isData);    
    }
    std::cout << "finished fitting " << nhisto[i] << std::endl;
  }

  for( int i=1; i< Nbins; i++){
    hfrac->SetBinContent(i, frac[i]);
    hfrac->SetBinError(i, frac_err[i]);
  }
}
