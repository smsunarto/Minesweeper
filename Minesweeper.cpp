#include <bits/stdc++.h>

using namespace std;

int panjang, tinggi, m, n, temp, bomb;

string convertInt(int number)
{
   stringstream ss;//create a stringstream
   ss << number;//add number to the stream
   return ss.str();//return a string with the contents of the stream
}
int main()
{
    // Get user input
    scanf("%d", &tinggi);
    scanf("%d", &panjang);


    // Start randomize
    printf("%dx%d\n", tinggi, panjang);
    string a [tinggi+2][panjang+2];
    for (n=1; n<panjang+1; n++){
        for (m=1; m<tinggi+1; m++){
        temp = rand() % 2;
        if (temp == 1) {
            a[n][m] = "*";
        }
        else {
            a[n][m] = "-";
        }
        cout << a[n][m];
        }
        cout << "\n";
    }

    cout << "-------------\n";

    // Start counting bombs
    for (n=1; n<panjang+1; n++){
        for (m=1; m<tinggi+1; m++){
        if (a[n][m] == "-") {
            // Single line check{
                if (a[n+1][m] == "*"){
                    bomb++;
                }
                if (a[n-1][m] == "*"){
                    bomb++;
                }
                if (a[n][m+1] == "*"){
                    bomb++;
                }
                if (a[n][m-1] == "*"){
                    bomb++;
                }

            // Diagonal Check
                    if (a[n+1][m+1] == "*"){
                        bomb++;
                    }
                    if (a[n-1][m-1] == "*"){
                        bomb++;
                    }
                    if (a[n+1][m-1] == "*"){
                        bomb++;
                    }
                    if (a[n-1][m+1] == "*"){
                        bomb++;
                    }
                    a[n][m] = convertInt(bomb);
                    bomb = 0;
                }
            cout << a[n][m];
        }
        cout << "\n";
    }
}
