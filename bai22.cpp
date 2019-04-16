#include<bits/stdc++.h>
#define forinc(i,a,b) for(int i=a;i<=b;i++)
using namespace std;
int l=0,n,k,a[100000],x[100000];
bool pass[101][10100][3];
int f[101][10100][3];
void tach(int i)
{
    while(i>0)
    {
        a[++l]=i%10;
        i=i/10;
    }
    reverse(a+1,a+l+1);
}
long long cal(int i,int s,int o)
{
    if(pass[i][s][o]) return f[i][s][o];
    pass[i][s][o]=true;
      if(i>l)
      {
          //cerr << i << " " << s << " " << o << " 1 \n";
          return f[i][s][o]=!s;
      }
    if(o)
    {
        forinc(j,0,9)
        {
            int pp,oo;
            if(o==1) pp=(s*j)%k;
            else pp=j%k;
            if(j) oo=1;
            else oo=o;
            f[i][s][o]+=cal(i+1,pp,oo);
        }
    }
    else forinc(j,0,a[i])
    {
       if(j==a[i]) f[i][s][o]+=cal(i+1,(s*j)%k,0);
       else
       if (i == 1 && !j) f[i][s][o] += cal(i+1,1,2);
       else f[i][s][o] += cal(i+1,(s*j)%k,1);
    }
    //cerr << i << " " << s << " " << o << " " << f[i][s][o] << "\n";
    return f[i][s][o];
}
int main()
{
    //freopen("bai2.inp","r",stdin);
    //freopen("bai2.out","w",stdout);
    cin>>n>>k;
    tach(n);
    memset(pass,false,sizeof(pass));
    cout<<cal(1,1,0)-1;
}

