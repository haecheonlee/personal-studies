/* reference: BledDest's ediotorial */

#include <iostream>
#include <vector>
#include <set>

using namespace std;
using pi=pair<int,int>;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N;
		cin>>N;
		
		multiset<int> s;
		for(int i=1; i<=N; i++) s.insert(i);
		
		vector<pi> ans;
		for(int i=0; i<N-1; i++) {
			auto it=s.end();
			it--;
			
			int a=*it;
			s.erase(it);
			
			it=s.end();
			it--;
			
			int b=*it;
			s.erase(*it);
			
			s.insert((a + b + 1) / 2);
			ans.push_back({a,b});
		}
		
		cout<<*s.begin()<<'\n';
		for(int i=0; i<ans.size(); i++) cout<<ans[i].first<<' '<<ans[i].second<<'\n';
	}
	
	return 0;
}
