#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Node.h"
#include "TransactionNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::ostream;
using std::istream;

class BST
{
public:
	BST();
	BST(const BST& copyBST);
	~BST();
	void SetRt(Node* FreshRoot); //set Root
	Node* GetRt() const; // get Root
	void insert(string& FreshDat, int& FreshUnits);
	void inOrderTraversal();
	TransactionNode& findSmallest();
	TransactionNode& findLargest();
private:
	Node* mpRoot;
	void destroyTree(Node*& fork);
	void insert(Node*& fork, string& FreshDat, int& FreshUnits);
	void inOrderTraversal(Node* fork); 
};