/* reference: baekjoon/codeplus */

#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

#define fastio ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

struct Student {
	int a, b, c;
};

const int MAX_N = 5e5 + 1;
const int INF = 1e9;

vector<Student> s;
int tree[MAX_N * 4];

void init(int node, int start, int end) {
	tree[node] = INF;
	if(start != end) {
		init(node * 2, start, (start + end) / 2);
		init(node * 2 + 1, (start + end) / 2 + 1, end);
	}
}

int query(int node, int start, int end, int L, int R) {
	if(L > end || R < start) return INF;
	if(L <= start && end <= R) return tree[node];
	
	return min(query(node * 2, start, (start + end) / 2, L, R), 
			   query(node * 2 + 1, (start + end) / 2 + 1, end, L, R));
}

void update(int node, int start, int end, int i, int v) {
	if(i > end || i < start) return;
	
	tree[node] = min(tree[node], v);
	if(start != end) {
		update(node * 2, start, (start + end) / 2, i ,v);
		update(node * 2 + 1, (start + end) / 2 + 1, end, i, v);
	}
}

int main() {
	fastio
	
	int N; cin >> N;
	
	s.resize(N + 1);
	for(int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		
		s[x].a = i;
	}
	
	for(int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		
		s[x].b = i;
	}
	
	for(int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		
		s[x].c = i;
	}
	
	sort(s.begin() + 1, s.end(), [](const Student& L, const Student& R) {
		return L.a < R.a;
	});

	init(1, 1, N);
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		int C = query(1, 1, N, 1, s[i].b);
		if(C > s[i].c) ans++;
		update(1, 1, N, s[i].b, s[i].c);
	}
	cout << ans << '\n';

	return 0;
}
