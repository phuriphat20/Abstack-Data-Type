#include<iostream>
using namespace std;

int main()
{
	int input,found ;
	int i,j,k ;
	char a[5][5] = {
	{'S','T','L','Y','R'} ,
	{'T','H','E','M','E'} ,
	{'A','N','A','G','O'} ,
	{'R','O','P','E','S'} ,
	{'K','T','T','U','C'} ,
	};
	
	string db[14] = 
	{
		"STLY","THEME","THE","THEM","HE","ME","AN","GO","AGO","ROPE","OPE","OGA","CUT","OR"
	};
	
	string temp;
	
	cout << "=====================================\n\n";
	cout << "                MENU                 \n\n";
	cout << "=====================================\n";
	cout << "1)Print from front" << endl;
	cout << "2)Print from back" << endl;
	cout << "3)Math data base" << endl;
	cout << "Please choose > " ;
	cin >> input ;
	
	switch(input)
	{
		case 1 : 
			for(int i = 0 ; i < 5 ; i++) //Loop Row
			{
				for(int j = 0 ; j < 5 ; j++ )
				{
					for(int k = j ; k < 5 ; k++)
					{
						for(int m = j ; m <= k ; m++)
						{
							cout << a[i][m];
						}
						cout << " " ;
					}
				}
				cout << endl ;
			}
			
			break;
			
		case 2 : 
			for(int i = 0 ; i < 5 ; i++) //Loop Row
			{
				for(int j = 4 ; j >= 0 ; j-- )
				{
					for(int k = j ; k >= 0 ; k--)
					{
						for(int m = j ; m >= k ; m--)
						{
							cout << a[i][m];
						}
						cout << " " ;
					}
				}
				cout << endl ;
			}
			
			break;
			
		case 3 : 
			// Loop Row
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                for (int k = j; k < 5; k++)
                {
                    for (int m = j; m <= k; m++)
                    {
                        temp += a[i][m];
                    }
                    cout << temp;
                    for (int m = 0; m < 14; m++)
                    {
                        if (temp == db[m])
                        {
                            found++;
                            cout << "\tFound " << found ;
                            //db[m] = "";
                        }
                    }
                    temp = "";
                    cout << endl;
                }
            }
        }
        for (int i = 0; i < 5; i++)
        {
            for (int j = 4; j >= 0; j--)
            {
                for (int k = j; k >= 0; k--)
                {
                    for (int m = j; m >= k; m--)
                    {
                        temp += a[i][m];
                    }
                    cout << temp;
                    for (int m = 0; m < 14; m++)
                    {
                        if (temp == db[m])
                        {
                            found++;
                            cout << "\tFound " << found;
                            db[m] = "";
                        }
                    }
                    temp = "";
                    cout << endl;
                }
            }
        }
			
			break;
	}
	
	return 0;
}
