/* sort the cards and make an array with the smallest (n-k) cards on the top, and the rest in reverse order. Then
loop and see if this is valid order or not*/

#include <bits/stdc++.h>
using namespace std;
#define f first
#define s second
typedef unsigned long long int ll;
const int N=5e5+5;
int n,k,a[N],b[N],lst,tmp,tmp2;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n>>k;
    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    for(int i=0;i<n-k;i++)
        b[i]=a[i];
    lst=n-k;
    for(int i=n-1;i>=n-k;i--,lst++)
        b[lst]=a[i];
    lst=0;
    for(int i=n-1;i>=0;i--)
        if(b[i]>lst)
            lst++;
    if(lst!=k)
        cout<<-1<<'\n';
    else{
        for(int i=0;i<n;i++)
            cout<<b[i]<<" ";
        cout<<'\n';
    }
	return 0;
}

