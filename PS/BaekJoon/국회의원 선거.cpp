#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int vote;
	cin>>vote;
	
	vector<int> list(n-1);
	for(int i=0; i<n-1; i++) cin>>list[i];
	sort(list.begin(),list.end(),greater<int>());
	
	int cnt=0;
	if(list.size()>0) {
		while(vote<=list[0]) {
			vote++;
			list[0]--;
			cnt++;
			sort(list.begin(),list.end(),greater<int>());
		}
	}
	cout<<cnt;

	return 0;
}

/*
INPUT:
3
5
7
7

OUTPUT:
2
*/
