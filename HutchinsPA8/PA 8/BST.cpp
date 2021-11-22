#include "BST.h"

BST::BST()
{
	this->mpRoot = nullptr;
}
BST::BST(const BST& copyBST)
{

}
BST::~BST()
{
	destroyTree(this->mpRoot);
}
void BST::destroyTree(Node*& fork)
{
	if (fork != nullptr)
	{
		destroyTree(fork->GetLeft());
		destroyTree(fork->GetRight());
		delete fork;
	}
}
void BST::SetRt(Node* FreshRoot)
{
	this->mpRoot = FreshRoot;
}
Node* BST::GetRt() const
{
	return this->mpRoot;
}
void BST::insert(string& FreshDat, int& FreshUnits)
{
	insert(this->mpRoot, FreshDat, FreshUnits);
}
void BST::insert(Node*& fork, string& FreshDat, int& FreshUnits)
{
	if (fork == nullptr)
	{
		this->mpRoot = new TransactionNode(FreshDat, FreshUnits);
	}
	else
	{
		if (dynamic_cast<TransactionNode*>(fork)->getUnits() > FreshUnits)
		{
			if (fork->GetLeft() == nullptr)
			{
				fork->SetLeft(new TransactionNode(FreshDat, FreshUnits));
			}
			else
			{
				insert(fork->GetLeft(), FreshDat, FreshUnits);
			}
		}
		else if (dynamic_cast<TransactionNode*>(fork)->getUnits() < FreshUnits)
		{
			if (fork->GetRight() == nullptr)
			{
				fork->SetRight(new TransactionNode(FreshDat, FreshUnits));
			}
			else
			{
				insert(fork->GetRight(), FreshDat, FreshUnits);
			}
		}
		else
		{
			cout << "Duplicate: " << FreshUnits << endl;
		}
	}
}

void BST::inOrderTraversal()
{
	inOrderTraversal(this->mpRoot);
}

TransactionNode& BST::findSmallest()
{
	Node* root = mpRoot;
	while (root->GetLeft() != nullptr)
	{
		root = root->GetLeft();
	}
	return dynamic_cast<TransactionNode&>(*root);
}

TransactionNode& BST::findLargest()
{
	Node* root = mpRoot;
	while (root->GetRight() != nullptr)
	{
		root = root->GetRight();
	}
	return dynamic_cast<TransactionNode&>(*root);
}

void BST::inOrderTraversal(Node* fork) 
{
	if (fork != nullptr)
	{
		inOrderTraversal(fork->GetLeft());
		fork->Node::printData();
		fork->printData();
		inOrderTraversal(fork->GetRight());
	}
}
