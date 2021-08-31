#!/bin/bash

python getdistribution/PrepareDistributions.py -M /data/users/fengyb/80Xresult/histos_GJet-3DSig_20_Med_5_v2/histo_GJetHT_merged.root -D /data/users/fengyb/80Xresult/histos_GJet-3DSig_20_Med_5_v2/histo_SinglePhoton_GH.root -Q /data/users/fengyb/ClosureTest/TestClosure/Result/0105/histo-QCDMC_Cut7_result_111_v0.root -O result/root/test_distributions_Cut7_v2.root

./fitdistribution/main -i result/root/test_distributions_Cut7_v2.root -o result/root/fit_test_Cut7_v2.root

./fitdata/main -f /data/users/fengyb/ClosureTest/TestClosure/Result/0105/histo-JetHT_Cut7_result_111_v0.root -t /data/users/fengyb/ClosureTest/TestClosure/Result/0105/histo-QCDMC_Cut7_result_111_v0.root -o result/root/bfraction_Data_result_Cut7_v2.root -s 1

./fitdata/main -f /data/users/fengyb/ClosureTest/TestClosure/Result/0105/histo-QCDMC_Cut7_result_111_v0.root -t /data/users/fengyb/ClosureTest/TestClosure/Result/0105/histo-QCDMC_Cut7_result_111_v0.root -o result/root/bfraction_MC_result_Cut7_v2.root -s 0

#hadd -f result/root/result_Data_Cut7_v2.root result/root/test_distributions_Cut7_v2.root result/root/fit_test_Cut7_v2.root result/root/bfraction_Data_result_Cut7_v2.root

#hadd -f result/root/result_MC_Cut7_v2.root result/root/test_distributions_Cut7_v2.root result/root/fit_test_Cut7_v2.root result/root/bfraction_MC_result_Cut7_v2.root

hadd -f result/root/result_Cut7_v2.root result/root/test_distributions_Cut7_v2.root result/root/fit_test_Cut7_v2.root result/root/bfraction_Data_result_Cut7_v2.root result/root/bfraction_MC_result_Cut7_v2.root
