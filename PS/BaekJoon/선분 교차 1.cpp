#include <iostream>

using namespace std;

struct Point {
	long long x;
	long long y;
};

struct Line {
	Point first;
	Point second;
};

int ccw(Point p1, Point p2, Point p3) {
	long long temp=p1.x*p2.y + p2.x*p3.y + p3.x*p1.y;
	temp-=(p1.y*p2.x + p2.y*p3.x + p3.y*p1.x);
	
	if(temp>0) return 1;
	if(temp<0) return -1;
	return 0;
}

bool isCrossed(Line l1, Line l2) {
	int l1l2=ccw(l1.first,l1.second,l2.first)*ccw(l1.first,l1.second,l2.second);
	int l2l1=ccw(l2.first,l2.second,l1.first)*ccw(l2.first,l2.second,l1.second);
	return l1l2<0 && l2l1<0;
}

int main() {
	Line l[2];
	
	for(int i=0; i<2; i++) {
		cin>>l[i].first.x>>l[i].first.y;
		cin>>l[i].second.x>>l[i].second.y;
	}
	
	cout<<isCrossed(l[0],l[1]);
	
	return 0;
}

/*
INPUT:
1 1 5 5
1 5 5 1

OUTPUT:
1
*/
