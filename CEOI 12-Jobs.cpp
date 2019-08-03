/* to get the minimum number of machines needed to execute the jobs with no delays later than d days after the day
the job was submitted in, we binary search using a function that checks if jobs can be executed using x machines */

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long int ll;
const int N=1e6+3;
int n,d,m;
pair<int,int> a[N];
bool chk(int x){
    queue < pair<int,int> > q;
    pair<int,int> tmp;
    for(int i=0;i<m;i++)
        q.push(make_pair(a[i].f,a[i].f+d));
    for(int i=1;i<=n&&q.size();i++){
        for(int j=0;j<x&&q.size();j++){
            tmp=q.front();
            if(tmp.s<i) return 0;
            if(tmp.f>i) break;
            q.pop();
        }
    }
    return (!q.size());
}
void out (int x){
    int tmp=0;
    for(int i=1;i<=n;i++){
        for(int j=0;j<x&&tmp<m;j++){
            cout<<a[tmp].s<<" ";
            tmp++;
        }
        cout<<0<<'\n';
    }
    return;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>d>>m;
    for(int i=0;i<m;i++){
        cin>>a[i].f;
        a[i].s=i+1;
    }
    sort(a,a+m);
    int s=1,e=m,mid;
    while(s<=e){
        mid=(s+e)/2;
        if(chk(mid))
            e=mid-1;
        else
            s=mid+1;
    }
    e++;
    cout<<e<<'\n';
    out(e);
	return 0;
}
