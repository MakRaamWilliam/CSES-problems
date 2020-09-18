#include <iostream>
 
using namespace std;
 
//int a[200005];
 
int main()
{
  int t;cin>>t;
 for(int p=0;p<t;p++){
  unsigned long long x,y;
  cin>>y>>x;
  if(x > y){
    if(x%2 == 1)
        cout<<x*x-y+1<<"\n";
    else
        cout<<(x-1)*(x-1)+y<<"\n";
  }else{
    if(y%2 == 0)
        cout<<y*y-x+1<<"\n";
    else
        cout<<(y-1)*(y-1)+x<<"\n";
  }
 
 }
 
    return 0;
}
