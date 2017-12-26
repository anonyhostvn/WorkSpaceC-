#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MAXN=2e5+5;
int n,q,p;
int cnt,root[MAXN];
struct Node{
    int l,r,sum;
}T[MAXN*40];

void init(){
    memset(T,0,sizeof(T));
    memset(root,0,sizeof(root));
    cnt=0;
}

void UpDate(int l,int r,int &x,int y,int pos){
    T[++cnt]=T[y];
    T[cnt].sum++;
    x=cnt;
    if(l==r)return;
    int mid=(l+r)>>1;
    if(pos<=mid)UpDate(l,mid,T[x].l,T[y].l,pos);
    else UpDate(mid+1,r,T[x].r,T[y].r,pos);
}

int Query(int l,int r,int x,int L,int R){
    if(L>R)return 0;
    if(L<=l&&r<=R)return T[x].sum;
    int mid=(l+r)>>1,ret=0;
    if(L<=mid)ret+=Query(l,mid,T[x].l,L,R);
    if(R>mid)ret+=Query(mid+1,r,T[x].r,L,R);
    return ret;
}

int main(){
    freopen("853C.inp" , "r" , stdin) ;
    init();
    scanf("%d%d",&n,&q);
    for(int i=1;i<=n;i++){
        scanf("%d",&p);
        UpDate(1,n,root[i],root[i-1],p);
    }
    int l,r,u,d;
    while(q--){
        scanf("%d%d%d%d",&l,&d,&r,&u);
        int m1=Query(1,n,root[l-1],u+1,n);
        int m2=Query(1,n,root[r],u+1,n)-Query(1,n,root[l-1],u+1,n);
        int m3=Query(1,n,root[n],u+1,n)-Query(1,n,root[r],u+1,n);
        int m4=Query(1,n,root[l-1],d,u);
        int m5=Query(1,n,root[r],d,u)-Query(1,n,root[l-1],d,u);
        int m6=Query(1,n,root[n],d,u)-Query(1,n,root[r],d,u);
        int m7=Query(1,n,root[l-1],1,d-1);
        int m8=Query(1,n,root[r],1,d-1)-Query(1,n,root[l-1],1,d-1);
        int m9=Query(1,n,root[n],1,d-1)-Query(1,n,root[r],1,d-1);
        ll ans=(ll)m1*(m5+m6+m8+m9)+(ll)m2*(m4+m5+m6+m7+m8+m9)
        +(ll)m3*(m4+m5+m7+m8)+(ll)m4*(m5+m6+m8+m9)+(ll)m5*(m6+m7+m8+m9)
        +(ll)m6*(m7+m8)+(ll)m5*(m5-1)/2;
        printf("%I64d\n",ans);
    }
    return 0;
}
