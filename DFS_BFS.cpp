#include <bits/stdc++.h>
using namespace std;

void dfs(vector<vector<int>> &graph, vector<bool> &visited, int i)
{
    if (visited[i])
    {
        return;
    }
    visited[i] = true;
    cout << i + 1 << " ";
    for (auto x : graph[i])
    {
        if (!visited[x])
        {
            dfs(graph, visited, x);
        }
    }
}

void bfs(vector<vector<int>> &graph, vector<bool> &visited, int i)
{
    queue<int> q;
    q.push(i);
    visited[i] = true;
    while (!q.empty())
    {
        int c = q.front();
        q.pop();
        cout << c + 1 << " ";
        visited[c] = true;
        for (auto x : graph[c])
        {
            if (!visited[x])
            {
                q.push(x);
            }
        }
    }
}

int main()
{
    int v, e;
    cout << "-----------ASSIGNMENT 1-----------\n";
    cout << "Enter number of vertices of graph: ";
    cin >> v;
    vector<bool> visited;
    vector<vector<int>> graph;
    vector<int> blank;
    for (int i = 0; i < v; i++)
    {
        visited.push_back(false);
        graph.push_back(blank);
    }
    cout << "Enter number of edges in graph: ";
    cin >> e;
    int src, des;
    for (int i = 0; i < e; i++)
    {
        cout << "Enter the edge number " << i + 1 << " (src & des):";
        cin >> src >> des;
        graph[src - 1].push_back(des - 1);
        graph[des - 1].push_back(src - 1);
    }
    cout << "DFS of given undirected graph from vertex 1 is: ";
    dfs(graph, visited, 0);
    cout << "\n";
    for (int i = 0; i < v; i++)
    {
        visited[i] = false;
    }
    cout << "BFS of given undirected graph from vertex 1 is: ";
    bfs(graph, visited, 0);
    cout << "\n";
    return 0;
}