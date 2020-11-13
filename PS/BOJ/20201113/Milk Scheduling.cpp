#include <iostream>
#include <queue>
#include <vector>

using namespace std;

typedef long long ll;

const int MAX = 1e4 + 1;

vector<int> a[MAX];
int t[MAX], d[MAX];
int in[MAX];

int main() {
	int N, M;
	cin >> N >> M;

	for(int i = 1; i <= N; i++) {
		cin >> t[i];
		d[i] = t[i];	
	}
	for(int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		
		a[A].push_back(B);
		in[B]++;
	}
	
	queue<int> q;
	for(int i = 1; i <= N; i++) {
		if(in[i] == 0) q.push(i);
	}

	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(auto& y : a[x]) {
			in[y]--;

			d[y] = max(d[y], d[x] + t[y]);
			if(in[y] == 0) q.push(y);
		}
	}
	
	int ans = 0;
	for(int i = 1; i <= N; i++) ans = max(ans, d[i]);
	cout << ans;

	return 0;
}
