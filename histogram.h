#pragma once
#include <iostream>
#include <vector>
using namespace std;

void find_minmax(const vector<double>& numbers, double& min, double& max);
vector<double> input_numbers(size_t count);
vector <size_t> make_histogram(const vector<double>& numbers, size_t bin_count, double min, double max);
void show_histogram_text(vector <size_t> bins);
vector <string> input_colors(size_t bin_count);





