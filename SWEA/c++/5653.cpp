/**
 * 시뮬레이션 문제. 명세에 있는 대로 구현함.
 * 구현하면서 어려웠던 점
 * 1. 중복되는 조건을 생각하지 않아 난관이 있었다.
 * 2. 그래도 기능별로 모듈화를 하니 디버깅에 시간이 적게 걸리는 것 같다.
 * */

#include<iostream>
#define CENTER 320
#define EMPTY 0
#define DEAD -1
#define NONLIVE 1
#define LIVE 2
#define ADDING 3

using namespace std;


int map[700][700];
int life[700][700];
int original[700][700];
int n, m, k;
int ans;
int xl, xr, yh, yd;


int dx[4] = {-1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};

void setX(int x) {
    if(x < xl) xl = x;
    if(x > xr) xr = x;
}

void setY(int y) {
    if(y < yd) yd = y;
    if(y > yh) yh = y;
}

void init() {
    ans = 0;
    xl = 700;
    xr = 0;
    yd = 700;
    yh = 0;

    for(int i = 0; i < 700; ++i) {
        for(int j = 0; j < 700; ++j) {
            map[i][j] = EMPTY;
            life[i][j] = 0;
            original[i][j] = 0;
        }
    }

    cin >> n >> m >> k;

    int temp = 0;
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> temp;
            if(temp == 0) continue;
            
            life[i+CENTER][j+CENTER] = temp;
            original[i+CENTER][j+CENTER] = temp;
            map[i+CENTER][j+CENTER] = NONLIVE;
            setX(j+CENTER);
            setY(i+CENTER); 
        }
    }
}

void reduceTime() {
    for(int i = yd; i <= yh; ++i) {
        for(int j = xl; j <= xr; ++j) {
            if(map[i][j] == DEAD || map[i][j] == EMPTY || map[i][j] == ADDING) continue;

            life[i][j]--;
        }
    }
}

void adding(int y, int x) {
    for(int d = 0; d < 4; ++d) {
        if(map[y+dy[d]][x+dx[d]] == EMPTY || map[y+dy[d]][x+dx[d]] == ADDING) {
            if(life[y+dy[d]][x+dx[d]] < original[y][x]) {
                map[y+dy[d]][x+dx[d]] = ADDING;
                life[y+dy[d]][x+dx[d]] = original[y][x];
                original[y+dy[d]][x+dx[d]] = original[y][x];
                setX(x+dx[d]);
                setY(y+dy[d]);
            }
        } 
    }
}

void change() {
    for(int i = yd-1; i <= yh+1; ++i) {
        for(int j = xl-1; j <= xr+1; ++j) {
            if(map[i][j] == DEAD || map[i][j] == EMPTY || map[i][j] == ADDING) { continue;}

            if(map[i][j] == NONLIVE && life[i][j] == 0) {
                life[i][j] = original[i][j];
                map[i][j] = LIVE;
            } else if(map[i][j] == LIVE && life[i][j] == original[i][j]-1) {
                adding(i, j);
                if(life[i][j] == 0) map[i][j] = DEAD;
            } else if(map[i][j] == LIVE && life[i][j] == 0) {
                map[i][j] = DEAD;
            }
        }
    }
}

void finish() {
    for(int i = yd; i <= yh; ++i) {
        for(int j = xl; j <= xr; ++j) {
            if(map[i][j] == ADDING) {
                map[i][j] = NONLIVE;
            }
        }
    }
}

int main(int argc, char** argv) {
    int t, tc = 0;
    cin >> t;

    while(++tc <= t) {
        init();
        
        while(--k >= 0) {
            
            reduceTime();
            
            change();

            finish();
        }

        for(int i = yd; i <= yh; ++i) {
            for(int j = xl; j <= xr; ++j) {
                
                if(map[i][j] == LIVE || map[i][j] == NONLIVE) {
                    ans++;
                }
            }
        }

        cout << "#" << tc << " " << ans << endl;
    }
}