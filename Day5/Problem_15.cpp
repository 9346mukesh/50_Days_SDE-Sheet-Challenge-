/* Topic :- Maths
Problem Name :- Implement Pow(x,n) | X raised to the power N
Problem Statement :- Implement pow(x, n), which calculates x raised to the power n (i.e., x^n).
*/

// TC : O(log n) and SC : O(1)



#include <bits/stdc++.h>
using namespace std;

double myPow(double x, int n) {
    long long power = n;
    
    if (power < 0)
        power = -power;

    double ans = 1.0;

    while (power > 0) {
        if (power % 2 == 1) {
            ans *= x;
            power--;
        } else {
            x *= x;
            power /= 2;
        }
    }

    if (n < 0)
        ans = 1.0 / ans;

    return ans;
}

int main() {
    double x;
    int n;

    cin >> x >> n;

    cout << myPow(x, n);

    return 0;
}