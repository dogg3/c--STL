// ConsoleApplication4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "pch.h"
#include "stats.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <list>


using namespace std;


//All these is just examples from lecture 5



vector<string> split_words(const string &s) {
	typedef string::const_iterator iter;
	vector<string> v;
	iter start = find_if_not(s.cbegin(), s.cend(), space);


	while (start != s.cend()) {
		iter end = find_if(start, s.cend(), space);
		v.push_back(string(start, end));
		start = find_if_not(end, s.cend(),space);

	}

	return v;

}


void remove_elements(list<double> &li) {

	li.erase(remove(li.begin(),li.end(),0), li.end());


}


//Moving data between containers
void append_data(list<double> &l, list<double> &q) {

	copy(l.cbegin(), l.cend(), back_inserter(q));

}


//splitting a container
//task: move all small elements from list x to another list y

bool small(double d) {
	return d < 10;
}

void split_list(list<double> &li, list<double> &qi) {
	copy_if(li.begin(), li.end(), back_inserter(qi), small);

	li.erase(remove_if(li.begin(),li.end(), small), li.end());

}

void write_list(ostream &out, const list<double> &li) {

	for (list<double>::const_iterator iter = li.begin(); iter != li.cend(); ++iter) {
		cout << *iter;
		cout << "\n";
	}

}

bool not_small(double d) {
	return ! small(d);
}

void split_list_parition(list<double> &li, list<double> &q) {
	list<double>::iterator p = partition(li.begin(),li.end(),not_small);

	copy(p, li.end(), back_inserter(q));
	li.erase(p, li.end());

}


//Splitting a container in one pass


int main()
{




	string s = "hej jag, ejjhej,  , , , hej jah, hjs";

	vector<string> v = split_commas(s);
	

	for (vector<string>::const_iterator iter = v.cbegin(); iter != v.cend(); ++iter) {
		cout << "\n";
		cout << *iter;

	}








	/*list<int> li = {-20, -23, -77,21,2,3,4};
	double x = count_negativ(li);
		
	list<double> liq = { -20, 0,20, -7, 0, 1,2,3,4 };
	int y = number_of_zeros(liq);

	cout << "number of negativ numbers in the list is " << y;

*/



	////string s = "hej jag heter douglas och jag knullar dig";


	////vector<string> v = split_words(s);



	////for (vector<string>::const_iterator iter = v.cbegin(); iter != v.cend(); ++iter) {
	////		
	////	cout << *iter;
	////	cout << "\n";
	////}

	//
	//list<double> li = {2,3,4,5,0,32,3};
	//list<double> another_list = {2000,2000,2000};

	//split_list_parition(li, another_list);

	//

	////cout << "The lists before the split of small numbers to the other: /n first- List ";
	////write_list(cout, li);

	////cout << "second list";
	////write_list(cout, another_list);

	////split_list(li, another_list);

	////cout << "\n";
	////cout << "\n";
	////cout << "\n";
	////cout << "\n";
	////cout << "\n";

	//cout << "The lists agter the split of small numbers to the other: \n first- List \n ";
	//write_list(cout, li);

	//cout << "\n";
	//cout << "second list \n";
	//write_list(cout, another_list);	

	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
