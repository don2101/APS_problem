/**
 * 시뮬레이션 문제
 * 
 * 풀면서 어려웠던 점
 * 1. 블록을 내리면서 제한조건을 걸지 않아 오류가 남
 * 2. 오타때문에 오류
 * 3. 모듈을 실행시킬 때 오류가 나지 않을지 생각하고 실행하자
 * */

#include<iostream>

using namespace std;

int n, w, h;
int ans;
int map[15][12];
bool live[15][12];
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


bool isInside(int y, int x) {
    if(y < 0 || y >= h) return false;
    if(x < 0 || x >= w) return false;

    return true;
}

int counting() {
    int ret = 0;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            if(map[i][j] > 0 && live[i][j]) ret++;
        }
    }
    
    return ret;
}

void dropBlock() {
    for(int i = h-2; i >= 0; --i) {
        for(int j = 0; j < w; ++j) {
            if(map[i][j] > 0 && live[i][j]) {
                int curY = i;
                int curX = j;
                while(true) {
                    if(isInside(curY+1, curX)) {
                        if(map[curY+1][curX] == 0 && !live[curY+1][curX]) curY++;
                        else break;
                    }
                    else break;
                }
                if(i == curY) continue;

                map[curY][curX] = map[i][j];
                live[curY][curX] = true;
                map[i][j] = 0;
                live[i][j] = false;
            }
        }
    }
}

void breakBlock(int y, int x) {
    int range = map[y][x];

    live[y][x] = false;
    map[y][x] = 0;

    if(range == 1) {
        return;
    }

    for(int d = 0; d < 4; ++d) {
        for(int i = 1; i < range; ++i) {
            if(isInside(y+i*dy[d], x+i*dx[d])) {
                if(live[y+i*dy[d]][x+i*dx[d]] && map[y+i*dy[d]][x+i*dx[d]] > 0) {
                    breakBlock(y+i*dy[d], x+i*dx[d]);
                }
            } else {
                break;
            }
        }
    }

}

void dropBall(int x) {
    int i = 0;
    while(!live[i][x] && isInside(i, x)) {
        i++;
    }

    if(i >= h) return;

    breakBlock(i, x);
}

void init() {
    cin >> n >> w >> h;

    ans = 99999;
    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            cin >> map[i][j];
            if(map[i][j] > 0) live[i][j] = true;
            else live[i][j] = false;
        }
    }
}


void dfs(int c) {
    if(ans == 0) return;
    if(c == 0) {
        int count = counting();
        if(ans > count) ans = count;
        
        return;
    }

    int original[15][12];
    bool originalLive[15][12];

    for(int i = 0; i < h; ++i) {
        for(int j = 0; j < w; ++j) {
            original[i][j] = map[i][j];
            originalLive[i][j] = live[i][j];
        }
    }

    for(int k = 0; k < w; ++k) {
        dropBall(k);
        dropBlock();

        dfs(c-1);
        for(int i = 0; i < h; ++i) {
            for(int j = 0; j < w; ++j) {
                map[i][j] = original[i][j];
                live[i][j] = originalLive[i][j];
            }
        }
    }

    return;
}

int main(int argc, char** argv)
{
    int t, tc = 0;
    cin >> t;

    while(++tc <= t) {
        init();
        dfs(n);

        cout << "#" << tc << " " << ans << endl;
    }

    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}