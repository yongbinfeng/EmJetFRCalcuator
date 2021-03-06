void bfraction_1tag__Data_418()
{
//=========Macro generated from canvas: Fig_/Fig_
//=========  (Wed Apr 18 10:23:41 2018) by ROOT version6.06/01
   TCanvas *Fig_ = new TCanvas("Fig_", "Fig_",0,0,800,800);
   gStyle->SetOptStat(0);
   Fig_->SetHighLightColor(2);
   Fig_->Range(0,0,1,1);
   Fig_->SetFillColor(0);
   Fig_->SetBorderMode(0);
   Fig_->SetBorderSize(2);
   Fig_->SetFrameFillStyle(0);
   Fig_->SetFrameBorderMode(0);
  
// ------------>Primitives in pad: pad1
   TPad *pad1 = new TPad("pad1", "",0,0.3,1,1);
   pad1->Draw();
   pad1->cd();
   pad1->Range(-0.1428571,-4.126644,1.047619,2.205545);
   pad1->SetFillColor(0);
   pad1->SetBorderMode(0);
   pad1->SetBorderSize(2);
   pad1->SetLogy();
   pad1->SetLeftMargin(0.12);
   pad1->SetRightMargin(0.04);
   pad1->SetTopMargin(0.08);
   pad1->SetBottomMargin(0.02);
   pad1->SetFrameBorderMode(0);
   pad1->SetFrameBorderMode(0);
   
   TH1F *h_nTrack__1 = new TH1F("h_nTrack__1"," ",100,0,1);
   h_nTrack__1->SetMinimum(0.0001);
   h_nTrack__1->SetMaximum(50);
   h_nTrack__1->SetStats(0);

   Int_t ci;      // for color index setting
   TColor *color; // for color definition with alpha
   ci = TColor::GetColor("#000099");
   h_nTrack__1->SetLineColor(ci);
   h_nTrack__1->GetXaxis()->SetNdivisions(506);
   h_nTrack__1->GetXaxis()->SetLabelFont(42);
   h_nTrack__1->GetXaxis()->SetLabelSize(0);
   h_nTrack__1->GetXaxis()->SetTitleSize(0.035);
   h_nTrack__1->GetXaxis()->SetTitleFont(42);
   h_nTrack__1->GetYaxis()->SetTitle("A.U.");
   h_nTrack__1->GetYaxis()->SetNdivisions(506);
   h_nTrack__1->GetYaxis()->SetLabelFont(42);
   h_nTrack__1->GetYaxis()->SetLabelSize(0.035);
   h_nTrack__1->GetYaxis()->SetTitleSize(0.05);
   h_nTrack__1->GetYaxis()->SetTitleFont(42);
   h_nTrack__1->GetZaxis()->SetLabelFont(42);
   h_nTrack__1->GetZaxis()->SetLabelSize(0.035);
   h_nTrack__1->GetZaxis()->SetTitleSize(0.035);
   h_nTrack__1->GetZaxis()->SetTitleFont(42);
   h_nTrack__1->Draw("");
   
   TH1F *data__2 = new TH1F("data__2","jet_csv__Standard__1tag",20,0,1);
   data__2->SetBinContent(0,0.0004426682);
   data__2->SetBinContent(1,0.000860041);
   data__2->SetBinContent(2,0.1606632);
   data__2->SetBinContent(3,0.1398452);
   data__2->SetBinContent(4,0.1425897);
   data__2->SetBinContent(5,0.07453267);
   data__2->SetBinContent(6,0.06123998);
   data__2->SetBinContent(7,0.05382845);
   data__2->SetBinContent(8,0.04228113);
   data__2->SetBinContent(9,0.03795563);
   data__2->SetBinContent(10,0.03585612);
   data__2->SetBinContent(11,0.02957023);
   data__2->SetBinContent(12,0.023512);
   data__2->SetBinContent(13,0.02442263);
   data__2->SetBinContent(14,0.0224496);
   data__2->SetBinContent(15,0.02067893);
   data__2->SetBinContent(16,0.02051451);
   data__2->SetBinContent(17,0.02079276);
   data__2->SetBinContent(18,0.02141249);
   data__2->SetBinContent(19,0.02229783);
   data__2->SetBinContent(20,0.04469683);
   data__2->SetBinError(0,7.482457e-05);
   data__2->SetBinError(1,0.0001042953);
   data__2->SetBinError(2,0.001425487);
   data__2->SetBinError(3,0.00132993);
   data__2->SetBinError(4,0.001342917);
   data__2->SetBinError(5,0.0009709088);
   data__2->SetBinError(6,0.000880081);
   data__2->SetBinError(7,0.0008251085);
   data__2->SetBinError(8,0.0007312711);
   data__2->SetBinError(9,0.0006928564);
   data__2->SetBinError(10,0.0006734212);
   data__2->SetBinError(11,0.0006115507);
   data__2->SetBinError(12,0.0005453181);
   data__2->SetBinError(13,0.000555778);
   data__2->SetBinError(14,0.0005328555);
   data__2->SetBinError(15,0.0005114099);
   data__2->SetBinError(16,0.0005093727);
   data__2->SetBinError(17,0.0005128155);
   data__2->SetBinError(18,0.0005204017);
   data__2->SetBinError(19,0.0005310512);
   data__2->SetBinError(20,0.0007518713);
   data__2->SetEntries(79101);
   data__2->SetMarkerStyle(22);
   data__2->SetMarkerSize(2);
   data__2->GetXaxis()->SetRange(1,100);
   data__2->GetXaxis()->SetLabelFont(42);
   data__2->GetXaxis()->SetLabelSize(0.035);
   data__2->GetXaxis()->SetTitleSize(0.035);
   data__2->GetXaxis()->SetTitleFont(42);
   data__2->GetYaxis()->SetLabelFont(42);
   data__2->GetYaxis()->SetLabelSize(0.035);
   data__2->GetYaxis()->SetTitleSize(0.035);
   data__2->GetYaxis()->SetTitleFont(42);
   data__2->GetZaxis()->SetLabelFont(42);
   data__2->GetZaxis()->SetLabelSize(0.035);
   data__2->GetZaxis()->SetTitleSize(0.035);
   data__2->GetZaxis()->SetTitleFont(42);
   data__2->Draw("Ep same");
   
   TH1F *mc1__3 = new TH1F("mc1__3","jet_csv__B__Standard__1tag",20,0,1);
   mc1__3->SetBinContent(0,0.0005002756);
   mc1__3->SetBinContent(1,7.799559e-05);
   mc1__3->SetBinContent(2,0.01856295);
   mc1__3->SetBinContent(3,0.01901941);
   mc1__3->SetBinContent(4,0.03145057);
   mc1__3->SetBinContent(5,0.02025455);
   mc1__3->SetBinContent(6,0.02006328);
   mc1__3->SetBinContent(7,0.01888316);
   mc1__3->SetBinContent(8,0.01994804);
   mc1__3->SetBinContent(9,0.02263441);
   mc1__3->SetBinContent(10,0.02093044);
   mc1__3->SetBinContent(11,0.01908531);
   mc1__3->SetBinContent(12,0.02058257);
   mc1__3->SetBinContent(13,0.02657202);
   mc1__3->SetBinContent(14,0.0298496);
   mc1__3->SetBinContent(15,0.03092684);
   mc1__3->SetBinContent(16,0.04428442);
   mc1__3->SetBinContent(17,0.05805866);
   mc1__3->SetBinContent(18,0.0827616);
   mc1__3->SetBinContent(19,0.1248609);
   mc1__3->SetBinContent(20,0.3711933);
   mc1__3->SetBinError(0,0.0002888343);
   mc1__3->SetBinError(1,3.496946e-05);
   mc1__3->SetBinError(2,0.001852511);
   mc1__3->SetBinError(3,0.001855972);
   mc1__3->SetBinError(4,0.002377035);
   mc1__3->SetBinError(5,0.00193628);
   mc1__3->SetBinError(6,0.001887715);
   mc1__3->SetBinError(7,0.00180435);
   mc1__3->SetBinError(8,0.001868398);
   mc1__3->SetBinError(9,0.002073974);
   mc1__3->SetBinError(10,0.001905728);
   mc1__3->SetBinError(11,0.001854119);
   mc1__3->SetBinError(12,0.00190079);
   mc1__3->SetBinError(13,0.002183926);
   mc1__3->SetBinError(14,0.002313279);
   mc1__3->SetBinError(15,0.002313509);
   mc1__3->SetBinError(16,0.002872449);
   mc1__3->SetBinError(17,0.003285308);
   mc1__3->SetBinError(18,0.003830352);
   mc1__3->SetBinError(19,0.004806403);
   mc1__3->SetBinError(20,0.008269199);
   mc1__3->SetEntries(10978);
   mc1__3->SetLineColor(2);
   mc1__3->GetXaxis()->SetRange(1,100);
   mc1__3->GetXaxis()->SetLabelFont(42);
   mc1__3->GetXaxis()->SetLabelSize(0.035);
   mc1__3->GetXaxis()->SetTitleSize(0.035);
   mc1__3->GetXaxis()->SetTitleFont(42);
   mc1__3->GetYaxis()->SetLabelFont(42);
   mc1__3->GetYaxis()->SetLabelSize(0.035);
   mc1__3->GetYaxis()->SetTitleSize(0.035);
   mc1__3->GetYaxis()->SetTitleFont(42);
   mc1__3->GetZaxis()->SetLabelFont(42);
   mc1__3->GetZaxis()->SetLabelSize(0.035);
   mc1__3->GetZaxis()->SetTitleSize(0.035);
   mc1__3->GetZaxis()->SetTitleFont(42);
   mc1__3->Draw("same");
   
   TH1F *mc2__4 = new TH1F("mc2__4","jet_csv__L__Standard__1tag",20,0,1);
   mc2__4->SetBinContent(0,0.0003108789);
   mc2__4->SetBinContent(1,0.001405003);
   mc2__4->SetBinContent(2,0.1913138);
   mc2__4->SetBinContent(3,0.145373);
   mc2__4->SetBinContent(4,0.1588928);
   mc2__4->SetBinContent(5,0.08070883);
   mc2__4->SetBinContent(6,0.06648169);
   mc2__4->SetBinContent(7,0.0547543);
   mc2__4->SetBinContent(8,0.04240157);
   mc2__4->SetBinContent(9,0.03927891);
   mc2__4->SetBinContent(10,0.03781799);
   mc2__4->SetBinContent(11,0.03066593);
   mc2__4->SetBinContent(12,0.02280085);
   mc2__4->SetBinContent(13,0.024444);
   mc2__4->SetBinContent(14,0.02188327);
   mc2__4->SetBinContent(15,0.01749106);
   mc2__4->SetBinContent(16,0.01773107);
   mc2__4->SetBinContent(17,0.01620992);
   mc2__4->SetBinContent(18,0.01364112);
   mc2__4->SetBinContent(19,0.01016915);
   mc2__4->SetBinContent(20,0.006535754);
   mc2__4->SetBinError(0,7.498516e-05);
   mc2__4->SetBinError(1,0.0001508367);
   mc2__4->SetBinError(2,0.002053789);
   mc2__4->SetBinError(3,0.001760839);
   mc2__4->SetBinError(4,0.001845116);
   mc2__4->SetBinError(5,0.001307318);
   mc2__4->SetBinError(6,0.001182636);
   mc2__4->SetBinError(7,0.001069928);
   mc2__4->SetBinError(8,0.0009391772);
   mc2__4->SetBinError(9,0.0009112868);
   mc2__4->SetBinError(10,0.0008972686);
   mc2__4->SetBinError(11,0.0008019819);
   mc2__4->SetBinError(12,0.0006798142);
   mc2__4->SetBinError(13,0.0007125863);
   mc2__4->SetBinError(14,0.0006762963);
   mc2__4->SetBinError(15,0.0005934319);
   mc2__4->SetBinError(16,0.0006108589);
   mc2__4->SetBinError(17,0.0005816954);
   mc2__4->SetBinError(18,0.0005309509);
   mc2__4->SetBinError(19,0.0004649277);
   mc2__4->SetBinError(20,0.000358408);
   mc2__4->SetEntries(99878);
   mc2__4->SetLineColor(3);
   mc2__4->GetXaxis()->SetRange(1,100);
   mc2__4->GetXaxis()->SetLabelFont(42);
   mc2__4->GetXaxis()->SetLabelSize(0.035);
   mc2__4->GetXaxis()->SetTitleSize(0.035);
   mc2__4->GetXaxis()->SetTitleFont(42);
   mc2__4->GetYaxis()->SetLabelFont(42);
   mc2__4->GetYaxis()->SetLabelSize(0.035);
   mc2__4->GetYaxis()->SetTitleSize(0.035);
   mc2__4->GetYaxis()->SetTitleFont(42);
   mc2__4->GetZaxis()->SetLabelFont(42);
   mc2__4->GetZaxis()->SetLabelSize(0.035);
   mc2__4->GetZaxis()->SetTitleSize(0.035);
   mc2__4->GetZaxis()->SetTitleFont(42);
   mc2__4->Draw("same");
   
   TH1F *result__5 = new TH1F("result__5","jet_csv__B__Standard__1tag",20,0,1);
   result__5->SetBinContent(0,0.0005002756);
   result__5->SetBinContent(1,0.001263594);
   result__5->SetBinContent(2,0.172905);
   result__5->SetBinContent(3,0.1319085);
   result__5->SetBinContent(4,0.1453122);
   result__5->SetBinContent(5,0.07426666);
   result__5->SetBinContent(6,0.06153523);
   result__5->SetBinContent(7,0.05093177);
   result__5->SetBinContent(8,0.04000886);
   result__5->SetBinContent(9,0.03750522);
   result__5->SetBinContent(10,0.03601841);
   result__5->SetBinContent(11,0.02943187);
   result__5->SetBinContent(12,0.02256446);
   result__5->SetBinContent(13,0.02467077);
   result__5->SetBinContent(14,0.02273218);
   result__5->SetBinContent(15,0.01892281);
   result__5->SetBinContent(16,0.02056067);
   result__5->SetBinContent(17,0.02066943);
   result__5->SetBinContent(18,0.02100678);
   result__5->SetBinContent(19,0.022391);
   result__5->SetBinContent(20,0.04539461);
   result__5->SetBinError(0,0.0002888343);
   result__5->SetBinError(1,0.000134869);
   result__5->SetBinError(2,0.001918079);
   result__5->SetBinError(3,0.001634916);
   result__5->SetBinError(4,0.001724999);
   result__5->SetBinError(5,0.001207474);
   result__5->SetBinError(6,0.001092034);
   result__5->SetBinError(7,0.0009876929);
   result__5->SetBinError(8,0.0008717532);
   result__5->SetBinError(9,0.0008525963);
   result__5->SetBinError(10,0.0008352835);
   result__5->SetBinError(11,0.0007497218);
   result__5->SetBinError(12,0.0006456793);
   result__5->SetBinError(13,0.0006849241);
   result__5->SetBinError(14,0.0006602909);
   result__5->SetBinError(15,0.0005926346);
   result__5->SetBinError(16,0.0006390402);
   result__5->SetBinError(17,0.000647702);
   result__5->SetBinError(18,0.00066606);
   result__5->SetBinError(19,0.0007422087);
   result__5->SetBinError(20,0.001377596);
   result__5->SetEntries(10998);
   result__5->SetLineColor(4);
   result__5->GetXaxis()->SetRange(1,100);
   result__5->GetXaxis()->SetLabelFont(42);
   result__5->GetXaxis()->SetLabelSize(0.035);
   result__5->GetXaxis()->SetTitleSize(0.035);
   result__5->GetXaxis()->SetTitleFont(42);
   result__5->GetYaxis()->SetLabelFont(42);
   result__5->GetYaxis()->SetLabelSize(0.035);
   result__5->GetYaxis()->SetTitleSize(0.035);
   result__5->GetYaxis()->SetTitleFont(42);
   result__5->GetZaxis()->SetLabelFont(42);
   result__5->GetZaxis()->SetLabelSize(0.035);
   result__5->GetZaxis()->SetTitleSize(0.035);
   result__5->GetZaxis()->SetTitleFont(42);
   result__5->Draw("same");
   
   TPaveText *pt = new TPaveText(0.4818342,0.94,0.5181658,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   TText *AText = pt->AddText(" ");
   pt->Draw();
   
   TH1F *h_nTrack_copy__6 = new TH1F("h_nTrack_copy__6"," ",100,0,1);
   h_nTrack_copy__6->SetMinimum(0.0001);
   h_nTrack_copy__6->SetMaximum(50);
   h_nTrack_copy__6->SetDirectory(0);
   h_nTrack_copy__6->SetStats(0);

   ci = TColor::GetColor("#000099");
   h_nTrack_copy__6->SetLineColor(ci);
   h_nTrack_copy__6->GetXaxis()->SetNdivisions(506);
   h_nTrack_copy__6->GetXaxis()->SetLabelFont(42);
   h_nTrack_copy__6->GetXaxis()->SetLabelSize(0);
   h_nTrack_copy__6->GetXaxis()->SetTitleSize(0.035);
   h_nTrack_copy__6->GetXaxis()->SetTitleFont(42);
   h_nTrack_copy__6->GetYaxis()->SetTitle("A.U.");
   h_nTrack_copy__6->GetYaxis()->SetNdivisions(506);
   h_nTrack_copy__6->GetYaxis()->SetLabelFont(42);
   h_nTrack_copy__6->GetYaxis()->SetLabelSize(0.035);
   h_nTrack_copy__6->GetYaxis()->SetTitleSize(0.05);
   h_nTrack_copy__6->GetYaxis()->SetTitleFont(42);
   h_nTrack_copy__6->GetZaxis()->SetLabelFont(42);
   h_nTrack_copy__6->GetZaxis()->SetLabelSize(0.035);
   h_nTrack_copy__6->GetZaxis()->SetTitleSize(0.035);
   h_nTrack_copy__6->GetZaxis()->SetTitleFont(42);
   h_nTrack_copy__6->Draw("sameaxis");
   
   TLegend *leg = new TLegend(0.52,0.62,0.92,0.9,NULL,"brNDC");
   leg->SetBorderSize(0);
   leg->SetTextFont(32);
   leg->SetTextSize(0.06);
   leg->SetLineColor(1);
   leg->SetLineStyle(1);
   leg->SetLineWidth(1);
   leg->SetFillColor(0);
   leg->SetFillStyle(1001);
   TLegendEntry *entry=leg->AddEntry("NULL","bfraction_1tag__Data","h");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(21);
   entry->SetMarkerSize(1);
   entry->SetTextFont(32);
   entry=leg->AddEntry("data","data","pel");
   entry->SetLineColor(1);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(22);
   entry->SetMarkerSize(2);
   entry->SetTextFont(32);
   entry=leg->AddEntry("mc1","b jet","pel");
   entry->SetLineColor(2);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(32);
   entry=leg->AddEntry("mc2","light jet","pel");
   entry->SetLineColor(3);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(32);
   entry=leg->AddEntry("result","result","pel");
   entry->SetLineColor(4);
   entry->SetLineStyle(1);
   entry->SetLineWidth(1);
   entry->SetMarkerColor(1);
   entry->SetMarkerStyle(1);
   entry->SetMarkerSize(1);
   entry->SetTextFont(32);
   leg->Draw();
      tex = new TLatex(0.42,0.42,"#chi^{2} = 66.16 ndof= 20");
   tex->SetTextFont(32);
   tex->SetTextSize(0.04);
   tex->SetLineWidth(2);
   tex->Draw();
   pad1->Modified();
   Fig_->cd();
  
// ------------>Primitives in pad: pad2
   TPad *pad2 = new TPad("pad2", "",0,0,1,0.3);
   pad2->Draw();
   pad2->cd();
   pad2->Range(-0.1428571,-0.9636364,1.047619,1.945455);
   pad2->SetFillColor(0);
   pad2->SetBorderMode(0);
   pad2->SetBorderSize(2);
   pad2->SetGridy();
   pad2->SetLeftMargin(0.12);
   pad2->SetRightMargin(0.04);
   pad2->SetTopMargin(0.05);
   pad2->SetBottomMargin(0.4);
   pad2->SetFrameBorderMode(0);
   pad2->SetFrameBorderMode(0);
   
   TH1F *h_ratio__7 = new TH1F("h_ratio__7"," ",100,0,1);
   h_ratio__7->SetMinimum(0.2);
   h_ratio__7->SetMaximum(1.8);
   h_ratio__7->SetStats(0);

   ci = TColor::GetColor("#000099");
   h_ratio__7->SetLineColor(ci);
   h_ratio__7->GetXaxis()->SetTitle("jet_csv");
   h_ratio__7->GetXaxis()->SetLabelFont(42);
   h_ratio__7->GetXaxis()->SetLabelSize(0.1);
   h_ratio__7->GetXaxis()->SetTitleSize(0.1);
   h_ratio__7->GetXaxis()->SetTitleFont(42);
   h_ratio__7->GetYaxis()->SetTitle("ratio");
   h_ratio__7->GetYaxis()->SetNdivisions(4);
   h_ratio__7->GetYaxis()->SetLabelFont(42);
   h_ratio__7->GetYaxis()->SetLabelSize(0.07);
   h_ratio__7->GetYaxis()->SetTitleSize(0.07);
   h_ratio__7->GetYaxis()->SetTitleOffset(0.5);
   h_ratio__7->GetYaxis()->SetTitleFont(42);
   h_ratio__7->GetZaxis()->SetLabelFont(42);
   h_ratio__7->GetZaxis()->SetLabelSize(0.035);
   h_ratio__7->GetZaxis()->SetTitleSize(0.035);
   h_ratio__7->GetZaxis()->SetTitleFont(42);
   h_ratio__7->Draw("");
   
   TH1F *h2__8 = new TH1F("h2__8","jet_csv__B__Standard__1tag",20,0,1);
   h2__8->SetBinContent(0,1.130137);
   h2__8->SetBinContent(1,1.469225);
   h2__8->SetBinContent(2,1.076195);
   h2__8->SetBinContent(3,0.9432464);
   h2__8->SetBinContent(4,1.019093);
   h2__8->SetBinContent(5,0.9964311);
   h2__8->SetBinContent(6,1.004821);
   h2__8->SetBinContent(7,0.946187);
   h2__8->SetBinContent(8,0.9462581);
   h2__8->SetBinContent(9,0.9881334);
   h2__8->SetBinContent(10,1.004526);
   h2__8->SetBinContent(11,0.9953208);
   h2__8->SetBinContent(12,0.9596997);
   h2__8->SetBinContent(13,1.01016);
   h2__8->SetBinContent(14,1.012587);
   h2__8->SetBinContent(15,0.9150771);
   h2__8->SetBinContent(16,1.00225);
   h2__8->SetBinContent(17,0.994069);
   h2__8->SetBinContent(18,0.9810526);
   h2__8->SetBinContent(19,1.004179);
   h2__8->SetBinContent(20,1.015611);
   h2__8->SetBinError(0,0.6798737);
   h2__8->SetBinError(1,0.237352);
   h2__8->SetBinError(2,0.01528734);
   h2__8->SetBinError(3,0.01473578);
   h2__8->SetBinError(4,0.01544254);
   h2__8->SetBinError(5,0.02075918);
   h2__8->SetBinError(6,0.02294567);
   h2__8->SetBinError(7,0.02338882);
   h2__8->SetBinError(8,0.02632389);
   h2__8->SetBinError(9,0.02880878);
   h2__8->SetBinError(10,0.02997684);
   h2__8->SetBinError(11,0.032658);
   h2__8->SetBinError(12,0.03534947);
   h2__8->SetBinError(13,0.03626217);
   h2__8->SetBinError(14,0.03798324);
   h2__8->SetBinError(15,0.03651686);
   h2__8->SetBinError(16,0.03987058);
   h2__8->SetBinError(17,0.03964119);
   h2__8->SetBinError(18,0.03919296);
   h2__8->SetBinError(19,0.04098698);
   h2__8->SetBinError(20,0.03523914);
   h2__8->SetEntries(5487.59);
   h2__8->SetLineColor(4);
   h2__8->GetXaxis()->SetRange(1,100);
   h2__8->GetXaxis()->SetLabelFont(42);
   h2__8->GetXaxis()->SetLabelSize(0.035);
   h2__8->GetXaxis()->SetTitleSize(0.035);
   h2__8->GetXaxis()->SetTitleFont(42);
   h2__8->GetYaxis()->SetLabelFont(42);
   h2__8->GetYaxis()->SetLabelSize(0.035);
   h2__8->GetYaxis()->SetTitleSize(0.035);
   h2__8->GetYaxis()->SetTitleFont(42);
   h2__8->GetZaxis()->SetLabelFont(42);
   h2__8->GetZaxis()->SetLabelSize(0.035);
   h2__8->GetZaxis()->SetTitleSize(0.035);
   h2__8->GetZaxis()->SetTitleFont(42);
   h2__8->Draw("same");
   
   pt = new TPaveText(0.4868593,0.94,0.5131407,0.995,"blNDC");
   pt->SetName("title");
   pt->SetBorderSize(0);
   pt->SetFillColor(0);
   pt->SetFillStyle(0);
   pt->SetTextFont(42);
   AText = pt->AddText(" ");
   pt->Draw();
   pad2->Modified();
   Fig_->cd();
   Fig_->Modified();
   Fig_->cd();
   Fig_->SetSelected(Fig_);
}
