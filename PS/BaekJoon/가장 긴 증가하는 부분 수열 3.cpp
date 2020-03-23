#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int n,num;
	cin>>n;

	vector<int> vec;
	for(int i=0; i<n; i++) {
		cin>>num;
		
		auto it=lower_bound(vec.begin(),vec.end(),num);
		if(it==vec.end()) vec.push_back(num);
		else *it=num;
	}
	
	cout<<vec.size();
	
	return 0;
}

/*
INPUT:
6
10 20 10 30 20 50

OUTPUT:
4
*/
