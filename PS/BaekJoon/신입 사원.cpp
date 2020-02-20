#include <iostream>
#include <vector> 
#include <algorithm>

using namespace std;

bool sortByFirst(const pair<int, int> &l, const pair<int,int> &r) {
	return l.first<r.first;	
}

int main() {
	int t,n;
	cin>>t;
	
	while(t--) {
		cin>>n;
		
		vector<pair<int,int>> vec(n);
		for(int i=0; i<n; i++) cin>>vec[i].first>>vec[i].second;
		sort(vec.begin(), vec.end(), sortByFirst);
		
		int cnt=1, result_second=vec[0].second;
		for(int i=1; i<n; i++) {
			if(vec[i].second<result_second) {
				result_second=vec[i].second;
				cnt++;
			}
		}
		
		cout<<cnt<<'\n';
	}
	
	return 0;
}

/*
boj.kr/1946

INPUT:
2
5
3 2
1 4
4 1
2 3
5 5
7
3 6
7 3
4 2
1 4
5 7
2 5
6 1

OUTPUT:
4
3
*/
