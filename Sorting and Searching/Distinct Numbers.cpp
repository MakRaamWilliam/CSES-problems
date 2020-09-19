#include <iostream>
#include <string>
#include <stack>
#include <set>
 
using namespace std;
 
//long long a[100];
 
 
int main()
{
 cin.tie(0);
 cin.sync_with_stdio(0);
 
 int n; cin>>n;
 set<int> st;
 for(int i=0;i<n;i++){
    long long x;cin>>x;
    st.insert(x);
 }
 cout<<st.size()<<"\n";
 
 
    return 0;
}
