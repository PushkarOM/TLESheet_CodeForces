#include<bits/stdc++.h>

using namespace std;

int main(){

    int t;
    cin >> t;

    while(t--){
        
        char arr[10][10];

        for(int i = 0; i < 10; i++){
            for(int j = 0; j < 10; j++){
                cin >> arr[i][j];
            }
        }

        int points = 0;


        // counting points in column
        // column j = 0 and j = 9
        for(int k = 1; k < 9; k++ ){
            if(arr[k][0] == 'X') points += 1;    
            if(arr[k][9] == 'X') points += 1; 
        }

        // column j = 1 and j = 8
        for(int k = 2; k < 8; k++ ){
            if(arr[k][1] == 'X') points += 2;    
            if(arr[k][8] == 'X') points += 2; 
        }

        // column j = 2 and j = 7
        for(int k = 3; k < 7; k++ ){
            if(arr[k][2] == 'X') points += 3;    
            if(arr[k][7] == 'X') points += 3; 
        }

        // column j = 3 and j = 6
        for(int k = 4; k < 6; k++ ){
            if(arr[k][3] == 'X') points += 4;    
            if(arr[k][6] == 'X') points += 4; 
        }


        // for counting points in the row
        for(int i = 0; i < 10; i++){
            
            // ring 1 i = 0 or 9  , j 0 to 9
            if(i == 0 || i == 9){
                for(int j = 0; j < 10; j++){
                    if(arr[i][j] == 'X') points += 1;
                }
            }

            // ring 2 i = 1 or 8  , j 1 to 8
            if(i == 1 || i == 8){
                for(int j = 1; j < 9; j++){
                    if(arr[i][j] == 'X') points += 2;
                }
            }

            // ring 3 i = 2 or 7  , j 2 to 7
            if(i == 2 || i == 7){
                for(int j = 2; j < 8; j++){
                    if(arr[i][j] == 'X') points += 3;
                }
            }

            // ring 4 i = 3 or 6  , j 3 to 6
            if(i == 3 || i == 6){
                for(int j = 3; j < 7; j++){
                    if(arr[i][j] == 'X') points += 4;
                }
            }

            // ring 5 i = 4 or 5  , j 4 to 5
            if(i == 4 || i == 5){
                for(int j = 4; j < 6; j++){
                    if(arr[i][j] == 'X') points += 5;
                }
            }
        }

        cout << points << "\n";

    }

}