#include <iostream>
using namespace std;

int main ()
{
   int n , i = 2 ;
   cout << "Input Number : ";
   cin >> n ;

    if(n < 2)
    {
        cout << "Not Prime Number" ;
    }else
    {
        while(i <= n-1)
        {
            if(n % i == 0)
            {
                cout << "Not Prime Number";
                return 0;
            }  i = i+1 ;
        }
    cout << "Prime Number";
    }
    return 0 ;
}