#include <iostream>

using namespace std;

typedef pair<int,int> pii;

const int MAX = 1e5 + 1;

pii a[MAX];

int main() {
	int N;
	cin>>N;
	
	for(int i = 0; i < N; i++) cin>>a[i].first>>a[i].second;
	
	int dist = 0;
	for(int i = 0; i < N - 1; i++) {
		dist += abs(a[i].first - a[i + 1].first) + 
				abs(a[i].second - a[i + 1].second);
	}
	
	int ans = dist;
	for(int i = 0; i < N - 2; i++) {
		int next = abs(a[i + 2].first - a[i].first) + abs(a[i + 2].second - a[i].second);
		int now = abs(a[i + 1].first - a[i].first) + abs(a[i + 1].second - a[i].second) + 
				  abs(a[i + 1].first - a[i + 2].first) + abs(a[i + 1].second - a[i + 2].second);
		ans = min(ans, dist - now + next);
	}
	cout<<ans;
	
	return 0;
}
