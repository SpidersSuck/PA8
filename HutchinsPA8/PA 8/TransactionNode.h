#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Node.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

class TransactionNode : public Node
{
public:
	TransactionNode(const string& FreshDat = "", const int& FreshUnits = 0) : Node(FreshDat), mUnits(FreshUnits) {}
	TransactionNode(const TransactionNode& CpyTranNo);
	~TransactionNode();
	void setUnits(int FreshUnits);
	int getUnits() const;
	void printData();
private:
	int mUnits;
};