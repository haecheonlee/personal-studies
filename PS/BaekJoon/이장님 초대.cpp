#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int t[n];
	for(int i=0; i<n; i++) cin>>t[i];
	sort(t, t+n, greater<int>());
	
	int end=t[0]+1, days=1;
	for(int i=1; i<=end; i++) {
		if(i<n) end=max(end,t[i]+i+1);
		days++;
	}
	cout<<days;

	return 0;
}

/*
boj.kr/9237

INPUT:
6
39 38 9 35 39 20

OUTPUT:
42
*/
