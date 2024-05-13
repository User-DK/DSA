// can be optimised using 1d array and for looop see link: https://www.geeksforgeeks.org/binomial-coefficient-dp-9/
// may approaches look the above link can be also solved with gcd and sievves and modular inversion technique

#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

// not space optimised
vector<vector<int>> dp;
int calculateCoefficient(int k, int n)
{
  if (k > n)
  {
    return 0;
  }
  if (k == 0 || k == n)
  {
    dp[n][k] = 1;
    return dp[n][k];
  }
  if (dp[n][k] != -1)
  {
    return dp[n][k];
  }
  dp[n][k] = calculateCoefficient(k - 1, n - 1) + calculateCoefficient(k, n - 1);
  return dp[n][k];
}

int binomialCoeff(int k, int n)
{
  int c[k + 1];
  memset(c, 0, sizeof(c));

  c[0] = 1;

  for (int i = 1; i <= n; i++)
  {
    for (int j = min(k, i); j > 0; j--)
    {
      c[j] = c[j] + c[j - 1];
    }
  }
  return c[k];
}

// using Formula time complexity k and space complexity constant
int usingFormula(int k, int n)
{
  if (k > n || k < 0)
  {
    cout << "invalid";
    return 0;
  }
  if (k == 0 || k == n)
  {
    cout << 1;
  }
  int result = 1;
  int factk = 1;
  for (int i = 0; i < k; i++)
  {
    result *= (n - i);
    factk *= (i + 1);
  }

  cout << result / factk;
  return result/factk;
}

int main()
{
  int n, k;
  cout << "Enter n: ";
  cin >> n;
  cout << "Enter k: ";
  cin >> k;
  int ans = binomialCoeff(k, n);
  cout << "Answer: " << ans;
  return 0;
}