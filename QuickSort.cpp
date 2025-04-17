#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int RandomArray(int tab[], int n) {
    srand(time(0));
    for (int i = 0; i < n; i++)
        tab[i] = rand() % 100;
    return 0;
}

int Print(int tab[], int n) {
    for (int i = 0; i < n; i++)
        cout << tab[i] << " ";
    cout << endl;
    return 0;
}

int QuickSort(int T[], int l, int p, int &k) {
    int i = l, j = p;
    int x = T[(l + p) / 2];

    do {
        while (T[i] < x) {
            i++;
            k++;
        }
        while (T[j] > x) {
            j--;
            k++;
        }
        if (i <= j) {
            swap(T[i], T[j]);
            i++;
            j--;
            k++;
        }
    } while (i <= j);

    if (l < j) QuickSort(T, l, j, k);
    if (i < p) QuickSort(T, i, p, k);

    return 0;
}
int QuickSortsquare(int T[], int l, int p, int &k) {
    int i = l, j = p;
    int x = T[p];

    do {
        while (T[i] < x) {
            i++;
            k++;
        }
        while (T[j] > x) {
            j--;
            k++;
        }
        if (i <= j) {
            swap(T[i], T[j]);
            i++;
            j--;
            k++;
        }
    } while (i <= j);

    if (l < j) QuickSortsquare(T, l, j, k);
    if (i < p) QuickSortsquare(T, i, p, k);

    return 0;
}

int main() {
    const int N = 100;
    int c = 0;
    int A[N];
    setlocale(LC_CTYPE, "Polish");

    RandomArray(A, N);
    cout << "Tablica na wejściu: " << endl;
    Print(A, N);

    QuickSort(A, 0, N - 1, c);
    cout << "Tablica posortowana: " << endl;
    Print(A, N);
    cout << "Ilosc porownan: " << c << endl;

    RandomArray(A, N);
    cout << "Tablica na wejściu: " << endl;
    Print(A, N);

    QuickSortsquare(A, 0, N - 1, c);
    cout << "Tablica posortowana: " << endl;
    Print(A, N);
    cout << "Ilosc porownan: " << c << endl;

    return 0;