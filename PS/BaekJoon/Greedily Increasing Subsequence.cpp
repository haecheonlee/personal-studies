#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	int A[N+1];
	vector<int> G;
	for(int i=1; i<=N; i++) cin>>A[i];
	G.push_back(A[1]);
	
	for(int i=2; i<=N; i++) {
		if(G[G.size()-1]<A[i]) G.push_back(A[i]);
	}
	
	cout<<G.size()<<endl;
	for(auto& x : G) cout<<x<<" ";
	
	return 0;
}
