#include <iostream>
 
using namespace std;
 
//int a[200005];
 
int main()
{
   unsigned long long sum=0;
    long long n;
    cin>>n;
    for(int i=0;i<n-1;i++){
        int x;cin>>x;
        sum+=x;
    }
   unsigned long  long total = n*(n+1)/2;
    cout<<total-sum<<"\n";
    return 0;
}
