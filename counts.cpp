#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int n,a[1000001],s,x[1000001],res=0;
void nhap()
{
    cin>>n;
    forinc(i,1,n) cin>>a[i];
    cin>>s;
}
void ktra()
{
    int kq=0;
    forinc(i,1,n)
    {
        if(x[i]==1)
        {
            kq=kq+a[i];
        }
    }
    if(kq==s)
    {
        res++;
    }
}
void duyet(int i)
{
    if(i==n+1) ktra();
    else
    {
        forinc(k,0,1)
        {
        x[i]=k;
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
