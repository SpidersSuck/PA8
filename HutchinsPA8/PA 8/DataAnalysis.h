#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BST.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;
using std::ifstream;

class DataAnalysis
{
public:
	void runAnalysis();
private:
	BST mTreeSold;
	BST mTreePurchased;
	ifstream mCsvStream;
	void openFile();
	void splitLine(int& FreshUnits, string& FreshType, string& FreshField);
	void readLines(); 
	void compareInsert(int& newUnts, string& FreshType, string& FreshField);
	void printTrends();
};