/* editorial */

#include <iostream>
#include <vector>

#define sz(x) (int)x.size()

using namespace std;

const int MAX = 1e5 + 1;

int N, M, distinct;
int freq[MAX];

void remove() {
	for(int i = 1; i <= N; i++) {
		freq[i]--;
		if(freq[i] == 0) distinct--;
	}
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int x; cin >> x;
		
		if(freq[x] == 0) distinct++;
		freq[x]++;
		
		if(distinct == N) {
			cout << 1;
			remove();
		} else {
			cout << 0;
		}
	}
	
	return 0;
}
