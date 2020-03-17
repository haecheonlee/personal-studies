#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	string a,b;
	cin>>a>>b;
	sort(a.begin(),a.end());
	
	int result=-1;
	do {
		if(a[0]=='0') continue;
		int i_a=stoi(a);
		int i_b=stoi(b);
		
		if(i_a<=i_b) result=i_a;
	} while(next_permutation(a.begin(), a.end()));
	
	cout<<result;

	return 0;
}

/*
INPUT:
1234 3456

OUTPUT:
3421
*/
