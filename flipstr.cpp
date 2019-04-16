#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int a[11],b[11],k,m,n,x[22],res=;
void nhap()
{
    cin>>n>>m;
    k=n/m;
    forinc(i,1,n)
    {
        char ch;
        cin>>ch;
        if(ch=='1') a[i]=1;
        if(ch=='0') a[i]=0;
    }
}
void ktra()
{
    int dem=0;
    forinc(i,1,n) {b[i]=a[i];}
  forinc(i,1,n)
  {
      if(x[i]==1)
      {
          b[i]=1-b[i];
          dem++;
      }
  }
  forinc(i,n+1,n+k)
  {
      if(x[i]==1)
      {
          forinc(j,1,(i-n)*m)
          {
             b[i]=1-b[i];
          }
          dem++;
      }
  }
  bool ok=true;
  forinc(i,1,m)
  {
      if(b[i]!=b[n-m+i]) {ok=false;}
  }
  if(ok)
  {
      res=min(res,dem);
  }
}
void duyet(int i)
{
    if(i==n+k+1) ktra();
    else
    {
        forinc(j,0,1)
        {
            x[i]=j;
            duyet(i+1);
        }
    }
}
int main()
{
    nhap();
    duyet(1);
    cout<<res;
}
