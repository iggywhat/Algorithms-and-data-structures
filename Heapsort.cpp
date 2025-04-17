#include <iostream>
#include <iomanip>
#include <ctime>
#include <cstdlib>
#include <cmath>

using namespace std;

const int MAX = 2147483647;

int counterBuild = 0;
int counterExtract = 0;

int losowa(int tab[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 100;
    return 0;
}

int rosnaca(int tab[], int n) {
    for (int i = 0; i < n; i++)
        tab[i] = i + 1;
    return 0;
}

int drukuj(int tab[], int n) {
    for (int i = 0; i < n; i++) {
        cout << tab[i] << " ";
        if ((i + 1) % 35 == 0) cout << endl;
    }
    cout << endl;
    return 0;
}

int StackSort(int tab[], int n) {
    int i, j, left, older;

    for (i = 2; i <= n; i++) {
        j = i;
        int k = j / 2;
        while (k >= 1 && ++counterBuild && tab[k - 1] < tab[j - 1]) {
            swap(tab[j - 1], tab[k - 1]);
            j = k;
            k = j / 2;
        }
    }

    cout << "Kopiec przed rozbiorka:" << endl;
    drukuj(tab, n);

    for (i = n; i > 1; i--) {
        swap(tab[i - 1], tab[0]);
        j = 1;
        left = 2;

        while (left < i) {
            if (left + 1 < i && ++counterExtract && tab[left] > tab[left - 1]) {
                older = left + 1;
            } else {
                older = left;
            }
            if (++counterExtract && tab[older - 1] <= tab[j - 1]) break;
            swap(tab[j - 1], tab[older - 1]);
            j = older;
            left = 2 * j;
        }
    }
    return 0;
}

int main() {
    const int N = 100;
    int A[N];

    setlocale(LC_CTYPE, "Polish");

    cout << "ROSNACA" << endl;
    rosnaca(A, N);
    cout << "Tablica przed posortowaniem:" << endl;
    drukuj(A, N);
    cout << endl;
    StackSort(A, N);
    cout<<endl;
    cout << "Liczba porownan budowanie kopca: " << counterBuild << endl;
    cout<<endl;
    cout << "Liczba porownan rozbior kopca: " << counterExtract << endl;
    cout<<endl;
    cout << "Calkowita liczba porównań: " << counterBuild + counterExtract << endl;
    cout<<endl;
    cout << "Tablica po posortowaniu:" << endl;
    drukuj(A, N);
    cout << endl;

    return 0;
}