//https://github.com/mostafa-saad/MyCompetitiveProgramming/blob/master/Olympiad/COCI/official/2015/contest4_solutions/solutions.pdf

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
#define mp make_pair
typedef long long int ll;
const int N=2e5+5;
int n,t,x,y,a[N];
vector<int> e[N];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<5;i++){
        cin>>t;
        while(t--){
            cin>>x>>y;
            e[x].push_back(y);
            e[y].push_back(x);
        }
    }
    for(int k=0;k<10;k++)
    for(int i=1;i<=n;i++){
        t=0;
        for(int j=0;j<e[i].size();j++)
            if(a[e[i][j]]==a[i]) t++;
        if(t>2)
            a[i]=(a[i]+1)%2;
    }

    for(int i=1;i<=n;i++)
        cout<<((char)(a[i]+'A'));
    cout<<'\n';
    return 0;
}
