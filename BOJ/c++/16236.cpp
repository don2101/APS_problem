/*
문제 분석
1. 배열제어, 방향 이동
2. 상어 현재위치 계속 추적
3. bfs으로 가장 가까운 물고기 추적
4. 거리만큼 이동, 시간 추가, 크기 증가
5. 반복

주의
1. 거리: 지나갈 수 있는 거리 최소값
2. 사이즈 < 물고기: 먹기 X, 지나가기 X
3. 사이즈 == 물고기: 먹기 X, 지나가기 O
4. 사이즈 > 물고기: 먹기 O, 지나가기 O
*/

#include <iostream>

using namespace std;

int fishX[400];
int fishY[400];
int fish;
int remain;
bool fishEat[400];

int curX;
int curY;
int n;
int size;
int count;

int map[20][20];
int dist[20][20];
bool visited[20][20];
int times;
int nextX;
int nextY;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};


bool isInside(int y, int x) {
    if(y >= n || y < 0) return false;
    if(x >= n || x < 0) return false;
    return true;
}


int distance() {
    int minDist = 99999;


    for(int i = 0; i < fish; ++i) {
        if(!fishEat[i]) {
            if(dist[fishY[i]][fishX[i]] < minDist) {
                minIdx = i;
                minDist = dist[fishY[i]][fishX[i]];
            }
        } else if(dist[fishY[i]][fishX[i]] < minDist) {
            
        }
    }

    next = minIdx;

    return minDist;
}

int bfs() {
    int qx[400];
    int qy[400];
    int qd[400];
    int f = 0;
    int r = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            visited[i][j] = false;
            dist[i][j] = 99999;
        }
    }

    qx[r] = curX;
    qy[r] = curY;
    qd[r++] = 0;

    while(r != f) {
        int cx = qx[f];
        int cy = qy[f];
        int cd = qd[f++];
        visited[cy][cx] = true;
        
        dist[cy][cx] = cd;

        for(int d = 0 ; d < 4; ++d) {
            if(isInside(cy+dy[d], cx+dx[d]) && !visited[cy+dy[d]][cx+dx[d]]) {
                if(size >= map[cy+dy[d]][cx+dx[d]]) {
                    qx[r] = cx+dx[d];
                    qy[r] = cy+dy[d];
                    qd[r++] = cd+1;
                }
            }
        }
    }
}


int main(void) {
    cin >> n;
    size = 2;
    fish = 0;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            cin >> map[i][j];
            visited[i][j] = false;

            if(map[i][j] == 9) {
                curX = j;
                curY = i;
            } else if(map[i][j] > 0) {
                fishX[fish] = j;
                fishY[fish] = i;
                fishEat[fish] = false;
                fish++;
            }
        }
    }

    times = 0;
    count = 0;
    remain = fish;

    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < n; ++j) {
            dist[i][j] = 99999;
        }
    }

    while(remain > 0) {
        int nextDist = bfs();
        times += nextDist;
        count += map[nextY][nextX];

        if(count >= size) {
            count -= size;
            size++;
        }

        if(count >= size) {
            count -= size;
            size++;
        }

        curX = nextX;
        curY = nextY;
        map[nextY][nextX] = 0;
        remain--;
    }

    cout << times << endl;
} 