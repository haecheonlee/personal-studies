#include <iostream>

using namespace std;

int main()
{
    long long result=5;
    
    long long n;
    cin>>n;
    
    for(int i=1;i<n;i++) {
		result+=(7+((i-1)*3));
    }
    
    cout<<result%45678<<endl;

    return 0;
}

/*
boj.kr/1964

INPUT:
3

OUTPUT:
22
*/
