#include <iostream>
#include <fstream>

using namespace std;

struct record
{
    long long stdID;
    string stdName;
    struct record *next;

};

struct record *insert(struct record *head , string id ,string name)
{
    if(head == NULL)
        {
            head = new struct record ;
            head -> stdID = stoll(id);
            head -> stdName = name ;
            head -> next = NULL ;
        }
        else
        {
            struct record *node = new struct record;
            struct record *p ;
            node -> stdID = stoll(id);
            node -> stdName = name ;
            node -> next = NULL ;
            p = head ;

            while(p ->next != NULL)
                {
                    p = p ->next ;
                }
            p ->next = node ;

        }
    return head ;
}
int Menu(void)
{
    int choose = 0 ;

    cout << "\n===========MENU==========\n\n" ;
    cout << "1.Separate Chaining\n" ;
    cout << "2.Linear Probling\n" ;
    cout << "3.Quardratic probling\n" ;
    cout << "4.Double Hashing\n" ;
    cout << "5.Exit\n\n" ;
    cout << "Please choose > ";
    cin >> choose ;

    return choose ;
}

int hashValue(string key, int tableSize, int countRepeat)
{
    return (stoll(key) + countRepeat) % tableSize;
}

int hashValue2(string key, int tableSize)
{
    return 3 - (stoll(key) % tableSize);
}

void separateChaining(int tableSize)
{
    int index = 0 ;
    struct record *separateChainingRecord[tableSize] ;
    struct record *p ;
    string name, id ;

    ifstream readFile("ADT.txt");
    for (int i = 0; i < tableSize; i++)
    {
        separateChainingRecord[i] = NULL ;
    }

    while (readFile >> id >> name)
    {
        index = hashValue(id, tableSize, 0);
        separateChainingRecord[index] = insert(separateChainingRecord[index], id, name);
    }
    readFile.close();

    cout << "\n\nIndex\tID\n\n";
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "\t" ;
        p = separateChainingRecord[i];

        while (p != NULL)
        {
            cout << p -> stdID << "\t" << p -> stdName << endl << "\t";
            p = p -> next;
        }
        cout << "\n\n";
    }

}

void linearProbling(int tableSize)
{
    int index = 0;
    int countRepeat = 0;
    struct record *linearProblingRecord[tableSize] ;
    struct record *p ;
    string name, id ;

    ifstream readFile("ADT.txt");
    for (int i = 0; i < tableSize; i++)
    {
        linearProblingRecord[i] = NULL ;
    }

    while (readFile >> id >> name)
    {
        index = hashValue(id, tableSize, countRepeat);
        while (linearProblingRecord[index] != NULL && countRepeat <= 100)
        {
            countRepeat++ ;
            index = hashValue(id, tableSize, countRepeat) ;
        }
        if (countRepeat > 100)
        {
            cout << "\n\nError, Can not insert data!\n\n" ;
            break ;
        }
        linearProblingRecord[index] = insert(linearProblingRecord[index], id, name) ;
        countRepeat = 0 ;
    }
    readFile.close() ;

    cout << "\n\nIndex\tID\n\n";
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "\t";
        p = linearProblingRecord[i];
        while (p != NULL)
        {
            cout << p -> stdID << "\t" << p -> stdName << endl << "\t";
            p = p -> next;
        }
        cout << "\n\n";
    }

}

void quardraticProbling(int tableSize)
{
    int index = 0 ;
    int countRepeat = 0 ;
    struct record *quardraticRecord[tableSize] ;
    struct record *p ;
    string name, id ;

    ifstream readFile("ADT.txt") ;

    for (int i = 0; i < tableSize; i++)
    {
        quardraticRecord[i] = NULL ;
    }

    while (readFile >> id >> name)
    {
        index = hashValue(id, tableSize, countRepeat) ;
        while (quardraticRecord[index] != NULL && countRepeat <= 100)
        {
            countRepeat++ ;
            index = hashValue(id, tableSize, countRepeat * countRepeat) ;
        }
        if (countRepeat > 100)
        {
            cout << "\n\nError, Can not insert data!\n\n" ;
            break ;
        }
        quardraticRecord[index] = insert(quardraticRecord[index], id, name) ;
        countRepeat = 0 ;
    }
    readFile.close() ;

    cout << "\n\nIndex\tID\n\n";
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "\t" ;
        p = quardraticRecord[i] ;
        while (p != NULL)
        {
            cout << p -> stdID << "\t" << p -> stdName << endl << "\t" ;
            p = p -> next ;
        }
        cout << "\n\n" ;
    }
}

void doubleHashing(int tableSize)
{
    int index = 0;
    int countRepeat = 0;
    struct record *doubleHashingRecord[tableSize];
    struct record *p;
    string name, id;

    ifstream readFile("ADT.txt");

    for (int i = 0; i < tableSize; i++)
    {
        doubleHashingRecord[i] = NULL ;
    }

    while (readFile >> id >> name)
    {
        index = hashValue(id, tableSize, countRepeat) ;

        while (doubleHashingRecord[index] != NULL && countRepeat <= 100)
        {
            countRepeat++ ;
            index = (hashValue(id, tableSize, 0) + countRepeat * hashValue2(id, tableSize)) % tableSize ;
        }
        if (countRepeat > 100)
        {
            cout << "\n\nError, Can not insert data!\n" ;
            break ;
        }

        doubleHashingRecord[index] = insert(doubleHashingRecord[index], id, name) ;
        countRepeat = 0 ;
    }
    readFile.close() ;

    cout << "\n\nIndex\tID\n\n" ;
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "\t" ;
        p = doubleHashingRecord[i] ;
        while (p != NULL)
        {
            cout << p -> stdID << "\t" << p -> stdName << endl << "\t" ;
            p = p -> next ;
        }
        cout << "\n\n" ;
    }
}

int main()
{
    int tableSize = 5;
    int choose = 0;
    do{
            choose = Menu() ;

            switch(choose)
            {
                case 1 :
                    separateChaining(tableSize);

                    break ;

                case 2 :
                    linearProbling(tableSize) ;

                    break ;

                case 3 :
                    quardraticProbling(tableSize) ;

                    break ;

                case 4 :
                    doubleHashing(tableSize) ;

                    break ;

                case 5 :
                    cout << endl << "Thank you!!!\n\n";

                    break ;

                default :
                    cout << "please input again!!!!\n" ;

                    break ;
            }


        }while(choose != 5) ;

}
