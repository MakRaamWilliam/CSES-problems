#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
 
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
 int n;cin>>n;
 int a[n],b[n];
 for(int i=0;i<n;i++)
    cin>>a[i]>>b[i];
 sort(a,a+n);
 sort(b,b+n);
 int mx=1,curr=1,i=1,j=0;
 while(i<n && j<n){
    if(a[i]<b[j]){
        curr++;
        mx=max(curr,mx);
        i++;
    }else{
     curr--;
     j++;
    }
 }
 cout<<mx<<"\n";
 
    return 0;
}
