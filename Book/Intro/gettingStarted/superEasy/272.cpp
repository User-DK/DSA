#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define REP(i, a, b) for (int i = a; i <= b; i++)
const int MOD = 1e9 + 7;
using ull = unsigned long long;
using ld = long double;

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  // freopen("input.txt", "r", stdin);
  string input;
  string op = "";
  bool cur = 0;
  char c = '"';
  while (getline(cin,input))
  {
    for (int i = 0; i < input.length(); i++)
    {
      if (input[i] == c)
      {
        if (cur == 0)
        {
          op += "``";
          cur = 1;
        }
        else
        {
          op += "''";
          cur = 0;
        }
      }
      else
      {
        op += input[i];
      }
    }
    cout << op<<endl;
    op = "";
  }
  return 0;
}