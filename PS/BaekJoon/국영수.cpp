#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Student {
public:
	string name;
	int korean;
	int english;
	int math;
};

bool customSort(const Student &l, const Student &r) {
	if(l.korean>r.korean) return l.korean>r.korean;
	else if(l.korean==r.korean) {
		if(l.english<r.english) return l.english<r.english;
		else if(l.english==r.english) {
			if(l.math>r.math) return l.math>r.math;
			else if(l.math==r.math) return l.name<r.name;
		}
	}
	
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int N;
	cin>>N;
	
	vector<Student> v;
	while(N--) {
		Student s;
		cin>>s.name>>s.korean>>s.english>>s.math;
		
		v.push_back(s);
	}
	
	sort(v.begin(), v.end(), customSort);
	
	for(int i=0; i<v.size(); i++) {
		cout<<v[i].name<<'\n';
	}

	return 0;
}

/*
boj.kr/10825

INPUT:
12
Junkyu 50 60 100
Sangkeun 80 60 50
Sunyoung 80 70 100
Soong 50 60 90
Haebin 50 60 100
Kangsoo 60 80 100
Donghyuk 80 60 100
Sei 70 70 70
Wonseob 70 70 90
Sanghyun 70 70 80
nsj 80 80 80
Taewhan 50 60 90

OUTPUT:
Donghyuk
Sangkeun
Sunyoung
nsj
Wonseob
Sanghyun
Sei
Kangsoo
Haebin
Junkyu
Soong
Taewhan
*/
