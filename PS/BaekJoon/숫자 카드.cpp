#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	unordered_map<string, bool> uM;

	int n,m,num;
	
	cin>>n;
	for(int i=0; i<n; i++) {
		cin>>num;
		uM[to_string(num)]=true;
	}
	
	cin>>m;
	for(int i=0; i<m; i++) {
		cin>>num;
		cout<<uM[to_string(num)]<<" ";
	}

	return 0;
}

/*
boj.kr/10815

INPUT:
5
6 3 2 10 -10
8
10 9 -5 2 3 4 5 -10

OUTPUT:
1 0 0 1 1 0 0 1
*/
