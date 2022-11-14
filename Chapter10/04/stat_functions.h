#pragma once
/*
David Garza

12/23/2021

1003
Write a program that reads the data from raw_temps.txt created in ex-
ercise 2 into a vector and then calculates the mean and median tempera-
tures in your data set. Call this program temp_stats.cpp.

This file declares the mean and median functions needed to complete the program

*/
#include "../../dcg.h"
#include "data.h"

double mean(vector<Reading>& r);
double median(vector<Reading>& r);
void print_sats(vector<Reading>& r);