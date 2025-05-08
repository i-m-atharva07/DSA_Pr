#include<iostream>
#include<string>
using namespace std;

const int MAX = 10;

class Queue {
    int front, rear;
    int data[MAX];

public:
    Queue() {
        front = rear = -1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int val) {
        if (rear == MAX - 1)
            cout << "Queue is full\n";
        else {
            if (front == -1) front = 0;
            data[++rear] = val;
        }
    }

    int dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty\n";
            return -1;
        } else {
            return data[front++];
        }
    }
};

void DFS(int v, int visited[], int adj[][MAX], int n, string names[]){
    cout<<names[v]<<" ";
    visited[v] = 1;
    for(int i = 0; i<n; i++){
        if(adj[v][i] == 1 &&  visited[i] == 0){
            DFS(i, visited, adj, n, names);
        }
    }
}

void BFS(int start, int adj[][MAX], int n, string names[]){
    int visited[MAX] = {0};
    Queue q;
    q.enqueue(start);
    visited[start] = 1;
    cout<<"BFS Traversal is: ";
    while (!q.isEmpty()){
        int j = q.dequeue();
        cout<<names[j]<<" ";
        for(int k = 0; k<n; k++){
            if(adj[j][k] == 1 && visited[k] == 0){
                visited[k] = 1;
                q.enqueue(k);
            }
        }
    }
}

int main(){
    int n, e;
    cout<<"Enter no. of landmarks: ";
    cin>>n;
    int adj[MAX][MAX] = {0};
    string names[MAX];
    cout<<"\n Enter names of landmarks:"<<endl;
    
    for(int i = 0; i<n; i++){
        cout<<"Name: ";
        cin>>names[i];
    }

    cout<<"Enter no. of paths: ";
    cin>>e;

    cout<<"Enter each edge as pair of indices (0 to "<<n-1<<"):"<<endl;
    for (int i = 0; i < e; i++){
        int u, v;
        cin >> u >> v;
        adj[u][v] = adj[v][u] = 1;
    }
    int visited[MAX] = {0};
    cout<<"DFS traversal: ";
    DFS(0, visited, adj, n, names);
    cout<<endl;

    BFS(0, adj, n, names);
}
