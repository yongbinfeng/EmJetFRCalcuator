#!/bin/bash

# Get csv/b-discriminator, truth b jet fraction and different fakerate distributions
python getdistribution/PrepareDistributions.py -M /data/users/fengyb/80Xresult/histos_GJet-3DSig_10_Med_5_v2/histo_GJetHT_merged.root -D /data/users/fengyb/80Xresult/histos_GJet-3DSig_10_Med_5_v2/histo_SinglePhoton_GH.root -Q /data/users/fengyb/ClosureTest/TestClosure/Result/0105/histo-QCDMC_Cut8_result_111_v0.root -O result/root/test_distributions_Cut8_v2.root

# calculate fakerate of b jets and light jets in gjet mc and data
./fitdistribution/main -i result/root/test_distributions_Cut8_v2.root -o result/root/fit_test_Cut8_v2.root

# get the b-jet fraction in qcd mc
./fitdata/main -f /data/users/fengyb/ClosureTest/TestClosure/Result/0105/histo-JetHT_Cut8_result_111_v0.root -t /data/users/fengyb/ClosureTest/TestClosure/Result/0105/histo-QCDMC_Cut8_result_111_v0.root -o result/root/bfraction_Data_result_Cut8_v2.root -s 1

# get the b-jet fraction in qcd data
./fitdata/main -f /data/users/fengyb/ClosureTest/TestClosure/Result/0105/histo-QCDMC_Cut8_result_111_v0.root -t /data/users/fengyb/ClosureTest/TestClosure/Result/0105/histo-QCDMC_Cut8_result_111_v0.root -o result/root/bfraction_MC_result_Cut8_v2.root -s 0

#merge histograms together 
#hadd -f result/root/result_Data_Cut8_v2.root result/root/test_distributions_Cut8_v2.root result/root/fit_test_Cut8_v2.root result/root/bfraction_Data_result_Cut8_v2.root

#hadd -f result/root/result_MC_Cut8_v2.root result/root/test_distributions_Cut8_v2.root result/root/fit_test_Cut8_v2.root result/root/bfraction_MC_result_Cut8_v2.root

hadd -f result/root/result_Cut8_v2.root result/root/test_distributions_Cut8_v2.root result/root/fit_test_Cut8_v2.root result/root/bfraction_Data_result_Cut8_v2.root result/root/bfraction_MC_result_Cut8_v2.root
