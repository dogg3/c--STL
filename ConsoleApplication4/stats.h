#pragma once
#include <string>
#include <list>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool neg(int n);

bool not_neg(int n);

bool is_comma(char c);

bool space(char c);

double count_negativ(std::list<int> &l);

int number_of_zeros(std::list<double> &l);

std::vector<std::string> split_commas(std::string &s);

int empty_strings(std::vector<std::string> &v);