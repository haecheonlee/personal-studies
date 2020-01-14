#include <iostream>

using namespace std;

int main() {
	int N;
	cin>>N;
	
	char arr[N][N];
	
	for(int i=0; i<N; i++) 
		for(int j=0; j<N; j++) cin>>arr[i][j];
	
	int candy=-1;
	for(int i=0; i<N; i++) {
		for(int j=0; j<N; j++) {
			int count;
			char current;
			
			/* swap col */
			if(j<N-1) {
				swap(arr[i][j], arr[i][j+1]);
	
				for(int n=j; n<=j+1; n++) {
					current=arr[0][n];
					count=1;
					for(int m=1; m<N; m++) {
						if(current==arr[m][n]) count++;
						else {
							current=arr[m][n];
							count=1;
						}
						
						candy=max(candy, count);
					}	
				}
				
				count=1;
				current=arr[i][0];
				for(int n=1; n<N; n++) {
					if(current==arr[i][n]) { 
						count++;
					}
					else {
						current=arr[i][n];
						count=1;
					}
					
					candy=max(candy, count);
				}
				swap(arr[i][j], arr[i][j+1]);
			}
			
			if(i<N-1) {
				/* swap row */
				swap(arr[i][j], arr[i+1][j]);
				for(int m=i; m<=i+1; m++) {
					current=arr[m][0];
					count=1;
					
					for(int n=1; n<N; n++) {
						if(current==arr[m][n]) { 
							count++;
						}
						else {
							current=arr[m][n];
							count=1;
						}
						
						candy=max(candy, count);
					}
				}
	
				count=1;
				current=arr[0][j];
				for(int m=1; m<N; m++) {
					if(current==arr[m][j]) count++;
					else {
						current=arr[m][j];
						count=1;
					}
					
					candy=max(candy, count);
				}
				
				swap(arr[i][j], arr[i+1][j]);
			}
		}
	}
	
	cout<<candy;
	return 0;
}

/*
boj.kr/3085

INPUT:
5
YCPZY
CYZZP
CCPPP
YCYZC
CPPZZ

OUTPUT:
4
*/
