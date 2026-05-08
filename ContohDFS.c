// Referensi
// https://www.geeksforgeeks.org/dsa/depth-first-search-or-dfs-for-a-graph/

#include <stdio.h>

#define V 5

void dfsRec(int adj[V][V], int visited[V], int s, int res[V], int *idx) {
    visited[s] = 1;
    res[(*idx)++] = s;

    // Recursively visit all adjacent vertices
    // that are not visited yet
    for (int i = 0; i < V; i++) {
        if (adj[s][i] && visited[i] == 0)
            dfsRec(adj, visited, i, res, idx);
    }
}

void dfs(int adj[V][V], int res[V]) {
    int visited[V] = {0};
    int idx = 0;
    dfsRec(adj, visited, 0, res, &idx);
}

void addEdge(int adj[V][V], int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;  // undirected
}

int main() {
    int adj[V][V] = {0};

    
    // creating adjacency list
    addEdge(adj, 1, 2);
    addEdge(adj, 1, 0);
    addEdge(adj, 2, 0);
    addEdge(adj, 2, 3);
    addEdge(adj, 2, 4);

    int res[V];
    
    // Perform DFS starting from the source vertex 0
    dfs(adj, res);

    for (int i = 0; i < V; i++)
        printf("%d ", res[i]);

    return 0;
}
