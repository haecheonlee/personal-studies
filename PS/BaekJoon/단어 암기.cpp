/* reference: https://panty.run/boj-8117 */

#include <iostream>

using namespace std;

int current=0;
int bit[10000];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	for(int i=0; i<N; i++) {
		string s;
		cin>>s;
		
		for(auto& c : s) {
			current |= 1<<(c-'a');
			bit[i] |= 1<<(c-'a');
		}
	}

	while(M--) {
		int o;
		char x;
		cin>>o>>x;
		
		if(o==1) {
			// forget
			current &= ~(1<<(x-'a'));
		} else {
			// remember
			current |= (1<<(x-'a'));
		}
		
		// get answer
		int ans=0;
		for(int i=0; i<N; i++) {
			if((bit[i] & current) == bit[i]) ans++;
		}
		cout<<ans<<'\n';
	}
	
	return 0;
}
