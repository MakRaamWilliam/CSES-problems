#include <iostream>
 
using namespace std;
 
//int a[1000005];
 
int main()
{
  unsigned long long n;
  cin>>n;
  unsigned op =1;
  unsigned long con=0,curr=5;
  while(n/curr > 0){
    con+=n/curr;
    curr*=5;
  }
  cout<<con<<"\n";
    return 0;
}
