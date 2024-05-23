#include <iostream>
#include <vector>
#include <stack>
#include <map>
using namespace std;

class Graph
{
public:
    map<int, bool> visited;
    map<int, vector<int>> adj;

    void addEdge(int v, int w);
    void DFS(int v);
};

void Graph::addEdge(int v, int w)
{
    adj[v].push_back(w);
}

void Graph::DFS(int v)
{
    stack<int> stack;
    visited[v] = true;
    stack.push(v);

    while (!stack.empty())
    {
        v = stack.top();
        stack.pop();
        cout << v << " ";

        for (auto i : adj[v])
        {
            if (!visited[i])
            {
                visited[i] = true;
                stack.push(i);
            }
        }
    }
}

int main()
{
    Graph g;
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);

    cout << "DFS Traversal starting from vertex 2: \n";
    g.DFS(2);

    return 0;
}
