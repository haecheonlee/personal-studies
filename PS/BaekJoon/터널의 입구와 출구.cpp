#include <iostream>

using namespace std;

int main() {
	int n, m;
	cin>>n>>m;
	
	int entered=0, left=0;
	int max = m;
  
	for(int i=1; i<=n; i++) {
		cin>>entered>>left;
		m += entered - left;
		
		if(max < m) max = m;
		if(m < 0) {
			max = 0;
			break;
		}
	}
	
	cout<<max;
}

/*
boj.kr/5612

INPUT:
3
2
2 3
2 3
4 1

OUTPUT:
3
*/
