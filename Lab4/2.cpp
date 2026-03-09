#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int V;
    vector<vector<int>> adj; // adjacency list

    void dfs(int v, vector<int>& visited, int& count) {
        count++;
        visited[v] = count;
        
        cout << "Node: " << v << "   Visit order: " << count << endl;

        for (int w : adj[v]) {
            if (visited[w] == 0) {
                dfs(w, visited, count);
            }
        }
    }

public:
    Graph(int vertices) {
        V = vertices;
        adj.resize(V);
    }

    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    void DFS_G() {
        vector<int> visited(V, 0); 
        
        int count = 0; 

        for (int v = 0; v < V; v++) {
            if (visited[v] == 0) {
                dfs(v, visited, count);
            }
        }
    }
};

int main() {
    Graph g(5);

    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 3);
    g.addEdge(2, 4);

    cout << "Depth first search:" << endl;
    g.DFS_G();

    return 0;
}