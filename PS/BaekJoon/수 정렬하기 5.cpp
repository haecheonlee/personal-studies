#include <iostream>

using namespace std;

int list[2000001]{0};
int n,x;

int main() {
	scanf("%d", &n);
	for(int i=0; i<n; i++) {
		scanf("%d", &x);
		list[x+1000000]++;
	}
	
	for(int i=0; i<=2000000; i++) {
		if(list[i]>0) {
			while(list[i]--) printf("%d\n", i-1000000);
		}
	}

	return 0;
}

/*
INPUT:
5
5
4
3
2
1

OUTPUT:
1
2
3
4
5
*/
