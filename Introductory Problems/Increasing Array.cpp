#include <iostream>
 
using namespace std;
 
//int a[200005];
 
int main()
{
 
  int n;
  cin>>n;
  int  a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  unsigned long op=0;
  for(int i=1;i<n;i++){
    if(a[i]<a[i-1]){
        op+=a[i-1]-a[i];
        a[i]=a[i-1];
    }
  }
  cout<<op<<"\n";
 
    return 0;
}
