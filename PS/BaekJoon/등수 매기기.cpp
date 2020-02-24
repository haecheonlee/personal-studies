#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	vector<long long> vec(n);
	for(int i=0; i<n; i++) cin>>vec[i];
	sort(vec.begin(), vec.end());
	
	long long total=0;
	for(int i=1; i<=n; i++) total+=abs(vec[i-1]-i);
	
	cout<<total;
	
	return 0;
}

/*
boj.kr/2012

INPUT:
5
1
5
3
1
2

OUTPUT:
3
*/
