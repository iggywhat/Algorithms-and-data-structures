/*
#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

struct slistEl
{
    slistEl * next;
    int data;
};

class queue
{
private:
    slistEl * head;
    slistEl * tail;

public:
    queue( );
    ~queue( );
    bool empty ( );
    int front ();
    void enqueue ( int v );
    void dequeue ( );
    void print ( );
};

queue::queue( )
{
    head = tail = NULL;
}

queue::~queue( )
{
    while( head ) dequeue( );
}

bool queue::empty ( void )
{
    return !head;
}

int queue::front()
{
if(head != 0) return head->data;
else cout<<"Queue is empty"<<endl;
}

void queue::enqueue ( int v )
{
    slistEl * p;
    p = new slistEl;
    p->next = NULL;
    p->data = v;

    if( !head ) head = tail = p;
    else  {
      tail ->next = p;
        tail = p;
    }
}
void queue::dequeue ( )
{
    slistEl * p;
    p = head;
    if( head )
    {
        head = head->next;
        if(!head) tail = NULL;
    }
    delete p;
}

void queue::print()
{
    slistEl * p;

    if (head) {
        p = head;
        while (p) {
            cout << p->data << " ";
            p = p->next;
        }
        cout<<endl;
    }else
        cout << "Queue is empty" << endl;

}

int main( )
{
    queue Q;
    int i, v;

    srand ( time ( NULL ) );

    for( i = 1; i <= 10; i++ )
    {
        v = rand( ) %  100;
        Q.enqueue ( v );
    }

    Q.print();
    cout << "Front: " << Q.front() << endl;

    for( i = 1; i <= 10; i++ ) {
        Q.dequeue();
        Q.dequeue();
        Q.print();
        cout << "Front: " << Q.front() << endl;
        v = rand( ) %  100;
        Q.enqueue ( v );
        Q.print();
        cout << "Front: " << Q.front() << endl;
    }

    Q.dequeue();
    Q.print();
    cout << "Front: " << Q.front() << endl;

}
*/
//Zad.3.1.2
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N=10;

class queue
{
private:
    int T[N];
    int first, size;

public:
    queue( );
    ~queue( );
    bool empty ( );
    int front ();
    void enqueue ( int v );
    void dequeue ( );
    void print ( );
};

queue::queue( )
{
    first = 0;
    size = 0;
};

queue::~queue( )
{
};

bool queue::empty ( void )
{
return size == 0;
};

int queue::front()
{
    if(!NULL) {
        return T[first];
    }else{
        cout<<"Queue is empty"<<endl;
        return 0;
    }
};

void queue::enqueue ( int v )
{
   if(size < N){
       int a = (first + size) % N;
       T[a] = v;
       size++;
   }
};

void queue::dequeue ( )
{
    if (first < N){
        first++;
        size--;
        if(first == N) {
            first = 0;
            size--;
        }
    }
};

void queue::print()
// skomentować kod - wyjaśnić jak działa
{
    int i, n;
    if (size) {
        for (int i = 0; i < size; i++){
            n = first + i; //implementacja cyklicznosci tablicy
            if (n >= N)
                n = n - N;
            cout << T[n] << " "; // wypisuje element
        }
        cout << endl;
    }
};

int main( )
{
    queue Q;
    int i, v;

    srand ( time ( NULL ) );

    for( i = 1; i <= 10; i++ )
    {
        v = rand( ) %  100;
        Q.enqueue ( v );
    }

    Q.print();
    if (!Q.empty())
        cout << "Front: " << Q.front() << endl;

    for( i = 1; i <= 10; i++ ) {
        Q.dequeue();
        Q.dequeue();
        Q.print();
        if (!Q.empty())
            cout << "Front: " << Q.front() << endl;
        v = rand( ) %  100;
        Q.enqueue ( v );
        Q.print();
        if (!Q.empty())
            cout << "Front: " << Q.front() << endl;
    }

    Q.dequeue();
    Q.print();
    if (!Q.empty())
        cout << "Front: " << Q.front() << endl;

    return 0;

};
