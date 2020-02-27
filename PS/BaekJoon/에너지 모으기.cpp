#include <iostream>
#include <vector>

using namespace std;

int go(vector<int> &a) {
	int n=a.size();
	if(n==2) return 0;
	
	int result=0;
	for(int i=1; i<n-1; i++) {
		int energy=a[i-1]*a[i+1];
		vector<int> b(a);
		b.erase(b.begin()+i);
		energy+=go(b);
		if(result<energy) result=energy;
	}
	
	return result;
}

int main() {
	int n;
	cin>>n;
	
	vector<int> a(n);
	for(int i=0; i<n; i++) cin>>a[i];
	cout<<go(a)<<'\n';

	return 0;
}

/*
boj.kr/16198

INPUT:
7
2 2 7 6 90 5 9

OUTPUT:
1818
*/
