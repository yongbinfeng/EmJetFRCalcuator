#ifndef FITFRACTION_H
#define FITFRACTION_H

#include "AlphaFitter.h"

#include <iostream>
#include <string>
#include <TROOT.h>
#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>

void fithisto(TH1F* data, TH1F* mc1, TH1F *mc2, double &frac, double &frac_err, string histoname, bool isData);
void GetDistribution(TFile *f1, string tpname, TH1F *hfrac, float binwidth[], int Nbins, bool isData);
void GetDistribution_Alpha3DSigM(TFile *f1, string tpname, TH1F *hfrac, float binwidth[], int Nbins, bool isData);

using namespace std;

#endif
