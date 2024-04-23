#include<iostream>
#include<stdio.h>
using namespace std ;

struct Node ;
typedef struct Node *stack;

struct Node
{
    int value;
    struct Node *Next;
};

stack CreateStack(void)
{
    stack S;
    S = new struct Node ;
    if(S == NULL)
        {
            cout << "Out of space!!!" <<endl ;
        }
    S ->Next = NULL;

    return S;
};

int IsEmpty(stack S)
{
    return S ->Next == NULL ;
}

void Push(int data,stack S)
{
    stack TmpCell;
    TmpCell = new struct Node;
    if(TmpCell == NULL)
    {
       cout << "Out of space!!!";
    }else
        {   TmpCell->value = data;
            TmpCell->Next = S->Next;
            S->Next = TmpCell;
        }
}

void Pop(stack S)
{
stack FirstCell;
    if(IsEmpty(S))
    {
        cout << "Empty Stack!!!";
    }else
        {
            FirstCell = S->Next;
            S->Next = S->Next->Next;
            delete(FirstCell);
        }
}

int Top(stack S)
{
    if(!IsEmpty(S))
        {
            return S->Next->value;
        }

 return 0;
}


void MakeEmpty(stack S)
{
    if (S== NULL)
        {
            cout << "Must use CreateStack first" << endl;
        }else
            {
                while(!IsEmpty(S))
                    Pop(S);
            }

}

void menu()
{
	cout << endl ;
	cout << "======= MENU =======" << endl ;
	cout << "1) Push " << endl ;
	cout << "2) Pop " << endl ;
	cout << "3) Top " << endl ;
	cout << "4) Exit " << endl ;
	cout << "Please choose : " ;
}

int main()
{
int input , data ;
stack S = CreateStack();

	do
	{
		menu();
		cin >> input ;

		switch(input)
		{
			case 1:
				cout << endl << "Push : ";
				cin >> data ;
				Push(data,S) ;
				cout << "Success!!! " << endl;

				break ;

			case 2:
			    if(Top(S) != NULL)
                {
                    cout << endl << "Pop : " <<Top(S) << endl;
                    Pop(S);
                }else
                    {
                        cout << endl;
                        Pop(S);
                    }


                break;

            case 3:
				cout << endl << "Top : " << Top(S) << endl;

                break;

            case 4:
				cout << endl << "==== Good Bye (^O^)/ ====" << endl ;

                break;

			default:
    			cout << endl << "Please choose again!!!";

    			break ;

        }
	}while(input != 4);


return 0 ;

}
