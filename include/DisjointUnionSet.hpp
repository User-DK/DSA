#include <bits/stdc++.h>
using namespace std;

class DSU
{
  vector<int> rank;
  vector<int> parent;

public:
  DSU(int n)
  {
    rank = vector<int>(n + 1, 0);
    parent = vector<int>(n + 1);
    for (int i = 0; i <= n; i++)
    {
      parent[i] = i;
    }
  }

  int find_U(int v)
  {
    if (parent[v] == v)
    {
      return v;
    }
    return parent[v] = find_U(parent[v]);
  }

  void unite(int u, int v)
  {
    int ulPu = find_U(u);
    int ulPv = find_U(v);
    if (ulPu == ulPv)
    {
      return;
    }
    if (rank[ulPv] < rank[ulPu])
    {
      parent[ulPv] = ulPu;
    }

    else if (rank[ulPv] > rank[ulPu])
    {
      parent[ulPu] = ulPv;
    }

    else
    {
      parent[ulPu] = ulPv;
      rank[ulPv]++;
    }
  }
};
