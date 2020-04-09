#include <iostream>

using namespace std;

int ccw(int x1, int y1, int x2, int y2, int x3, int y3) {
	int temp=x1*y2+x2*y3+x3*y1;
	temp=temp-x2*y1-x3*y2-x1*y3;
	
	if(temp>0) return 1;
	else if(temp<0) return -1;
	else return 0;
	
}

int main() {
	int x1,x2,x3;
	int y1,y2,y3;
	
	cin>>x1>>y1;
	cin>>x2>>y2;
	cin>>x3>>y3;
	
	cout<<ccw(x1,y1,x2,y2,x3,y3);

	return 0;
}

/*
INPUT:
1 1
3 3
5 5

OUTPUT:
0
*/
