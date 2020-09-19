#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
 
///int  dp[200005];
 
 
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
 
 
int main()
{
 cin.tie(0);
 cin.sync_with_stdio(0);
 int n;
 cin>>n;
 long long a[n];
 
 for(int i=0;i<n;i++){
    cin>>a[i];
 }
 
 int mx=0,curr=0,j=0,i=0;
 map<int,int>mp;
 while(j < n){
    if(!mp[a[j]] ){
       mp[a[j]]++;curr++;
       mx=max(mx,curr);j++;
    }else{
     curr--;
     mp[a[i]]--;i++;
    }
 }
 
 cout<<max(mx,curr)<<"\n";
 return 0;
}
