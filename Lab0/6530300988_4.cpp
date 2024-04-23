#include <iostream>
using namespace std;

int main()
{
    int i ;
    
    cout << "input : " ;
    cin >> i ;

    for(int a = 1 ; a <= i ; a++)
    {
        cout << a << " " ;

        for(int b = a+1 ; b <= i ; b++)
        {
             for(int c = a ; c <= b ; c++)
             {
                cout << c ;
             }
            cout << " " ;
        }
        if(a == i)
        {
            cout << i ;
        }
        cout << endl ;
    }

    return 0;
}