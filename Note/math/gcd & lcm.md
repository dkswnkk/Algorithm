## 최대공약수 & 최소공배수 ##

```cpp
#include <iostream>
using namespace std;

int GCD(int n1, int n2) {
    if (n2 == 0) return n1;
    else return GCD(n2,n1%n2);
    
}
int main() {
    int A, B,gcd,lcm;
    cin >> A >> B;
    
    gcd=GCD(A, B);
    lcm=A*B/GCD(A,B);
    
}

```
