#include <iostream>

using namespace std;

const int MAX=1e5+1;

int in[MAX], out[MAX];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	for(int i=0; i<N-1; i++) {
		int u,v;
		cin>>u>>v;

		in[v]++; out[u]++;
	}

	int Q;
	cin>>Q;

	while(Q--) {
		int q,x;
		cin>>q>>x;
		
		if(q==1) {
			// cut vertex
			if((in[x] && out[x]) || in[x]>=2 || out[x]>=2) cout<<"yes";
			else cout<<"no";
		} else if(q==2) {
			// cut edge
			cout<<"yes";
		}
		
		cout<<'\n';
	}
	
	return 0;
}
