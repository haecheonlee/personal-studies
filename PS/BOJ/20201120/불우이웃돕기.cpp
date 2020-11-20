#include <iostream>
#include <vector>
#include <algorithm>

#define fi first
#define sc second
#define sz(x) (int)(x.size())

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e2 + 1;

vector<pair<int,pii>> a;
int p[MAX];

int convert(char x) {
	if(x >= 'a' && x <= 'z') return x - 'a' + 1;
	return x - 'A' + 27;
}

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(p[x]);
	y = Find(p[y]);
	
	if(x != y) {
		p[y] = x;
	}
}

int main() {
	int N;
	cin >> N;
	
	int sum = 0;
	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			char x;
			cin >> x;
			
			if(x != '0') {
				int c = convert(x);
				a.push_back({c, {i,j}});

				sum += c;
			}
		}
	}
	
	sort(a.begin(), a.end());
	for(int i = 1; i <= N; i++) p[i] = i;
	
	int used = 0;
	for(int i = 0; i < sz(a); i++) {
		int c = a[i].fi;
		int x = a[i].sc.fi;
		int y = a[i].sc.sc;
		
		if(Find(x) != Find(y)) {
			used += c;
			Union(x,y);
		}
	}
	
	bool is_all_connected = true;
	for(int i = 2; i <= N; i++) {
		if(Find(i) != Find(i - 1)) is_all_connected = false;
	}
	
	cout << (is_all_connected ? (sum - used) : - 1) << '\n';
	
	return 0;
}
