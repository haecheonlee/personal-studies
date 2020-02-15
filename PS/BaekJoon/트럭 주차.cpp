#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	int a,b,c,start=101,end=0;
	cin>>a>>b>>c;
	
	vector<pair<int,int>> vec;
	for(int i=0; i<3; i++) {
		int t1,t2;
		cin>>t1>>t2;
		
		vec.push_back({t1,t2});
		start=min(t1,start);
		end=max(t2,end);
	}
	
	int car_count=0, price=0;
	bool check[3] {false};
	for(int i=start; i<=end; i++) {
		if(car_count==1) price+=(a);
		else if(car_count==2) price+=(b*car_count);
		else if(car_count==3) price+=(c*car_count);
		
		for(int j=0; j<vec.size(); j++) {
			if(vec[j].first<=i) check[j]=true;
			if(i>=vec[j].second) check[j]=false;
		}
		
		car_count=0;
		for(int x=0; x<3; x++) if(check[x]) car_count++;
	}
	
	cout<<price;
	
	return 0;
}

/*
boj.kr/2979

INPUT:
5 3 1
1 6
3 5
2 8

OUTPUT:
33
*/
