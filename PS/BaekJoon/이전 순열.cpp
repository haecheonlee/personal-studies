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
	while(prev_permutation(v.begin(), v.end())) {
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
boj.kr/10973

INPUT:
5
5 4 3 2 1

OUTPUT:
5 4 3 1 2
*/
