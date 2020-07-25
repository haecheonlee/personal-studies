/* reference: https://www.youtube.com/watch?v=YBqINhka5OA */

#include <iostream>

using namespace std;

int main() {
	int T;
	cin>>T;
	
	while(T--) {
		int N,M,K;
		cin>>N>>M>>K;
		

		int winner=min(N/K,M);
		int loser=(M-winner+K-2)/(K-1);
		
		cout<<winner-loser<<'\n';
	}
	return 0;
}
