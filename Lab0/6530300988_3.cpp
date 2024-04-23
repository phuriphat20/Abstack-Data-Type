#include <iostream>
using namespace std;

int main()
{
    int num[10] ;

    cout << "Enter Number : ";

    for (int i = 0; i < 10; i++) 
    {
        cin >> num[i] ;
    }

    cout << "Output : ";
    for (int i = 9; i >= 0; i--) 
    {
        cout << num[i] << " " ;
    }

    
}