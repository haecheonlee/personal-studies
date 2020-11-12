/* reference: https://fieldanimal.tistory.com/43 */

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 1;

vector<pii> a[MAX];
int p[MAX];
int d[MAX];
int in[MAX];

void print(int x) {
	if(p[x] != 1) print(p[x]);
	cout << x << ' ';
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N, M;
	cin >> N >> M;
	
	for(int i = 0; i < M; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		
		a[u].push_back({v,c});
		in[v]++;
	}
	
	queue<int> q;
	q.push(1);
	
	while(in[1]) {
		int x = q.front();
		q.pop();
		
		for(auto& next : a[x]) {
			int y = next.first;
			int nc = next.second + d[x];
			
			in[y]--;
			if(d[y] < nc) {
				d[y] = nc;
				p[y] = x;
			}
			
			if(in[y] == 0) {
				q.push(y);
			}
		}
	}
	
	cout << d[1] << '\n';
	cout << 1 << ' '; print(1);
	
	return 0;
}
