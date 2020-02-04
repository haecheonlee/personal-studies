#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,m,num;
	cin>>n>>m;
	
	vector<vector<int>> vec;
	vec.resize(n);
	for(int i=0; i<n; i++) {
		vec[i].resize(m);
		for(auto &j : vec[i]) cin>>j;
	}
	
	sort(vec.begin(), vec.end());
	for(int i=1; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(vec[i-1][j]>vec[i][j]) {
				cout<<"NO";
				return 0;
			}
		}
	}
	
	cout<<"YES";
	
	return 0;
}

/*
boj.kr/18248

INPUT:
1 2
1 1

OUTPUT:
YES
*/
