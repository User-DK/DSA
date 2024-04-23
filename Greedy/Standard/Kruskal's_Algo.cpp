#include <bits/stdc++.h>
#include "../../include/DisjointUnionSet.hpp"
#include "../../include/Graph.hpp"
using namespace std;

void Graph::kruskals_mst(int V)
{
  sort(edgeList.begin(), edgeList.end());

  DSU set(V);
  int ans = 0;
  cout << "Following are the edges constructed in the MST:" << endl;

  for (auto it : edgeList)
  {
    int w = it[0];
    int x = it[1];
    int y = it[2];

    if (set.find_U(x) != set.find_U(y))
    {
      set.unite(x, y);
      ans += w;
      cout << x << " -- " << y << " == " << w << endl;
    }
  }
  cout << "Min cost Spanning tree: " << ans;
}

int main()
{
  Graph g;
  g.addEdge(0, 1, 10);
  g.addEdge(1, 3, 15);
  g.addEdge(2, 3, 4);
  g.addEdge(2, 0, 6);
  g.addEdge(0, 3, 5);
  g.kruskals_mst(4);
  return 0;
}