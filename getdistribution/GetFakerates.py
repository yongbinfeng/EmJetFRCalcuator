import sys, os
sys.path.append('/data/users/fengyb/CMSPLOTS/Plotter')
from myFunction import GetHisto
from BasicFunctions import customizeHisto, parseLYAnaInputArgs
from collections import OrderedDict
from ROOT    import TFile
from array   import *

def GetFakerates(gjetmcinput, gjetdatainput, qcdmcinput, outdir):

    NHistoInfos = OrderedDict()
    NHistoInfos["GJetData"] = [
         # color  label                            numerator                             denominator
         ("1", "fakerate_GJetData",            ["jet_nTrackPostCut__JTAFM",             "jet_nTrackPostCut"          ]),
         ("1", "fakerate_GJetData_TypeV",    ["jet_nTrackPostCut__JTAlpha__TypeV",  "jet_nTrackPostCut__TypeV" ]),
         ("1", "fakerate_GJetData_TypeVI",   ["jet_nTrackPostCut__JTAlpha__TypeVI", "jet_nTrackPostCut__TypeVI"]),
                              ]
    NHistoInfos["GJetMC"] = [
         ("2", "fakerate_GJetMC",              ["jet_nTrackPostCut__JTAFM",             "jet_nTrackPostCut"          ]),
         ("2", "fakerate_GJetMC_TypeV",      ["jet_nTrackPostCut__JTAlpha__TypeV",  "jet_nTrackPostCut__TypeV" ]),
         ("2", "fakerate_GJetMC_TypeVI",     ["jet_nTrackPostCut__JTAlpha__TypeVI", "jet_nTrackPostCut__TypeVI"]),          
         ("2", "fakerate_GJetMC_BJet",         ["jet_nTrackPostCut__5__JTAFM+jet_nTrackPostCut__19__JTAFM", "jet_nTrackPostCut__5+jet_nTrackPostCut__19"]),
         ("2", "fakerate_GJetMC_LightJet",     ["jet_nTrackPostCut__1__JTAFM+jet_nTrackPostCut__21__JTAFM", "jet_nTrackPostCut__1+jet_nTrackPostCut__21"]),
                             ]
    NHistoInfos["QCDMC"] =  [
         #("3", "fakerate_QCDMC",              ["jet_nTrackPostCut__JTAFM",             "jet_nTrackPostCut"          ]),
         #("3", "fakerate_QCDMC_BJet",         ["jet_nTrackPostCut__5__JTAFM+jet_nTrackPostCut__19__JTAFM", "jet_nTrackPostCut__5+jet_nTrackPostCut__19"]),
         #("3", "fakerate_QCDMC_LightJet",     ["jet_nTrackPostCut__1__JTAFM+jet_nTrackPostCut__21__JTAFM", "jet_nTrackPostCut__1+jet_nTrackPostCut__21"]),
         ("3", "fakerate_QCDMC",               ["jet_nTrackPostCut__Emerging",          "jet_nTrackPostCut"]),
         ("3", "fakerate_QCDMC_BJet",          ["jet_nTrackPostCut__B__Emerging",       "jet_nTrackPostCut__B"]),
         ("3", "fakerate_QCDMC_LightJet",      ["jet_nTrackPostCut__L__Emerging",       "jet_nTrackPostCut__L"]),
                             ]

    #binwidth_nTrack = array('d', [0, 5, 10, 15, 20, 24, 40, 80])
    binwidth_nTrack = array('d', [1, 6, 11, 16, 21, 24, 40, 80])
    #binwidth_nTrack = array('d', [1, 6, 11, 16, 21, 40, 80])
    #binwidth_nTrack = array('d', [1, 6, 11, 16, 21, 30, 80])
    
    myhistos_nTrack = []
    
    print "Read GJet MC   input from %s"%gjetmcinput
    print "Read GJet Data input from %s"%gjetdatainput
    print "Read QCD  MC   input from %s"%qcdmcinput
    
    myfiles = OrderedDict()
    myfiles["GJetMC"]    = TFile("%s"%gjetmcinput)
    myfiles["GJetData"]  = TFile("%s"%gjetdatainput)
    myfiles["QCDMC"]     = TFile("%s"%qcdmcinput)
    
    # loop over all files
    for ifile in myfiles:
        # loop over all needed histograms
        idx = 0
        for ihistoinfo in NHistoInfos[ifile]:
            # nTrackPostCut
            #if idx:
               print "\n **** making %s **** "%ihistoinfo[1]
               print ihistoinfo[2][0]
               #hnum = GetHisto(myfiles[ifile], [ihistoinfo[2][0]], binwidth_nTrack, "%s_nTrack"%(ihistoinfo[1].replace("fakerate", "pass")))
               #hden = GetHisto(myfiles[ifile], [ihistoinfo[2][1]], binwidth_nTrack, "%s_nTrack"%(ihistoinfo[1].replace("fakerate", "total")))
               #htemp = hnum.Clone("%s_nTrack"%ihistoinfo[1])
               #htemp.Divide(hnum, hden, 1.0, 1.0, "B")
               htemp = GetHisto(myfiles[ifile], ihistoinfo[2], binwidth_nTrack, "%s_nTrack"%ihistoinfo[1])
               #hnum.SetDirectory( outdir )
               #hden.SetDirectory( outdir )
               customizeHisto(htemp, 1, int(ihistoinfo[0]), outdir, ihistoinfo[1])
            #else:
            #   print "\n **** making %s **** (unmerged bin)"%ihistoinfo[1]
            #   htemp = GetHisto(myfiles[ifile], ihistoinfo[2])
            #   customizeHisto(htemp, 1, int(ihistoinfo[0]), outdir, ihistoinfo[1])
            #idx+=1

if __name__ == "__main__":
   print "running %s"%os.path.basename(sys.argv[0])
   options = parseLYAnaInputArgs()

   myfile_save = TFile(options.output, 'recreate')
   mydir = myfile_save.mkdir("Dfakerates")

   GetFakerates( options.gjetmcinput, options.gjetdatainput, options.qcdmcinput, mydir )

   myfile_save.Write()
   myfile_save.Close()
