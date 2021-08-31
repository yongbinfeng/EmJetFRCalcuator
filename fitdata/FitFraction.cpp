#include "FitFraction.h"

void fithisto(TH1F* data, TH1F* mc1, TH1F *mc2, double &frac, double &frac_err, string histoname, bool isData)
{
  AlphaFitter fittest(data, mc1, mc2);
  if( !isData ) fittest.SetSmear(true);
  fittest.DoFit();
  frac = fittest.GetFraction();
  frac_err = fittest.GetFractionError();  
  std::cout << "fraction is "<< frac << " error is "<< frac_err << std::endl;
  //fittest.SaveResult();
  if( !isData )
     fittest.MakePlot(frac, true, histoname+ "__MC");
  else
     fittest.MakePlot(frac, true, histoname+"__Data");
}
