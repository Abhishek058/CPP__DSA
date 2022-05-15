#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

class Graph
{
public:
    unordered_map<int, list<int>> adj;

    void addEdge(int u, int v, bool direction)
    {
        // direction = 0 -> undirected graph
        // direction = 1 -> directed graph

        // create an edge from u to v
        adj[u].push_back(v);

        if (direction == 0)
        {
            adj[v].push_back(u);
        }
    }
    void printList()
    {
        for (auto i : adj)
        {
            cout << i.first << "-> ";
            for (auto j : i.second)
            {
                cout << j << ", ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int n;
    cout<<"Enter the number of node: "<<endl;
    cin>>n;

    int m;
    cout<<"Enter the number of edge: "<<endl;
    cin>>m;

    Graph g;
    for(int i=0; i<m; i++){
        int u, v;
        cin>>u>>v;
        //creating an undirected graph
        g.addEdge(u, v, 0);
    }

    g.printList();
    return 0;
}