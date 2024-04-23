#include<iostream>
using namespace std ;

void Menu()
{
    cout << "==========MENU==========" <<endl ;
    cout << "1) Insert\n" ;
    cout << "2) Print InOrder " << endl ;
    cout << "3) Exit\n" ;
    cout << "\nPlease Choose >>> " ;
}

struct node
{
    int value ;
    int height;
    struct node* left ;
    struct node* right ;
};

int find_height(struct node *p)
{
    if (p == NULL)
    {
        return -1;
    }
    else
    {
        return p -> height;
    }
}

struct node *insert(int data, struct node *tree)
{
    if (tree == NULL)
    {
        tree = new struct node;
        tree -> value = data;
        tree -> left = NULL;
        tree -> right = NULL;
        tree -> height = 0;
    }
    else
    {
        if (data < tree -> value)
        {
            tree -> left = insert(data, tree -> left);
        }
        else
        {
            tree -> right = insert(data, tree -> right);
        }
    }
    tree -> height = (max(find_height(tree -> left), find_height(tree -> right)) + 1);

    return tree;
}

void PrintInorder(struct node* node)
{
    if(node == NULL)
    {
        return ;
    }else
        {
            PrintInorder(node->left);
            cout << node -> value << " " ;
            PrintInorder(node ->right) ;
        }
}

int main()
{
    int input,data ;
    struct node *tree = NULL ;

    do
    {
        Menu() ;
        cin >> input ;

        switch(input)
        {
            case 1:
                cout << endl << "Insert : " ;
                cin >> data ;
                tree = insert(data,tree);
                if ((find_height(tree -> left) - find_height(tree -> right)) == 2)
                    {
                        cout << "\nYou have to rotate trees!\n";
                        return 0;
                    }
                    else
                    {
                        if ((find_height(tree -> right) - find_height(tree -> left)) == 2)
                        {
                            cout << "\nYou have to rotate trees!\n";
                            return 0;
                        }
                        else
                        {
                            cout << "\nSuccess!\n";
                        }
                    }

                break ;

            case 2:
                cout << "InOrder : " ;
                PrintInorder(tree);
                cout << endl << endl ;

                break ;

            case 3:
                cout << endl << "==== Good Bye (^O^)/ ====" << endl ;

                break ;

            default:
                cout << endl << "Please choose again!!!\n" << endl;

                break ;

        }

    }while(input != 3);

    return 0 ;

}
