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

unordered_map<int, int> memo;

int collatz(int n)
{
  if (memo.find(n) != memo.end()) 
    return memo[n];

  int length = 1;
  ll num = n;
  while (num != 1)
  {
    if (num % 2 == 0)
      num /= 2;
    else
      num = 3 * num + 1;
    length++;

    if (memo.find(num) != memo.end())
    {
      length += memo[num] - 1;
      break;
    }
  }
  memo[n] = length; 
  return length;
}

int main()
{
  ios::sync_with_stdio(0);
  cin.tie(0);
  int i, j;
  freopen("input.txt", "r", stdin);
  while (cin >> i >> j)
  {
    int maxim = 0;
    for (int k = min(i, j); k <= max(i, j); k++)
    {
      maxim = max(maxim, collatz(k));
    }
    cout << i << " " << j << " " << maxim << endl;
  }

  return 0;
}
