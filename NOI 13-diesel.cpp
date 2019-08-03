/* to get the maximum cost we can get to reach cell (m-1,n-1), we can use BFS to get the best path for every cell
and handle the case in which reaching that cell is impossible*/

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef long long int ll;
const int N=1e3+5;
int n,m,a[N][N],vis[N][N];
bool valid(int x, int y){
    return (!(x<0||y<0||y>=m||x>=n));
}
void BFS(){
    int mass= 33000;
    priority_queue< pair< int,pair<int,int> > > q;
    pair< int,pair<int,int> > tmp;
    q.push(mp( mass, mp(0,0)));
    while(q.size()){
        tmp=q.top();
        q.pop();
        if(tmp.f<=vis[tmp.s.f][tmp.s.s])
            continue;
        vis[tmp.s.f][tmp.s.s]=tmp.f;
        if(valid(tmp.s.f,tmp.s.s+1)){
            if(a[tmp.s.f][tmp.s.s+1]>a[tmp.s.f][tmp.s.s]){
                int x=(tmp.f/1000) * (a[tmp.s.f][tmp.s.s+1]-a[tmp.s.f][tmp.s.s])/100*4+10;
                if(vis[tmp.s.f][tmp.s.s+1]<tmp.f-x)
                q.push(mp(tmp.f-x, mp(tmp.s.f,tmp.s.s+1)));
            }
            else
                if(vis[tmp.s.f][tmp.s.s+1]<tmp.f-10)
                q.push(mp(tmp.f-10,mp(tmp.s.f,tmp.s.s+1)));
        }
        if(valid(tmp.s.f,tmp.s.s-1)){
            if(a[tmp.s.f][tmp.s.s-1]>a[tmp.s.f][tmp.s.s]){
                int x=tmp.f/1000*(a[tmp.s.f][tmp.s.s-1]-a[tmp.s.f][tmp.s.s])/100*4+10;
                 if(vis[tmp.s.f][tmp.s.s-1]<tmp.f-x)
                q.push(mp(tmp.f-x, mp(tmp.s.f,tmp.s.s-1)));
            }
            else
                if(vis[tmp.s.f][tmp.s.s-1]<tmp.f-10)
                q.push(mp(tmp.f-10,mp(tmp.s.f,tmp.s.s-1)));
        }
        if(valid(tmp.s.f+1,tmp.s.s)){
            if(a[tmp.s.f+1][tmp.s.s]>a[tmp.s.f][tmp.s.s]){
                int x=tmp.f/1000*(a[tmp.s.f+1][tmp.s.s]-a[tmp.s.f][tmp.s.s])/100*4+10;
                 if(vis[tmp.s.f+1][tmp.s.s]<tmp.f-x)
                q.push(mp(tmp.f-x, mp(tmp.s.f+1,tmp.s.s)));
            }
            else
                if(vis[tmp.s.f+1][tmp.s.s]<tmp.f-10)
                q.push(mp(tmp.f-10,mp(tmp.s.f+1,tmp.s.s)));
        }
    }
    return;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=0;i<n;i++)
    for(int j=0;j<m;j++)
        cin>>a[i][j];
    BFS();
    if(vis[n-1][m-1]<8000)
        cout<<-1<<'\n';
    else
        cout<<vis[n-1][m-1]-8000<<'\n';
	return 0;
}
