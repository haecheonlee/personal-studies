#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin>>N;

	vector<int> v;
	for(int i=1; i<=N; i++) v.push_back(i);  

	do {
		for(int i=0; i<N; i++) {
			cout<<v[i]<<" ";	
		}
		cout<<'\n';
	}while(next_permutation(v.begin(), v.end()));

	return 0;
}

/*
boj.kr/10974

INPUT:
3

OUTPUT:
1 2 3
1 3 2
2 1 3
2 3 1
3 1 2
3 2 1
*/
