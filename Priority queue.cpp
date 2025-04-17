#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAX = 2147483647;

const int N = 100;


struct QueueEl
{

    int priority, data;
};


class priorityqueue
{
private:
    QueueEl T[ N ];
    int n;

public:
    priorityqueue( );
    ~priorityqueue( );
    bool empty ( void );
    int findmaxdata ( void );
    int findmaxpriority ( void );
    void insert ( int priority, int data, int& c );
    void deletemax ( void );
    void print ( void);
};


priorityqueue::priorityqueue( )
{
    n=0;
}

priorityqueue::~priorityqueue( )
{

}


bool priorityqueue::empty ( void )
{
    return !n;
}

int priorityqueue::findmaxdata ( void )
{
    if (n) return T[1].data;
    else        return MAX;
}

int priorityqueue::findmaxpriority ( void )
{
    if (n) return T[1].priority;
    else        return MAX;
}

void priorityqueue::insert ( int priority, int data, int& x )
{
    int i, j;
    x = 0;
    n++;
    i = n;

    T[i].priority = priority;
    T[i].data = data;

    j = i / 2;
    while ((i > 1) && (++x) && (T[j].priority < T[i].priority))
    {
        swap(T[i], T[j]);
        i = j;
        j = i / 2;
    }
}


void priorityqueue::deletemax ( void )
{
    int i, d, p, older;
    p = T[n].priority;
    d = T[n].data;
    n--;
    if (n != 0)
    {
        i = 1;
        T[i].priority = p;
        T[i].data = d;
        while (i <= n / 2)
        {
            older = 2 * i;
            if (older + 1 <= n && T[older + 1].priority > T[older].priority)
            {
                older++;
            }
            if (T[i].priority < T[older].priority)
            {
                swap(T[i], T[older]);
                i = older;
            }
            else
            {
                n = i;
            }
        }
    }
}


int main( )
{
    priorityqueue Q;
    int i, p, v, x;

    setlocale(LC_CTYPE, "Polish");

    srand ( time ( NULL ) );

    cout << "wprowadzone elementy w postaci element:priorytet\n";

    for( i = 1; i <= 10; i++ )
    {
        v = i;
        p = rand( ) % 100;
        cout << v << "|" << p << endl;
        Q.insert (p, v, x);
        cout<<"Liczba porownan: "<< x << endl;
    }

    cout << "\n" << "kolejka priorytetowa w postaci element:priorytet\n";

    while ( !Q.empty() )
    {
        cout << Q.findmaxdata( ) << "|" << Q.findmaxpriority( ) << endl;
        Q.deletemax( );
    }
}