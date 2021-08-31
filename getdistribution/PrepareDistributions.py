import sys, os
from BasicFunctions import parseLYAnaInputArgs
from GetFakerates import GetFakerates
from GetCsvDistributions import GetCsvDistributions
from GetAlpha3DSigMDistributions import GetAlpha3DSigMDistributions
from GetFractions import GetFractions
from ROOT import TFile

options = parseLYAnaInputArgs()

myfile_save = TFile(options.output, 'recreate')

print "\n-----------------------------------------------"
print "Preparing jet csv histograms for fitting..."
print "-----------------------------------------------\n"
mydir1 = myfile_save.mkdir("Dcsv")
GetCsvDistributions( options.gjetmcinput, options.gjetdatainput, mydir1 )

print "\n------------------------------------------------------"
print "Preparing fake rates histograms for future calculation"
print "------------------------------------------------------\n"
mydir3 = myfile_save.mkdir("Dfakerates")
GetFakerates( options.gjetmcinput, options.gjetdatainput, options.qcdmcinput, mydir3 )

print "\n-------------------------------------------------------------"
print "Preparing truth fractions histograms for future comparisons"
print "--------------------------------------------------------------\n"
mydir4 = myfile_save.mkdir("Dfractions")
GetFractions( options.gjetmcinput, options.gjetdatainput, options.qcdmcinput, mydir4 )

myfile_save.Write()
myfile_save.Close()
