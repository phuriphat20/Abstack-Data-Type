#include<iostream>
using namespace std ;

int main()
{
	int i,j,k ;
	char a[5][5] = {
	{'S','T','L','Y','R'} ,
	{'T','H','E','M','E'} ,
	{'A','N','A','G','O'} ,
	{'R','O','P','E','S'} ,
	{'K','T','T','U','C'} ,
	};
	
	cout << "Input : " ;
	cin >> k ;
	for(i = 0 ; i < 5 ; i++)
	{
		for(j = 0 ; j <= i ; j++)
		{
			cout << a[k-1][j] ;
			
		}
		cout << " ";
	}
	return 0 ;
}
