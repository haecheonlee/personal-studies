#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	vector<long long> v(N, 0);
	for(int i=0; i<N; i++) cin>>v[i];
	
	sort(v.begin(), v.end());
	
	long long result = 0;
	result=v[0]*v[N-1];

	cout<<result;

	return 0;
}

/*
boj.kr/1037

INPUT:
2
4 2

OUTPUT:
8
*/
