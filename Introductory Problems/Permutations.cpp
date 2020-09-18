#include <iostream>
 
using namespace std;
 
//int a[200005];
 
int main()
{
 
  int n;
  cin>>n;
  if(n==2 || n==3 )
    cout<<"NO SOLUTION\n";
  else{
        int i;
        if(n%2 == 0)
          i=2;
         else
            i=1;
    for(;i<=n;i+=2)
        cout<<i<<" ";
        if(n%2 == 0)
          i=1;
         else
            i=2;
    for(;i<=n;i+=2)
        cout<<i<<" ";
    cout<<"\n";
  }
 
    return 0;
}
