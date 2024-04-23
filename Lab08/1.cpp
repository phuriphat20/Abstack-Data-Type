#include<iostream>
using namespace std ;

struct record
{
    int value ;
    struct record *next ;
};

struct box
{
    struct record *head = NULL;
    struct record *end = NULL;
};

struct box insert(struct box box , int data)
{
    struct record *node ;

    if(box.head == NULL)
        {
            box.head = new struct record ;
            box.head ->value = data ;
            box.head ->next = NULL ;
            box.end = box.head ;

        }else
        {
            node = new struct record ;
            node -> value = data;
            node -> next = NULL;
            box.end ->next = node ;
            box.end = node ;

        }
return box  ;

}

int main()
{
    int data;
    struct box box;
    struct record *p ;

    cout << "Insert : ";
    while(data != -1)
        {
            cin >> data ;

            if(data != -1)
            {
                box = insert(box , data) ;
            }
        }

    cout << endl ;

    p = box.head ;
    cout << "List : " ;

    while (p != NULL)
    {
        cout << p -> value << " " ;
        p = p -> next ;
    }

    return  0 ;
}
