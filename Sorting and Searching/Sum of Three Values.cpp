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
 cin.tie(0);
 cin.sync_with_stdio(0);
 int n,k;cin>>n>>k;
 int a[n];
 map<int,int>mp1,mp2,mp3;
 for(int i=0;i<n;i++){
     cin>>a[i];
     if(!mp1[a[i]])
        mp1[a[i]]=i+1;
     else if(!mp2[a[i]])
        mp2[a[i]]=i+1;
     else
        mp3[a[i]]=i+1;
 }
 sort(a,a+n);
 int flag=1,fir,sec,thir;
 for(int i=0;i<n&&flag;i++){
    int l=i+1,r=n-1,target=k-a[i];
    if(target<=0)
        break;
    while(l<r){
        if(a[l]+a[r] == target){
            flag=0;fir=a[i];sec=a[l];thir=a[r];
            break;
        }else if(a[l]+a[r]>target)
            r--;
         else
            l++;
    }
 }
 if(flag )
    cout<<"IMPOSSIBLE\n";
 else{
   /// cout<<fir<<" "<<sec<<" "<<thir<<"\n";
    cout<<mp1[fir]<<" ";
    if(sec != fir ){
      cout<<mp1[sec]<<" ";
      if(thir != sec)
         cout<<mp1[thir]<<" ";
      else
         cout<<mp2[thir]<<"\n";
    }
    else{
       cout<<mp2[sec]<<" ";
       if(sec != thir)
         cout<<mp2[thir]<<"\n";
       else
        cout<<mp3[thir]<<"\n";
    }
 }
 
 
 return 0;
}
 
