#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

class Node
{
public:
	Node(const string& FreshDat = "");
	Node(const Node& copyNode);
	virtual ~Node();
	string GetData() const;
	Node*& GetLeft();
	Node*& GetRight();
	void setData(string FreshDat);
	void SetLeft(Node* FreshLnode);
	void SetRight(Node* FreshRnode);
	virtual void printData() = 0;
protected:
	string mData;
	Node* mpLeft;
	Node* mpRight;
};