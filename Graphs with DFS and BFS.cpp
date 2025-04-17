#include <iostream>
#include <iomanip>
#include <locale.h>

using namespace std;

const int MAXINT = 2147483647;

const int N = 10;

bool visited[N] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

int A[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 1, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 1, 0},
        {0, 1, 0, 1, 0, 0, 1, 0, 1, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 0, 0, 0, 1, 0}
};

int B[N][N] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 0, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 1, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 1, 1, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
        {0, 0, 0, 0, 0, 0, 0, 1, 1, 0}
};

struct slistEl {
    slistEl *next;
    int data;
};

class queue {
private:
    slistEl *head;
    slistEl *tail;

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
    slistEl *p = new slistEl;
    p->next = NULL;
    p->data = v;
    if (tail) tail->next = p;
    else head = p;
    tail = p;
}

void queue::pop(void) {
    if (head) {
        slistEl *p = head;
        head = head->next;
        if (!head) tail = NULL;
        delete p;
    }
}

void DFS(int v, int graph[N][N]) {
    visited[v] = true;
    cout << v << " ";
    for (int i = 0; i < N; i++)
        if (graph[v][i] && !visited[i])
            DFS(i, graph);
}

void BFS(int v, int graph[N][N]) {
    queue Q;
    Q.push(v);
    visited[v] = true;
    while (!Q.empty()) {
        v = Q.front();
        cout << v << " ";
        Q.pop();
        for (int i = 0; i < N; i++)
            if (graph[v][i] && !visited[i]) {
                Q.push(i);
                visited[i] = true;
            }
    }
}

int main() {
    int i;
    cout << "Graf z zadania: " << endl;
    setlocale(LC_CTYPE, "Polish");

    cout << "Przejście grafu w głąb - DFS(1):" << endl;
    DFS(1, A);
    cout << endl;

    for (i = 0; i < N; i++)
        visited[i] = false;

    cout << "Przejście grafu wszerz - BFS(1):" << endl;
    BFS(1, A);
    cout << endl;
    cout << "- - - - - - - - - - - - - - - - - - -" << endl;
    cout << "Moj graf: " << endl;
    for (i = 0; i < N; i++)
        visited[i] = false;

    cout << "Przejscie grafu w glab - DFS(1):" << endl;
    DFS(1, B);
    cout << endl;

    for (i = 0; i < N; i++)
        visited[i] = false;

    cout << "Przejscie grafu wszerz - BFS(1):" << endl;
    BFS(1, B);
    cout << endl;
    return 0;
}