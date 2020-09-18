#include <iostream>
 
using namespace std;
 
//int a[1000005];
 
int main()
{
  unsigned long long n;
  cin>>n;
  unsigned op =1;
  for(int i =0;i<n;i++)
    op= (op*2) % 1000000007;
  cout<<op<<"\n";
 
 
    return 0;
}
