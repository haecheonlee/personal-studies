#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

const int MAX = 1e3;

vector<int> a[MAX];
string b[MAX];
int d[MAX], p[MAX];

void go(int y) {
	if(y == -1) return;
	go(p[y]);
	cout<<y + 1<<' ';
}

int main() {
	int N,L;
	cin>>N>>L;
	
	for(int i = 0; i < N; i++) cin>>b[i];
	
	for(int i = 0; i < N; i++) {
		for(int j = i + 1; j < N; j++) {
			int diff = 0;
			for(int k = 0; k < L; k++) 
				if(b[i][k] != b[j][k]) diff++;
			
			if(diff == 1) {
				a[i].push_back(j);
				a[j].push_back(i);
			}
		}
	}
	
	int S,E;
	cin>>S>>E;
	S--, E--;
	
	memset(p, -1, sizeof(p));
	memset(d, -1, sizeof(d));

	queue<int> q;
	q.push(S);
	d[S] = 0;
	
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		
		for(auto& y : a[x]) {
			if(d[y] == -1) {
				d[y] = d[x] + 1;
				p[y] = x;
				q.push(y);
			}
		}
	}

	if(d[E] == -1) cout<<-1;
	else go(E);
	
	return 0;
}
