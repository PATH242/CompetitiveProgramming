#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=1e4+5;
int n,z,o,t,vis[N];
pair<int,int> a[N];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>a[i].second;
        a[i].first= (a[i].second%3);
        if(!a[i].first) z++;
        else
            if(a[i].first==1) o++;
        else
            if(a[i].first==2) t++;
    }
    sort(a,a+n);
    if( (z>=min(o,t)||z)&&z<=o+t+1){
        if(z>=min(o,t)){
            int f= ((z==min(o,t))?z:0), s=((z==min(o,t))?0:z);
            while(f<n||s<n){
                if(f<n&&!vis[f]) cout<<a[f].second<<" ";
                    vis[f]=1;
                if(s<n&&!vis[s]) cout<<a[s].second<<" ";
                vis[s]=1;
                s++; f++;
            }

        }
        else{
            for(int i=z;i<z+o;i++)
                cout<<a[i].second<<" ";
            int f=0,s=z+o;
            while(s<n){
                if(!a[f].first) cout<<a[f].second<<" ";
                cout<<a[s].second<<" ";
                f++; s++;
            }
        }
        cout<<'\n';
    }
    else
        cout<<"impossible\n";
    return 0;
}
