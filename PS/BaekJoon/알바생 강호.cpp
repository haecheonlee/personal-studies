#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<int> vec(n);
	for(int i=0; i<n; i++) cin>>vec[i];
	sort(vec.rbegin(), vec.rend());
	
	long long total=0;
	for(int i=0; i<n; i++) {
		long long sum=vec[i]-((i+1)-1);
		if(sum>0) total+=sum;
	}
	cout<<total;
	
	return 0;
}

/*
boj.kr/1758

INPUT:
4
3
3
3
3

OUTPUT:
6
*/
