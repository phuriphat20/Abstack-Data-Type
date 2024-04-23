#include<iostream>
using namespace std ;

void Menu()
{
    cout << "\n =========MENU========\n" ;
    cout << "1) Insert data to array \n" ;
    cout << "2) Build Heap \n" ;
    cout << "3) Heap Sort \n" ;
    cout << "4) Heap insert \n" ;
    cout << "5) Priority Queue \n" ;
    cout << "6) Extract Max \n" ;
    cout << "7) Exit \n" ;
    cout << "       Please choose > " ;
}

int heapsize ;

int parents(int i)
{
    return i / 2 ;
}

int left(int i)
{
    return 2 * i ;
}

int right(int i)
{
    return (2 * i) + 1 ;
}

void exchange(int A[] , int i , int largest)
{
    int temp ;

    temp = A[i] ;
    A[i] = A[largest] ;
    A[largest] = temp ;
}

void Heapify(int A[] , int i)
{
    int l , r , largest ;

    l = left(i) ;
    r = right(i) ;

    if(l <= heapsize && A[l] > A[i])
        {
            largest = l ;
        }else
        {
            largest = i ;
        }

    if(r <= heapsize && A[r] > A[largest])
        {
            largest = r ;
        }
    if(largest != i)
        {
            exchange(A , i , largest) ;
            Heapify(A,largest) ;
        }
}

void Build_heap(int A[])
{
    int length = heapsize ;

    for(int i = length/2 ; i >= 1 ; i-- )
        {
            Heapify(A , i) ;
        }
}

void HeapSort(int A[])
{
    int heaplength = heapsize;

    Build_heap(A) ;
    for(int i = heapsize ; i >= 2 ; i--)
        {
            exchange(A , 1 , i) ;
            heapsize = heapsize - 1 ;
            Heapify(A , 1) ;
        }
}

void Heap_Insert(int A[] , int key)
{
    int i ;

    heapsize = heapsize + 1 ;
    i = heapsize ;
    while(i > 1 && A[parents(i)] < key)
        {
            A[i] = A[parents(i)] ;
            i = parents(i) ;
            A[i] = key ;
        }
}

int Heap_Exact_Max(int A[])
{
    int max ;

    if(heapsize < 1)
        {
            cout << endl << "Heap underflow!" ;
        }

    max = A[1] ;
    A[1] = A[heapsize] ;
    heapsize = heapsize - 1 ;
    Heapify(A , 1) ;

    return max ;
}

void printHeap(int A[])
{
    for(int i = 1; i <= heapsize; i++)
    {
        cout << A[i] << " ";
    }

    cout << endl;
}

int main()
{
    int A[30] ;
    int input , data , key ;

    do
        {
            Menu() ;
            cin >> input ;

            switch(input)
            {
             case 1 :

                cout << endl <<"input : " ;
                for(int i = 1 ; i <= 10 ; i++)
                    {
                        cin >> data ;
                        A[i] = data ;
                        heapsize++ ;
                    }

                break ;

            case 2 :

                Build_heap(A) ;
                cout << endl << "Heap : ";
                printHeap(A);

                break ;

            case 3 :

                HeapSort(A) ;
                cout << endl << "Heap Sort : " ;
                heapsize = 10 ;
                printHeap(A);

                break ;

            case 4 :

                cout << "\nInsert : " ;
                cin >> key ;
                A[heapsize + 1] = key ;
                heapsize++ ;

                cout << endl << "Array : ";
                printHeap(A);

                heapsize-- ;
                Heap_Insert(A , key) ;
                cout << endl << "Heap : " ;
                printHeap(A) ;

                break ;

            case 5 :


                cout << endl << "Priority Queue Heap : " ;
                printHeap(A) ;

                break ;

            case 6 :

                cout << endl << "Max = " << Heap_Exact_Max(A) << endl ;
                cout << endl << "Heap : " ;
                printHeap(A);

                break ;

            case 7 :

                cout << endl << "Thank you!!!";

                break ;

            default:

            cout << "please input again!!!!\n" ;

            break;

            }

        }while(input != 7) ;

return 0 ;

}
