#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	unordered_map<int, bool> m;
	vector<int> v;
	
	int n,num;
	
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>num;
		if(m[num]) continue;
		
		m[num]=true;
		v.push_back(num);
	}
	
	sort(v.begin(), v.end());
	
	for(int i=0; i<v.size(); i++) cout<<v[i]<<" ";
	
	return 0;
}

/*
boj.kr/10867

INPUT:
10
1 4 2 3 1 4 2 3 1 2

OUTPUT:
1 2 3 4
*/
