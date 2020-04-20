#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

string convert(int digit) {
	if(digit==0) return "zero";
	if(digit==1) return "one";
	if(digit==2) return "two";
	if(digit==3) return "three";
	if(digit==4) return "four";
	if(digit==5) return "five";
	if(digit==6) return "six";
	if(digit==7) return "seven";
	if(digit==8) return "eight";
	if(digit==9) return "nine";
}

bool sorting(const pair<string,int> &left, const pair<string,int> &right) {
	return left.first<right.first;	
}

int main() {
	int n,m;
	cin>>n>>m;
	
	vector<pair<string, int>> list;
	for(int i=n; i<=m; i++) {
		int num=i;
		string number="";
		
		if(num>=10) {
			while(num/10!=0) {
				int digit=i/10;
				number+=convert(digit)+" ";
				num%=10;
			}
			number+=convert(num);
		}
		else number+=convert(num);	
		
		list.push_back(make_pair(number,i));
	}
	
	sort(list.begin(), list.end(), sorting);
	for(int i=0; i<list.size(); i++) {
		cout<<list[i].second<<" ";
		if((i+1)%10==0) cout<<'\n';
	}
	return 0;
}

/*
INPUT:
8 28

OUTPUT:
8 9 18 15 14 19 11 17 16 13
12 10 28 25 24 21 27 26 23 22
20
*/
