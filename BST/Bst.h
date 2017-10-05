#pragma once
#include<iostream>
#include<memory>

class Bst
{
protected:
	struct BstNode
	{
		int value;
		std::unique_ptr<BstNode> left;
		std::unique_ptr<BstNode> right;

		BstNode(int value) {
			this->value = value;
			left = nullptr;
			right = nullptr;
		}
	};
public: 
	
	std::unique_ptr<BstNode>node; 
	Bst();	

	void print_inorder();
	void print_preorder();
	void print_postorder();
	void addBst(int value);
	int minimum();	
	int maximum();
	bool contains(int value);

	~Bst();
private:
	void inorder(BstNode* bst); 
	void preorder(BstNode* bst);
	void postorder(BstNode* bst); 
	void addBst1(std::unique_ptr<BstNode>& root2, int value);
	int minimum1(BstNode* bst);
	int maximum1(BstNode* bst);
	bool contains1(BstNode* bst, int value);

};

