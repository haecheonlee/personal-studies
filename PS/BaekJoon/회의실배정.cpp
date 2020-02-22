#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool cmp(const pair<int,int> &l, const pair<int,int> &r) {
	if(l.second==r.second) return l.first<r.first;
	else return l.second<r.second;
}

int main() {
	int n;
	cin>>n;

	vector<pair<int,int>> vec(n);
	for(int i=0; i<n; i++) cin>>vec[i].first>>vec[i].second;
	sort(vec.begin(), vec.end(), cmp);
	
	int cnt=0,end=0;
	for(int i=0; i<vec.size(); i++) {
		if(end<=vec[i].first) {
			end=vec[i].second;
			cnt++;
		}
	}
	
	cout<<cnt;

	return 0;
}

/*
boj.kr/1931

INPUT:
11
1 4
3 5
0 6
5 7
3 8
5 9
6 10
8 11
8 12
2 13
12 14

OUTPUT:
4
*/
