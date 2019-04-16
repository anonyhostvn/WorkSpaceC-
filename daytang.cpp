#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int res=0,f[10001],a[10001],n;
void nhap()
{
    cin>>n;
    forinc(i,1,n) cin>>a[i];
}
void ktra()
{
    forinc(i,1,n) f[i]=1;
    forinc(i,2,n)
    {
        forinc(j,1,i) if(a[j]<a[i]) f[i]=max(f[i],f[j]+1);
    }
    forinc(i,1,n) res=max(res,f[i]);
}
int main()
{
    nhap();
    ktra();
    cout<<res;
}
