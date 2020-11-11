#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e3 + 5;

int N, M;
vector<pii> a;
int d[MAX][MAX];

int get_distance(int x, int y) {
	return abs(a[x].first - a[y].first) + abs(a[x].second - a[y].second);
}

int go(int now, int p1, int p2) {
	if(now > M) return 0;
	
	int& ret = d[p1][p2];
	if(ret != -1) return ret;
	ret = 1e9;

	int d1 = go(now + 1, now, p2) + get_distance(now, p1);
	int d2 = go(now + 1, p1, now) + get_distance(now, p2);
	
	return ret = min(d1, d2);
}

void go2(int now, int p1, int p2) {
	if(now > M) return;
	
	int d1 = go(now + 1, now, p2) + get_distance(now, p1);
	int d2 = go(now + 1, p1, now) + get_distance(now, p2);
	
	if(d1 < d2) {
		cout << 1 << '\n';
		go2(now + 1, now, p2);
	} else {
		cout << 2 << '\n';
		go2(now + 1, p1, now);
	}
}

int main() {
	cin >> N >> M;

	a.resize(M + 2);
	a[0] = {1,1};
	for(int i = 1; i <= M; i++) cin >> a[i].first >> a[i].second;
	a[M + 1] = {N, N};

	memset(d, -1, sizeof(d));	
	cout << go(1, 0, M + 1) << '\n';
	go2(1, 0, M + 1);

	return 0;
}
