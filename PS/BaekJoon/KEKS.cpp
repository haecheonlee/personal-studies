#include <iostream>
#include <vector>

using namespace std;

int main() {
	int N,K,x;
	cin>>N>>K;
	
	vector<int> ans;
	for(int i=0; i<N; i++) {
		scanf("%1d", &x);
		
		while(K && !ans.empty() && ans.back()<x) {
			ans.pop_back();
			K--;
		}
		
		ans.push_back(x);
	}
	
	for(int i=0; i<ans.size()-K; i++) cout<<ans[i];

	return 0;
}
