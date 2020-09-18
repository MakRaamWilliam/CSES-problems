#include <iostream>
 
using namespace std;
 
//int a[1000005];
 
int main()
{
 //cin.tie(0);
 //cin.sync_with_stdio(0);
 
  int t;cin>>t;
  for(int p=0;p<t;p++){
   unsigned long a,b;
   cin>>a>>b;
   if(max(a,b)/2 > min(a,b))
    cout<<"NO\n";
   else{
 
   if(!a && !b || (a==1 && b==2) || (a==2&&b==1) ||((a+b)%3 ==0 ) )
     cout<<"YES\n";
   else
     cout<<"NO\n";
  }
  }
    return 0;
}
