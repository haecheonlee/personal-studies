#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int t,n,m;
	cin>>t;
	
	while(t--) {
		unordered_map<int,bool> list;
		cin>>n;
		
		int num;
		for(int i=0; i<n; i++) {
			cin>>num;
			list[num]=true;
		}
		
		cin>>m;
		for(int i=0; i<m; i++) {
			cin>>num;
			
			if(list[num]) cout<<1<<'\n';
			else cout<<0<<'\n';
		}
	}

	return 0;
}

/*
boj.kr/2776

INPUT:
1
5
4 1 5 2 3
5
1 3 7 9 5

OUTPUT:
1
1
0
0
1
*/
