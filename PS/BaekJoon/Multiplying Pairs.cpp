/* reference: ghjo92's code */

#include <iostream>
#include <vector>

using namespace std;

const int MAX=5e4+1;
const int LIMIT=1e5+2;

bool is_not_prime[MAX];
bool multiple[LIMIT];
vector<int> p;

int main() {
	// sieve of eratosthenes
	for(int i=2; i*i<MAX; i++) {
		if(is_not_prime[i]==false) {
			for(int j=i+i; j<MAX; j+=i) is_not_prime[j]=true;
		}
	}
	
	for(int i=2; i<MAX; i++) {
		if(is_not_prime[i]==false) {
			for(auto& x : p) {
				if(x*i<LIMIT) multiple[x*i]=true;
				else break;
			}
			p.push_back(i);
		}
	}

	int T;
	cin>>T;
	
	while(T--) {
		int K;
		cin>>K;
		
		for(int i=K; i<LIMIT; i++) {
			if(multiple[i]) {
				cout<<i<<'\n';
				break;
			}	
		}
	}

	return 0;
}
