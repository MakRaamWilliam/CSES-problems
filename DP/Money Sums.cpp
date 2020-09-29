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
unsigned long long combinationSum2(vector<int>& nums, int target) {
    int n=nums.size();
    unsigned long long  dp[target+2];
    dp[0]=1;
    for (int i = 1; i <= target; ++i) {
        dp[i]=0;
    }
   // sort(nums.begin(),nums.end());
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j <=target ; ++j) {
            if(nums[i] > j)
                continue;
//            if( ll(dp[i])+dp[i-nums[j]] > LONG_LONG_MAX )
//                continue;
            dp[j]= (dp[j] %MOD + dp[j-nums[i]]%MOD )%MOD;
        }
    }
    return  dp[target];
}
 
int coinChange(vector<int>& coins, int amount) {
   int n=coins.size();
   int dp[amount+2];
    for (int i = 0; i <= amount; ++i) {
        dp[i]=1000000007;
    }
    dp[0]=0;
    sort(coins.begin(),coins.end());
    for (int i = 0; i <= amount; ++i) {
        for (int j = 0; j < n; ++j) {
            if(coins[j] > i)
                break;
//            if(  long(dp[i-coins[j]])+1 > INT8_MAX )
//                continue;
                if(dp[i-coins[j]] != MOD )
                 dp[i]=min(dp[i],  (dp[i-coins[j]]%MOD +1)%MOD )%MOD;
        }
    }
    if(dp[amount] == 1000000007 )
        return -1;
    return dp[amount];
}
 
//int dp[5][5];
//int Lineofwines(int l,int r,int n,int a[]){
//   if(l>r || l<0 || r>=n)
//       return 0;
//
//   if(dp[l][r] != 0)
//       return dp[l][r];
//   int y=n-r+l;
//   dp[l][r]=max( Lineofwines(l,r-1,n,a)+y*a[r],Lineofwines(l+1,r,n,a)+y*a[l] );
//   int cs=dp[l][r];
//    return dp[l][r];
//}
 
ll Remove(int n){
    if(n<10)
        return 1;
    ll dp[n+2];
    for (int i = 0; i < 9; ++i) {
        dp[i]=1;
    }
    dp[10]=2;
    for (int i = 11; i <= n; ++i) {
        vector<int> vec;
        int k=i;
        while (k>0){
            if(k%10)
              vec.push_back(k%10);
            k=k/10;
        }
        ll mn=dp[i-vec.back()];vec.pop_back();
        while (!vec.empty()){
            mn=min(mn,dp[i-vec.back()]);
            vec.pop_back();
     //       cout<<mn<<" "<<i<<"\n";
        }
        dp[i]=mn+1;
    }
    return dp[n];
}
 
ll gridpaths(vector<vector<int>>& obs){
    int n,m;
    n=obs.size();
    if(n == 0)
        return 0;
    m=obs[0].size();
    if(n==0 || m==0)
        return 0;
    if(obs[0][0]==1)
        return 0;
    vector<vector<ll>>v(n,vector<ll>(m,1));
 
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(obs[i][j]==0){
                int ro= i==0?0:v[i-1][j];
                int col= j==0?0:v[i][j-1];
                v[i][j]=(ro%MOD +col%MOD)%MOD;
            }
            else
                v[i][j]=0;
            if(i == 0 && j==0)
                v[i][j]=1;
 
        }
    }
 
    return v[n-1][m-1];
 
}
 
ll Bookshop(int v[],int W,int weg[], int n){
    ll dp[W+1][n+1];
    for (int i = 0; i <= W; ++i) {
        dp[i][0]=0;
    }
    for (int i = 0; i <= n ; ++i) {
        dp[0][i]=0;
    }
    for (int i = 1; i <= n; ++i) {
        for (int w = 1; w<= W; ++w) {
            dp[w][i]=dp[w][i-1];
            if(weg[i]<= w){
                dp[w][i]=max(dp[w][i],dp[w-weg[i]][i-1]+v[i]);
            }
      //      cout<<dp[w][i]<<" ";
        }
     //   cout<<"\n";
    }
    return dp[W][n];
}
//ll dp[5001][5001];
//string  s1,s2;
//ll find(ll n,ll m){
//    if(n<0){
//        if(m<0) return 0;
//        else return m+1;
//    }
//    if(m<0){
//        if(n<0) return 0;
//        else return n+1;
//    }
//    ll ans=dp[n][m];
//    if(ans!=-1) return ans;
//    if(s1[n]!=s2[m]){
//        ans=min(find(n-1,m-1),min(find(n-1,m),find(n,m-1)))+1;
//    }
//    else{
//        ans=find(n-1,m-1);
//    }
//    dp[n][m]=ans;
//    return ans;
//}
 
//ll dp[501][501];
//ll cutRec(int n, int m){
// if(dp[n][m] != -1)
//     return dp[n][m];
// ll ans =10000000;
//    for (int i = 1; i < n; ++i) {
//        ans=min(ans,cutRec(n-i,m)+cutRec(i,m)+1);
//    }
//    for (int i = 1; i < m; ++i) {
//        ans=min(ans,cutRec(n,m-i)+cutRec(n,i)+1);
//    }
//    dp[n][m]=dp[m][n]=ans;
//    return ans;
//}
 
int dp[105][100005];
vector<ll> v;
set<ll> ans;
 
void sumMoney(ll ind,ll sum){
    if(ind == ll (v.size()) ) {
        ans.insert(sum);
        return;
    }
    if (dp[ind][sum] != -1)
        return;
    dp[ind][sum]=1;
    sumMoney(ind+1,sum + v[ind]);
    sumMoney(ind+1,sum);
 
}
 
int main()
{
    cin.tie(0);
    cin.sync_with_stdio(0);
 
    int n;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        ll x;cin>>x;
        v.push_back(x);
    }
    for (int i = 0; i < 105; ++i) {
        for (int j = 0; j < 100005; ++j) {
         dp[i][j]=-1;
        }
    }
    sumMoney(0,0);
    cout<<ans.size()-1<<"\n";
    ans.erase(ans.begin());
    while (ans.empty() == false){
        cout<<*ans.begin()<<" ";
        ans.erase(ans.begin());
    }
    cout<<"\n";
 
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
