#include<iostream>
using namespace std ;

void Menu()
{
    cout << "==========MENU==========" <<endl ;
    cout << "1) Insert\n" ;
    cout << "2) Print InOrder, print leave node, print NonLeave node" << endl ;
    cout << "3) Delete\n" ;
    cout << "4) Find\n" ;
    cout << "5) Exit\n" ;
    cout << "\nPlease Choose >>> " ;
}

struct node
{
    int value ;
    struct node* left ;
    struct node* right ;
};

struct node *insert(int data ,struct node *tree)
{
    if(tree == NULL)
        {
            tree = new struct node ;
            tree ->value = data ;
            tree ->left = tree ->right = NULL ;

        }else
            {
               if(data < tree -> value)
                {
                    tree ->left = insert(data , tree ->left);
                }else
                    {
                      if(data > tree -> value)
                      {
                          tree ->right = insert(data , tree ->right) ;
                      }
                    }
            }

    return tree ;
}

void PrintInorder(struct node* tree)
{
    if(tree == NULL)
    {
        return ;
    }else
        {
            PrintInorder(tree->left);
            cout << tree -> value << " " ;
            PrintInorder(tree ->right) ;
        }
}

void PrintLeaveNode(struct node *tree)
{
    if(tree == NULL)
        {
            return ;
        }

    PrintLeaveNode(tree->left) ;
    if(tree ->left == NULL && tree ->right == NULL)
        {
            cout << tree ->value << " " ;
        }

        PrintLeaveNode(tree->right) ;
}

void PrintNonLeaveNode(struct node *tree)
{
    if(tree == NULL)
        {
            return ;
        }

    PrintNonLeaveNode(tree->left) ;
    if(tree ->left != NULL || tree ->right != NULL)
        {
            cout << tree ->value << " " ;
        }

        PrintNonLeaveNode(tree->right) ;
}

struct node *find_min(struct node *tree)
{
    if(tree == NULL)
    {
        return NULL;
    }
    else
    {
        if (tree -> left == NULL)
        {
            return tree;
        }
        else
        {
            return find_min(tree -> left);
        }
    }
}

struct node *deleteTree(struct node *tree, int data)
{
    struct node *tmpcell, *child;
    if (tree == NULL)
    {
        cout << "No Node\n";
    }
    else
    {
        if (data < tree -> value)
        {
            tree -> left = deleteTree(tree -> left, data);
        }
        else
        {
            if (data > tree -> value)
            {
                tree -> right = deleteTree(tree -> right, data);
            }
            else
            {
                if(tree -> left != NULL && tree -> right != NULL)
                {
                    tmpcell = find_min(tree -> right);
                    tree -> value = tmpcell -> value;
                    tree -> right = deleteTree(tree -> right, tree -> value);
                }
                else
                {
                    tmpcell = tree;
                    if (tree -> left == NULL)
                    {
                        child = tree -> right;
                    }
                    else
                    {
                        child = tree -> left;
                    }
                    delete(tmpcell);
                    return child;
                }
            }
        }
    }
    return tree;
}

int find(struct node *tree, int data)
{
    if (tree == NULL)
    {
        return 0;
    }
    else
    {
        if (tree -> value == data)
        {
            return 1;
        }
        else
        {
            return find(tree -> left, data) + find(tree -> right, data);
        }

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
                cout << "Success !!!\n" ;
                cout << endl ;

                break ;

            case 2:
                cout << "InOrder : " ;
                PrintInorder(tree);
                cout << endl ;

                cout << "Leave : " ;
                PrintLeaveNode(tree);
                cout << endl ;

                cout << "Non-Leave : " ;
                PrintNonLeaveNode(tree);
                cout << endl ;

                break ;

            case 3:
                cout << "Delete : ";
                cin >> data;
                tree = deleteTree(tree, data);
                cout << "Success!\n";

                break ;

            case 4:
                cout << "Search : ";
                cin >> data;
                if (find(tree, data) > 0)
                {
                    cout << "Found!\n";
                }
                else
                {
                    cout << "Not Found!\n";
                }

                break;

            case 5:
                cout << endl << "==== Good Bye (^O^)/ ====" << endl ;

                break ;

            default:
                cout << endl << "Please choose again!!!\n" << endl;

                break ;

        }

    }while(input != 5);

    return 0 ;

}
