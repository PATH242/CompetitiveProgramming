/* binary search on the minimum string size that contains more than or equal the minimum number of each of the R nucleobases,
the function that checks if there exists a substring of size x in the main string that contains more than or equal the
minimum number of each of the R nucleobases uses sliding window to check all the valid substrings of size x.
rc is equal to the number of nucleobases we have more than or equal the minimum required number of them in the current substring
if rc equals to R at any given time then we've found a valid substring of size x so chk returns 1
ps: the answer is impossible if all the Xs we've checked returned false, so we output impossible when the binary search loop has reached 
its end and found no valid x*/



#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef long long int ll;
const int N=2e5+5;
int n,k,r,a[N],b,q,vis[N],sm,c;
bool chk(int x){
    int v2[n];
    int rc=c;
    if(!x) return (!sm);
    memset(v2,0,sizeof v2);
    for(int i=0;i<n;i++){
        if(i>=x&&vis[a[i-x]]){
            v2[a[i-x]]--;
            if(v2[a[i-x]]==vis[a[i-x]]-1)
                rc--;
        }
        if(vis[a[i]]){
            v2[a[i]]++;
            if(v2[a[i]]==vis[a[i]]) rc++;
        }
        if(rc==r) return 1;
    }
    return 0;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k>>r;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<r;i++){
        cin>>b>>q;
        vis[b]=q;
        sm+=q;
        if(!q) c++;
    }
    int s=0,e=n,mid;
    while(s<=e){
        mid=(s+e)/2;
        if(chk(mid))
            e=mid-1;
        else{
            if(s==e&&!chk(e+1)){
                cout<<"impossible\n";
                return 0;
            }
            s=mid+1;
        }
    }
    cout<<e+1<<'\n';
    return 0;
}
