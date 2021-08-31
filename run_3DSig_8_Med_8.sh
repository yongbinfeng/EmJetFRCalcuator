#!/bin/bash

python getdistribution/PrepareDistributions.py -M /data/users/fengyb/80Xresult/histos_GJet-3DSig_8_Med_8/histo_GJetHT_merged.root -D /data/users/fengyb/80Xresult/histos_GJet-3DSig_8_Med_8/histo_SinglePhoton_GH.root -Q /data/users/fengyb/ClosureTest/TestClosure/Result/histo-QCDMC_3DSig_8_Med_8_result_1118_remove3_pt100.root -O result/root/test_distributions_3DSig_8_Med_8.root

./fitdistribution/main -i result/root/test_distributions_3DSig_8_Med_8.root -o result/root/fit_test_3DSig_8_Med_8.root

#./fitdata/main -f /data/users/fengyb/ClosureTest/TestClosure/Result/histo-JetHT_3DSig_8_Med_8_result_1114_0.root -t /data/users/fengyb/ClosureTest/TestClosure/Result/histo-QCDMC_3DSig_8_Med_8_result_01114.root -o result/root/bfraction_Data_result_3DSig_8_Med_8.root -s 1

./fitdata/main -f /data/users/fengyb/ClosureTest/TestClosure/Result/histo-QCDMC_3DSig_8_Med_8_result_1121_fill.root -t /data/users/fengyb/ClosureTest/TestClosure/Result/histo-QCDMC_3DSig_8_Med_8_result_1121_fill.root -o result/root/bfraction_MC_result_3DSig_8_Med_8.root -s 0

#hadd result/root/result_Data_3DSig_8_Med_8_haha.root result/root/test_distributions_3DSig_8_Med_8_haha.root result/root/fit_test_3DSig_8_Med_8_haha.root result/root/bfraction_Data_result_3DSig_8_Med_8.root

hadd result/root/result_MC_3DSig_8_Med_8.root result/root/test_distributions_3DSig_8_Med_8.root result/root/fit_test_3DSig_8_Med_8.root result/root/bfraction_MC_result_3DSig_8_Med_8.root
