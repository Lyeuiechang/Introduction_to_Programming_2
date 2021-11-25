#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX=1e5+9;
pair<ll,ll> a[MAX];//store initial skill and id
ll sum[MAX],res[MAX],n,cf,cm,m,A;
pair<ll,pair<ll,ll>> ans;// store sth we need
int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>n>>A>>cf>>cm>>m;
    for(int i=1;i<=n;i++) cin>>a[i].first,a[i].second=i;
    sort(a+1,a+n+1);
    for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i].first;
    ll p=n;
    for(ll i=0;i<=n;i++)
    {
        ll d=m-i*A+sum[n]-sum[n - i];
        if(d<0) break;
        p=min(p,n-i);
        while(p>1 && d<p*a[p].first-sum[p]) p--;
        d-=p*a[p].first-sum[p];
        ll k=min(A,i==n?A:(a[p].first+d/p));
        //store ans,pos,minleval
        ans=max(ans,{i*cf+k*cm,{i,k}});
    }
    cout<<ans.first<<'\n';
    for(int i=0;i<ans.second.first;i++) a[n-i].first=A;
    for(int i=1;i<=n;i++) a[i].first=max(a[i].first,ans.second.second),res[a[i].second]=a[i].first;
    for(int i=1;i<=n;i++) cout<<res[i]<<" ";
}
