#include <iostream>

#include <cstdlib>

#include <ctime>

#include <locale.h>

using namespace std;

struct Node
{
    Node * next;
    int data;
};


void insert_front (Node * &head, int data )
{
    Node * p = new Node;

    p->data = data;

    p->next = head;

    head = p;
}

void delete_p (Node * &head, Node *p)
{

    Node * prev = NULL;

    if(head==p){

        head=head->next;


        delete p;

}else
{

prev=head;

while(prev->next!=p)
    prev=prev->next;

prev->next=p->next;

delete p;
}
}

Node * find( Node * p, int data ){

    while(p){
        if(p->data==data)
            return p;
        p=p->next;
    }
return NULL;
}

int size( Node * p )
{
    int size = 0;

while(p){
    size++;
    p=p->next;
}

    cout << "Liczba elementow listy: " << size << endl;
    return 0;
}

void print ( Node * head )
{
    int i = 0;
    Node * p = head;
while(p){
    cout << ++i << ": " << p->data << endl;
    p=p->next;
}

    cout << endl;
}

int main ()
{
    Node * L, *p;
    int i, data;

    L=NULL;

    setlocale(LC_CTYPE, "Polish");

srand(time(NULL));
for(i=0;i<20;i++) {
    insert_front(L, rand() % 100);

}
    print(L);
cout<<"Wprowadz element do usunecia: ";
cin>>data;
cout<<endl;

p=find(L,data);
if(p!=NULL) delete_p(L,p);
else
    cout<<"Nie znaleziono elementu"<<endl;
    size(L);
    print(L);
    return 0;

}