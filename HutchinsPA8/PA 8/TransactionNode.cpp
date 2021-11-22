#include "TransactionNode.h"

TransactionNode::TransactionNode(const TransactionNode& copytemp)
{

}
TransactionNode::~TransactionNode()
{

}
void TransactionNode::setUnits(int FreshUnits)
{
	this->mUnits = FreshUnits;
}
int TransactionNode::getUnits() const
{
	return this->mUnits;
}
void TransactionNode::printData()
{
	cout << this->mUnits << endl;
}