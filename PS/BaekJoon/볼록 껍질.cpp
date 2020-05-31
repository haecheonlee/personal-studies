#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Point {
	int x,y;
};

Point a[200000];
Point p;

int ccw(Point p1, Point p2, Point p3) {
	long long temp = (long long)(p2.x-p1.x)*(long long)(p3.y-p1.y)-
					 (long long)(p3.x-p1.x)*(long long)(p2.y-p1.y);
	
	if(temp>0) return 1;
	if(temp<0) return -1;
	return 0;
}

long long dist(Point p1, Point p2) {
	long long d1 = (long long)(p1.x-p2.x);
	long long d2 = (long long)(p1.y-p2.y);
	
	return d1*d1+d2*d2;
}

bool cmp(const Point &u, const Point &v) {
	int temp=ccw(p,u,v);
	
	if(temp==0) return dist(p,u)<=dist(p,v);
	else return temp==1;
}

int main() {
	int n;
	cin>>n;
	
	for(int i=0; i<n; i++) cin>>a[i].x>>a[i].y;
	
	p=a[0];
	for(int i=1; i<n; i++) {
		if(a[i].y<p.y || (a[i].y==p.y && a[i].x<p.x)) p=a[i];
	}
	
	sort(a, a+n, cmp);
	vector<Point> s;
	
	for(int i=0; i<n; i++) {
		while(s.size()>=2 && ccw(s[s.size()-2], s[s.size()-1], a[i])<=0) {
			s.pop_back();
		}
		
		s.push_back(a[i]);
	}
	
	cout<<s.size();
	
	return 0;
}
