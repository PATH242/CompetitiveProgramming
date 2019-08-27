/*binary search on the minimum number of seconds needed to deliver the news and check if x seconds is valid by function
"chk" which basically checks the furthest (closest to the next element) each element can get and if it's valid or not*/

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef long long int ll;
const int N=1e5+5;
const double er=0.001;
int n;
double k,d[N],a;
bool chk(double x){
    a=d[0]+x;
    for(int i=1;i<n;i++){
        if(d[i]-a-x<=k)
           a=min(a+k,d[i]+x);
        else
            return 0;
    }
    return 1;
}
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>k>>n;
    for(int i=0;i<n;i++)
        cin>>d[i];
    double s=0.0,e=d[n-1]-d[0],mid;
    while(s<e&&e-s>er){
        mid=(s+e)/2.0;
        //cout<<mid<<" start\n";
        if(chk(mid))
            e=mid;
        else
            s=mid;
        //cout<<mid<<" end\n";
    }
    cout<<setprecision(3)<<fixed;
    cout<<e<<'\n';
    return 0;
}
