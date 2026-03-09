#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    int numNodes = 6;
    
    vector<vector<int>> graph(numNodes);

    graph[0].push_back(1);
    graph[0].push_back(2);
    
    graph[1].push_back(3);
    graph[1].push_back(4);
    
    graph[2].push_back(4);
    
    graph[3].push_back(5);
    graph[4].push_back(5);

    vector<bool> visited(numNodes, false); 
    
    queue<int> q; 

    int startNode = 0;

    visited[startNode] = true;
    
    q.push(startNode);

    cout << "Breadth-first search from node " << startNode << ":" << endl;

    while (q.empty() == false) {
        
        int currentNode = q.front(); 
        
        q.pop(); 

        cout << "Visiting node: " << currentNode << endl;

        for (int i = 0; i < graph[currentNode].size(); i++) {
            
            int neighbor = graph[currentNode][i];

            if (visited[neighbor] == false) {
                
                visited[neighbor] = true; 
                
                q.push(neighbor);         
            }
        }
    }

    return 0;
}