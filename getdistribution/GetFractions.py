import sys, os
sys.path.append('/data/users/fengyb/CMSPLOTS/Plotter')
from myFunction import GetHisto
from BasicFunctions import customizeHisto, parseLYAnaInputArgs
from collections import OrderedDict
from ROOT    import TFile
from array   import *

def GetFractions(gjetmcinput, gjetdatainput, qcdmcinput, outdir):

    NHistoInfos = OrderedDict()
    NHistoInfos["GJetMC"] = [
         ("2", "fraction_GJetMC_BJet",               ["jet_nTrackPostCut__5+jet_nTrackPostCut__19",                     "jet_nTrackPostCut"          ]),
         ("2", "fraction_GJetMC_BJet_TypeV",       ["jet_nTrackPostCut__5__TypeV+jet_nTrackPostCut__19__TypeV",   "jet_nTrackPostCut__TypeV" ]),
         ("2", "fraction_GJetMC_BJet_TypeVI",      ["jet_nTrackPostCut__5__TypeVI+jet_nTrackPostCut__19__TypeVI", "jet_nTrackPostCut__TypeVI"]),      
                             ]
    NHistoInfos["QCDMC"] =  [
         #("3", "fraction_QCDMC_BJet",                ["jet_nTrackPostCut__5+jet_nTrackPostCut__19",                      "jet_nTrackPostCut"         ]),
         ("3", "fraction_QCDMC_BJet",                ["jet_nTrackPostCut__B",                                             "jet_nTrackPostCut"        ]),
                             ]

    #binwidth_nTrack = array('d', [0, 4, 8, 12, 16, 20, 24, 80])
    binwidth_nTrack = array('d', [1, 6, 11, 16, 21, 24, 80])
    #binwidth_nTrack = array('d', [1, 6, 11, 16, 21, 80])

    
    myhistos_nTrack = []
    
    print "Read GJet MC   input from %s"%gjetmcinput
    print "Read QCD  MC   input from %s"%qcdmcinput
    
    myfiles = OrderedDict()
    myfiles["GJetMC"]    = TFile("%s"%gjetmcinput)
    myfiles["QCDMC"]     = TFile("%s"%qcdmcinput)
    
    # loop over all files
    for ifile in myfiles:
        # loop over all needed histograms
        for ihistoinfo in NHistoInfos[ifile]:
            # nTrackPostCut
            print "\n **** making %s **** "%ihistoinfo[1]
            htemp = GetHisto(myfiles[ifile], ihistoinfo[2], binwidth_nTrack, "%s_nTrack"%ihistoinfo[1])
            customizeHisto(htemp, 1, int(ihistoinfo[0]), outdir, ihistoinfo[1])

if __name__ == "__main__":
   print "running %s"%os.path.basename(sys.argv[0])
   options = parseLYAnaInputArgs()

   myfile_save = TFile(options.output, 'recreate')
   mydir = myfile_save.mkdir("Dfractions")

   GetFractions( options.gjetmcinput, options.gjetdatainput, options.qcdmcinput, mydir )

   myfile_save.Write()
   myfile_save.Close()
