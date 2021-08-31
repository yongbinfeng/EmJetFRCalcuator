#include "FitFraction.h"
#include "CalFR.h"

#include <iostream>
#include <string>
#include <TROOT.h>
#include <TFile.h>
#include <TH1F.h>

#include "tclap/CmdLine.h"

using namespace TCLAP;

int main(int argc, char *argv[])
{

  CmdLine cmd("Run FractionFitter", ' ', "0.9");

  ValueArg<string> inputFileArg("i", "inputfile",  "input root file" ,  true, "", "string");
  cmd.add( inputFileArg );

  ValueArg<string> outputFileArg("o", "outputfile", "output root file", true, "", "string");
  cmd.add( outputFileArg );

  // Parse the args.
  cmd.parse( argc, argv );

  string inputfilename = inputFileArg.getValue();
  string outputfilename = outputFileArg.getValue();


  // Get Fractions
  //float binwidth[] = {0, 5, 10, 15, 20, 80}; 
  float binwidth[] = {1, 6, 11, 16, 21, 80};
  int Nbins = sizeof(binwidth)/sizeof(float);

  TFile *finput = new TFile( inputfilename.c_str() );

  TFile *myfile_save   = new TFile( outputfilename.c_str(), "RECREATE");

  TH1F *hfrac_typeV, *hfrac_typeVI;
  //TH1F *hfrac_a_typeV, *hfrac_a_typeVI;
  TH1F *hfr1, *hfr2, *hfb_calc, *hfl_calc;
  TH1F *hfb_calcTF, *hfl_calcTF;
  TH1F* hfracTF_typeV = (TH1F*)finput->Get(("Dfractions/fraction_GJetMC_BJet_TypeV"));
  TH1F* hfracTF_typeVI = (TH1F*)finput->Get(("Dfractions/fraction_GJetMC_BJet_TypeVI"));

  for(int i=0; i<2; i++){
    string tag;
    bool isData;
    if( i==0 ){
      tag = "GJetMC";
      isData = false;
    }
    else{
      tag = "GJetData";
      isData = true;
    }
    
    hfrac_typeV  = new TH1F(("fraction_"+tag+"_TypeV").c_str(),  ("fraction distribution in TypeV in "+tag).c_str(),  sizeof(binwidth)/sizeof(float)-1, binwidth);
    hfrac_typeVI = new TH1F(("fraction_"+tag+"_TypeVI").c_str(), ("fraction distribution in TypeVI in "+tag).c_str(), sizeof(binwidth)/sizeof(float)-1, binwidth);

    //hfrac_a_typeV  = new TH1F(("fraction_a_"+tag+"_TypeV").c_str(),  ("fraction_a distribution in TypeV in "+tag).c_str(),  sizeof(binwidth)/sizeof(float)-1, binwidth);
    //hfrac_a_typeVI = new TH1F(("fraction_a_"+tag+"_TypeVI").c_str(), ("fraction_a distribution in TypeVI in "+tag).c_str(), sizeof(binwidth)/sizeof(float)-1, binwidth);

    GetDistribution(finput, "TypeV",   hfrac_typeV,  binwidth, Nbins, isData);
    GetDistribution(finput, "TypeVI",  hfrac_typeVI, binwidth, Nbins, isData);

    //GetDistribution_Alpha3DSigM(finput, "TypeV", hfrac_a_typeV,   binwidth, Nbins, isData);
    //GetDistribution_Alpha3DSigM(finput, "TypeVI", hfrac_a_typeVI,  binwidth, Nbins, isData);

    hfrac_typeV->SetDirectory(myfile_save);   hfrac_typeV->SetName(("fraction_"+tag+"_TypeV").c_str());   hfrac_typeV->Write(); 
    hfrac_typeVI->SetDirectory(myfile_save);  hfrac_typeVI->SetName(("fraction_"+tag+"_TypeVI").c_str());   hfrac_typeVI->Write();

    //hfrac_a_typeV->SetDirectory(myfile_save);     hfrac_a_typeV->Write();
    //hfrac_a_typeVI->SetDirectory(myfile_save);    hfrac_a_typeVI->Write();

    // Get Fakerates
    hfr1 =  (TH1F*)finput->Get(("Dfakerates/fakerate_" + tag + "_TypeV" ).c_str());
    hfr2 =  (TH1F*)finput->Get(("Dfakerates/fakerate_" + tag + "_TypeVI").c_str());

    // Get Fakerate using fitted b jet fraction
    hfb_calc = (TH1F*)hfr1->Clone(("fakerate_" + tag + "_BJet_calc").c_str());
    hfl_calc = (TH1F*)hfr2->Clone(("fakerate_" + tag + "_LightJet_calc").c_str());
    hfb_calc->SetTitle(("calculated fakerate of BJet in "+ tag).c_str());
    hfl_calc->SetTitle(("calculated fakerate of LightJet in "+ tag).c_str());

    FrHistoCal(hfrac_typeV, hfrac_typeVI, hfr1, hfr2, hfb_calc, hfl_calc);

    hfb_calc->SetDirectory(myfile_save); hfb_calc->Write();
    hfl_calc->SetDirectory(myfile_save); hfl_calc->Write();
  
    // Get Fakerate using truth b jet fraction
    hfb_calcTF = (TH1F*)hfr1->Clone(("fakerate_" + tag + "_BJet_calcTF").c_str());
    hfl_calcTF = (TH1F*)hfr2->Clone(("fakerate_" + tag + "_LightJet_calcTF").c_str());
    hfb_calcTF->SetTitle(("calculated fakerate of BJet using truth b jet fraction in " + tag).c_str());
    hfl_calcTF->SetTitle(("calculated fakerate of LightJet using truth b jet fraction in " + tag).c_str());
 
    FrHistoCal(hfracTF_typeV, hfracTF_typeVI, hfr1, hfr2, hfb_calcTF, hfl_calcTF);
    
    hfb_calcTF->SetDirectory(myfile_save); hfb_calcTF->Write();
    hfl_calcTF->SetDirectory(myfile_save); hfl_calcTF->Write();

    hfr1->SetDirectory(myfile_save); hfr1->SetName(("fakerate_" + tag + "_TypeV").c_str());  hfr1->Write();
    hfr2->SetDirectory(myfile_save); hfr2->SetName(("fakerate_" + tag + "_TypeVI").c_str());   hfr2->Write();
    
  }

  myfile_save->Close();
}   
