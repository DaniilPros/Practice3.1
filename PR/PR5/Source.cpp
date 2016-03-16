#include<iostream>
//#include"Symbols.h"
using namespace std;

int main()
{
	//Symbols symbols(3, 4);
	const int a = 1;
	int* pa = const_cast<int*>(&a);
	*pa = 2;
	std::cout << a << *pa;

	
	
	system("pause");
	return 0;
}