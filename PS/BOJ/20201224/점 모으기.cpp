#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

bool cmpX(pii p, pii pp) {
	return p.first < pp.first;
}

bool cmpY(pii p, pii pp) {
	return p.second < pp.second; 
}

int main() {
	int N, M;
	cin >> N >> M;
	
	vector<pii> a(M);
	for(int i = 0; i < M; i++) cin >> a[i].first >> a[i].second;
	
	int X, Y;
	
	sort(a.begin(), a.end(), cmpX);
	X = a[M / 2].first;
	sort(a.begin(), a.end(), cmpY);
	Y = a[M / 2].second;
	
	int ans = 0;
	for(int i = 0; i < M; i++) ans += abs(X - a[i].first) + abs(Y - a[i].second);
	cout << ans << '\n';
	
	return 0;
}
