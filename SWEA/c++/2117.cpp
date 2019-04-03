#include <iostream>

using namespace std;

int map[20][20];
int m;
int n;
int ans;

bool isInside(int y, int x) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= n) return false;
    return true; 
}

int scan(int y, int x, int k) {
    int ret = 0;
    int step = 1;

    for(int i = y-k+1; i < y+k+1; ++i) {
        for(int j = x-step+1; j < x+step; ++j) {
            if(isInside(i, j) && map[i][j] == 1) {
                ret++;
            }
        }
        if(i >= y) step--;
        else step++;
    }

    return ret;
}

int main(void) {
    int t, tc = 0;
    scanf("%d", &t);

    while(++tc <= t) {
        ans = 0;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &map[i][j]);
            }
        }

        int k = n+1;

        while(k >= 1) {
            int cost = k*k + (k-1)*(k-1);
            
            bool find = false;
            for(int i = 0; i < n; ++i) {
                for(int j = 0; j < n; ++j) {
                    int count = scan(i, j, k);
                    if(cost <= count*m) {
                        find = true;
                        if(ans < count) ans = count;
                    }
                }
            }

            if(find) break;
            k--;
        }

        printf("#%d %d\n", tc, ans);
    }
}