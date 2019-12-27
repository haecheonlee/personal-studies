#include <iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int M, N;
	cin>>M>>N;
	
	bool check[1000001] {false};

	for(int i=2; i<=N; i++) {
		if(check[i]==false) {
			if(i>=M) cout<<i<<'\n';
			for(int j=i+i; j<=N; j+=i) check[j]=true;
		}
	}

	return 0;
}

/*
boj.kr/1929

INPUT:
3 16

OUTPUT:
3
5
7
11
13
*/
