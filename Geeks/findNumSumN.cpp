#include <bits/stdc++.h>

using namespace std;

int **dp, *change;

int cnt(int m, int n) {

    if(m < 0 || n < 0) {
        return 0;
    }

    if(dp[m][n] != -1) {
        return dp[m][n];
    }

    // if(n == 0) {
    //     return 1;
    // }

    // if(m <= 0 && n >= 1) {
    //     return 0;
    // }

    dp[m][n] = cnt(m-1, n)              //Without the last coin
             + cnt(m, n-change[m-1]);   //With atleast one last coin

    return dp[m][n];
}

int main() {

    int n = 7, m = 3;
    change = new int[m];
    change[0] = 2;
    change[1] = 3;
    change[2] = 5;

    dp = new int*[m+1];
    for(int i = 0; i <= m; i++) {
        *(dp+i) = new int[n+1];
    }


    for(int i = 0; i <= m; i++)
        for(int j = 0; j <= n; j++)
            dp[i][j] = -1;

    for(int i = 0; i <= m; i++)
        dp[i][0] = 1;

    for(int j = 0; j <= n; j++)
        dp[0][j] = 0;

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++)
            cout << dp[i][j] << ' ';

        cout << endl;
    }

    cout << cnt(m,n) << endl;

    for(int i = 0; i <= m; i++) {
        for(int j = 0; j <= n; j++)
            cout << dp[i][j] << ' ';

        cout << endl;
    }

    return 0;
}
