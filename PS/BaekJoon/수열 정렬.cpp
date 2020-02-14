#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	vector<int> vec(n,0), sorted;
	for(int i=0; i<n; i++) {
		cin>>vec[i];
		sorted.push_back(vec[i]);
	}
	
	sort(sorted.begin(), sorted.end());
	
	bool check[1001]{false};
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			if(check[j]) continue;
			if(vec[i]==sorted[j]) {
				check[j]=true;
				cout<<j<<" ";
				break;
			}
		}
	}
	
	return 0;
}

/*
boj.kr/1015

INPUT:
3
2 3 1

OUTPUT:
1 2 0
*/
