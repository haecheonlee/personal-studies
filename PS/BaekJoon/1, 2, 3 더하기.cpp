#include <iostream>

using namespace std;

int result2[11];

int getResult(int n) {
    if(n == 0) return 0;
    else if(n == 1) return 1;
    else if(n == 2) return 2;
    else if(n == 3) return 4;
    
    if(result2[n] != 0) return result2[n];
    result2[n] = getResult(n-1) + getResult(n-2) + getResult(n-3);
    
    return result2[n];
}

int main()
{
    int result[11];
    result[0] = 0;
    result[1] = 1;
    result[2] = 2;
    result[3] = 4;
    
    int test_case = 0;
    cin>>test_case;

    int test[test_case];
    
    for(int i=0; i<test_case; i++) {
        cin>>test[i];
        int final_result = getResult(test[i]);
        cout<<final_result<<endl;
    }
    
    return 0;
}

/*
boj.kr/9095

INPUT:
3
4
7
10

OUTPUT:
7
44
274
*/
