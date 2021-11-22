#include "DataAnalysis.h"

void DataAnalysis::runAnalysis()
{
	openFile();
	readLines();
	printTrends();
}

void DataAnalysis::openFile()
{
	mCsvStream.open("data.csv");
}

void DataAnalysis::splitLine(int& FreshUnits, string& FreshType, string& FreshField)
{
	char line[150] = "";

	mCsvStream.getline(line, 150, ',');
	FreshUnits = atoi(line);
	mCsvStream.getline(line, 150, ',');
	FreshType = line;
	mCsvStream.getline(line, 150);
	FreshField = line;
}

void DataAnalysis::readLines()
{
	int Units = 0;
	string Type = "";
	string Field = "";
	char L[100] = "";

	mCsvStream.getline(L, 150);

	while (!mCsvStream.eof())
	{
		splitLine(Units, Type, Field);
		compareInsert(Units, Type, Field);
	}
	mCsvStream.close();
	cout << "::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
	cout << ":::                 Sold                     :::" << endl;
	cout << "::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
	mTreeSold.inOrderTraversal();

	cout << endl;
	cout << "::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
	cout << ":::              Purchased                   :::" << endl;
	cout << "::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
	mTreePurchased.inOrderTraversal();
}

void DataAnalysis::compareInsert(int& FreshUnits, string& FreshType, string& FreshField)
{
	if (FreshField == "Purchased")
	{
		mTreePurchased.insert(FreshType, FreshUnits);
	}
	else if (FreshField == "Sold")
	{
		mTreeSold.insert(FreshType, FreshUnits);
	}
}

void DataAnalysis::printTrends()
{
	TransactionNode temp;

	cout << endl;
	cout << "Least Units Sold: ";
	temp = mTreeSold.findSmallest();
	temp.Node::printData();
	temp.printData();
	cout << "------------------------------------------------" << endl;
	cout << "Most Units Sold: ";
	temp = mTreeSold.findLargest();
	temp.Node::printData();
	temp.printData();
	cout << "------------------------------------------------" << endl;
	cout << "Least Units Purchased: ";
	temp = mTreePurchased.findSmallest();
	temp.Node::printData();
	temp.printData();
	cout << "------------------------------------------------" << endl;
	cout << "Most Units Purchased: ";
	temp = mTreePurchased.findLargest();
	temp.Node::printData();
	temp.printData();
	cout << "------------------------------------------------" << endl;
}