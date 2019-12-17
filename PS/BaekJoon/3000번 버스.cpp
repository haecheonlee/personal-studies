#include <iostream>

using namespace std;

int main() {
	int k;
	cin>>k;
	
	int T_case;
	for(int i=0; i<k; i++) {
		cin>>T_case;
		
		int result = 0;
		while(T_case) {
			result = (result + 0.5) * 2;
			T_case--;
		}
		
		cout<<result<<endl;
	}

	return 0;
}

/*
boj.kr/9546

INPUT:
2
1
3

OUTPUT:
1
7
*/
