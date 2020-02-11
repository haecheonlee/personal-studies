#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	cout.setf(ios::fixed);
	cout.precision(3);

	int n;
	cin>>n;
	
	double arr[n], result[n], largest=0.000;
	for(int i=0; i<n; i++) {
		cin>>arr[i];
		
		if(i>0) {
			result[i]=arr[i]*result[i-1];
			if(result[i]<arr[i]) result[i]=arr[i];
		} else {
			result[i]=arr[i];
		}
		
		largest=max(largest,result[i]);
	}
	
	cout<<largest;

	return 0;
}

/*
boj.kr/2670

INPUT:
8
1.1
0.7
1.3
0.9
1.4
0.8
0.7
1.4

OUTPUT:
1.638
*/
