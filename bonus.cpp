#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
long long k,x[5],a[11][11],d[5],c[5],dem=0,res=0;
bool daxet[5],F[11][11];
int dk[8]={2, 2,1, 1,-2,-2,-1,-1};
int ck[8]={1,-1,2,-2, 1,-1,-2, 2};
void nhap()
{
    memset(a,0,sizeof(a));
    cin>>k;
    forinc(i,1,k)
    {
        int u,v,c;
        cin>>u>>v>>c;
        a[u][v]=c;
    }
    forinc(i,1,8)
    {
        forinc(j,1,8)
        {
           if(a[i][j]==0)
           {dem++; d[dem]=i; c[dem]=j;}
        }
    }
}
void xepxe(int u,int v)
{
    forinc(i,1,8)
    {
        F[u][i] =true;
        F[i][v] =true;
    }
}
void xeptuong(int u,int v)
{
    forinc(i,1,8)
    {
        forinc(j,1,8)
        {
            if(i-j==u-v) F[i][j]=true;
            if(i+j==u+v) F[i][j]=true;
        }
    }
}
void xephau(int u,int v)
{

    forinc(i,1,8)
    {
        F[u][i] =true;
        F[i][v] =true;
    }
     forinc(i,1,8)
    {
        forinc(j,1,8)
        {
            if(i-j==u-v) F[i][j]=true;
            if(i+j==u+v) F[i][j]=true;
        }
    }
}
void xepma(int u,int v)
{
    forinc(i,0,7)
    {
        if(u+dk[i]>=1 && v+ck[i]>=1) F[u+dk[i]][v+ck[i]]=true;
    }
}
void ktra()
{
    memset(F,false,sizeof(F));
    forinc(i,1,4)
    {
        if(x[i]==1) xephau(d[i],c[i]);
        if(x[i]==2) xeptuong(d[i],c[i]);
        if(x[i]==3) xepxe(d[i],c[i]);
        if(x[i]==4) xepma(d[i],c[i]);
    }
    long long sum=0;
    forinc(i,1,8)
    {
        forinc(j,1,8)
        {
            if(F[i][j]) sum+=a[i][j];
        }
    }
    res=max(res,sum);
}
void duyet(int i)
{
    if(i==5) ktra();
    else
    {
        forinc(j,1,4)
        {
            if(daxet[j]==false)
            {
                x[i]=j;
                daxet[j]=true;
                duyet(i+1);
                daxet[j]=false;
            }
        }
    }
}
int main()
{
    freopen("bonus.inp","r",stdin);
    freopen("bonus.out","w",stdout);
    nhap();
    memset(daxet,false,sizeof(daxet));
    duyet(1);
    cout<<res;
}
