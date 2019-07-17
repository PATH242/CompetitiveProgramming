/* Counts number of elements that are going to shift a[i] to the right, and number of elements that are going to shift a[i] to the left.
answer is abs ( ( (i+1) + right shifts - left shift) - a[i]) 
right shifts are counted in s[N], left shifts are counted in p[N]
*/

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long int ll;
typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;
const int N=1e5+5;
int n,a[N],p[N],s[N],ans[N],vis[N],x;
ordered_set st;
int main(){
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++){
            st.insert(a[i]);
            vis[a[i]]=1;
        if(a[i]<n/2+1){
            st.insert(n-a[i]+2);
            x= st.size()-st.order_of_key(n-a[i]+2)+vis[n-a[i]+2]-1;
            if(!vis[n-a[i]+2])
                st.erase(n-a[i]+2);

        }
          else
             x= st.size()-st.order_of_key(a[i])-1;
            p[i]=x;
    }
    st.clear();
    memset(vis,0,sizeof vis);
    for(int i=n-1;i>=0;i--){
        if(a[i]<n/2+1){
            st.insert(a[i]);
            vis[a[i]]=1;
            x= st.order_of_key(a[i]);
            s[i]=x;
            ans[a[i]]= (i+1) -p[i]+s[i];
            ans[a[i]]=abs(ans[a[i]]-a[i]);
        }
        else{
            st.insert(n-a[i]+1);
            x= st.order_of_key(n-a[i]+1)+ vis[n-a[i]+1];
            st.insert(a[i]);
            vis[a[i]]=1;
            if(!vis[n-a[i]+1]) st.erase(n-a[i]+1);
            s[i]=x;
            ans[a[i]]= (i+1)-p[i]+s[i];
            ans[a[i]]= abs(ans[a[i]]-a[i]);
        }
    }
    //for(int i=0;i<n;i++)
       // cout<<p[i]<<" "<<s[i]<<'\n';
    int s=1,e=n;
    for(int i=0;i<n;i++){
        if((i%2)){
            cout<<ans[e]<<'\n';
            e--;
        }
        else{
            cout<<ans[s]<<'\n';
            s++;
        }
    }
    return 0;
}
