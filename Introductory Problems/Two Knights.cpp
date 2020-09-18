int main()
{
  int n;
  cin>>n;
  for(int i=1;i<=n;i++){
    unsigned long long op = (unsigned long long) i*i*(i*i -1)/2 - 4*(i-1)*(i-2);
    cout<<op<<"\n";
 
  }
 
    return 0;
}
