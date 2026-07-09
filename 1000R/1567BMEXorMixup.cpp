#include<bits/stdc++.h>

using namespace std;


int prefixXor(int n) {
    if (n % 4 == 0) return n;
    if (n % 4 == 1) return 1;
    if (n % 4 == 2) return n + 1;
    return 0;
}

int main(){

    int t;
    cin >> t;

    while(t--){

        int a, b;
        cin >> a >> b;
        int x = prefixXor(a - 1);

        if (x == b)
            cout << a << '\n';
        else if ((x ^ b) == a)
            cout << a + 2 << '\n';
        else
            cout << a + 1 << '\n';  
        
    }
}

/*
Observation:

To have MEX = a:
- Every number from 0 to a-1 must be present.
- Number a must NOT be present.
- Any number greater than a (or duplicates of numbers < a) can be added freely
  without changing the MEX.

Hence, the shortest possible array must start with:
    {0, 1, 2, ..., a-1}

Let:
    x = XOR(0, 1, 2, ..., a-1)

Now there are only three cases:

1) x == b
   - The mandatory elements already satisfy the required XOR.
   - No extra elements are needed.
   - Answer = a.

2) x != b
   - If one extra element is added, it must be:
         z = x ^ b
     since:
         x ^ z = b.

   - If z != a, adding z preserves the MEX
     (duplicates and values > a are allowed).
     Answer = a + 1.

3) z == a
   - Adding a would invalidate the MEX.
   - One extra element is therefore impossible.
   - Instead, add two numbers u and v such that:
         u ^ v = a
     which gives:
         x ^ u ^ v = x ^ a = b.
   - Such a pair always exists without using the value a.
   - Answer = a + 2.

The only remaining task is computing:
    XOR(0..a-1)
which is done in O(1) using the standard prefix XOR pattern.
*/
