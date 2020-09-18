#include <iostream>
 
using namespace std;
 
int a[1000005];
 
int main()
{
  unsigned long long n;
  cin>>n;
  unsigned long sum= n*(n+1)/2;
  if(sum % 2 == 1)
    cout<<"NO\n";
  else{
    cout<<"YES\n";
    sum=sum/2;
    unsigned long long curr=n;
    int con=0;
    a[n]=1;
    for(int i=n-1;i>0;i--){
        if(sum - (curr + i) < i  && sum - (curr + i)>=0 ){
            a[i]=1,a[sum - (curr + i)]=1;
            break;
        }else if(curr + i < sum){
        a[i]=1;
        curr+=i;
        }
    }
     for(int i=n;i>0;i--){
        if(a[i])
            con++;
    }
    cout<<con<<"\n";
    for(int i=n;i>0;i--){
        if(a[i])
            cout<<i<<" ";
    }
    cout<<"\n"<<n-con<<"\n";
     for(int i=n;i>0;i--){
        if(!a[i])
            cout<<i<<" ";
    }
  }
 
    return 0;
}
