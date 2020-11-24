#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef pair<int,int> pii;

struct Node {
	int x, y, z, idx;	
	Node(int x, int y, int z, int idx) : x(x), y(y), z(z), idx(idx) {}
};

bool cmpX(const Node& L, const Node& R) {
	return L.x < R.x;
}

bool cmpY(const Node& L, const Node& R) {
	return L.y < R.y;
}

const int MAX = 1e5 + 1;

vector<pair<int,pii>> a;
vector<Node> b;
int p[MAX];

int getDist(int n1, int n2) {
	int x = abs(b[n1].x - b[n2].x);
	int y = abs(b[n1].y - b[n2].y);
	int z = abs(b[n1].z - b[n2].z);
	
	return min(x, min(y, z));
}

int Find(int x) {
	if(p[x] == x) return x;
	return p[x] = Find(p[x]);
}

void Union(int x, int y) {
	x = Find(x);
	y = Find(y);
	
	if(x != y) p[y] = x;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;

	for(int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		
		b.push_back({x, y, z, i});
	}
	
	sort(b.begin(), b.end(), cmpX);
	for(int i = 0; i < N; i++) {
		if(i - 1 >= 0) a.push_back({getDist(i, i - 1), {b[i].idx, b[i - 1].idx}});
		if(i + 1 < N) a.push_back({getDist(i, i + 1), {b[i].idx, b[i + 1].idx}});
	}
	
	sort(b.begin(), b.end(), cmpY);
	for(int i = 0; i < N; i++) {
		if(i - 1 >= 0) a.push_back({getDist(i, i - 1), {b[i].idx, b[i - 1].idx}});
		if(i + 1 < N) a.push_back({getDist(i, i + 1), {b[i].idx, b[i + 1].idx}});
	}

	sort(b.begin(), b.end(), [](const Node& L, const Node& R) {
		return L.z < R.z;
	});

	for(int i = 0; i < N; i++) {
		if(i - 1 >= 0) a.push_back({getDist(i, i - 1), {b[i].idx, b[i - 1].idx}});
		if(i + 1 < N) a.push_back({getDist(i, i + 1), {b[i].idx, b[i + 1].idx}});
	}

	// mst starts
	sort(a.begin(), a.end());	
	for(int i = 0; i < N; i++) p[i] = i;
	
	long long ans = 0;
	for(int i = 0; i < (int)a.size(); i++) {
		int c = a[i].first;
		int x = a[i].second.first;
		int y = a[i].second.second;
		
		if(Find(x) != Find(y)) {
			Union(x, y);
			ans += c;
		}
	}
	cout << ans << '\n';

	return 0;
}
