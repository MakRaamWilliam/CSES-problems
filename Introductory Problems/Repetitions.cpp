#include <iostream>
 
using namespace std;
 
//int a[200005];
 
int main()
{
 
  string s;
  cin>>s;
  char curr=s[0];
  int con=1,mx=0;
  for(int i=1;i<s.size();i++){
    if(s[i] == curr)
        con++;
    else{
        mx=max(mx,con);
        con=1;
        curr=s[i];
    }
  }
  cout<<max(mx,con)<<"\n";
 
    return 0;
}
