#include<bits/stdc++.h>
using namespace std;

void addEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void printGraph(vector<int> adjList[], int vertex)
{
    for(int i = 0; i < vertex; i++)
    {
        for(int j = 0; j < adjList[i].size(); j++)
            cout << adjList[i][j] << " ";
        cout << endl;
    }
}
int main()
{
    int vertex = 4;
    vector<int> adjList[vertex];
    addEdge(adjList, 0, 1);
    addEdge(adjList, 1, 0);
    addEdge(adjList, 0, 2);
    addEdge(adjList, 2, 0);
    addEdge(adjList, 0, 3);
    addEdge(adjList, 3, 0);
    addEdge(adjList, 2, 4);
    addEdge(adjList, 4, 2);
    return 0;
}