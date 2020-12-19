#include <iostream>
 
using namespace std;
 
const int MAX = 1e5 + 1;
 
int d[MAX];
bool check[MAX];
 
int main() {
	// prime
	for(int i = 2; i < MAX; i++) {
		if(!check[i]) {
			for(int j = i + i; j < MAX; j += i) check[j] = true;
		}
	}
	
	// number of divsors
	for(int i = 2; i < MAX; i++) {
		int x = i;
		for(int k = 2; k * k <= x; k++) {
			if(x % k == 0) {
				if(!check[k]) d[i]++;
				x /= k;
				k = 1;
			}
		}
		
		if(x != 1 && !check[x]) d[i]++;
	}
	
	int A, B;
	cin >> A >> B;
	
	int ans = 0;
	for(int i = A; i <= B; i++) {
		if(d[i] == 0 || d[i] == 1) continue;
		if(!check[d[i]]) ans++;
	}
	cout << ans << '\n';
 
	return 0;
}
