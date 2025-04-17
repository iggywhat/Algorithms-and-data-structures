#include <iostream>
#include <vector>
#include <locale.h>
using namespace std;
int main(){
    setlocale(LC_CTYPE,"Polish");
    int n = 5;
    int m = 7;
    int matrix[n][m] = {
            {1,0,0,0,0,-1,0},
            {-1,1,0,0,-1,0,-1},
            {0,-1,1,0,0,0,1},
            {0,0,-1,-1,0,0,0},
            {0,0,0,1,1,1,0}
    };

    cout<<"   ";
    for(int i = 0; i < m; i++)
    {
        cout<<"e"<<i+1<<" ";
    }
    cout << endl;
    for(int i = 0; i < n; i++)
    {
        cout << "v" << i +1  << " ";
        for(int j = 0; j < m; j++)
        {
            cout << matrix[i][j] <<"  ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < n; ++i) {
        int a = 0;
        int b = 0;
        vector<int> nbs;

        for (int j = 0; j < m; ++j) {
            if (matrix[i][j] == 1) {
                a++;
                for (int x = 0; x < n; ++x) {
                    if (matrix[x][j] == -1) {
                        nbs.push_back(x);
                    }
                }
            } else if (matrix[i][j] == -1) {
                b++;
            }
        }
        cout << "Sąsiedzi v" << i+1 << ": ";
        for (int nb : nbs) {
            cout << nb + 1 << " ";
        }
        cout << endl;
        cout << "Stopień wychodzący v" << i+1 << ": " << a << endl;
        cout << "Stopień wchodzący v" << i+1 << ": " << b << endl;
        cout << endl;
    }
    return 0;
}