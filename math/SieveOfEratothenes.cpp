// used to find the prime numbers till n
// time complexity = o(n*log(log(n)))
// space complexity = o(n)

#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
  int n;
  cout << "Enter n: ";
  cin >> n;
  vector<int> arr(n + 1, 1);
  for (int i = 2; i <= sqrt(n); i++)
  {
    if (arr[i] != 1)continue;

    for (int j = i * i; j <= n; j += i)
    {
      arr[j] = 0;
    }
  }

  for (int i = 2; i <= n; i++)
  {
    if (arr[i] == 1)
    {
      cout << i << " ";
    }
  }
}