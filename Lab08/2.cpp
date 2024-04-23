#include<iostream>
using namespace std ;

struct record
{
    int value ;
    struct record *next ;
};

void Menu()
{
    cout << "\n=======MENU==========\n" ;
    cout << "1)Input adjacency list\n" ;
    cout << "2)Input adjacency matrix\n" ;
    cout << "3)Show self loop from adjacency list\n" ;
    cout << "4)Exit\n" ;
    cout << "Please choose > " ;
}

struct record *insert(struct record *head , int data)
{
    struct record *end , *p ;

    while(data != -1)
    {
        cin >> data ;
    if(data != -1)
        {
            if(head == NULL)
                {
                    head = new struct record ;
                    head ->value = data ;
                    head ->next = NULL ;
                    end = head ;

                }else
                {
                    p = new struct record ;
                    p -> value = data;
                    p -> next = NULL;
                    end ->next = p ;
                    end = p ;
                }
        }
    }

return head ;

}

void PrintADJ_List(struct record *adj[])
{
    struct record *p ;
    int i ;

    cout << "\n-ADJACENCY LIST-\n\n" ;
    for(i = 0 ; i < 6 ; i ++)
        {
            p = adj[i];
            cout << "#" << i << " : " ;
            while(p != NULL)
                {
                    cout << p ->value << " " ;
                    p = p ->next ;
                }
            cout << endl ;
        }
    cout << endl;

}

void PrintADJ_Matrix(int matrix[][6])
{
    struct record *p ;
    int i , j ;

    cout << "\n-ADJACENCY LIST-\n\n" ;
    cout << "--------------------\n\n" ;

        for(i = 0 ; i < 6 ; i ++)
            {

                for(j = 0 ; j < 6 ; j++)
                    {
                        cout << matrix[i][j] << " ";
                    }
                cout << endl << endl ;
            }
}

void PrintSelf_Loop(struct record *adj[])
{
    struct record *p ;
    int i ;

    cout << "SelfLoop : " ;
    for(i = 0 ; i < 6 ; i ++)
        {
            p = adj[i] ;
            if(p ->value == i)
                {
                    cout << p->value << " " ;
                }
        }
}

int main()
{
    int data , input ;
    struct record *adj[6];
    int matrix[6][6];
    struct record *head = NULL , *p ;

    do
    {
        Menu();
        cin >> input ;

        switch(input)
        {
            case 1 :

                for(int i = 0 ; i < 6 ;i++)
                    {
                        cout << "Enter #" << i << " : " ;
                        adj[i] = insert(head,data);

                    }

                    cout << endl ;
                    PrintADJ_List(adj);

            break;

            case 2 :

                for(int i = 0 ; i < 6 ;i++)
                    {
                        cout << "Enter #" << i << " : " ;
                        adj[i] = insert(head,data);

                    }


                    for(int i = 0 ; i < 6 ; i ++)
                        {
                            p = adj[i] ;

                            while(p != NULL)
                                {
                                    for(int j = 0 ; j < 6 ; j++)
                                    {
                                        if(p ->value == j)
                                            {
                                                matrix[i][j] = 1 ;

                                            }else
                                            {
                                                if (matrix[i][j] == 1)
                                                {
                                                    continue;
                                                }
                                                matrix[i][j] = 0 ;
                                            }
                                    }
                                    p = p -> next;
                                }

                        }
                    cout << endl ;
                    PrintADJ_Matrix(matrix);

            break;

            case 3 :

                PrintSelf_Loop(adj);
                cout << endl << endl ;

            break;

            case 4 :
                cout << endl << "==== Good Bye (^O^)/ ====" << endl ;

                break;
            default:
                cout << endl << "Please choose again!!!\n" << endl;

                break ;
        }
    }while(input != 4);

    return 0 ;
}
