#ifndef AlphaFitter_h
#define AlphaFitter_h

#include <iostream>
#include <TROOT.h>
#include <TH1F.h>
#include <TMinuit.h>
#include <TMath.h>
#include <TFile.h>
#include <TCanvas.h>
#include <TLegend.h>
#include <THStack.h>
#include <TRandom.h>
#include <TRandom3.h>
#include <TStyle.h>
#include <TLatex.h>
#include <ctime>

#include "CMS_lumi.h"
#include "tdrstyle.h"

using namespace std;

class AlphaFitter {
	protected:
	       // Histograms for fitting
	       TH1F *data;
               TH1F *mc1;
	       TH1F *mc2;
               TH1F *result; 

	       double frac_mc1_;
	       double err_mc1_;
	       double chi2_;
         
         bool doSmear_;

	private:
	       double Fit_Function( const double *par);
               static void Get_ChiSquare( int &npar, double *gin, double &f,double *par, int iflag);
	       void SmearHisto();
	       TMinuit* Launch_Fit( double pinit);

	public:
	       //AlphaFitter();
	       AlphaFitter(TH1F *dat, TH1F *mc_1, TH1F *mc_2);
	       //~AlphaFitter();
	       void DoFit();
               double GetFraction(); 
	       double GetFractionError();
	       double GetChi2();
	       void SaveResult(string ofilename);
	       void MakePlot(double frac1, bool showratio, string histoname);
         void SetSmear(bool doSmear);
};

#endif
