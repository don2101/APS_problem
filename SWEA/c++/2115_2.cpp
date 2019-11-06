#include <iostream>

using namespace std;

int n, m, c;
int dp[10][10];
int map[10][10];
int ans;


int selectTwo(int h, int l) {
    int maxProfit = 0;

    if(l < n) {
        for(int j = l; j+m-1 < n; ++j) {
            if(maxProfit < dp[h][j]) maxProfit = dp[h][j]; 
        }
    }

    for(int i = h+1; i < n; ++i) {
        for(int j = 0; j+m-1 < n; ++j) {
            if(maxProfit < dp[i][j]) maxProfit = dp[i][j]; 
        }
    }

    return maxProfit;
}

void selectOne() {
    int maxProfit = 0;


    for(int i = 0; i < n; ++i) {
        for(int j = 0; j+m-1 < n; ++j) {
            int one = dp[i][j];
            int two = selectTwo(i, j+m);

            if(one+two > ans) ans = one+two;
        }
    }
}


void createNumber(int h, int l, int r) {
    int maxNumber = 0;

    for(int i = 0; i < (1 << m); ++i) {
        int numberSum = 0;
        int profitSum = 0;

        for(int j = 0; j < m; ++j) {
            if(i & (1 << j)) {
                numberSum += map[h][l+j];
                profitSum += map[h][l+j]*map[h][l+j];
            }

            if(numberSum > c) {
                profitSum = 0;
                break;
            }
        }

        if(profitSum > maxNumber) {
            maxNumber = profitSum;
        }
    }

    dp[h][l] = maxNumber;
}

void makeDp() {
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j+m-1 < n; ++j) {
            createNumber(i, j, j+m-1);
        }
    }
    
}

void init() {
    ans = 0;
    cin >> n >> m >> c;

    for(int i = 0; i < 10; ++i) {
        for(int j = 0; j < 10; ++j) {
            dp[i][j] = 0;
        }
    }

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> map[i][j];
        }
    }
}

int main(void) {
    int t, tc = 0;
    cin >> t;

    while(++tc <= t) {
        init();
        makeDp();
        selectOne();

        cout << "#" << tc << " " << ans << endl;
    }
}