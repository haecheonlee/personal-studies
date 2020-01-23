#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool sorting(const pair<int,double> &l, const pair<int,double> &r) {
	if(l.second>r.second) return true;
	else if(l.second==r.second) {
		if(l.first<r.first) return true;
	}
	
	return false;
}

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int n,w,c;
		cin>>n;
		
		vector<pair<int,double>> v;
		for(int i=0; i<n; i++) {
			cin>>w>>c;
			v.push_back({c,(double)w/c});
		}
		
		sort(v.begin(), v.end(), sorting);
		cout<<v[0].first<<'\n';
	}

	return 0;
}

/*
boj.kr/9070

INPUT:
3
2
300 2000
200 1500
3
320 2139
700 3200
1400 6400
5
250 1920
500 2980
430 2700
380 2350
340 2310

OUTPUT:
2000
3200
2980
*/
