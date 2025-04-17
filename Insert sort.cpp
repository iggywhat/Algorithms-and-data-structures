#include <iostream>
#include <cstdlib>
#include <ctime>
#include <ctime>

using namespace std ;

int RandomArray(int tab[], int n){
	srand(time(0));
	for (int i=0; i < n; i++)
	tab[i] = rand() % 100;
	return 0;
}


int Print(int tab[], int n){
	for (int i=0; i < n; i++)
	cout<<tab[i]<<" ";
	cout<<endl;
	return 0;
}

int InsertSort(int tab[], int n, int compare){

    for (int i=1; i < n; i++){
            int x = tab[i];
            int j = i - 1;
            while (j >= 0 && tab[j] > x){
                compare++;
                tab[j + 1] = tab[j];
                j--;
            }
            tab[j + 1] = x;
            if(j >= 0){
                compare++;
            }

    }
    cout<<"Ilosc porownan: "<<compare<<endl;

    return 0;}
int PlusArray(int tab[], int n){
    for (int i = 0; i < n; i++)
        tab[i] = i;
    return 0;
}

int MinusArray(int tab[], int n){
    for (int i = 0; i < n; i++)
        tab[i] = n - i;
    return 0;
}

int main ( ) {
    int compare = 0;
const int N=100;
int A[N];

	setlocale(LC_CTYPE, "Polish");

	cout<<"LOSOWA"<<endl;
	RandomArray(A, N);
	cout<<"Tablica przed posortowaniem:"<<endl;
	Print(A, N);
	cout<<endl;
	InsertSort(A, N, compare);
	cout<<"Tablica po posortowaniu:"<<endl;
	Print(A, N);
	cout<<endl;

    const int B=100;
    int C[B];

    setlocale(LC_CTYPE, "Polish");

    cout<<"Rosnaca"<<endl;
    PlusArray(C, B);
    cout<<"Tablica przed posortowaniem:"<<endl;
    Print(C, B);
    cout<<endl;
    InsertSort(C, B, compare);
    cout<<"Tablica po posortowaniu:"<<endl;
    Print(C, B);
    cout<<endl;

    const int D=100;
    int E[D];

    setlocale(LC_CTYPE, "Polish");

    cout<<"Malejaca"<<endl;
    MinusArray(E, D);
    cout<<"Tablica przed posortowaniem:"<<endl;
    Print(E, D);
    cout<<endl;
    InsertSort(E, D, compare);
    cout<<"Tablica po posortowaniu:"<<endl;
    Print(E, D);
    cout<<endl;
return 0;

}
