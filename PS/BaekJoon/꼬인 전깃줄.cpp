#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	vector<int> ans;
	for(int i=0; i<N; i++) {
		int x;
		cin>>x;
		
		auto it=lower_bound(ans.begin(), ans.end(), x);
		if(it==ans.end()) ans.push_back(x);
		else *it=x;
	}
	
	cout<<N-ans.size();

	return 0;
}
