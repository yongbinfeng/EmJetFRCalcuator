#ifndef FRCAL_H
#define FRCAL_H

#include <iostream>
#include <string>
#include <TROOT.h>
#include <TFile.h>
#include <TH1F.h>
#include <TMath.h>

void FrHistoCal(TH1F* hfrac1, TH1F* hfrac2, TH1F* hfr1, TH1F* hfr2, TH1F* hfb, TH1F* hfl);

using namespace std;

#endif
