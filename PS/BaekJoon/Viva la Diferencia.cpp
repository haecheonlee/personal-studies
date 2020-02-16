#include <iostream>

using namespace std;

int main() {
	int a=-1,b=-1,c=-1,d=-1;

	while(1) {
		cin>>a>>b>>c>>d;
		if(a==0 && b==0 && c==0 && d==0) break;
		
		int count=0;
		while(a!=b || b!=c || c!=d || d!=a) {
			int current_a=a, current_b=b, current_c=c, current_d=d;
			
			a=abs(current_a-current_b);
			b=abs(current_b-current_c);
			c=abs(current_c-current_d);
			d=abs(current_d-current_a);
			
			count++;
		}
		cout<<count<<'\n';
	}
	
	return 0;
}

/*
boj.kr/4084

INPUT:
1 3 5 9
4 3 2 1
1 1 1 1
0 0 0 0

OUTPUT:
6
4
0
*/
