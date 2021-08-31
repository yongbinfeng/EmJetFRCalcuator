#!/bin/bash

python getdistribution/PrepareDistributions.py -M /data/users/fengyb/80Xresult/histos_GJet-3DSig_20_Med_25_CSV_SF/histo_GJetHT_merged.root -D /data/users/fengyb/80Xresult/histos_GJet-3DSig_20_Med_25_CSV_SF/histo_SinglePhoton_GH.root -Q /data/users/fengyb/ClosureTest/TestClosure/Result/CSVReweight/histo-QCDMC_Cut4MET_result_610_v0.root -O result/root/test_distributions_Cut4_CSV_SF.root

./fitdistribution/main -i result/root/test_distributions_Cut4_CSV_SF.root -o result/root/fit_test_Cut4_CSV_SF.root

./fitdata/main -f /data/users/fengyb/ClosureTest/TestClosure/Result/CSVReweight/histo-JetHT_Cut4MET_result_610_v0.root -t /data/users/fengyb/ClosureTest/TestClosure/Result/CSVReweight/histo-QCDMC_Cut4MET_result_610_v0.root -o result/root/bfraction_Data_result_Cut4_CSV_SF.root -s 1

./fitdata/main -f /data/users/fengyb/ClosureTest/TestClosure/Result/CSVReweight/histo-QCDMC_Cut4MET_result_610_v0.root -t /data/users/fengyb/ClosureTest/TestClosure/Result/CSVReweight/histo-QCDMC_Cut4MET_result_610_v0.root -o result/root/bfraction_MC_result_Cut4_CSV_SF.root -s 0

hadd -f result/root/result_Data_Cut4_CSV_SF.root result/root/test_distributions_Cut4_CSV_SF.root result/root/fit_test_Cut4_CSV_SF.root result/root/bfraction_Data_result_Cut4_CSV_SF.root

hadd -f result/root/result_MC_Cut4_CSV_SF.root result/root/test_distributions_Cut4_CSV_SF.root result/root/fit_test_Cut4_CSV_SF.root result/root/bfraction_MC_result_Cut4_CSV_SF.root

hadd -f result/root/result_Cut4_CSV_SF.root result/root/test_distributions_Cut4_CSV_SF.root result/root/fit_test_Cut4_CSV_SF.root result/root/bfraction_Data_result_Cut4_CSV_SF.root result/root/bfraction_MC_result_Cut4_CSV_SF.root
