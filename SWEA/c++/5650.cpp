/*
1. 시뮬레이션 문제
2. 각 조건에 따라 제어를 정확하게 수행
3. 모든 조건을 만족하도록 순서를 명확하게 수행

배운것:
1. 제어문 작성시 최대한 간단하고 명료하게 작성할 것
*/

#include <iostream>
#define MAX_VALUE 100

using namespace std;

int map[MAX_VALUE][MAX_VALUE];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int n;
int ans;

bool isInside(int y, int x) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= n) return false;

    return true;
}

int changeDirection(int i, int j, int curD) {
    if(map[i][j] == 1) {
        if(curD == 0) return 2;
        if(curD == 1) return 0;
        if(curD == 2) return 3;
        if(curD == 3) return 1;
    } else if(map[i][j] == 2) {
        if(curD == 0) return 2;
        if(curD == 1) return 3;
        if(curD == 2) return 1;
        if(curD == 3) return 0;
    } else if(map[i][j] == 3) {
        if(curD == 0) return 1;
        if(curD == 1) return 3;
        if(curD == 2) return 0;
        if(curD == 3) return 2;
    } else if(map[i][j] == 4) {
        if(curD == 0) return 3;
        if(curD == 1) return 2;
        if(curD == 2) return 0;
        if(curD == 3) return 1;
    }

    return (curD+2)%4;
}


int main(void) {
    int t, tc = 0;
    scanf("%d", &t);

    while(++tc <= t) {
        ans = 0;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &map[i][j]);
            }
        }

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                if(map[i][j] == 0) {

                    for(int d = 0; d < 4; ++d) {
                        int maxScore = 0;
                        int curD = d;
                        int curX = j;
                        int curY = i;

                        do {
                            curX += dx[curD];
                            curY += dy[curD];

                            if(!isInside(curY, curX)) {
                                curD = (curD+2)%4;
                                maxScore++;
                            } else if(map[curY][curX] >= 1 && map[curY][curX] <= 5) {
                                curD = changeDirection(curY, curX, curD);
                                maxScore++;
                            } else if(map[curY][curX] >= 6 && map[curY][curX] <= 10) {
                                int nextX = 0;
                                int nextY = 0;
                                bool find = false;

                                for(int a = 0; a < n; ++a) {
                                    for(int b = 0; b < n; ++b) {
                                        if(map[a][b] == map[curY][curX] && (a != curY || b != curX)) {
                                            nextX = b;
                                            nextY = a;
                                            find = true;
                                            break;
                                        }
                                    }
                                    if(find) break;
                                }
                                curX = nextX;
                                curY = nextY;
                            }

                        } while(!(map[curY][curX] == -1 || (j == curX && i == curY)));

                        if(ans < maxScore) {
                            ans = maxScore;
                        }
                    }
                }
            }
        }

        printf("#%d %d\n", tc, ans);
    }
}