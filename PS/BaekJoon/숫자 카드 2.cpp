#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	unordered_map<string, int> mp;
	
	int n,m,num;
	
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>num;
		
		if(mp.find(to_string(num)) == mp.end()) {
			mp[to_string(num)]=1;
		} else {
			mp[to_string(num)]++;
		}
	}
	
	cin>>m;
	for(int i=0; i<m; i++) {
		cin>>num;
		
		if(mp.find(to_string(num)) == mp.end()) cout<<0<<" ";
		else cout<<mp[to_string(num)]<<" ";
	}

	return 0;
}

/*
boj.kr/10816

INPUT:
10
6 3 2 10 10 10 -10 -10 7 3
8
10 9 -5 2 3 4 5 -10

OUTPUT:
3 0 0 1 2 0 0 2
*/
