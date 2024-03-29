/*  The initial sum of the first half is the sum of the first n elements, and the initial sum of the second half is the
sum of the last n elements. Now loop on the middle n elements from the beginning and see how you can maximize the sum of
the first half if you consider a[i] (i=n,i<2*n;i++) instead of any number of the first n numbers, and loop on the middle n
elements from last to first to try and minimize the sum of the second half...
xs== sum of the first half and vx[N] is the array that holds all possible sums of the first half
ys== sum of the second half and vy[N] is the array that holds all possible sums of the second half
maximize the answer then ...
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
const int N=5e5+5;
priority_queue < ll > x,y;
ll xs,ys,vy[N],vx[N],ans, n,a[N];
int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);
    ans=-1e16+7;
    cin>>n;
    for(int i=0;i<3*n;i++){
        cin>>a[i];
        if(i<n){
            x.push(-a[i]);
            xs+=a[i];
        }
        else
        if(i>=2*n){
            y.push(a[i]);
            ys+=a[i];
        }
    }
    vx[n]=xs;
    for(int i=n;i<2*n;i++){
        if(a[i]>-x.top()){
            xs+=x.top();
            x.pop();
            xs+=a[i];
            x.push(-a[i]);
        }
        vx[i-n]=xs;
    }
    vy[n]=ys;
    for(int i=2*n-1;i>=n;i--){
        if(a[i]<y.top()){
            ys-=y.top();
            y.pop();
            ys+=a[i];
            y.push(a[i]);
        }
        vy[i-n]=ys;
    }
    for(int i=0;i<n;i++)
        ans=max(ans,vx[i]-vy[i+1]);
    ans=max(vx[n]-vy[n],ans);
    ans=max(vx[n]-vy[0],ans);
    cout<<ans<<'\n';
    return 0;
}
