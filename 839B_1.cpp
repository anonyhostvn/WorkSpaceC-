#include <bits/stdc++.h>
using namespace std;

int n,k;
multiset<int> s;

int main()
{
    cin>>n>>k;
    int x,Count=0;
    while(k--)
    {
        cin>>x;
        s.insert(x);
    }
    for(int i=1; i<=n; i++)
        if(s.size()>0)
        {
            int tmp=*s.rbegin();
            s.erase(s.find(*s.rbegin()));
            if(tmp>2)
            {
                tmp-=4;
                if(tmp>0)
                    s.insert(tmp);
            }
            else
                Count++;
        }
    for(int i=1; i<=2*n; i++)
        if(s.size()>0)
        {
            int tmp=*s.rbegin();
            s.erase(s.find(*s.rbegin()));
            tmp-=2;
            if(tmp>0)
                s.insert(tmp);
        }
    if(s.size()==0)
        cout<<"YES";
    else if(*s.rbegin()==1&&s.size()<=Count)
        cout<<"YES";
    else
        cout<<"NO";
}
