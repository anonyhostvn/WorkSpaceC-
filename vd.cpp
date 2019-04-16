#include<bits/stdc++.h>
#define base 1000000007
using namespace std;
bool pass[100001];
int f[100001],n;
int fibo(int i)
{
    if(pass[i]) return f[i];
    pass[i]=true;
    if(i<3) return f[i]=1;
    return f[i]=(fibo(i-1)+fibo(i-2))%base;
}
int main()
{
    cin>>n;
    cout<<fibo(n);
}
