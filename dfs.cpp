#include <iostream>
using namespace std;

int adj[100][100];
int visited[100];
int n;

void dfs(int node) {
    visited[node] = 1;

    cout << node << " ";

    for (int i = 0; i < n; i++) {
        if (adj[node][i] == 1 && visited[i] == 0) {
            dfs(i);
        }
    }
}

int main() {
    int m;

    cin >> n >> m;


    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;

        adj[u][v] = 1;
        adj[v][u] = 1; // for undirected graph
    }

    int start;
    cin >> start;

    cout << "DFS Traversal: ";

    dfs(start);

    return 0;
}
