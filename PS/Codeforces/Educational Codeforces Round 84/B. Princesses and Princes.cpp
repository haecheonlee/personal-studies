#include <iostream>
#include <vector>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;

		vector<int> a[N];
		bool d_check[N] {false};
		bool k_check[N] {false};
		for(int i=0; i<N; i++) {
			int K;
			cin>>K;
			
			while(K--) {
				int x;
				cin>>x;
				
				x-=1;
				a[i].push_back(x);
			}
		}
		
		// matching starts
		for(int i=0; i<N; i++) {
			for(auto x : a[i]) {
				if(k_check[x]==false) {
					k_check[x]=d_check[i]=true;
					break;
				}
			}
		}
		
		// check if there is not matched one
		int d_index=-1, k_index=-1;
		for(int i=0; i<N; i++) {
			if(d_check[i]==false && d_index==-1) d_index=i+1;
			if(k_check[i]==false && k_index==-1) k_index=i+1;
		}
		
		if(d_index==-1 && k_index==-1) cout<<"OPTIMAL\n";
		else {
			cout<<"IMPROVE\n";
			cout<<d_index<<" "<<k_index<<"\n";
		}
	}

	return 0;
}
