#include "Node.h"

Node::Node(const string& FreshDat)
{
	this->mData = FreshDat;
	this->mpLeft = nullptr;
	this->mpRight = nullptr;
}
Node::Node(const Node& copyNode)
{

}
Node::~Node()
{

}
void Node::setData(string FreshDat)
{
	this->mData = FreshDat;
}
void Node::SetLeft(Node* FreshLnode)
{
	this->mpLeft = FreshLnode;
}
void Node::SetRight(Node* FreshRnode)
{
	this->mpRight = FreshRnode;
}
string Node::GetData() const
{
	return this->mData;
}
Node*& Node::GetLeft()
{
	return this->mpLeft;
}
Node*& Node::GetRight()
{
	return this->mpRight;
}
void Node::printData()
{
	cout << this->mData << " Data: ";
}