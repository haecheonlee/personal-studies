#include <iostream>
#include <vector>

using namespace std;

typedef pair<int,int> pii;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin >> N;
	
	int a[N + 1];
	for(int i = 1; i <= N; i++) cin >> a[i];
	
	vector<pii> ans;
	for(int i = 1; i < N; i++) {
		int j = i;
		
		bool is_all_same = true;
		while(a[j] >= a [j + 1] && j < N) {
			if(a[j] != a[j + 1]) is_all_same = false;
			j++;
		}
		
		if(j != i && !is_all_same) {
			ans.push_back({i, j});
			i = j;
		}
	}
	
	if(ans.size() >= 2) {
		cout << "impossible";
	} else if(ans.size() == 0){
		cout << "1 1";
	} else {
		int S = ans[0].first, E = ans[0].second;

		bool check = true;
		
		for(int i = 1; i < S; i++) if(a[i] > a[E]) check = false;
		for(int i = N; i > E; i--) if(a[i] < a[S]) check = false;
			
		if(check) cout << S << ' ' << E ;
		else cout << "impossible";
	}

	return 0;
}
