#include <iostream>
using namespace std ;

int main() 
{
	int arr[5];
	int value ;
	
	cout << "Enter Your Number (Positive Integer) : " ;
	for(int i = 0 ; i < 5 ; i++)
	{
		cin >> arr[i] ;
		
	}
		cout << "(index) | " ; 
		for(int i = 0 ; i < 5 ; i++)
		{
			cout <<  i << " " ; 
		}
		cout << endl << "________|_________";
			
		cout << endl << "(value) | " ;
		for(int i = 0 ; i < 5 ; i++)
		{
			cout << arr[i] << " ";
		}
			
	cout << endl << endl << "Enter value : ";
    cin >> value;
	
	for(int i = 0 ; i < 5 ; i++)
	{
		if(value < arr[i])
		{
			cout << "index = " << i ;
			break;
		}
	}
	
	if(value > arr[4])
	{
		cout << "No number" ;
	}
				
	return 0;
}
