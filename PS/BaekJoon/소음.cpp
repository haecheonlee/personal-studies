#include <iostream>
#include <string>

using namespace std;

int convertCharToInt(char c) {
    return c - 48;
}

int main()
{
    string A, B;
    char op;
    cin>>A>>op>>B;
    
    if(A.size() < B.size()) A.swap(B); // Always 'A' is longer
    
    if(op == '+') {
        int index = A.size() - B.size();
        int result = convertCharToInt(A[index]) + convertCharToInt(B[0]);
        A.replace(index, 1, to_string(result));
    } else {
        B.erase(0, 1);  // remove 1
        A += B;
    }
    
    cout<<A<<endl;

    return 0;
}

/*
boj.kr/2935

INPUT:
1000
*
100

OUTPUT:
100000

*/
