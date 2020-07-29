// reference: baekjoon/codeplus
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

double dist(double x1, double y1, double z1, double x2, double y2, double z2) {
	return sqrt((x2-x1)*(x2-x1)+(y2-y1)*(y2-y1)+(z2-z1)*(z2-z1));
}

int main() {
	double x1,y1,z1,x2,y2,z2,x3,y3,z3;
	cin>>x1>>y1>>z1>>x2>>y2>>z2>>x3>>y3>>z3;
	
	double dx=x2-x1;
	double dy=y2-y1;
	double dz=z2-z1;
	double left=0.0;
	double right=1.0;
	double m=0;
	
	while(true) {
		if(abs(right-left)<1e-9) {
			m=(left+right)/2;
			break;
		}
		
		double m1=left+(right-left)/3;
		double m2=right-(right-left)/3;
		
		double m1x=x1+m1*dx;
		double m1y=y1+m1*dy;
		double m1z=z1+m1*dz;
		
		double m2x=x1+m2*dx;
		double m2y=y1+m2*dy;
		double m2z=z1+m2*dz;
		
		double d1=dist(m1x,m1y,m1z,x3,y3,z3);
		double d2=dist(m2x,m2y,m2z,x3,y3,z3);
		
		if(d1>d2) left=m1;
		else right=m2;
	}
	
	double x0=x1+m*dx;
	double y0=y1+m*dy;
	double z0=z1+m*dz;
	double ans=dist(x0,y0,z0,x3,y3,z3);
	
	cout<<fixed<<setprecision(10)<<ans;
	
	return 0;
}
