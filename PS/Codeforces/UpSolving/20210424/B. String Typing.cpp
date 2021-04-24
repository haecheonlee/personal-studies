#include <iostream>
#include <queue>
#include <cstring>

#define fi first
#define sc second

using namespace std;

typedef pair<int,int> pii;

const int MAX_N = 1e2 + 10;

int d[MAX_N][2];

int main() {
	int N; cin >> N;
	string s; cin >> s;

	memset(d, 0x3f, sizeof(d));
	priority_queue<pair<int,pii>, vector<pair<int,pii>>, greater<pair<int,pii>>> pq;
	pq.push({1, {1, 0}});
	d[1][0] = 1;
	
	while(!pq.empty()) {
		int c = pq.top().fi;
		int x = pq.top().sc.fi;
		int o = pq.top().sc.sc;
		pq.pop();
		
		if(d[x][o] < c) continue;
		
		// next one
		if(x < N) {
			if(d[x + 1][o] > d[x][o] + 1) {
				d[x + 1][o] = d[x][o] + 1;
				pq.push({d[x + 1][o], {x + 1, o}});
			}
		}
		
		// copy & append
		if(o == 0) {
			int nx = x + (x + 1);
			
			if(nx < N) {
				bool flag = 1;
				for(int i = x + 1; i <= nx && flag; i++) 
					if(s[i] != s[i - (x + 1)]) flag = 0;
					
				if(flag && nx < N) {
					if(d[nx][1] > d[x][o] + 1) {
						d[nx][1] = d[x][o] + 1;
						pq.push({d[nx][1], {nx, 1}});
					}
				}
			}
		}
	}
	
	cout << min(d[N][0], d[N][1]) << '\n';
	
	return 0;
}
