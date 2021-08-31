#include "CalFR.h"

#include <iostream>
#include <string>
#include <TROOT.h>
#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>

#include "tclap/CmdLine.h"

using namespace TCLAP;
using namespace std;

int main(int argc, char *argv[])
{
  CmdLine cmd("Run Avg Fakerate Calculator", ' ', "0.9");

  ValueArg<string> inputFitFileArg("i", "inputfile",  "input file" ,  true, "", "string");
  cmd.add( inputFitFileArg );

  ValueArg<string> outputFileArg("o", "outputfile", "output root file", true, "", "string");
  cmd.add( outputFileArg );

  ValueArg<bool> isDataArg("s", "isdata", "input file type, 1 for data and 0 for MC", true, false, "bool");
  cmd.add( isDataArg );
 
  //ValueArg<int> nTagArg("n", "ntag", "specify either 0tag or 0tag", false, 1, "int");
  //cmd.add( nTagArg );

  // Parse the args.
  cmd.parse( argc, argv );

  string inputFitFile = inputFitFileArg.getValue();
  string outputFile = outputFileArg.getValue();
  bool isData = isDataArg.getValue();
  //int nTag = nTagArg.getValue();
 
  string Datatype;
  if( isData )  Datatype= "Data";
  else          Datatype= "MC";
  TFile *f1 = new TFile(inputFitFile.c_str());
  /*
  TH1F* hfrac1 = (TH1F*)f1->Get(("fraction_GJet"+Datatype+"_TypeVI").c_str());
  TH1F* hfrac2 = (TH1F*)f1->Get(("fraction_GJet"+Datatype+"_TypeV").c_str());
  TH1F* hfr1 = (TH1F*)f1->Get(("fakerate_GJet"+Datatype+"_TypeVI").c_str());
  TH1F* hfr2 = (TH1F*)f1->Get(("fakerate_GJet"+Datatype+"_TypeV").c_str());
  TH1F* hfractot = (TH1F*)f1->Get(("bfraction_in_tags_"+Datatype).c_str());
  */
  TH1F* hfrac1 = (TH1F*)f1->Get(("fraction_GJet"+Datatype+"_TypeI").c_str());
  TH1F* hfrac2 = (TH1F*)f1->Get(("fraction_GJet"+Datatype+"_TypeII").c_str());
  TH1F* hfr1 = (TH1F*)f1->Get(("fakerate_GJet"+Datatype+"_TypeI").c_str());
  TH1F* hfr2 = (TH1F*)f1->Get(("fakerate_GJet"+Datatype+"_TypeII").c_str());
  TH1F* hfractot = (TH1F*)f1->Get("bfraction_in_tags");

  TH1F* hfr0tagtot = (TH1F*)hfr1->Clone("hfr0tagtot");
  TH1F* hfr1tagtot = (TH1F*)hfr1->Clone("hfr1tagtot");

  double fb0tagtot=0, err_fb0tagtot = 0;
  std::cout << " working on 0 tag" << std::endl;
  fb0tagtot = hfractot->GetBinContent(1);
  err_fb0tagtot = hfractot->GetBinError(1); 
  FrHistoCalTot(hfrac1, hfrac2, hfr1, hfr2, fb0tagtot, err_fb0tagtot, hfr0tagtot);

  double fb1tagtot=0, err_fb1tagtot = 0;   
  std::cout << " working on 1 tag" << std::endl;
  fb1tagtot = hfractot->GetBinContent(2);
  err_fb1tagtot = hfractot->GetBinError(2);
  FrHistoCalTot(hfrac1, hfrac2, hfr1, hfr2, fb1tagtot, err_fb1tagtot, hfr1tagtot);

  /*
     repeated using truth b jet fraction
  */
  /*
  TH1F* hfracTF1 = (TH1F*)f1->Get("Dfractions/fraction_GJetMC_BJet_TypeV");
  TH1F* hfracTF2 = (TH1F*)f1->Get("Dfractions/fraction_GJetMC_BJet_TypeVI");
  TH1F* hfractotTF = (TH1F*)f1->Get("bfraction_in_tags_MC");    
  TH1F* hfr0tagtotTF = (TH1F*)hfr1->Clone("hfr0tagtotTF");
  TH1F* hfr1tagtotTF = (TH1F*)hfr1->Clone("hfr1tagtotTF");
  */
  TH1F* hfracTF1 = (TH1F*)f1->Get("Dfractions/fraction_GJetMC_BJet_TypeIIII");
  TH1F* hfracTF2 = (TH1F*)f1->Get("Dfractions/fraction_GJetMC_BJet_TypeIII");
  TH1F* hfractotTF = (TH1F*)f1->Get("bfraction_in_tags");
  TH1F* hfr0tagtotTF = (TH1F*)hfr1->Clone("hfr0tagtotTF");
  TH1F* hfr1tagtotTF = (TH1F*)hfr1->Clone("hfr1tagtotTF");

  double fb0tagtotTF=0, err_fb0tagtotTF = 0;
  std::cout << " working on TF 0 tag" << std::endl;
  fb0tagtotTF = hfractotTF->GetBinContent(1);
  err_fb0tagtotTF = hfractotTF->GetBinError(1);
  FrHistoCalTot(hfracTF1, hfracTF2, hfr1, hfr2, fb0tagtotTF, err_fb0tagtotTF, hfr0tagtotTF);

  double fb1tagtotTF=0, err_fb1tagtotTF = 0;
  std::cout << " working on TF 1 tag" << std::endl;
  fb1tagtotTF = hfractotTF->GetBinContent(2);
  err_fb1tagtotTF = hfractotTF->GetBinError(2);
  FrHistoCalTot(hfracTF1, hfracTF2, hfr1, hfr2, fb1tagtotTF, err_fb1tagtotTF, hfr1tagtotTF);

  /*
     save histograms
  */

  TFile *fnew = new TFile(outputFile.c_str(), "RECREATE");

  hfr0tagtot->SetName("fakerate_0tag"); 
  hfr0tagtot->SetTitle("weighted average of fakerate in 0tag");
  hfr0tagtot->SetDirectory(fnew);

  hfr1tagtot->SetName("fakerate_1tag");
  hfr1tagtot->SetTitle("weighted average of fakerate in 1tag");
  hfr1tagtot->SetDirectory(fnew);

  hfr0tagtotTF->SetName("fakerate_TF_0tag");
  hfr0tagtotTF->SetTitle("weighted average of fakerate using truth b fraction in 0tag");
  hfr0tagtotTF->SetDirectory(fnew);

  hfr1tagtotTF->SetName("fakerate_TF_1tag");
  hfr1tagtotTF->SetTitle("weighted average of fakerate using truth b fraction in 1tag");
  hfr1tagtotTF->SetDirectory(fnew);
  
  fnew->Write();
  fnew->Close();
}


