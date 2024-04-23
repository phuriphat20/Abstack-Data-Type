#include<iostream>
using namespace std ;

struct record
{
	int value ;
	struct record *next ;
};

struct record *insert(struct record *head , int data)
{
	struct record *node , *p ;
	
	if(head == NULL)
	{
		head  = new struct record ;
		head -> value = data ;
		head -> next = NULL ;
	}else
		{
			node = new struct record ;
			node -> value = data ;
			
			if(data < head -> value)
				{
					node ->next = head ;
					head = node ;
				}else
					{
						p = head ;
						while(p -> next != NULL)
						{
							if(data < p ->next -> value)
							{
								node ->next = p -> next;
								p ->next = node ;
								break;
							}else
								{
									p = p ->next ;
								}
						}
						if(p ->next == NULL)
						{
							node ->next = NULL ;
							p ->next = node ;
						}	
					}		
		}
	    return head ;
}

void menu()
{
	cout << endl ;
	cout << "======= MENU =======" << endl ;
	cout << "1) Insert " << endl ;
	cout << "2) Print All data " << endl ;
	cout << "3) Print first and last " << endl ;
	cout << "4) Exit " << endl ;
	cout << "Please choose : " ;
}

void printAllData(struct record *head)
{
	struct record *temp ;
	
	if(head != NULL)
	{
		cout << endl << "List : " ;
		temp = head ;
		
		while(temp != NULL)
		{
			cout << temp -> value << " " ;
			temp = temp -> next ;
		}
	
		cout << endl;
	}else
		{
			cout << "Empty list !!!" << endl ;
		}	
}

void printFristLast(struct record *head )
{
	struct record *temp ;
	
	if(head != NULL)
	{
		cout << endl << "Frist : " ;
		temp = head ;
		cout << temp -> value << endl ;
		cout << "Last : " ;
		while(temp -> next != NULL)
		{
			temp = temp -> next ;
		}
		cout << temp -> value << endl ;	
	}else
	{
		cout << "Empty list !!!" << endl ;
	}	
}

int main()
{
	int input , data ;
	struct record *head = NULL;
	
	do
	{
		menu();
		cin >> input ;
		
		switch(input)
		{
			case 1: 
				cout << endl << "Insert : ";
				cin >> data ;
				head = insert(head,data) ;
				cout << "Success" ;
				printAllData(head) ;
				
				break ;
				
			case 2:
				printAllData(head) ;
				
                break;
                
            case 3:
				printFristLast(head) ;
				
                break;
                
            case 4:
				cout << "==== Good Bye (^O^)/ ====" << endl ;
				
                break;
			
			default:
    			cout << endl << "Please choose again!!!";
    			break ;
			
		}	
	}while(input != 4);	
	return 0 ;
}
