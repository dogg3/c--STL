#include "pch.h"
#include "stats.h"

bool neg(int n)
{
	return n<0;
}

bool not_neg(int n)
{
	return ! neg(n);
}

bool is_comma(char c)
{
	return c == ',';
}

double count_negativ(std::list<int>& l)
{

	
	std::list<int>::iterator iter = partition(l.begin(),l.end(), not_neg);
	double count = 0;
	while (iter != l.end()) {
		count++;
		iter++;
	}

	return count;

}

int number_of_zeros(std::list<double> &li)
{

	li.erase(std::remove(li.begin(),li.end(),1),   li.end());
	int count = 0;
	for (std::list<double>::const_iterator iter = li.begin();
		iter != li.end(); ++iter
		) {
		std::cout << *iter;
		if (*iter == 0) {
			count++;
		}

		
	}

	return count;



}

std::vector<std::string> split_commas(std::string &s)
{
	 std::vector<std::string> v;
	 std::string::const_iterator start = s.cbegin();
	 std::string::const_iterator comma = find_if(s.cbegin(), s.cend(), is_comma);
	 
	 while (start != s.cend()) {
		 comma = find_if(start, s.cend(), is_comma);
		 v.push_back(std::string(start,comma));
		 start = find_if_not(comma, s.cend(),is_comma);

	 }

	 return v;


}

int empty_strings(std::vector<std::string>& v)
{	
	int count = 0;
	typedef std::vector<std::string>::iterator iter;
	iter start = v.begin();
	iter end;
	while (start != v.end()) {

		end = find_if(start,v.end(), space);
		count++;
		start = find_if_not(end, v.end(),space);
	}

	return count;
}

bool space(char c) {

	return isspace(c);
}
