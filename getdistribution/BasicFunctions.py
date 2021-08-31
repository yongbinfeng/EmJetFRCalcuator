from ROOT    import gROOT, gStyle, TH1F, TH1D, gPad, gDirectory
import optparse

def parseLYAnaInputArgs():
    parser = optparse.OptionParser(description='make jet-related plots')
    parser.add_option('-M', '--gjetmcinput',        default=None,       help="input MC control sample")
    parser.add_option('-D', '--gjetdatainput',      default=None,       help="input Data control sample")
    parser.add_option('-Q', '--qcdmcinput',         default=None,       help="input QCD MC sample")
    parser.add_option('-O', '--output',             default=None,       help="tag for output files")

    (options, args) = parser.parse_args()

    return options

def PrepareMergeList(hnames, tag, *args):
    mergelist = []
    for iname in hnames:
        if len(args) == 2:
           for itrack in xrange(int(args[0]), int(args[1])+1):
                mergelist.append( iname.replace("__NTRACK", "__nTrack%d"%itrack) + tag )
        else:
           mergelist.append(      iname.replace("__NTRACK", "")                  + tag )

    return mergelist

def PrepareOutName(hout, tag, *args):
    if len(args) == 2:
       return hout.replace( "__NTRACK", "__nTrack%dto%d"%(args[0], args[1])) + tag
    else:
       return hout.replace( "__NTRACK", "")                                  + tag

def PrepareListandOutName(hnames, hout, tag, *args):
    mergelist = PrepareMergeList(  hnames, tag,    *args )
    houtput =   PrepareOutName(    hout,   tag,    *args )
    return mergelist, houtput


def customizeHisto(histo, rbin, color, sdir, name):
    histo.Rebin(rbin)
    histo.SetLineColor(color)
    histo.SetLineWidth(3)
    histo.SetDirectory(sdir)
    histo.SetName(name)
    histo.SetTitle(name)
    return histo
