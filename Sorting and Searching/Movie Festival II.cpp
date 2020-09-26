#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
typedef long long int ll;
 
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
 ll n,k;
 cin>>n>>k;
 pair<int,int> pa[n];
 
 for(int i=0;i<n;i++){
  cin>>pa[i].second>>pa[i].first;
 }
 int con=n;
 sort(pa,pa+n);
 //for(int i=0;i<n;i++){
 // cout<<pa[i].second<<" "<<pa[i].first<<"\n";
 //}
 multiset<int> st;
 st.insert(pa[0].first);
 for(int i=1;i<n;i++){
    auto it= st.upper_bound(pa[i].second);
    if(it == st.begin()){
        if(st.size()<k)
            st.insert(pa[i].first);
        else
            con--;
        }else{
         it--;
         st.erase(it);
         st.insert(pa[i].first);
        }
 
 }
 cout<<con<<"\n";
 
 
 return 0;
}
