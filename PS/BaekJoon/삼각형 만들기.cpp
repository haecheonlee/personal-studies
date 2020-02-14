#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<int> vec(n,0);
	for(int i=0; i<n; i++) cin>>vec[i];
	
	sort(vec.begin(), vec.end(), [](const int &l, const int &r) {
		return l>r;
	});
	

	for(int i=0; i<n-2; i++) {
		if(vec[i]<vec[i+1]+vec[i+2]) {
			cout<<vec[i]+vec[i+1]+vec[i+2];
			return 0;
		}
	}
	
	cout<<-1;
	
	return 0;
}

/*
boj.kr/1448

INPUT:
6
2
3
2
3
2
4

OUTPUT:
10
*/
