#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

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

int SelectSort(int tab[], int n){
for(int i = 0; i < n - 1; i++){
    int min = tab[i];
    int k = i;
    for(int j = i + 1; j < n; j++){
        if(tab[j] < min){
            min = tab[j];
            k = j;
        }
        if(tab[k] < tab[i]){
            swap(tab[i], tab[k]);
        }
    }
}
return 0;
}
int Compare(int n){
    int k = 0;
    for(int i = 0; i < n - 1; i++){
        for (int j = 0; j < n / 2; ++j) {
            k++;
        }
        }
    int theorethicalcomp = k;
    cout<<"Liczba porownan z dzialania algorytmu: "<<theorethicalcomp;
    cout<<endl;
    cout<<"Ilosc porownan ze wzoru: "<<(n * (n - 1)) / 2;;
    cout<<endl;
    return theorethicalcomp;
    }

int main ( ) {
    const int N = 50;
    int T[N];

    RandomArray(T, N);
    cout<<"Tablica przed sortowaniem:"<<endl;
    Print(T, N);
    Compare(N);
    SelectSort(T, N);
    cout<<"Tablica posortowana:"<<endl;
    Print(T, N);

    const int K = 100;
    int B[K];

    RandomArray(B, K);
    cout<<"Tablica przed sortowaniem:"<<endl;
    Print(B, K);
    Compare(K);
    SelectSort(B, K);
    cout<<"Tablica posortowana:"<<endl;
    Print(B, K);

    const int G = 200;
    int A[G];

    RandomArray(A, G);
    cout<<"Tablica przed sortowaniem:"<<endl;
    Print(A, G);
    Compare(G);
    SelectSort(A, G);
    cout<<"Tablica posortowana:"<<endl;
    Print(A, G);
}