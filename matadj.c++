#include <iostream>
using namespace std;

class Matrix
{
private:
    int nodes;
    int **adj;

public:
    Matrix(int nodes)
    {
        this->nodes = nodes;

        adj = new int *[nodes];

        for (int i = 0; i < nodes; i++)
        {
            adj[i] = new int[nodes];
            for (int j = 0; j < nodes; j++)
            {
                adj[i][j] = 0;
            }
        }
        display();
    }

    void addEdge(int origin, int destination, int weight)
    {
        if (origin > nodes || origin <= 0 || destination > nodes || destination <= 0)
        {
            cout << "Invalid edge!" << endl;
            return;
        }
        else
        {
            adj[origin - 1][destination - 1] = weight;
        }
    }

    void removeEdge(int origin, int destination)
    {
        if (origin > nodes || origin <= 0 || destination > nodes || destination <= 0)
        {
            cout << "Invalid edge!" << endl;
            return;
        }
        else
        {
            adj[origin - 1][destination - 1] = 0;
        }
    }

    void display()
    {
        for (int i = 0; i < nodes; i++)
        {
            for (int j = 0; j < nodes; j++)
            {
                cout << adj[i][j] << " ";
                ;
            }
            cout << endl;
        }
    }
};

int main()
{
    int nodes, max, origin, destination, edge_weight;
    cout << "Enter number of nodes: ";
    cin >> nodes;

    Matrix matrix(nodes);
    max = nodes * nodes;

    for (int i = 0; i < max; i++)
    {
        cout << "Edge: " << i + 1 << endl;
        cout << "Enter edge (-1, -1) to exit" << endl;
        cout << "Enter origin, destination and it's weight: " << endl;
        cin >> origin >> destination >> edge_weight;
        if (origin == -1 || destination == -1)
        {
            break;
        }
        else
        {
            matrix.addEdge(origin, destination, edge_weight);
        }
    }
    matrix.display();
    return 0;
}