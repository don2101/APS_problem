#include <iostream>

using namespace std;

int map[10][10];
int dp[10][10];
int n;
int m;
int c;
int ans;

void scan(int y, int x) {

    int temp_list[5];
    int sum = 0;
    int doubleSum = 0;
    int p = 0;

    for(int i = x; i < x+m; ++i) {
        temp_list[p] = map[y][i];
        p++;
    }

    
    for(int i = 0; i < 1<<p; ++i) {
        int tempSum = 0;
        int tempDoubleSum = 0;
        for(int j = 0; j < p; ++j) {
            if(i & 1<<j) {
                tempSum += temp_list[j];
                tempDoubleSum += temp_list[j]*temp_list[j];
            }
        }
        if(tempSum <= c && tempDoubleSum > doubleSum) {
            doubleSum = tempDoubleSum;
        }
    }

    dp[y][x] = doubleSum;
}

int main(void) {
    int t, tc = 0;
    scanf("%d", &t);

    while(++tc <= t) {
        ans = 0;
        scanf("%d %d %d", &n, &m, &c);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &map[i][j]);
                dp[i][j] = 0;
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n-m+1; ++j) {
                if(j+m > n) {
                    break;
                }

                int sum = 0;
                int doubleSum = 0;
                for(int k = j; k < j+m; ++k) {
                    sum += map[i][k];
                    doubleSum += map[i][k]*map[i][k];
                }

                if(sum > c) {
                    scan(i, j);
                } else {
                    dp[i][j] = doubleSum;
                }
            }
        }

        int maxFirst = 0;
        int maxSecond = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(maxFirst < dp[i][j]) {
                    maxFirst = dp[i][j];
                }
                maxSecond = 0;
                for(int a = i; a < n; ++a) {
                    if(i == a) {
                        for(int b = j+m; b < n; ++b) {
                            if(maxSecond < dp[a][b]) {
                                maxSecond = dp[a][b];
                            }
                        }
                    } else {
                        for(int b = 0; b < n; ++b) {
                            if(maxSecond < dp[a][b]) {
                                maxSecond = dp[a][b];
                            }
                        }
                    }
                }
                if(ans < maxFirst + maxSecond) ans = maxFirst + maxSecond;
            }
        }
        
        printf("#%d %d\n", tc, ans);
    }
}