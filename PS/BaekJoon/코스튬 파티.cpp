#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,s;
int ans=0;

int main() {
	cin>>n>>s;

	vector<int> list(n);
	for(int i=0; i<n; i++) cin>>list[i];
	sort(list.begin(), list.end());

	for(int i=0; i<n; i++) {
		for(int j=i+1; j<n; j++) {
			if(list[i]+list[j]<=s) ans++;
		}
	}	
	cout<<ans;
	
	return 0;
}

/*
INPUT:
4 6
3
5
2
1

OUTPUT:
4
*/
