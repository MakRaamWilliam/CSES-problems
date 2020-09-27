#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <vector>
typedef long long int ll;
#define MOD 1000000007
 
using namespace std;
 
//int  dp[200005];
 
 
int Bs(int l,int r,int key,int a[]){
    if(l>r)
        return l;
    int mid=(l+r)/2;
    if((a[mid]==key && !mid) || (a[mid]==key && a[mid-1]<key ))
        return mid;
    else if(a[mid]>=key )
        return Bs(l,mid-1,key,a);
    else
        return Bs(mid+1,r,key,a);
 
}
 
 
int minPathSum(vector<vector<int>>& grid) {
    int n=grid.size(),m=grid[0].size();
     int dp[n][m];
    dp[0][0]=grid[0][0];
    for(int i=0;i<n;i++){
        for (int j = 0; j < m; ++j) {
            if(!i && !j)
                continue;
            if(!i)
                dp[i][j]=dp[i][j-1]+grid[i][j];
            else if(!j)
                dp[i][j]=dp[i-1][j]+grid[i][j];
            else
                dp[i][j]=grid[i][j]+min(dp[i-1][j],dp[i][j-1]);
        }
    }
    return dp[n-1][m-1];
}
 
int climbStairs(int n) {
  int dp[n+2];
  dp[0]=1;
  dp[1]=1;
  for (int i = 2; i <= n; ++i) {
      dp[i]=dp[i-1]+dp[i-2];
  }
 
    return dp[n];
 
}
 
unsigned long long combinationSum4(vector<int>& nums, int target) {
    int n=nums.size();
    unsigned long long  dp[target+2];
    dp[0]=1;
    for (int i = 1; i <= target; ++i) {
        dp[i]=0;
    }
    sort(nums.begin(),nums.end());
    for (int i = 0; i <= target; ++i) {
        for (int j = 0; j <n ; ++j) {
            if(nums[j] > i)
                break;
//            if( ll(dp[i])+dp[i-nums[j]] > LONG_LONG_MAX )
//                continue;
            dp[i]= (dp[i] %MOD + dp[i-nums[j]]%MOD )%MOD;
        }
    }
    return  dp[target];
}
 
int coinChange(vector<int>& coins, int amount) {
   int n=coins.size();
   int dp[amount+2];
    for (int i = 0; i <= amount; ++i) {
        dp[i]=INT8_MAX;
    }
    dp[0]=0;
    sort(coins.begin(),coins.end());
    for (int i = 0; i <= amount; ++i) {
        for (int j = 0; j < n; ++j) {
            if(coins[j] > i)
                break;
            if( long(dp[i-coins[j]])+1 > INT8_MAX )
                continue;
 
                dp[i]=min(dp[i],dp[i-coins[j]]+1);
        }
    }
    if(dp[amount] == INT8_MAX)
        return -1;
    return dp[amount];
}
 
int dp[5][5];
int Lineofwines(int l,int r,int n,int a[]){
   if(l>r || l<0 || r>=n)
       return 0;
 
   if(dp[l][r] != 0)
       return dp[l][r];
   int y=n-r+l;
   dp[l][r]=max( Lineofwines(l,r-1,n,a)+y*a[r],Lineofwines(l+1,r,n,a)+y*a[l] );
   int cs=dp[l][r];
    return dp[l][r];
}
 
 
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
    int n;cin>>n;
    vector<int> vec;
    vec.push_back(1);vec.push_back(2);
    vec.push_back(3);vec.push_back(4);
    vec.push_back(5);vec.push_back(6);
    cout<<combinationSum4(vec,n)<<"\n";
 
 
//    int a[]={2,4,1,4,5};
//    Lineofwines(0,4,5,a);
//    for (int i = 0; i < 5; ++i) {
//        for (int j = 0; j < 5; ++j) {
//            cout<<dp[i][j]<<" ";
//        }
//        cout<<"\n";
//    }
 
 
 
 
 
    return 0;
}
