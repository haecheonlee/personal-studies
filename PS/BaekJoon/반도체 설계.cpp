#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int n,x;
	cin>>n;
	
	vector<int> vec;
	for(int i=0; i<n; i++) {
		cin>>x;
		
		auto it=lower_bound(vec.begin(),vec.end(),x);
		if(it==vec.end()) vec.push_back(x);
		else *it=x; 
	}

	cout<<vec.size();

	return 0;
}

/*
INPUT:
6
4 2 6 3 1 5

OUTPUT:
3
*/
