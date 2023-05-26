#include <bits/stdc++.h>
using namespace std;

vector<int> dijkstra(int source, vector<vector<pair<int, int>>> &graph)
{
    vector<bool> visited;
    vector<int> par;
    vector<int> distance;
    for (int i = 0; i < graph.size(); i++)
    {
        visited.push_back(false);
        par.push_back(-1);
        distance.push_back(INT_MAX);
    }
    set<pair<int, int>> s;
    s.insert({0, source});
    distance[source] = 0;
    while (s.size() > 0)
    {
        pair<int, int> node = *s.begin();
        int dist = node.first;
        int v = node.second;
        s.erase(s.begin());
        if (visited[v])
        {
            continue;
        }
        visited[v] = true;
        for (auto child : graph[v])
        {
            int child_v = child.first;
            int wt = child.second;
            if (distance[v] + wt < distance[child_v])
            {
                par[child_v] = v;
                distance[child_v] = distance[v] + wt;
                s.insert({distance[child_v], child_v});
            }
        }
    }
    for (int i = 0; i < distance.size(); i++)
    {
        cout << "Node: " << i << ", Distance: " << distance[i] << "\n";
    }
    return par;
}

int main()
{
    int v, e;
    cout << "-----------ASSIGNMENT 3-----------\n";
    // cout << "Enter number of vertices of graph: ";
    cin >> v;
    vector<bool> visited;
    vector<vector<pair<int, int>>> graph;
    vector<pair<int, int>> blank;
    for (int i = 0; i < v; i++)
    {
        visited.push_back(false);
        graph.push_back(blank);
    }
    // cout << "Enter number of edges in graph: ";
    cin >> e;
    int src, des, wt;
    for (int i = 0; i < e; i++)
    {
        // cout << "Enter the edge number " << i + 1 << " (src & des) and weight:";
        cin >> src >> des >> wt;
        graph[src].push_back({des, wt});
        graph[des].push_back({src, wt});
    }
    vector<int> ve = dijkstra(0, graph);
    int i = 0;
    for (auto x : ve)
    {
        cout << x << " : " << i << endl;
        i++;
    }
    return 0;
}

// 9 14
// 0 1 4
// 0 7 8
// 7 6 1
// 1 7 11
// 1 2 8
// 2 8 2
// 7 8 7
// 8 6 6
// 6 5 2
// 2 5 4
// 2 3 7
// 3 4 9
// 3 5 14
// 5 4 10