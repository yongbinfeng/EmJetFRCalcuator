void fitdoublegaussian(){

  TFile* fData = new TFile("/data/users/fengyb/ClosureTest/TestClosure2/Result/histo-JetHT_CutSet1_v2_result_314_v0.root");
  TFile* fMC = new TFile("/data/users/fengyb/ClosureTest/TestClosure2/Result/histo-QCDMC_CutSet1_v2_result_314_v0.root");

  TH1F* hData = (TH1F*)fData->Get("track_signedipXYP");
  TH1F* hMC   = (TH1F*)fMC->Get("track_signedipXYP");

  hMC->GetXaxis()->SetRangeUser(-0.004, 0.004);

  double parmc[6];
  TF1 *gmc1 = new TF1("gmc1", "gaus", -0.002, 0.002);  
  TF1 *gmc2 = new TF1("gmc2", "gaus", -0.004, 0.004);
  //TF1 *gmct = new TF1("gmct", "gaus(0)+gaus(3)", -0.004, 0.004);
  TF1 *gmct = new TF1("gmct", "[0]*exp(-0.5*((x-[1])/[2])**2) + [3]*exp(-0.5*((x-[1])/[4])**2)", -0.004, 0.004);
  //gmct->SetParLimits(2, 0, 100000);
  //gmct->SetParLimits(4, 0, 100000);
  
  gmc1->SetLineColor(3);
  gmc2->SetLineColor(4);

  hMC->Fit(gmc1, "R");
  hMC->Fit(gmc2, "R+");
  gmc1->GetParameters(&parmc[0]);
  gmc2->GetParameters(&parmc[3]);
  //gmct->SetParameters(parmc);
  gmct->SetParameter(0, parmc[0]);
  gmct->SetParameter(1, parmc[1]);
  gmct->SetParameter(2, parmc[2]);
  gmct->SetParameter(3, parmc[3]);
  gmct->SetParameter(4, parmc[5]);

  TFitResultPtr fptrmc = hMC->Fit(gmct, "SR");

  std::cout << "*****************************" << std::endl;
  hData->GetXaxis()->SetRangeUser(-0.004, 0.004);  

  double pardata[6];  
  TF1 *gdata1 = new TF1("gdata1", "gaus", -0.002, 0.002);
  TF1 *gdata2 = new TF1("gdata2", "gaus", -0.004, 0.004);
  TF1 *gdatat = new TF1("gdatat", "[0]*exp(-0.5*((x-[1])/[2])**2) + [3]*exp(-0.5*((x-[1])/[4])**2)", -0.004, 0.004);

  gdata1->SetLineColor(3);
  gdata2->SetLineColor(4);

  hData->Fit(gdata1, "R");
  hData->Fit(gdata2, "R+");
  gdata1->GetParameters(&pardata[0]);
  gdata2->GetParameters(&pardata[3]);
  //gdatat->SetParameters(pardata);
  gdatat->SetParameter(0, pardata[0]);
  gdatat->SetParameter(1, pardata[1]);
  gdatat->SetParameter(2, pardata[2]);
  gdatat->SetParameter(3, pardata[3]);
  gdatat->SetParameter(4, pardata[5]);

  TFitResultPtr fptrdata = hData->Fit(gdatat, "SR");
  
  std::cout << "*****************************" << std::endl;
  fptrmc->Print("v");
  fptrdata->Print("v");

  TF1* gmctest1 = new TF1("gmctest1", "gaus", -0.004, 0.004); 
  gmctest1->SetParameter(0, gmct->GetParameter(0));
  gmctest1->SetParameter(1, gmct->GetParameter(1));
  gmctest1->SetParameter(2, gmct->GetParameter(2));
  double fmc1 = gmctest1->Integral(-0.004, 0.004);

  TF1* gmctest2 = new TF1("gmctest2", "gaus", -0.004, 0.004);
  gmctest2->SetParameter(0, gmct->GetParameter(3));
  gmctest2->SetParameter(1, gmct->GetParameter(1));
  gmctest2->SetParameter(2, gmct->GetParameter(4));
  double fmc2 = gmctest2->Integral(-0.004, 0.004); 
 
  double tmc = gmct->Integral(-0.004, 0.004);

  TF1* gdatatest1 = new TF1("gdatatest1", "gaus", -0.004, 0.004);
  gdatatest1->SetParameter(0, gdatat->GetParameter(0));
  gdatatest1->SetParameter(1, gdatat->GetParameter(1));
  gdatatest1->SetParameter(2, gdatat->GetParameter(2));
  double fdata1 = gdatatest1->Integral(-0.004, 0.004);

  TF1* gdatatest2 = new TF1("gdatatest2", "gaus", -0.004, 0.004);
  gdatatest2->SetParameter(0, gdatat->GetParameter(3));
  gdatatest2->SetParameter(1, gdatat->GetParameter(1));
  gdatatest2->SetParameter(2, gdatat->GetParameter(4));
  double fdata2 = gdatatest2->Integral(-0.004, 0.004);

  double tdata = gdatat->Integral(-0.004, 0.004);

  std::cout << "******************************" << std::endl;
  std::cout << " MC: 1 "   << fmc1 << " fraction " << fmc1/tmc << " 2 " << fmc2 << " fraction " << fmc2/tmc << std::endl;
  std::cout << " DATA: 1 " << fdata1 << " fraction " << fdata1/tdata << " 2 " << fdata2 << " fraction " << fdata2/tdata << std::endl;
}
