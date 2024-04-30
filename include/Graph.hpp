#include <bits/stdc++.h>
using namespace std;

class Graph
{
  vector<vector<int>> edgeList;
  vector<vector<pair<int, int>>> adj;

public:
  Graph() {}

  Graph(int V)
  {
    adj.resize(V);
  }

  void addEdgeK(int x, int y, int w)
  {
    edgeList.push_back({w, x, y});
  }

  void addEdgeP(int x, int y, int w)
  {
    adj[x].push_back({w, y});
    adj[y].push_back({w, x});
  }

  void kruskals_mst(int V);
  void prims_mst(int V, int initial);
};