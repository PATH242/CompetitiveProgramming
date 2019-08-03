/* since we want to get he maximum number of participants in finals, and we can't have a club participate if their club size
isn't divisable by the team size, we try all possible team sizes and use sieve to get the maximum number of
eligible participants
*/
#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long int ll;
const int N=2e5+5,M=2e6+5;
int n,x,f[M],tmp;
ll ans;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&x);
        f[x]++;
    }
    for(int i=1;i<M;i++){
        tmp=0;
        for(int j=i;j<M;j+=i)
            tmp+=f[j];
        if(tmp>1)
        ans=max(ans, tmp* 1ll * i);
    }
    cout<<ans<<'\n';
	return 0;
}
