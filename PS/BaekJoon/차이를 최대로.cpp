#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculate(const vector<int> &v) {
	int result=0;
	for(int i=0; i<v.size()-1; i++) {
		result += abs(v[i]-v[i+1]);
	}
	return result;
}

int main() {
	int N;
	cin>>N;
	
	vector<int> v(N);
	for(int i=0; i<N; i++) cin>>v[i];
	
	sort(v.begin(), v.end());
	int result=0;
	do{
		result=max(calculate(v), result);
	}while(next_permutation(v.begin(), v.end()));

	cout<<result;

	return 0;
}

/*
boj.kr/10819

INPUT:
6
20 1 15 8 4 10

OUTPUT:
62
*/
