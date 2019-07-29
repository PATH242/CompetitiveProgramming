/* check the divisors of each i (0<=i<=n) and add the number of times those divisors were repeated
in the array of jumps (the frequency is calculated in f[N] so you can add f[divisor] )
*/
#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long int ll;
const int N=1e6+6;
int n,k,f[N],x,q,l,r;
ll a[N];
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<k;i++){
        cin>>x;
        f[x]++;
        a[0]++;
    }
    for(int i=1;i<n;i++){
        for(int j=1;j*j<=i;j++){
            if((i%j)) continue;
            if(j*j==i)
                a[i]+=f[j];
            else{
                a[i]+=f[j];
                a[i]+=f[i/j];
            }
        }
    }
    for(int i=1;i<n;i++)
        a[i]+=a[i-1];
    cin>>q;
    while(q--){
        cin>>l>>r;
        cout<<a[r]-(l==0?0:a[l-1])<<'\n';
    }
	return 0;
}

