#include <iostream>
#include <stack>
#include <queue>
using namespace std;

class Graph {
private:
    int n; // Number of vertices (houses)
    int e; // Number of edges (lanes)
    int adjMat[20][20]; // For adjacency matrix

public:
    Graph() {
        n = 0;
        e = 0;
        for (int i = 0; i < 20; i++) {
            for (int j = 0; j < 20; j++) {
                adjMat[i][j] = 0;
            }
        }
    }

    void createUsingAdjMat() {
        cout << "Enter Number of Vertices: ";
        cin >> n;

        cout << "Enter Number of Edges: ";
        cin >> e;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                adjMat[i][j] = 0;
            }
        }

        for (int i = 0; i < e; i++) {
            cout << "Enter edges that connect vertices " << i + 1 << ": ";
            int src, dest;
            cin >> src >> dest;
            adjMat[src][dest] = 1;
            adjMat[dest][src] = 1;
        }
    }

    void displayAdjMat() {
        cout << "Adjacency matrix is:\n";
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                cout << adjMat[i][j] << " ";
            }
            cout << endl;
        }
    }

    void dfs(int start) {
        int visited[n + 1] = {0};
        stack<int> s;
        s.push(start);
        visited[start] = 1;
        cout << "DFS Traversal is: ";

        while (!s.empty()) {
            int ele = s.top();
            s.pop();
            cout << ele << " ";

            for (int i = 1; i <= n; i++) {
                if (adjMat[ele][i] == 1 && visited[i] == 0) {
                    s.push(i);
                    visited[i] = 1;
                }
            }
        }
        cout << endl;
    }

    void bfs(int start) {
        queue<int> q;
        int visited[n + 1] = {0};
        q.push(start);
        visited[start] = 1;
        cout << "BFS Traversal is: " << start << " ";

        while (!q.empty()) {
            int val = q.front();
            q.pop();
            for (int i = 1; i <= n; i++) {
                if (adjMat[val][i] == 1 && visited[i] == 0) {
                    q.push(i);
                    visited[i] = 1;
                    cout << i << " ";
                }
            }
        }
        cout << endl;
    }
};

int main() {
    Graph g;
    cout << "Enter Graph details:\n";
    g.createUsingAdjMat();
    g.displayAdjMat();
    cout << "Enter Starting Vertex for DFS: ";
    int dfsStart;
    cin >> dfsStart;
    g.dfs(dfsStart);
    cout << "Enter Starting Vertex for BFS: ";
    int bfsStart;
    cin >> bfsStart;
    g.bfs(bfsStart);
    return 0;
}

