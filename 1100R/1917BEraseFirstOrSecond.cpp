#include<bits/stdc++.h>

using namespace std;

// // global set, to store valid string
// set<string> st;

// // recursive version of the solution,
// // build the string, store in set, check set size at the end
// void solve(string s){
//     if(s.empty()) return;

//     // a valid string
//     st.insert(s);

//     solve(s.substr(1));

//     if(s.length() >= 2){    
//         string temp = s;
//         temp.erase(1, 1);
//         solve(temp);
//     }
// }

int main(){

    int t;
    cin >> t;

    while(t--){

        int n;
        cin >> n;
        
        string str;
        cin >> str;
        
        // solve(str);
        
        // cout << st.size() << "\n";
        // // for(auto x : st)
        // //     cout << x << '\n';

        // st.clear();

        // simply count the distinct char's first occurencs, then we simply sum
        // n - index of these chars

        vector<int> arr(26,-1);
        int ans = 0;
        for(int i = 0; i < n; i++){
            if (arr[str[i] - 'a'] == -1) {
                arr[str[i] - 'a'] = i;
                ans += n - i;
            }
        }

        cout << ans << "\n";
    }

}

/*
    Key observation:
    Every generated string is determined by its first character.

    For a character c, only its FIRST occurrence matters.
    If c first appears at index i, we can generate exactly (n - i)
    distinct strings starting with c by repeatedly removing the
    second character.

    Later occurrences of c do not add new strings; they only produce
    strings already obtainable from the first occurrence.

    Therefore:
        answer = sum(n - firstIndex[c]) for every distinct character c.

    Time:  O(n)
    Space: O(1)  // only 26 characters
*/
