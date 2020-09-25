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
 
long long solve(long long mid,int a[],int n){
  long long sec=0;
  for(int i=0;i<n;i++)
    sec=sec+(mid/a[i]);
   return sec;
}
 
 
long long BSR(long long l,long long r,long long k, int a[],int n){
   long long mid=(l+r)/2;
   if(l == r)
    return mid;
   long long sec=solve(mid,a,n);
 //  cout<<sec<<"\n";
   if(sec<k)
     return BSR(mid+1,r,k,a,n);
   else{
 
     return BSR(l,mid,k,a,n);
   }
 
}
 
 
int main()
{
 //cin.tie(0);
 //cin.sync_with_stdio(0);
 int n,k;
 cin>>n>>k;
 pair<int,int> a[n];
 for(int i=0;i<n;i++){
    cin>>a[i].first;
    a[i].second=i+1;
 }
 sort(a,a+n);
 int flag=1,fir,sec,thir,forth;
 for(int i=0;i<n && flag;i++){
    for(int j=i+1;j<n && flag;j++){
        long long l=j+1,r=n-1,target=k-(a[i].first +a[j].first);
        if(target <=0)
            break;
        while(l<r){
            if(a[l].first +a[r].first == target){
                fir=a[i].second,sec=a[j].second,thir=a[l].second,forth=a[r].second;
                flag=0;break;
            }
            if(a[l].first+a[r].first < target )
                l++;
            else
                r--;
        }
    }
 }
 if(flag )
    cout<<"IMPOSSIBLE\n";
 else{
    cout<<fir<<" "<<sec<<" "<<thir<<" "<<forth<<"\n";
 }
 
 return 0;
}
 
