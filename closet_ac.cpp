#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1234567;
map<int,int>f;
pair<int,bool>a[N];
int main(){
	//freopen("closet.inp","r",stdin);
	int n,m,y1,y2;
	cin>>n>>m>>y1>>y2;
	for(int i=1;i<=n+m;i++){
		scanf("%d",&a[i].first);
		a[i].second = i>n;
	}
	sort(a+1,a+n+m+1);
	for(int i=2;i<=n+m;i++){
		if(a[i].second!=a[i-1].second){
			f[abs(a[i].first-a[i-1].first)]++;
		}
	}
	int ans = 1e9,cnt = 0;
	map<int,int>::iterator it;
	for(it = f.begin();it!=f.end();it++){
		if(ans>it->first){
			ans = it->first;
			cnt = it->second;
		}
	}
	cout<<ans+abs(y1-y2)<<" "<<cnt;
	return 0;
}
