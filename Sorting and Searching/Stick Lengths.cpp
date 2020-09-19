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
 long long a[n];int flg=1;
 unsigned long long sum=0;
 for(int i=0;i<n;i++)
    cin>>a[i];
 if(n == 1)
        cout<<"0\n";
 else{
 sort(a,a+n);
 
 for(int i=0;i<n;i++){
    sum+=abs(a[i]-a[0]);
 }
 unsigned long long mn=10e18;
 for(int i= 1;i<n;i++){
    sum=sum -  (a[i]-a[i-1])*(n-i) + (a[i]-a[i-1])*i;
 //   cout<<sum<<"\n";
    mn=min(mn,sum);
 }
   cout<<mn<<"\n";
 }
 
 return 0;
}
