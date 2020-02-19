#include <iostream>

using namespace std;

const int MAX=5;
int main() {
	int arr[MAX] {0}, total=0;
	
	for(int i=0; i<MAX; i++) {
		cin>>arr[i];
		total+=arr[i];
		
		for(int j=0; j<i; j++) {
			if(arr[j]>arr[i]) {
				swap(arr[j],arr[i]);
			}
		}
	}
	
	cout<<total/MAX<<'\n'<<arr[MAX/2];
	
	return 0;
}

/*
boj.kr/2587

INPUT:
10
40
30
60
30

OUTPUT:
34
30
*/
