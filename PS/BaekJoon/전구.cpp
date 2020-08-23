#include <iostream>
#include <set>

using namespace std;

const int MAX=1e5;

int a[MAX+1], p[MAX+1], b[MAX+1], d[MAX+1];

void get_list(int x, set<int>& list) {
	if(x==-1) return;
	get_list(b[x],list);
	list.insert(a[x]);
}

int main() {
	int N;
	cin>>N;
	
	for(int i=0; i<N; i++) cin>>a[i];
	for(int i=0; i<N; i++) {
		int x;
		cin>>x;
		
		p[x]=i;
	}
	
	
	for(int i=0; i<N; i++) {
		d[i]=1;
		b[i]=-1;
		
		for(int j=0; j<i; j++) {
			if(p[a[i]]>p[a[j]] && d[i]<d[j]+1) {
				d[i]=d[j]+1;
				b[i]=j;
			}
		}
	}
	
	int lis=0;
	int idx=-1;
	for(int i=0; i<N; i++) {
		if(d[i]>lis) {
			idx=i;
			lis=d[i];
		}
	}
	
	set<int> ans;
	get_list(idx,ans);
	
	// print answer
	cout<<ans.size()<<'\n';
	for(auto& x : ans) cout<<x<<' ';
	
	return 0;
}
