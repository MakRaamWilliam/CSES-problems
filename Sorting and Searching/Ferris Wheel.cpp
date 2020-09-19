#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;
 
//long long a[100];
 
 
int main()
{
 cin.tie(0);
 cin.sync_with_stdio(0);
 
 int n,x;
 cin>>n>>x;
 int a[n];
 for(int i=0;i<n;i++)
    cin>>a[i];
 sort(a,a+n);
 int l=0,r=n-1,con=0;
 while(l < r){
     //  cout<<l<<" "<<r<<"\n";
    if(a[l]+a[r]<=x){
        con++;l++;r--;
    }else{
        con++;r--;
    }
 }
 if(l==r && a[l]<=x)
    con++;
 cout<<con<<"\n";
 
    return 0;
}
