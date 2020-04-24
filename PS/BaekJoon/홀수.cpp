#include <iostream>

using namespace std;

int main() {
	int num;
	
	int sum=0,mn=101;
	for(int i=0; i<7; i++) { 
		cin>>num;
		
		if(num%2) {
			sum+=num;
			mn=min(mn,num);
		}
	}
	
	if(sum==0) cout<<-1;
	else cout<<sum<<'\n'<<mn;
	
	return 0;
}

/*
INPUT:
12
77
38
41
53
92
85

OUTPUT:
256
41
*/
