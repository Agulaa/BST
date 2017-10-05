#include "Bst.h"

Bst::Bst(){
	node = nullptr; 
}

void Bst::print_inorder(){
	inorder(node.get()); 
}

void Bst::print_preorder(){
	preorder(node.get()); 
}

void Bst::print_postorder(){
	postorder(node.get()); 
}

void Bst::addBst(int value){
	if (node == nullptr)node = std::make_unique<BstNode>(value);
	else addBst1(node, value);
}

int Bst::minimum(){
	return minimum1(node.get()); 
}

int Bst::maximum(){
	return maximum1(node.get()); 
}

bool Bst::contains(int value){
	return contains1(node.get(), value); 
}
//----------------------------------------
int Bst::minimum1(BstNode *bst){
	if (bst->left == nullptr)return bst->value;
	if (bst->left != nullptr) return minimum1(bst->left.get());
}
int Bst::maximum1(BstNode *bst){
	if (bst->right == nullptr)return bst->value;
	if (bst->right != nullptr) return maximum1(bst->right.get());
}
bool Bst::contains1(BstNode *bst, int value){
	if (bst != nullptr){
		if (bst->value == value)return true;
		else {
			if (bst->value > value) {
				return contains1(bst->left.get(), value);
			}
			else{
				return contains1(bst->right.get(), value);
			}
		}
	}
	return false;
}

void Bst::inorder(BstNode *bst){
	if (bst != nullptr){
		if (bst->left != nullptr){
			inorder(bst->left.get());
		}
		std::cout << bst->value << " ";
		if (bst->right != nullptr){
			inorder(bst->right.get());
		}
	}
}

void Bst::preorder(BstNode *bst){
	std::cout << bst->value << " ";
	if (bst != nullptr){
		if (bst->left != nullptr){
			inorder(bst->left.get());
		}
		if (bst->right != nullptr){
			inorder(bst->right.get());
		}
	}
}

void Bst::postorder(BstNode *bst){
	if (bst != nullptr){
		if (bst->left != nullptr){
			inorder(bst->left.get());
		}
		if (bst->right != nullptr){
			inorder(bst->right.get());
		}
	}
	std::cout << bst->value << " ";
}

void Bst::addBst1(std::unique_ptr<BstNode>& root2, int value){
	if (root2 == nullptr) {
		root2 = std::make_unique<BstNode>(value);
		return;
	}
	if (root2->value == value) {
		std::cout << "Can't add "<<value << std::endl;
	}
	else {
		if (root2->value > value) {
			if (root2->left == nullptr) {
				root2->left = std::make_unique<BstNode>(value);
			}
			else {
				addBst1(root2->left, value);
			}
		}
		else if (root2->value < value) {
			if (root2->right == nullptr) {
				root2->right = std::make_unique<BstNode>(value);
			}
			else {
				addBst1(root2->right, value);
			}
		}
	}
}
//-------------------------------------
Bst::~Bst()
{
}