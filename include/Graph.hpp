#include <bits/stdc++.h>
using namespace std;

class Graph
{
  vector<vector<int>> edgeList;

public:
  Graph() {}
  void addEdge(int x, int y, int w)
  {
    edgeList.push_back({w, x, y});
  }

  void kruskals_mst(int V);
  void prims_mst(int V);
};