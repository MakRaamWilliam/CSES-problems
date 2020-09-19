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
 int n,x;
 cin>>n>>x;
 int a[n];
 map<int,int> mp,mp2;
 for(int i=0;i<n;i++){
    cin>>a[i];
    if(!mp[a[i]])
      mp[a[i]]=i+1;
    else
        mp2[a[i]]=i+1;
 }
 sort(a,a+n);
 int l=0,r=n-1;
 while(l<r){
    if(a[l]+a[r] == x)
        break;
    if(a[l]+a[r]>x)
        r--;
    else
        l++;
 }
 if(l < r && a[l] !=a[r] )
    cout<<mp[a[l]]<<" "<<mp[a[r]]<<"\n";
 else if(l<r)
    cout<<mp[a[l]]<<" "<<mp2[a[r]]<<"\n";
 
 else
    cout<<"IMPOSSIBLE\n";
 
 
    return 0;
}
