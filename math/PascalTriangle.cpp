#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void generatePascalTriangle(int k)
{
  int c[k + 1];
  memset(c, 0, sizeof(c));
  c[0] = 1;
  for (int i = 1; i <= k; i++)
  {
    for (int j = k; j > 0; j--)
    {
      c[j] = c[j] + c[j - 1];
    }
    for (int z = 0; z <= k; z++)
    {
      cout << c[z] << " ";
    }
    cout << endl;
  }
}

int main()
{
  cout << "enter n: ";
  int n;
  cin >> n;
  generatePascalTriangle(n);
  return 0;
}