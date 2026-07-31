#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;


    while(t--){

        long long x,y,k;
        cin >> x >> y >> k;

        long long  numTrades =  (k*(y+1)-1) / (x-1);
        numTrades = (k*(y+1)-1) % (x-1) != 0 ? numTrades+=1 : numTrades;
        cout << numTrades + k << "\n";

    }
}

/*
Idea:

We need k torches.

Each torch requires:
- 1 stick
- 1 coal

So overall we must spend:
- k sticks for crafting
- k * y sticks to buy k coal

Total sticks that must be available:
    k * (y + 1)

We start with 1 stick.

Each stick trade:
- spend 1 stick
- receive x sticks
=> net gain = (x - 1) sticks.

After m stick trades, the number of sticks becomes:
    1 + m * (x - 1)

We need:
    1 + m * (x - 1) >= k * (y + 1)

Therefore:
    m = ceil((k * (y + 1) - 1) / (x - 1))

Finally, buying k coal requires exactly k coal trades.

Answer:
    m + k

Complexity:
O(1) per test case.
*/