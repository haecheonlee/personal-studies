#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	unordered_map<string, bool> m;

	int N,M,num;
	cin>>N;
	
	for(int i=0; i<N; i++) {
		cin>>num;
		m[to_string(num)]=true;
	} 
	
	cin>>M;
	for(int i=0; i<M; i++) {
		cin>>num;
		cout<<m[to_string(num)]<<'\n';
	}

	return 0;
}

/*
boj.kr/1920

INPUT:
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
