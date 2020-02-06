#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int a,b,l,r;
	cin>>a>>b;
	
	vector<int> vec(a+1,0);
	for(int i=1; i<=a; i++) cin>>vec[i];
	
	sort(vec.begin(), vec.end());
	int sum[a+1]{0};
	
	for(int i=1; i<=a; i++) sum[i]=vec[i]+sum[i-1];
	
	for(int i=0; i<b; i++) {
		cin>>l>>r;
		cout<<sum[r]-sum[l-1]<<'\n';
	}

	return 0;
}

/*
boj.kr/17390

INPUT:
5 6
2 5 1 4 3
1 5
2 4
3 3
1 3
2 5
4 5

OUTPUT:
15
9
3
6
14
9
*/
