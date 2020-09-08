#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> cls;
vector<int> power;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N,M;
	cin>>N>>M;
	
	cls.resize(N), power.resize(N);
	for(int i=0; i<N; i++) cin>>cls[i]>>power[i];
	for(int i=0; i<M; i++) {
		int x;
		cin>>x;
		
		auto idx = lower_bound(power.begin(), power.end(), x) - power.begin();
		cout<<cls[idx]<<'\n';
	}
	
	return 0;
}
