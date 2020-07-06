#include <iostream>
#include <vector>

using namespace std;

vector<int> go(vector<int> a) {
	int i=2;
	
	while(1) {
		int v=a[i-2]-a[i-1];
		if(v<0) break;
		
		a.push_back(v);	
		i++;
	}
	
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	vector<int> ans;
	for(int i=1; i<=N; i++) {
		vector<int> temp=go({N,i});
		
		if(temp.size()>ans.size()) ans=temp;
	}
	
	cout<<ans.size()<<'\n';
	for(auto x : ans) cout<<x<<" ";
	
	return 0;
}
