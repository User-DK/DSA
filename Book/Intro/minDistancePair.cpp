// #include <bits/stdc++.h>
// using namespace std;

// typedef long long ll;
// typedef vector<int> vi;
// typedef pair<int, int> pi;
// #define F first
// #define S second
// #define PB push_back
// #define MP make_pair
// #define REP(i, a, b) for (int i = a; i <= b; i++)
// const int MOD = 1e9 + 7;
// using ull = unsigned long long;
// using ld = long double;

// float calDistance(pair<int, int> a, pair<int, int> b)
// {
//   return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
// }

// void checkPairs(vector<pair<int, int>> &arr, vector<bool>& visited, int i , int n, float currentCost,float minCost)
// {
//   if(i>=n){
//     minCost = min(minCost, currentCost);
//     return;
//   }
  
//   for(int j =0;j<n;j++){
//     if(!visited[i]){
//       for(int k= j+1;k<n;k++){
//         if(!visited[j]){
//           visited[i] = visited[j] = true;
//           float dist = calDistance(arr[i],arr[j]);
//           checkPairs(arr, visited, i,n, currentCost,minCost);
//           visited[i] = visited[j] = false;
//         }
//       }
//     }
//   }
// }

//     int main()
// {
//   ios::sync_with_stdio(0);
//   cin.tie(0);
//   int n = 4;
//   vector<pair<int, int>> arr = {{1, 1}, {8, 6}, {6, 8}, {1, 3}};
//   float minCost = INT_MAX;
//   vector<bool> visited(n,false);
//   checkPairs(arr, visited, 0, n/2,0,minCost);
//   cout << minCost;
//   return 0;
// }

#include <bits/stdc++.h>

using namespace std;

int N;
float minCost = INT_MAX;

float calculateDistance(pair<int, int> p1, pair<int, int> p2)
{
  return sqrt(pow(p1.first - p2.first,2) + pow(p1.second - p2.second,2));
}

void backtrack(vector<pair<int, int>> &students, vector<bool> &visited, int groupIndex, float currentCost)
{
  if (groupIndex == N)
  {
    minCost = min(minCost, currentCost);
    return;
  }

  for (int i = 0; i < students.size(); i++)
  {
    if (!visited[i])
    {
      for (int j = i + 1; j < students.size(); j++)
      {
        if (!visited[j])
        {
          visited[i] = visited[j] = true;
          float distance = calculateDistance(students[i], students[j]);
          backtrack(students, visited, groupIndex + 1, currentCost + distance);
          visited[i] = visited[j] = false;
        }
      }
    }
  }
}

int main()
{
  int numStudents = 4;
  N = numStudents / 2;
  vector<pair<int, int>> students = {{1, 1}, {8, 6}, {6, 8}, {1, 3}};

  vector<bool> visited(numStudents, false);

  backtrack(students, visited, 0, 0);

  cout << "Minimum cost: " << minCost << endl;

  return 0;
}
