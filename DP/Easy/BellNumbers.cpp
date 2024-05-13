// Given a set of n elements, find number of ways of partitioning it.
//  The solution to above questions is Bell Number.

//     What is a Bell Number
//     ? Let
//       S(n, k) be total number of partitions of n elements into k sets. The value of n’th Bell Number is sum of S(n, k) for k = 1 to n.
// Bell(n) = \sum_{k=1}^{
//   n}S(n,k)
// Value of S(n, k) can be defined recursively as, S(n+1, k) = k*S(n, k) + S(n, k-1)

// How does above recursive formula work?
// When we add a (n+1)’th element to k partitions, there are two possibilities.
// 1) It is added as a single element set to existing partitions, i.e, S(n, k-1)
// 2) It is added to all sets of every partition, i.e., k*S(n, k)
// S(n, k) is called Stirling numbers of the second kind
// First few Bell numbers are 1, 1, 2, 5, 15, 52, 203, ….

// A Simple Method to compute n’th Bell Number is to one by one compute S(n, k) for k = 1 to n and return sum of all computed values. Refer this for computation of S(n, k).
// Below is Dynamic Programming based implementation of the above recursive code using the Stirling number-

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>>dp;

int getStirlinNumber(int k, int n)
{
  if (k == 0 || k > n)
  {
    return 0;
  }
  if(k==1 || k==n){
    return 1;
  }
  if (dp[n][k] != -1)
  {
    return dp[n][k];
  }
  dp[n][k] = (k * getStirlinNumber(k, n - 1)) + getStirlinNumber(k - 1, n - 1);
  return dp[n][k];
}

int main()
{
  int n;
  cout << "Enter the Number: ";
  cin >> n;
  dp.resize(n + 1, vector<int>(n + 1, -1));
  int bellNumber = 0;
  for (int i = 1; i <= n; i++)
  {
    bellNumber += getStirlinNumber(i, n);
  }
  cout << "\nThe Bell number is: " << bellNumber;
  return 0;
}