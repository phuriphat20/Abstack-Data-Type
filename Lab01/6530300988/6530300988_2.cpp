#include <iostream>
using namespace std ;

void show_data(int arr[] , int count)
{
	for(int i = 0 ; i < count ; i++)
	{
		cout << arr[i] << " " ;
	}
	cout << endl ;
	
}

int main()
{
	int arr[10] ;
	int count = 0 , input , temp ;
	
	while(input != -1)
	{
		cout << "==============MENU==================\n\n";
		cout << "1) insert the first value\n";
		cout << "2) insert front\n";
		cout << "3) insert last\n";
		cout << "4) insert middle\n";
		cout << "5) Exsit (-1)\n";
	
		cout << "Please choose > ";
		cin >> input  ;
		
		switch(input)
		{
		case 1:
			cout << "Enter data : ";
			cin >> arr[0];
			count++;
			
			cout << "Data in list : " ;
			show_data(arr,count) ;
			
			break;
			
		case 2 : 
			cout << "Enter data : ";
			cin >> temp ;
			cout << "Move = " << count << " Position" << endl ;
			cout << "Data Move = ";
			show_data(arr,count) ;
			
			for(int i = count ; i >= 0 ; i--)
			{
				arr[i] = arr[i-1];
			}
			arr[0] = temp ;
			count++;
			cout << "Data in list = " ;
			show_data(arr,count) ;
			
			break;
			
		case 3 :
			cout << "Enter data : ";
			cin >> arr[count] ;
			count++;
			cout << "Data in list = " ;
			show_data(arr,count) ;
			
			break;
			
		case 4:
			cout << "Enter data : ";
			cin >> temp ;
			cout << "Move = " << count/2 << " Position" << endl ;
			cout << "Data Move = ";
			
			for(int i = count/2 ; i < count ; i++)
			{
				cout << arr[i] << " " ;
			}
			cout << endl ;	
			
			for(int i = count ; i > count/2 ; i--)
			{
				arr[i] = arr[i-1];
			}
			arr[count/2] = temp ;
			count++;
			cout << "Data in list = " ;
			show_data(arr,count) ;
			
			break;
			
		case -1 :
			cout << "==== Bye (^O^)/ ====" << endl ;
			
			break;
			
		default:
    	cout << "Invalid Number !!!";	
    	
		}
	}
	return 0 ;
	
}
