#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n;
	cin>>n;
	
	int a[n][n];
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) cin>>a[i][j];
	}
	
	while(1) {
		for(int i=0; i<n; i+=2) {
			for(int j=0; j<n; j+=2) {
				vector<int> vec;
				for(int x=i; x<=i+1; x++) {
					for(int y=j; y<=j+1; y++) vec.push_back(a[x][y]);
				}
				sort(vec.begin(), vec.end(), greater<int>());
				a[i/2][j/2]=vec[1];
			}
		}
		
		n/=2;
		if(n==1) break;
	}
	
	cout<<a[0][0];
	return 0;
}

/*
boj.kr/17829

INPUT:
8
-1 2 14 7 -4 5 8 9
10 6 23 2 1 1 7 11
9 3 5 -2 4 4 6 6
7 15 0 8 21 9 6 6
19 8 12 -8 4 5 2 9
1 2 3 4 5 6 7 8
9 10 11 12 13 14 15 16
17 18 19 20 21 22 23 24

OUTPUT:
17
*/
