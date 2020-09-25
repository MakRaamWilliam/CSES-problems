#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
#include <map>
using namespace std;
 
///int  dp[200005];
 
 
int Bs(int l,int r,int key,int a[]){
  if(l>r)
    return l;
  int mid=(l+r)/2;
  if((a[mid]==key && !mid) || (a[mid]==key && a[mid-1]<key ))
    return mid;
  else if(a[mid]>=key )
    return Bs(l,mid-1,key,a);
  else
    return Bs(mid+1,r,key,a);
 
}
 
 
int main()
{
// cin.tie(0);
 //cin.sync_with_stdio(0);
 int n, curr,x;
	cin >> n>>x;
	set<int> arr;
	arr.insert(0);arr.insert(n);
    multiset<int> st; st.insert(n);
	for (int i = 0; i < x; i++)
	{
		cin >> curr;
		auto it = arr.upper_bound(curr);
		int l=*prev(it),r=*(it);
		arr.insert(it,curr);
	//	cout<<l<<" "<<r<<"\n";
 
		st.erase(st.find(r-l));
		st.insert(curr-l);
		st.insert(r-curr);
        cout<<*st.rbegin()<<" " ;
	}
 
 return 0;
}
