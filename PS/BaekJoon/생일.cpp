#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Person {
public:
	string name;
	int day;
	int month;
	int year;
};

bool sorting(const Person &l, const Person &r) {
	if(l.year==r.year) {
		if(l.month==r.month) {
			return l.day<r.day;
		}
		
		return l.month<r.month;
	}
	
	return l.year<r.year;
}

int main() {
	int n;
	cin>>n;
	
	vector<Person> vec(n);
	for(int i=0; i<n; i++) {
		cin>>vec[i].name>>vec[i].day>>vec[i].month>>vec[i].year;
	}
	
	sort(vec.begin(), vec.end(), sorting);
	cout<<vec[n-1].name<<'\n'<<vec[0].name;
	
	return 0;
}

/*
boj.kr/5635

INPUT:
5
Mickey 1 10 1991
Alice 30 12 1990
Tom 15 8 1993
Jerry 18 9 1990
Garfield 20 9 1990

OUTPUT:
Tom
Jerry
*/
