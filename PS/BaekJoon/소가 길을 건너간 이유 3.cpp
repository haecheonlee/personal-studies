#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int t1,t2;
	vector<pair<int,int>> vec;
	
	for(int i=0; i<n; i++) {
		cin>>t1>>t2;
		vec.push_back({t1,t2});
	}
	
	sort(vec.begin(), vec.end(), [](const pair<int,int> &l, const pair<int,int> &r) {
		return l.first<r.first;	
	});
	
	int current_time=0;
	for(int i=0; i<n; i++) {
		if(current_time<vec[i].first) {
			current_time=vec[i].first;
			current_time+=vec[i].second;
		} else {
			current_time+=vec[i].second;
		}
	}
	cout<<current_time;
	
	return 0;
}

/*
boj.kr/14469

INPUT:
3
2 1
8 3
5 7

OUTPUT:
15
*/
