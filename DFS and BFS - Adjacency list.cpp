#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int MAXINT = 2147483647;

int n;

struct slistEl {
    slistEl* next;
    int data;
};

slistEl** A; 
bool* visited;

class queue {
private:
    slistEl* head;
    slistEl* tail;

public:
    queue();
    ~queue();
    bool empty(void);
    int front(void);
    void push(int v);
    void pop(void);
};

queue::queue() {
    head = tail = NULL;
}

queue::~queue() {
    while (head) pop();
}

bool queue::empty(void) {
    return !head;
}

int queue::front(void) {
    if (head) return head->data;
    else return MAXINT;
}

void queue::push(int v) {
    slistEl* p = new slistEl;
    p->next = NULL;
    p->data = v;
    if (tail) tail->next = p;
    else head = p;
    tail = p;
}

void queue::pop(void) {
    if (head) {
        slistEl* p = head;
        head = head->next;
        if (!head) tail = NULL;
        delete p;
    }
}

void DFS(int v) {
    slistEl* p;
    visited[v] = true;
    cout << v << " ";
    p = A[v];
    while (p) {
        if (!visited[p->data])
            DFS(p->data);
        p = p->next;
    }
}

void BFS(int v) {
    queue Q;
    slistEl* p;

    visited[v] = true;
    cout << v << " ";
    Q.push(v);
    while (!Q.empty()) {
        v = Q.front();
        Q.pop();
        p = A[v];
        while (p) {
            if (!visited[p->data]) {
                visited[p->data] = true;
                cout << p->data << " ";
                Q.push(p->data);
            }
            p = p->next;
        }
    }
}

void resetVisited(int n) {
    for (int i = 0; i < n; i++)
        visited[i] = false;
}

void initializeGraph(int n, int m, int E[][2]) {
    slistEl* p;
    for (int i = 0; i < n; i++) {
        A[i] = NULL;
    }
    for (int i = 0; i < m; i++) {
        int vs = E[i][0];
        int ve = E[i][1];

        p = new slistEl;
        p->data = ve;
        p->next = A[vs];
        A[vs] = p;
    }
}

void printGraph(int n) {
    slistEl* p;
    for (int i = 0; i < n; i++) {
        cout << "A[" << i << "] =";
        p = A[i];
        while (p) {
            cout << setw(3) << p->data;
            p = p->next;
        }
        cout << endl;
    }
}

int main() {
    int i;

    setlocale(LC_CTYPE, "Polish");

    const int n = 4;
    const int m1 = 8;
    const int m2 = 7;

    int E1[m1][2] = { {0, 3}, {0, 1}, {1, 2}, {1, 0}, {2, 3}, {2, 1}, {3, 2}, {3, 0} };

    int E2[m2][2] = { {0, 1}, {0, 2}, {1, 3}, {2, 3}, {2, 1}, {3, 1}, {3, 2}};

    A = new slistEl * [n];
    visited = new bool[n];

    cout << "Graf z zadania:" << endl;
    initializeGraph(n, m1, E1);
    printGraph(n);

    cout << "Przejście grafu w głąb - DFS(0):" << endl;
    DFS(0);
    cout << endl;

    resetVisited(n);

    cout << "Przejście grafu wszerz - BFS(0):" << endl;
    BFS(0);
    cout << endl;

    cout << "- - - - - - - - - - - - - - - - - - -" << endl;

    cout << "Mój graf:" << endl;
    initializeGraph(n, m2, E2);
    printGraph(n);
    resetVisited(n);
    cout << "Przejście grafu w głąb - DFS(0):" << endl;
    DFS(0);

    cout << endl;

    resetVisited(n);

    cout << "Przejście grafu wszerz - BFS(0):" << endl;
    BFS(0);
    cout << endl;

    return 0;
}