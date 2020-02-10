#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compareIndex(const pair<int,int> &l, const pair<int,int> &r) {
	return l.first<r.first;
}

int main() {
	int start;
	int n,k,m;
	cin>>n>>k;
	
	vector<pair<int, int>> vec;
	for(int i=0; i<n; i++) {
		cin>>m;
		vec.push_back({i,m});
	}
	
	int cnt=0;
	do {
		bool check=true;
        start=500;
        
		for(int i=0; i<vec.size(); i++) {
			start+=(vec[i].second-k);

			if(start<500) {
				check=false;
				break;
			}
		}
		
		if(check) cnt++;
	}while(next_permutation(vec.begin(), vec.end(), compareIndex));
	
	cout<<cnt;

	return 0;
}

/*
boj.kr/18429

INPUT:
3 4
3 7 5

OUTPUT:
4
*/
