#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef long long int ll;
map<int,ll> r,c,rc,cc;
map< pair<int,int>, ll> vis;
int n,p,k,a,b;
ll ans,x;
void update(){
    ans-= (n-rc[c[b]]);
    ans-= (n-cc[r[a]]);
    if(r[a]==c[b])
        ans++;
    cc[c[b]]--;
    c[b]=(c[b]^x);
    cc[c[b]]++;
    rc[r[a]]--;
    r[a]=(r[a]^x);
    rc[r[a]]++;
    ans+=(n-rc[c[b]]);
    ans+=(n-cc[r[a]]);
    if(r[a]==c[b])
        ans--;
    return;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>p;
    rc[0]=cc[0]=n;
    while(k--){
        cin>>a>>b>>x;
        vis[mp(a,b)]=x;
        update();
    }
    while(p--){
        cin>>a>>b;
        x=vis[mp(a,b)];
        vis[mp(a,b)]=0;
        update();
        cin>>a>>b;
        update();
        vis[mp(a,b)]=x;
        cout<<ans<<'\n';
    }
    return 0;
}
