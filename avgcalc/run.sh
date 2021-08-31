#!/bin/bash

echo "Cut1 Data"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut1_v2.root -o result/result_Cut1_Data.root  -s 1
echo "Cut2 Data"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut2_v2.root -o result/result_Cut2_Data.root  -s 1
echo "Cut3 Data"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut3_v2.root -o result/result_Cut3_Data.root  -s 1
echo "Cut4 Data"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut4_v2.root -o result/result_Cut4_Data.root  -s 1
echo "Cut5 Data"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut5_v2.root -o result/result_Cut5_Data.root  -s 1
echo "Cut6 Data"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut6_v2.root -o result/result_Cut6_Data.root  -s 1
echo "Cut7 Data"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut7_v2.root -o result/result_Cut7_Data.root  -s 1
echo "Cut8 Data"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut8_v2.root -o result/result_Cut8_Data.root  -s 1

echo "Cut1 MC"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut1_v2.root -o result/result_Cut1_MC.root  -s 0
echo "Cut2 MC"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut2_v2.root -o result/result_Cut2_MC.root  -s 0
echo "Cut3 MC"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut3_v2.root -o result/result_Cut3_MC.root  -s 0
echo "Cut4 MC"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut4_v2.root -o result/result_Cut4_MC.root  -s 0
echo "Cut5 MC"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut5_v2.root -o result/result_Cut5_MC.root  -s 0
echo "Cut6 MC"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut6_v2.root -o result/result_Cut6_MC.root  -s 0
echo "Cut7 MC"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut7_v2.root -o result/result_Cut7_MC.root  -s 0
echo "Cut8 MC"
./main -i /data/users/fengyb/FRCal3/result/root/result_Cut8_v2.root -o result/result_Cut8_MC.root  -s 0
