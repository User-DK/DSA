// https://www.geeksforgeeks.org/subset-sum-problem-dp-25/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// recursive but finds all subset instead of just true or false
// vector<vector<int>> result;
// void subsetSum(vector<int> &set, vector<int> temp, int sum, int end)
// {
//   if (sum == 0)
//   {
//     result.push_back(temp);
//   }
//   if (sum < 0 || end < 0)
//   {
//     return;
//   }
//   temp.push_back(set[end]);
//   sum -= set[end];
//   subsetSum(set, temp, sum, end - 1);
//   temp.pop_back();
//   sum += set[end];
//   subsetSum(set, temp, sum, end - 1);
// }

int main()
{
  int n, sum;
  cout << "Enter the size: ";
  cin >> n;
  vector<int> set(n);
  cout << "Enter the array elements:\n";
  for (int i = 0; i < n; i++)
  {
    cin >> set[i];
  }
  cout << "enter the sum: ";
  cin >> sum;

  // iterative dp solution not space optimised
  // bool dp[n + 1][sum + 1];
  // // If sum is 0, then answer is true
  // for (int i = 0; i <= n; i++)
  //   dp[i][0] = true;
  // // If sum is not 0 and set is empty,
  // // then answer is false
  // for (int i = 1; i <= sum; i++)
  //   dp[0][i] = false;
  // for (int i = 1; i <= n; i++)
  // {
  //   for (int j = 1; j <= sum; j++)
  //   {
  //     if (set[i - 1] > j)
  //     {
  //       dp[i][j] = dp[i - 1][j];
  //     }
  //     else
  //     {
  //       dp[i][j] = dp[i - 1][j] || dp[i - 1][j - set[i - 1]];
  //     }
  //   }
  // }
  // if (dp[n][sum] == true)
  //   cout << "Found a subset with given sum";
  // else
  //   cout << "No subset with given sum";

  // dp but space optimised
  vector<bool> prev(sum + 1);
  prev[0] = true;

  for (int i = 1; i <= sum; i++)
  {
    prev[i] = false;
  }

  vector<bool> curr(sum + 1);
  for (int i = 1; i <= n; i++)
  {
    for (int j = 1; j <= sum; j++)
    {
      if (j < set[i - 1])
      {
        curr[j] = prev[j];
      }
      else
      {
        curr[j] = prev[j] || prev[j - set[i - 1]];
      }
    }
    prev = curr;
  }
  if (curr[sum] == true)
    cout << "Found a subset with given sum";
  else
    cout << "No subset with given sum";
}