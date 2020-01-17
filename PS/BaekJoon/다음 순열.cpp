#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int N;
	cin>>N;

	vector<int> v(N);
	for(int i=0; i<N; i++) cin>>v[i];  

	bool isLast=true;
	while(next_permutation(v.begin(), v.end())) {
		for(int i=0; i<N; i++) {
			cout<<v[i]<<" ";
		}
		isLast=false;
		break;
	}

	if(isLast) cout<<-1;

	return 0;
}

/*
boj.kr/10972

INPUT:
4
1 2 3 4

OUTPUT:
1 2 4 3
*/
