#include<iostream>
#include"Bst.h"
#include<random>
#include<memory>
int radnomint()
{
	std::random_device e;
	std::uniform_int_distribution<int> d(1, 100);
	return d(e);
}

void BSTTree() {

	Bst bst; 

	for (int i = 0; i < 10; i++){
		bst.addBst(radnomint());
	}

	std::cout << "Inorder:";
	bst.print_inorder();
	std::cout << std::endl;
	std::cout << "Preorder:";
	bst.print_preorder();
	std::cout << std::endl;
	std::cout << "Postorder:";
	bst.print_postorder();
	std::cout << std::endl;
	std::cout << "Min value : " << bst.minimum() << std::endl; 
	std::cout << "Max value : " << bst.maximum() << std::endl; 
	std::cout << "Give value to cheek :" << std::endl;
	int number;
	std::cin >> number;
	if (bst.contains(number))std::cout << "YES" << std::endl;
	if (!bst.contains(number))std::cout << "NO" << std::endl; 


}


int main() {


	BSTTree(); 

	std::cin.ignore(1); 
	return 0; 
}