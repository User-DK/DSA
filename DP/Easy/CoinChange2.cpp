#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> dp;

// memoization
int countCombinations(vector<int> &coins, int sum, int index)
{
  if (sum < 0 || index < 0)
  {
    return 0;
  }
  if (sum == 0)
  {
    return dp[index][sum] = 1;
  }
  if (dp[index][sum] != -1)
  {
    return dp[index][sum];
  }
  dp[index][sum] = countCombinations(coins, sum - coins[index], index) + countCombinations(coins, sum, index - 1);
  return dp[index][sum];
}

// tabulation
// int countCombinations(vector<int> &coins, int sum)
// {
//   int n = coins.size();
//   dp[0][0] = 1;
//   for (int i = 1; i <= n; i++)
//   {
//     for (int j = 0; j <= sum; j++)
//     {
//       dp[i][j] += dp[i - 1][j];

//       if (j - coins[i - 1] >= 0)
//       {
//         dp[i][j] += dp[i][j - coins[i - 1]];
//       }
//     }
//   }

//   return dp[n][sum];
// }

// tabulation space optimised
int countCombinations(vector<int> &coins, int sum)
{
  vector<int> dp1(sum + 1, 0);
  int n = coins.size();
  dp1[0] = 1;
  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j <= sum; j++)
    {
      dp1[j] += dp1[j - coins[i]];
    }
  }
  return dp1[sum];
}

int main()
{
  int sum, n;
  cout << "Enter the size of the coins array: ";
  cin >> n;
  vector<int> coins(n);
  cout << "Enter the array elements: ";
  for (int i = 0; i < n; i++)
  {
    cin >> coins[i];
  }
  cout << "Enter the sum: ";
  cin >> sum;
  // using memo
  dp.resize(n + 1, vector<int>(sum + 1, -1));
  // int ans = countCombinations(coins, sum, n - 1);
  // cout << "The count is using memoization: " << ans;

  // using tabulation
  int ans = countCombinations(coins, sum, n - 1);
  cout << "The count is using tabulation: " << ans;
}