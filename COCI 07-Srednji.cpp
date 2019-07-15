#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=1e5+5;
int n,k,a[N],p[N],s[N],ans;
map <int,int> f;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(a[i]<k)
            p[i]=p[i-1]+1;
        else
            if(a[i]>k)
                p[i]=p[i-1]-1;
        else
            p[i]=p[i-1];
    }
    for(int i=n;i>0;i--){
       if(a[i]<k)
            s[i]=s[i+1]+1;
        else
            if(a[i]>k)
                s[i]=s[i+1]-1;
        else
            break;
        f[s[i]]++;
    }
    f[0]++;
    for(int i=1;i<=n;i++){
        int x=p[n]-p[i-1];
        ans+=f[x];
        if(a[i]==k) break;
    }
    cout<<ans<<'\n';
    return 0;
}
