#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){

        string str;
        cin >> str;

        int count_0 = 0, count_1 = 0;


        for(int i = 0; i < str.length(); i++){
            if(str[i] == '0'){
                count_0++;
            }
            else{
                count_1++;
            }
        }

        if(min(count_0,count_1)%2 != 0) cout << "DA" << "\n";
        else cout << "NET" << "\n"; 

    }


}

/*
Observation:
Each valid move removes exactly one '0' and one '1'. Therefore, the total
number of moves can never exceed min(count_0, count_1).

Now, if the string still contains both a '0' and a '1', there must exist
at least one adjacent "01" or "10" pair (because a transition between the
two characters must occur somewhere). Hence, the game cannot stop early.

So, the total number of moves is exactly min(count_0, count_1).

Alice moves first and wins if she makes the last move. Therefore:
- Odd number of total moves  -> Alice wins ("DA")
- Even number of total moves -> Bob wins ("NET")

Time Complexity: O(n) per test case
Space Complexity: O(1)
*/