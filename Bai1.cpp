#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int l=0,n,dem=0,a[100000],x[100000];
bool pass[101][101][3];
int f[101][101][3];
void nhap()
{
    cin>>n;
}
void tach(int i)
{
    while(i>0)
    {
        a[++l]=i%10;
        i=i/10;
    }
    reverse(a+1,a+l+1);
}
bool snt(int i)
{
    if(i<2) return true;
    forinc(j,2,i-1)
    {
        if(i%j==0) return false;
    }
    return true;
}
long long cal(int i,int s,int o)
{
    if(pass[i][s][o]) return f[i][s][o];
    pass[i][s][o]=true;
      if(i>l)
     {
        if(snt) return f[i][s][o]=1;
        else return f[i][s][o]=0;
     }
    if(o==0) forinc(j,0,a[i]) f[i][s][o]+=cal(i+1,s+j,j!=a[i]);
    else forinc(j,0,9) f[i][s][o]+=cal(i+1,s+j,1);
    return f[i][s][o];
}
int main()
{
freopen("bai1.inp","r",stdin);
freopen("bai1.out","w",stdout);
    nhap();
    tach(n);
    cout<<cal(1,0,0);
}
