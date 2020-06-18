/* BOJ */

#include <iostream>
#include <vector>

using namespace std;
using ll=long long;

int a[100001];
int tree[270000];

void init(int node, int start, int end) {
    if(start==end) tree[node]=start;
    else {
        int mid=(start+end)/2;
        init(node*2, start, mid);
        init(node*2+1, mid+1, end);
        
        if(a[tree[node*2]]>a[tree[node*2+1]]) tree[node]=tree[node*2];
        else tree[node]=tree[node*2+1];
    }
}

void update(int node, int start, int end, int index, int val) {
    if(index<start || end<index) return;
    if(start==end) {
        a[index]=val;
        tree[node]=start;
        return;
    }
    
    int mid=(start+end)/2;
    update(node*2, start, mid, index, val);
    update(node*2+1, mid+1, end, index, val);
    
    if(a[tree[node*2]]>a[tree[node*2+1]]) tree[node]=tree[node*2];
    else tree[node]=tree[node*2+1];
}

int query(int node, int start, int end, int i, int j) {
    if(end<i || j<start) return -1;
    if(i<=start && end<=j) return tree[node];
    
    int mid=(start+end)/2;
    int m1=query(node*2, start, mid, i, j);
    int m2=query(node*2+1, mid+1, end, i, j);
    
    if(m1==-1) return m2;
    else if(m2==-1) return m1;
    else {
        if(a[m1]>a[m2]) return m1;
        else return m2;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin>>n;
    
    for(int i=1; i<=n; i++) cin>>a[i];
    init(1,1,n);
    
    int m;
    cin>>m;

    while(m--) {
        int q;
        cin>>q;
        
        if(q==1) {
            //update
            int i,v;
            cin>>i>>v;
            update(1,1,n,i,v);
        }
        
        if(q==2) {
            // print max
            int l,r;
            cin>>l>>r;
            
            int ans=0;
            int p=query(1,1,n,l,r);

            if(p-1>=l) {
                int p2=query(1,1,n,l,p-1);
                ans=max(ans, a[p]+a[p2]);
            }
            
            if(p+1<=r) {
                int p2=query(1,1,n,p+1,r);
                ans=max(ans, a[p]+a[p2]);
            }
            cout<<ans<<'\n';
        }
    }

    return 0;
}
