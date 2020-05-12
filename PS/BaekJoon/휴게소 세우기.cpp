#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> a;
int n,m,l;

int main() {
	cin>>n>>m>>l;
	
	a.resize(n);
	for(int i=0; i<n; i++) cin>>a[i];
	a.push_back(l);	// end of road
	sort(a.begin(), a.end());
	
	int left=0;
	int right=l;

	while(left<=right) {
		int mid=(left+right)/2;

		cout<<left<<" "<<right<<" "<<mid<<endl;
		int cnt=0;
		for(int i=0; i<n+1; i++) {
			if(a[i]-a[i-1]>mid) cnt+=(a[i]-a[i-1]-1)/mid;
		}
		cout<<" => "<<cnt<<endl<<endl;
		
		if(cnt>m) left=mid+1;
		else right=mid-1;
	}
	cout<<left;

	return 0;
}

/*
INPUT:
6 7 800
622 411 201 555 755 82

OUTPUT:
70
*/
