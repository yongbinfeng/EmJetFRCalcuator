void test(){
  /*
  const double err1 = 0.00137;
  const double err2 = 0.0003042;
  const double w1 = 1.0;
  const double w2 = 9.155;
  const double mean = 0.0001254;
  const double norm = 1.0/TMath::Sqrt(w1*w1+w2*w2);
  const double ratio = 0.329734;
  */

  //const double err1 = 0.0001717;
  //const double err2 = 0.0020568;
  const double w1 = 1.0;
  const double w2 = 0.03465;
  //const double mean = 0.000067569;
  const double ratio = 0.707414;

  const double mean = 0.0;
  const double err1 = 0.00116728;
 
  //const double mean = 0.0035;
  TFile* fData = new TFile("/data/users/fengyb/ClosureTest/TestClosure2/Result/histo-JetHT_CutSet1_v2_result_319_v0.root");
  TFile* fMC = new TFile("/data/users/fengyb/ClosureTest/TestClosure2/Result/histo-QCDMC_CutSet1_v2_result_319_v0.root");

  TH1D* hData = (TH1D*)fData->Get("track_signedipXYP");
  TH1D* hMC   = (TH1D*)fMC->Get("track_signedipXYP");

  TH1D* hMCs = (TH1D*)hMC->Clone("hMCs");

  TH1D* hsign = new TH1D("hsign", "hsign", 2, 0, 2);

  for(int ibin=1; ibin< hMC->GetNbinsX()+1; ibin++){
    //int ibin = 0;
    double ip = hMC->GetBinCenter(ibin);
    double ntrk = hMC->GetBinContent(ibin);
    if( ibin%100==0 ) std::cout << "track ipXY " << ip << " number of tracks "<< ntrk << std::endl;
    for(int itrk=1; itrk< ntrk; itrk++){
      //hMCs->Fill((gRandom->Gaus((ip-mean), err1) * w1 + gRandom->Gaus((ip-mean), err2) * w2));   
      double ran = gRandom->Uniform(0, 1.0);
      //if( ran<ratio && ran>0.0 ){
        hMCs->Fill(gRandom->Gaus((ip-mean), err1));
        hsign->Fill(0.);
      //}
      //else if( ran> ratio && ran<1.0){
      //  hMCs->Fill(gRandom->Gaus((ip-mean), err2));
      //  hsign->Fill(1.);
      //}
    }
  }

  // plot
  //const double sigma = 4.38556e-03;
  const double sigma = 4e-3;
  hData->GetXaxis()->SetRangeUser( -sigma,    sigma);
  hMC->GetXaxis()->SetRangeUser(   -sigma,    sigma);
  hMCs->GetXaxis()->SetRangeUser(  -sigma,    sigma);
  hData->Scale(1.0/hData->Integral());
  hMC->Scale(1.0/hMC->Integral());
  hMCs->Scale(1.0/hMCs->Integral());
  
  hData->SetLineColor(1);
  //hData->GetXaxis()->SetRangeUser(-0.01, 0.01);
  hData->SetMaximum(0.010);
  hData->Draw();
  hMC->SetLineColor(2);
  hMC->Draw("same");
  hMCs->SetLineColor(3);
  hMCs->Draw("same");

  TFile* fsave = new TFile("result.root", "recreate");
  hMCs->SetDirectory(0);
  hMCs->Write();
  hsign->SetDirectory(0);
  hsign->Write();
  hData->SetDirectory(0);
  hData->SetName("track_signedipXYP_Data");
  hData->Write();
  hMC->SetDirectory(0);
  hMC->SetName("track_signedipXYP_MC");
  hMC->Write();

}
