#include <iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	
	int current_highest_num=0, current_person=0;
	for(int i=1; i<=n; i++) {
		int arr[5]{0};
		for(int j=0; j<5; j++) cin>>arr[j];
		
		int result=0;
		for(int a=0; a<3; a++) {
			for(int b=a+1; b<4; b++) {
				for(int c=b+1; c<5; c++) {
					int first_digit=(arr[a]+arr[b]+arr[c])%10;
					result=max(first_digit, result);
				}
			}
		}
		
		if(current_highest_num<=result) {
			current_person=i;
			current_highest_num=result;
		}
	}
	
	cout<<current_person;

	return 0;
}

/*
boj.kr/2303

INPUT:
3
7 5 5 4 9
1 1 1 1 1
2 3 3 2 10

OUTPUT:
1
*/
