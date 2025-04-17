// Kolejka priorytetowa za pomocą listy

#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>

using namespace std;

const int MIN = 2147483647;

struct listEl
{
    listEl * next;
    int priority, data;
};

class priorityqueue
{
private:
    listEl * head;
    listEl * tail;

public:
    priorityqueue( );
    ~priorityqueue( );
    bool empty ( void );
    int  findmindata ( void );
    int  findminpriority ( void );
    void insert ( int priority, int v, int& c);
    void deletemin ( void );
};

priorityqueue::priorityqueue( )
{
    head = tail = NULL;
}

priorityqueue::~priorityqueue( )
{
    while(head)
    {
        deletemin();
    }
}

bool priorityqueue::empty ( void )
{
    return !head;
}

int priorityqueue::findmindata ( void )
{
    if(head){return head->data;}
    else
    {
        return MIN;
    }
}

int priorityqueue::findminpriority ( void )
{
    if(!head)
    {
        return MIN;
    }
    else
    {
        return head->priority;
    }
}

void priorityqueue::insert ( int priority, int v, int& x )
{
    listEl *p, *r;
    p = new listEl;
    p->next = NULL;
    p->priority = priority;
    p->data = v;
    x = 0;

    if(!head)
        head = tail = p;
    else if (++x && head->priority > priority)
    {
        p->next = head;
        head = p;
    }
    else
    {
        r = head;
        while((r->next) && ++x && (r->next->priority <= priority))

            r = r->next;
        p->next = r->next;
        r->next = p;
        if( !p->next )tail=p;


    }
}

void priorityqueue::deletemin ( void )
{
    if(head)
    {
        head = head->next;
        if(!head)
        {
            tail = NULL;
        }
    }
}

int main( )
{
    priorityqueue Q;
    int i, p, v, x;

    srand ( time ( NULL ) );
    cout << "wprowadzane elementy w postaci element:priorytet\n";
    for( i = 1; i <= 10; i++ )
    {
        v = i;
        p = rand( ) %  100;
        cout  << v << "|" << p << endl;
        Q.insert (p, v, x);
        cout << "Ilosc porownan: "<< x <<endl;
    }
    cout << "\n" << "kolejka priorytetowa w postaci element:priorytet\n";
    while( !Q.empty( ) )
    {
        cout << Q.findmindata( ) << "|" << Q.findminpriority( ) << endl;
        Q.deletemin( );
    }
}