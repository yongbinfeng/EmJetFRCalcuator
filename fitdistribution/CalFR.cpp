#include "CalFR.h"

double Pow2(double x) { return TMath::Power(x, 2.0); }

double Limit0to1(double x){
  if( x>=0 && x<=1 ) return x;
  else if(x<0) return 0.0;
  else         return 1.0;
}

void FrHistoCal(TH1F* hfrac1, TH1F* hfrac2, TH1F* hfr1, TH1F* hfr2, TH1F* hfb, TH1F* hfl){

  for(int i=1; i<= hfr1->GetNbinsX(); i++){

    int ibinfrac = hfrac1->FindBin(hfr1->GetBinCenter(i));

    double fb1 = hfrac1->GetBinContent(ibinfrac);           double err_fb1 = hfrac1->GetBinError(ibinfrac);
    double fl1 = 1.0 - fb1;
    double fb2 = hfrac2->GetBinContent(ibinfrac);           double err_fb2 = hfrac2->GetBinError(ibinfrac);
    double fl2 = 1.0 - fb2;
    double FR1 = hfr1->GetBinContent(i);                    double err_FR1 = hfr1->GetBinError(i);
    double FR2 = hfr2->GetBinContent(i);                    double err_FR2 = hfr2->GetBinError(i);

    double norm = 1.0/(fb1- fb2);

    //double FR_b = Limit0to1( norm*( fl2*FR1 - fl1*FR2) );
    //double FR_l = Limit0to1( norm*(-fb2*FR1 + fb1*FR2) );
    double FR_b = norm*( fl2*FR1 - fl1*FR2);
    double FR_l = norm*(-fb2*FR1 + fb1*FR2);

    double coef_b_fb1 = -fl2*(FR2-FR1)*TMath::Power(norm, 2.0);
    double coef_b_fb2 =  fl1*(FR2-FR1)*TMath::Power(norm, 2.0);
    double coef_b_FR1 = -fl2*norm;
    double coef_b_FR2 =  fl1*norm;

    double coef_l_fb1 = -fb2*(FR2-FR1)*TMath::Power(norm, 2.0);
    double coef_l_fb2 =  fb1*(FR2-FR1)*TMath::Power(norm, 2.0);
    double coef_l_FR1 = -fb2*norm;
    double coef_l_FR2 =  fb1*norm;

    //double err_FR_b  = ( norm*( fl2*FR1 - fl1*FR2)>=0.0 ?  TMath::Sqrt(Pow2(coef_b_fb1*err_fb1) + Pow2(coef_b_fb2*err_fb2) + Pow2(coef_b_FR1*err_FR1) + Pow2(coef_b_FR2*err_FR2)) : 0.0 );
    //double err_FR_l  = ( norm*(-fb2*FR1 + fb1*FR2)>=0.0 ?  TMath::Sqrt(Pow2(coef_l_fb1*err_fb1) + Pow2(coef_l_fb2*err_fb2) + Pow2(coef_l_FR1*err_FR1) + Pow2(coef_l_FR2*err_FR2)) : 0.0 );
    double err_FR_b  = ( 1.0 ?  TMath::Sqrt(Pow2(coef_b_fb1*err_fb1) + Pow2(coef_b_fb2*err_fb2) + Pow2(coef_b_FR1*err_FR1) + Pow2(coef_b_FR2*err_FR2)) : 0.0 );
    double err_FR_l  = ( 1.0 ?  TMath::Sqrt(Pow2(coef_l_fb1*err_fb1) + Pow2(coef_l_fb2*err_fb2) + Pow2(coef_l_FR1*err_FR1) + Pow2(coef_l_FR2*err_FR2)) : 0.0 );

    hfb->SetBinContent( i, FR_b);   hfb->SetBinError( i, err_FR_b);
    hfl->SetBinContent( i, FR_l);   hfl->SetBinError( i, err_FR_l);

    std::cout << " Bin Number " << i << " calc B " << std::setw(10) << hfb->GetBinContent(i) << " err " << setw(10) << hfb->GetBinError(i) << std::endl;
    std::cout << " Bin Number " << i << " calc L " << std::setw(10) << hfl->GetBinContent(i) << " err " << setw(10) << hfl->GetBinError(i) << std::endl;
  }

}
