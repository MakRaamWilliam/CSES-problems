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
 
 int n,m,k;
 cin>>n>>m>>k;
 int a[n],b[m];
 for(int i=0;i<n;i++)
    cin>>a[i];
 for(int i=0;i<m;i++)
    cin>>b[i];
 sort(b,b+m);
 sort(a,a+n);
 int con=0;
 auto big=b;
 for(int i=0;i<n;i++){
    if(a[i]-k>b[m-1] )
      break;
    auto it=lower_bound(big,b+m,a[i]-k);
    int low = *it;
  //  cout<<a[i]<<" "<<low<<"\n";
    if(abs(low-a[i])<= k )
        con++,big=it+1;
 }
    cout<<con;
 
 
    return 0;
}
