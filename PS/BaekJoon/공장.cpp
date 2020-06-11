#include <iostream>
#include <vector>
#include <map>

using namespace std;

int tree[2000001];

int sum(int node, int start, int end, int i, int j) {
	if(i>end || j<start) return 0;
	if(i<=start && end<=j) return tree[node];
	
	return sum(node*2, start, (start+end)/2, i, j)+
		   sum(node*2+1, (start+end)/2+1, end, i, j);
}

void update(int node, int start, int end, int i) {
	if(i<start || i>end) return;
	
	tree[node]+=1;
	if(start!=end) {
		update(node*2, start, (start+end)/2, i);
		update(node*2+1, (start+end)/2+1, end, i);
	}
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	
	map<int,int> position;
	for(int i=0; i<n; i++) {
		int num;
		cin>>num;
		
		position[num]=i;
	}
	
	long long ans=0;
	for(int i=0; i<n; i++) {
		ans+=(long long)sum(1, 1, n, position[a[i]], n);
		update(1, 1, n, position[a[i]]);
	}
	cout<<ans;
	
	return 0;
}
