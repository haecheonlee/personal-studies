#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t,n,m,p;
	cin>>t;

	while(t--) {
		cin>>n>>m;

		queue<pair<int,int>> q;
		vector<int> vec;

		for(int i=0; i<n; i++) {
			cin>>p;
			q.push({i,p});
			vec.push_back(p);
		}
		sort(vec.begin(), vec.end(), [](const int &l, const int &r){
			return l>r;
		});

		int start=1;
		while(1) {
			pair<int,int> current=q.front();
			q.pop();

			if(current.first==m && vec[start-1]==current.second) {
				cout<<start<<'\n';
				break;
			} 
			
			if(vec[start-1]!=current.second) q.push(current);
			else start++;
		}
	}
	
	return 0;
}

/*
boj.kr/1966

INPUT:
3
1 0
5
4 2
1 2 3 4
6 0
1 1 9 1 1 1

OUTPUT:
1
2
5
*/
