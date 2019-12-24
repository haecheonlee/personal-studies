#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int A, B;
	cin>>A>>B;
	
	A *= 2;
	int r = sqrt((A*A) - (4*B));
	
	int result1 = (-A-r) / 2;
	int result2 = (-A+r) / 2;
	
	if(result1 == result2) {
		cout<<result1;
	} else if(result1 < result2) {
		cout<<result1<<" "<<result2;
	} else {
		cout<<result2<<" "<<result1;
	}

	return 0;
}

/*
boj.kr/17945

INPUT:
2 3

OUTPUT:
-3 -1
*/
