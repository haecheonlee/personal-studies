#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int t;
	cin>>t;
	
	while(t--) {
		int j,n;
		cin>>j>>n;
		
		vector<int> a;
		for(int i=0; i<n; i++) {
			int r,c;
			cin>>r>>c;
			
			a.push_back(r*c);
		}
		
		sort(a.rbegin(), a.rend());
		int ans=0;
		for(auto &p : a) {
			ans++;
			j-=p;
			if(j<=0) break;
		}
		cout<<ans<<'\n';
	}

	return 0;
}

/*
INPUT:
1
20 5
3 4
2 5
1 8
3 3
2 5

OUTPUT:
2
*/
