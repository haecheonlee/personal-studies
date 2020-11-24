#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <iomanip>
#include <cstring>
 
#define sz(x) (int)(x.size())
 
using namespace std;
 
typedef long long ll;
typedef pair<int,int> pii;
 
int main() {
	int T;
	cin >> T;
 
	while(T--) {
		int N;
		cin >> N;
 
		int a[N + 1];
		for(int i = 1; i <= N; i++) a[i] = i;
		if(N&1) swap(a[N / 2], a[N / 2 + 1]);		
		for(int i = N; i >= 1; i--) cout << a[i] << ' ';
		cout << '\n';
	}
 
	return 0;
}
