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
 pair<int,int> pa[n];
 
 for(int i=0;i<n;i++){
  cin>>pa[i].second>>pa[i].first;
 }
 int con=1;
 sort(pa,pa+n);
 //for(int i=0;i<n;i++){
 // cout<<pa[i].second<<" "<<pa[i].first<<"\n";
 //}
 int ot=pa[0].first;
 for(int i=1;i<n;i++){
    if(pa[i].second>=ot ){
        con++;
        ot=pa[i].first;
    }
 }
 cout<<con<<"\n";
 
    return 0;
}
