#include <vector>
#include <iostream>
using namespace std;

int fibonacci(vector<long long> &dp, int i)
{
  if (i == 0)
  {
    dp[0] = 0;
    return dp[0];
  }
  if (i == 1)
  {
    dp[1] = 1;
    return dp[1];
  }
  if (dp[i] != -1)
  {
    return dp[i];
  }

  dp[i] = fibonacci(dp, i - 2) + fibonacci(dp, i - 1);
  return dp[i];
}

int main()
{
  int n;
  cout<< "Enter the Number: ";
  cin>>n;
  vector<long long> dp(n+1, -1);
  cout<<fibonacci(dp, n);
  return 0;
}