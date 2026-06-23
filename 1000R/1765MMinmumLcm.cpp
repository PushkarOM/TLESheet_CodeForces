#include <bits/stdc++.h>

using namespace std;


/*
Let a = g*x, b = g*y where gcd(x,y) = 1.

Then:
    g(x + y) = n
and
    lcm(a,b) = g*x*y.

To minimize the LCM, we want to maximize g.
Since g = n / (x + y), this means minimizing (x + y).

- If n is even, the minimum possible x+y is 2 (x=y=1),
  giving a=b=n/2.

- If n is odd, x+y=2 is impossible.
  Let d be the smallest divisor (>1) of n.
  Taking x=1 and y=d-1 gives x+y=d and gcd(x,y)=1.
  This maximizes g = n/d.

  Therefore:
      a = g
      b = (d-1)*g

For odd n, find the smallest divisor by checking up to sqrt(n).
If none exists, n is prime, so d=n.
*/

int main() {

    int t;
    cin >> t;

    while (t--) {
        long long n;
        cin >> n;

        if (n % 2 == 0) {
            cout << n / 2 << ' ' << n / 2 << '\n';
            continue;
        }

        long long d = n;

        for (long long i = 3; i * i <= n; i += 2) {
            if (n % i == 0) {
                d = i;
                break;
            }
        }

        long long g = n / d;
        cout << g << ' ' << (d - 1) * g << '\n';
    }

    return 0;
}