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
 int a[n];int flg=1;
 for(int i=0;i<n;i++){
    cin>>a[i];
    if(a[i]>0)
        flg=0;
 }
 if(flg)
    cout<<*max_element(a,a+n)<<"\n";
 else{
 long long mx=a[0],curr=0;
 for(int i=0;i<n;i++){
    if(curr+a[i]<0){
        mx=max(curr,mx);
        curr=0;
    }else{
        curr+=a[i];
        mx=max(mx,curr);
    }
 }
 cout<<max(mx,curr)<<"\n";
 }
 return 0;
}
 
