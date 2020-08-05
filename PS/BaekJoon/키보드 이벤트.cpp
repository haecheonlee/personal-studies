#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
using tpl=tuple<int,int,char>;

int main() {
	priority_queue<tpl> q;
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<M; i++) {
		int k,t;
		char l;
		
		cin>>k>>t>>l;
		q.push({t,k,l});
	}
	
	string ans="";
	while(!q.empty()) {
		ans+=get<2>(q.top());
		q.pop();
	}
	for(int i=ans.size()-1; i>=0; i--) cout<<ans[i];
	
	return 0;
}
