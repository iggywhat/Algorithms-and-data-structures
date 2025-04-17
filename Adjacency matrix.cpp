#include <iostream>
#include <vector>
#include <locale.h>
using namespace std;
int main(){
    setlocale(LC_CTYPE,"Polish");
    int n = 5;
    int matrix [n][n] = {
            {0,1,1,1,1},
            {0,1,1,1,1},
            {0,1,1,1,1},
            {1,1,1,1,1},
            {1,1,1,1,1}
    };
    cout<<"   ";
    for(int i = 0; i < n; i++)
    {
        cout<<"v"<<i<<" ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "v" << i << " ";
        for(int j = 0; j < n; j++)
        {
            cout << matrix[i][j] <<"  ";
        }
        cout << endl;
    }
    cout << endl;
    for (int i = 0; i < n; ++i)
    {
        int a = 0;
        int b = 0;
        vector<int> nb;

        for (int j = 0; j < n; ++j) {
            if (matrix[i][j] == 1) {
                a++;
                nb.push_back(j);
            }
        }
        for (int j = 0; j < n; ++j) {
            if (matrix[j][i] == 1) {
                b++;
            }
        }
        cout << "Sąsiedzi " << i << ": ";
        for (int sasiad : nb) {
            cout << sasiad << " ";
        }
        cout << endl;
        cout << "Stopień wychodzący " << i << ": " << a << endl;
        cout << "Stopień wchodzący " << i << ": " << b << endl;
        cout << endl;
    }
    return 0;
}
