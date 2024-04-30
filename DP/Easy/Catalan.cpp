#include <iostream>
#include <vector>
using namespace std;

int catalan(vector<int>dp, int i){
  if(i==1 || i==0){
    dp[i] = 1;
    return dp[i];
  }

  if(dp[i]!=-1)return dp[i];
  
  for(int j=0;j<i;j++){
    dp[i] += catalan(dp,j)*catalan(dp,i-j-1);
  }
  return dp[i];
}

int main(){
  int n;
  cout<<"Enter Number: ";
  cin>>n;
  vector<int> dp(n+2,-1);
  cout<<catalan(dp,n+1);
  return 0;
}