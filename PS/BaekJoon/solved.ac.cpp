#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
	long long n;
	cin>>n;
	
	if(n==0) {
		cout<<0;
		return 0;
	}
	
	vector<long long> vec(n,0);
	
	for(int i=0; i<n; i++) cin>>vec[i];
	sort(vec.begin(), vec.end());
	
	long long e=round(0.15*n);
	long double count=0,total=0;
	for(int i=e; i<n-e; i++) {
		total+=vec[i];count++;
	}
	
	cout<<round(total/count);

	return 0;
}

/*
boj.kr/18110

INPUT:
10
1
13
12
15
3
16
13
12
14
15

OUTPUT:
13
*/
