#include<iostream>
using namespace std ;

struct record
{
	int value ;
	struct record *next ;
	struct record *prev ;
};

struct record *insert(struct record *head , int data)
{
	struct record *node , *p ;

	if(head == NULL)
	{
		head  = new struct record ;
		head -> value = data ;
		head -> next = NULL ;
		head -> prev = NULL ;
	}else
		{
			node = new struct record ;
			node -> value = data ;

			if(data < head -> value)
				{
					node ->next = head ;
					node ->prev = NULL ;
					head ->prev = node ;
					head = node ;
				}else
					{
						p = head ;
						while(p -> next != NULL)
						{
							if(data < p ->next -> value)
							{
								node ->next = p -> next;
								node ->prev = p ;
								p ->next -> prev = node ;
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
							node ->prev = p ;
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
	cout << "2) Print min to max / max to min " << endl ;
	cout << "3) Exit " << endl ;
	cout << "Please choose : " ;
}

void printMinAndMax(struct record *head)
{
    struct record *temp ;

    cout << endl << "Min To Max : " ;
    temp = head ;

    while(temp != NULL)
    {
        cout << temp -> value << " " ;
        temp = temp ->  next;
    }

    cout << endl;
    cout << endl << "Max To Min : " ;
    temp = head ;

    while(temp ->next != NULL)
    {
			temp = temp -> next ;
    }
    while(temp != NULL)
    {
        cout << temp -> value << " " ;
        temp = temp -> prev;
    }

    cout << endl;
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

				break ;

            case 2:
                printMinAndMax(head);

                break;

            case 3:
				cout << "==== Good Bye (^O^)/ ====" << endl ;

                break;

			default:
    			cout << endl << "Please choose again!!!";

    			break ;
        }

	}while(input != 3);

return 0 ;

}
