#include <iostream>
#define n 5

using namespace std;

int main() {
	int sum=0, num;
	for(int i=0; i<n; i++) {
		cin>>num;
		sum+=(num*num);
	}
	
	cout<<sum%10;
	
	return 0;
}

/*
INPUT:
0 4 2 5 6

OUTPUT:
1
*/
