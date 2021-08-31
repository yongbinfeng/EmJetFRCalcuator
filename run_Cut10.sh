#!/bin/bash

python getdistribution/PrepareDistributions.py -M /data/users/fengyb/80Xresult/histos_GJet-3DSig_30_Med_15_Alpha5/histo_GJetHT_merged.root -D /data/users/fengyb/80Xresult/histos_GJet-3DSig_30_Med_15_Alpha5/histo_SinglePhoton_GH.root -Q /data/users/fengyb/ClosureTest/TestClosure/Result/histo-QCDMC_Cut10_result_221_v0.root -O result/root/test_distributions_Cut10_v2.root

./fitdistribution/main -i result/root/test_distributions_Cut10_v2.root -o result/root/fit_test_Cut10_v2.root

./fitdata/main -f /data/users/fengyb/ClosureTest/TestClosure/Result/histo-QCDMC_Cut10_result_221_v0.root -t /data/users/fengyb/ClosureTest/TestClosure/Result/histo-QCDMC_Cut10_result_221_v0.root -o result/root/bfraction_MC_result_Cut10_v2.root -s 0

./fitdata/main -f /data/users/fengyb/ClosureTest/TestClosure/Result/histo-JetHT_Cut10_result_221_v0.root -t /data/users/fengyb/ClosureTest/TestClosure/Result/histo-QCDMC_Cut10_result_221_v0.root -o result/root/bfraction_Data_result_Cut10_v2.root -s 1

hadd -f result/root/result_Data_Cut10_v2.root result/root/test_distributions_Cut10_v2.root result/root/fit_test_Cut10_v2.root result/root/bfraction_Data_result_Cut10_v2.root

hadd -f result/root/result_MC_Cut10_v2.root result/root/test_distributions_Cut10_v2.root result/root/fit_test_Cut10_v2.root result/root/bfraction_MC_result_Cut10_v2.root

hadd -f result/root/result_Cut10_v2.root result/root/test_distributions_Cut10_v2.root result/root/fit_test_Cut10_v2.root result/root/bfraction_Data_result_Cut10_v2.root result/root/bfraction_MC_result_Cut10_v2.root
