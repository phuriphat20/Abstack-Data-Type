#include<iostream>
using namespace std ;

struct record
{
	int value ;
	struct record *next ;
};

struct record *p ;

int main()
{
	int data ;
	p = new struct record;
	
	cout << "Enter : " ;
	cin >> data ;
	
	p -> value = data ; 
	cout << "Value = " << p -> value ; 
	
	return 0 ;
	
}
