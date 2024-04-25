#include <bits/stdc++.h>
#include "../../include/Graph.hpp"
using namespace std;

void Graph::prims_mst(int V, int initial)
{
  priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
  vector<bool> inMST(V, 0);
  vector<int> parent(V, -1);
  int sum = 0;

  pq.push({0, initial});

  while (!pq.empty())
  {
    int w = pq.top().first;
    int v = pq.top().second;
    pq.pop();

    if (inMST[v] == true)
    {
      continue;
    }

    inMST[v] = true;
    sum += w;

    for (auto it : adj[v])
    {
      int currw = it.first;
      int currv = it.second;
      if (!inMST[currv])
      {
        pq.push({currw, currv});
        parent[currv] = v;
      }
    }
  }

  for (int i = 0; i < V; i++)
  {
    if (i == initial)
      continue;
    cout << parent[i] << " -- " << i << endl;
  }
  cout << "The Min Cost spanning tree: " << sum << endl;
}

int main()
{
  Graph g1(5);
  g1.addEdgeP(0, 1, 2);
  g1.addEdgeP(0, 3, 6);
  g1.addEdgeP(1, 2, 3);
  g1.addEdgeP(1, 3, 8);
  g1.addEdgeP(1, 4, 5);
  g1.addEdgeP(2, 4, 7);
  g1.prims_mst(5, 1);
}
