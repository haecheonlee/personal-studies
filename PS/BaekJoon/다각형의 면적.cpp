#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	double x[n], y[n];
	for(int i=0; i<n; i++) cin>>x[i]>>y[i];
	
	double temp1=0.0, temp2=0.0;
	for(int i=0; i<n; i++) {
		if(i==n-1) temp1+=x[i]*y[0];
		else temp1+=x[i]*y[i+1];
		
		if(i==n-1) temp2+=x[0]*y[i]; 
		else temp2+=x[i+1]*y[i];
	}
	
	double result=abs(temp1-temp2);
	cout<<fixed<<setprecision(1)<<(result/2);
	
	return 0;
}

/*
INPUT:
4
0 0
0 10
10 10
10 0

OUTPUT:
100.0
*/
