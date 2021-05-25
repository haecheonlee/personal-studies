#include <iostream>
#include <vector>

using namespace std;

const int MAX_N = 1e3 + 10;

vector<int> G[MAX_N];
bool check[MAX_N];

int main() {
	int N; cin >> N;
	for(int i = 1; i <= N - 1; i++) {
		int x; cin >> x;
		G[x].push_back(i + 1);
		check[x] = 1;
	}
	
	for(int i = 1; i <= N; i++) {
		if(check[i]) {
			int leaf = 0;
			for(auto& y : G[i]) if(!check[y]) leaf++;
			if(leaf < 3) {
				cout << "No" << '\n';
				return 0;
			}
		}
	}
	
	cout << "Yes" << '\n';
	
	return 0;
}
