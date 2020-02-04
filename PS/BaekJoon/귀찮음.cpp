#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	long long n,total=0;
	cin>>n;
	
	vector<int> vec(n,0);
	
	for(int i=0; i<n; i++) {
		cin>>vec[i];
		total+=vec[i];
	}
	
	sort(vec.begin(), vec.end());
	
	long long value=0;
	for(int i=n-1; i>=0; i--) {
		total-=vec[i];
		value+=(total*vec[i]);
	}
	
	cout<<value;

	return 0;
}

/*
boj.kr/16208

INPUT:
10
12 43 22 51 2 55 8 21 98 50

OUTPUT:
55164
*/
