#include <iostream>
#include <vector>
 
using namespace std;
using pii=pair<int,int>;
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int T;
	cin>>T;
 
	while(T--) {
		int N;
		cin>>N;
 
		for(int i = 4; i <= N * 4; i++) {
			vector<int> ans;
			ans.push_back(i);
 
			for(int j = i + 2; j <= N * 4 && ans.size() < N; j += 2) {
				if(i % 2 == 0) {
					bool is_possible = true;
 
					for(auto& x : ans) {
						if(j % x == 0) {
							is_possible = false;
							break;
						}
					}
 
					if(is_possible) ans.push_back(j);
				}
			}
 
			if(ans.size() == N) {
				for(auto& x : ans) cout<<x<<' ';
				cout<<'\n';
				break;
			}
		}
	}
 
	return 0;
}
