import sys, os
sys.path.append('/data/users/fengyb/CMSPLOTS/Plotter')
from BasicFunctions import *
from myFunction import PrepareHisto
from collections import OrderedDict
from ROOT import TFile


def GetCsvDistributions(gjetmcinput, gjetdatainput, outdir):
    
    NHistoInfos = OrderedDict()
    NHistoInfos["Data"] = [("1", "jet_csvReweight__NTRACK__Data",        "jet_csvReweight__NTRACK")]
    NHistoInfos["MC"]   = [
                           ("2", "jet_csvReweight__NTRACK__MC",          "jet_csvReweight__NTRACK"),
                           ("3", "jet_csvReweight__NTRACK__MCLightJet",  "jet_csvReweight__NTRACK__1+jet_csvReweight__NTRACK__21"),
                           ("4", "jet_csvReweight__NTRACK__MCBJet",      "jet_csvReweight__NTRACK__5+jet_csvReweight__NTRACK__19"),
                          ]
    
    myhisto = {}
    binsize = {
                '': 5,
                '__TypeV': 5,
                '__TypeVI': 5, 
              }
    
    #BinTrack = [0, 4, 8, 12, 16, 20, 25]
    #BinTrack = [0, 5, 10, 15, 20, 25]
    BinTrack = [1, 6, 11, 16, 21, 25]
    
    print "Read MC   input from %s"%gjetmcinput
    print "Read Data input from %s"%gjetdatainput
    
    myfiles = OrderedDict()
    myfiles["MC"]   = TFile("%s"%gjetmcinput)
    myfiles["Data"] = TFile("%s"%gjetdatainput)
    
    # loop over different files
    for ifile in myfiles:
        print "\n--------------------------------------------------------------"
        print "------------------------  %s ----------------------------"%ifile
        print "--------------------------------------------------------------\n"
        # loop over different types
        for itype in binsize:
            # loop over all required output histograms
            for ihistoinfo in NHistoInfos[ifile]:
                # loop over track ranges
                for itrackbin in xrange(len(BinTrack)):
                    if itrackbin < len(BinTrack)-1:
                       # with track bins
                       mergelist, houtname = PrepareListandOutName( ihistoinfo[2].split("+"), ihistoinfo[1], itype, BinTrack[itrackbin], BinTrack[itrackbin+1]-1)
                    else:
                       # without track bins
                       mergelist, houtname = PrepareListandOutName( ihistoinfo[2].split("+"), ihistoinfo[1], itype )
                    print "merge %s into %s"%(mergelist, houtname)
                    htemp = PrepareHisto(myfiles[ifile], mergelist, False)
                    
                    ## customize the histograms
                    customizeHisto(htemp, binsize[itype], int(ihistoinfo[0]), outdir, houtname)


if __name__ == "__main__":
   print "running %s"%os.path.basename(sys.argv[0])
   options = parseLYAnaInputArgs()

   myfile_save = TFile(options.output, 'recreate')
   mydir = myfile_save.mkdir("Dcsv")
  
   GetCsvDistributions( options.gjetmcinput, options.gjetdatainput, mydir )   
   
   myfile_save.Write()
   myfile_save.Close()
