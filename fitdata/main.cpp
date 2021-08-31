#include "FitFraction.h"

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
  CmdLine cmd("Run FractionFitter", ' ', "0.9");

  ValueArg<string> inputFitFileArg("f", "fitfile",  "input fit file" ,  true, "", "string");
  cmd.add( inputFitFileArg );

  ValueArg<string> inputTemplateFileArg("t", "templatefile",  "input template file" ,  true, "", "string");
  cmd.add( inputTemplateFileArg );

  ValueArg<string> outputFileArg("o", "outputfile", "output root file", true, "", "string");
  cmd.add( outputFileArg );

  ValueArg<bool> isDataArg("s", "isdata", "input file type, 1 for data and 0 for MC", true, false, "bool");
  cmd.add( isDataArg );

  // Parse the args.
  cmd.parse( argc, argv );

  string inputFitFile = inputFitFileArg.getValue();
  string inputTemplateFile = inputTemplateFileArg.getValue();
  string outputFile = outputFileArg.getValue();
  bool isData = isDataArg.getValue();

  //TFile *f1 = new TFile("/data/users/fengyb/ClosureTest/TestClosure/Result/11315/histo-JetHTOct16_5mm_A3D45_result_withcount.root");
  TFile *f1 = new TFile(inputFitFile.c_str());
  TH1F *data1 = (TH1F*)f1->Get("jet_csvReweight__Standard__1tag")->Clone("test_data1");
  TH1F *data0 = (TH1F*)f1->Get("jet_csvReweight__Standard__0tag")->Clone("test_data0");

  //TFile *f2 = new TFile("/data/users/fengyb/ClosureTest/TestClosure/Result/11316/histo-QCDMCOct16_5mm_A3D45_result_0.root");
  TFile *f2 = new TFile(inputTemplateFile.c_str());
  TH1F *mc1l = (TH1F*)f2->Get("jet_csvReweight__L__Standard__1tag")->Clone("test_mc1l");
  TH1F *mc1b = (TH1F*)f2->Get("jet_csvReweight__B__Standard__1tag")->Clone("test_mc1b");
  TH1F *mc0l = (TH1F*)f2->Get("jet_csvReweight__L__Standard__0tag")->Clone("test_mc0l");
  TH1F *mc0b = (TH1F*)f2->Get("jet_csvReweight__B__Standard__0tag")->Clone("test_mc0b");
 
  data1->Rebin(5); 
  mc1l->Rebin(5);
  mc1b->Rebin(5);

  data0->Rebin(5);
  mc0l->Rebin(5);
  mc0b->Rebin(5);
  

  double frac0, frac1;
  double frac_err0, frac_err1;
  
  std::cout << "working on " << ( isData ? "Data" : "MC" ) << std::endl;
  fithisto(data1, mc1b, mc1l, frac1, frac_err1, "bfraction_1tag", isData);
  fithisto(data0, mc0b, mc0l, frac0, frac_err0, "bfraction_0tag", isData);

  std::cout << "0tag : fraction b "<< std::setprecision(10) << frac0 << "+/-" << std::setprecision(10) << frac_err0 << std::endl;
  std::cout << "1tag : fraction b "<< std::setprecision(10) << frac1 << "+/-" << std::setprecision(10) << frac_err1 << std::endl;

  TFile *fnew = new TFile(outputFile.c_str(), "RECREATE");
  string datatype = (isData ? "Data" : "MC");
  TH1F* hbfraction = new TH1F(("bfraction_in_tags_"+datatype).c_str(), ("bfraction in 0tag and 1tag in "+datatype).c_str(), 2, 0, 2);
  hbfraction->SetBinContent(1, frac0); hbfraction->SetBinError(1, frac_err0);
  hbfraction->SetBinContent(2, frac1); hbfraction->SetBinError(2, frac_err1);

  fnew->Write();
  fnew->Close();
}   
