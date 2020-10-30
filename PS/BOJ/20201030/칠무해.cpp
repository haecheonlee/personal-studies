#include <iostream>
#include <set>
#include <iomanip>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	multiset<double> ans;
	for(int i=0; i<N; i++) {
		double x;
		cin>>x;
		
		if(ans.size() < 7) {
			ans.insert(x);
		}
		else {
			auto it = ans.end();
			it--;
			
			if(*it > x) {
				ans.erase(it);
				ans.insert(x);
			}
		}
	}
	
	cout<<fixed<<setprecision(3);
	for(auto& x : ans) cout<<x<<'\n';

	return 0;
}
