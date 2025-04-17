//Stos za pomocą listy
/*
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

struct slistEl
{
	slistEl * next;
	int data;
};

class stack
{
	private:
    	slistEl * tail;

	public:
    	stack( );
    	~stack( );
    	bool empty ( void );
    	int top ( void );
    	void push ( int v );
    	void pop ( void );
    	void print ( void );
};

stack::stack( )
{
	tail = NULL;
}

stack::~stack( )
{
  	while( tail ) pop( );
}

bool stack::empty ( void )
{
return tail = NULL;
}


int stack::top( void )
{
    if(!NULL) {
        return tail->data;
    }else cout<<"NULL"<<endl;
}

void stack::push ( int v )
{
  	slistEl * p;
  	p = new slistEl;
  	p->next = NULL;
  	p->data = v;

  	if( !tail ) tail = p;
  	else  {
  		p -> next = tail;
           tail = p;
  	}
}

void stack::pop ( void )
{
	slistEl * p;

  	if( tail )
  	{
        p = tail;
  		tail = tail->next;
        delete p;
      }
}

void stack::print()
{
	slistEl * p;

	if (tail) {
		p = tail;
if(tail) {
    p = tail;
    while( p ) {
        cout << p->data << " ";
        p = p->next;
    }
    cout<<endl;
}
else cout<<"Stos jest pusty"<<endl;
	}
}

int main( )
{
  	stack S;
  	int i, v;

  	srand ( time ( NULL ) );

  	for( i = 1; i <= 10; i++ )
  	{
       	v = rand( ) %  100;
     	S.push ( v );
  	}

  	S.print();
  	cout << "top: " << S.top() << endl;

  	for( i = 1; i <= 5; i++ ) {
  		S.pop();
  		S.pop();
  		S.print();
  		cout << "top: " << S.top() << endl;
  		v = rand( ) %  100;
     	S.push ( v );
  		S.print();
  		cout << "top: " << S.top() << endl;
	}

	for( i = 1; i <= 5; i++ ) {
  		S.pop();
  		S.print();
  		cout << "top: " << S.top() << endl;
	}

}
*/
//Zad.3.2.2
//Stos za pomocą tablicy

#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int N=10;

class stack
{
private:
    int T[N];
    int s_top, size;

public:
    stack( );
    ~stack( );
    bool empty ( void );
    int top ( void );
    void push ( int v );
    void pop ( void );
    void print ( void );
};

stack::stack( )
{
    s_top = -1;
    size = 0;
}

stack::~stack( )
{

}

bool stack::empty ( void )
{
    return s_top == 0;
}

int stack::top( void )
{
if(s_top >=0) {
    return T[s_top];

}
cout<<"NULL"<<endl;
}

void stack::push ( int v )
{
   if( size < N ) {
       s_top++;
       T[s_top] = v;
       size++;
   }
}

void stack::pop ( void )
{
   if( size > 0 ) {
s_top--;
size--;
   }
}

void stack::print()
{ if(s_top >=0) {
        for (int i = s_top; i >= 0; i--) {
            cout << T[i] << " ";
        }
        cout << endl;
    }
}




int main( )
{
    stack S;
    int i, v;

    srand ( time ( NULL ) );

    for( i = 1; i <= 10; i++ )
    {
        v = rand( ) %  100;
        S.push ( v );
    }

    S.print();
    cout << "top: " << S.top() << endl;

    for( i = 1; i <= 5; i++ ) {
        S.pop();
        S.pop();
        S.print();
        cout << "top: " << S.top() << endl;
        v = rand( ) %  100;
        S.push ( v );
        S.print();
        cout << "top: " << S.top() << endl;
    }

    for( i = 1; i <= 5; i++ ) {
        S.pop();
        S.print();
        cout << "top: " << S.top() << endl;
    }
}
