/*
정보
1. 1번 한쪽, 2번 반대 두쪽, 3번 직각 두쪽, 4번 세방향, 5번 네방향
2. cctv 회전가능
3. 6은 벽, 통과 불가능
4. 1 <= n, m <=8, 0 빈칸, cctv수 <= 8

cctv의 방향을 정해 최소 사각지대 수?
*/

/*
풀이
1. 각 cctv를 cctv[]에 저장
2. dfs로 방향을 정하고 scan
3. scan: 정해진 방향에 대해 진행
    3.1. 6아니고, 안쪽이라면 진행
    3.2. !visited이고 0이라면 count 증가
4. unscan: 정해진 방향에 대해 scan 반대
5. 최종 depth에 도달하면 count가 더 많은것을 선택
*/

#include <iostream>

using namespace std;


int n, m;
int ans;
int cctv[8];
int map[8][8];
bool visited[8][8];
int blank;
int cp;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
int cctvX[8];
int cctvY[8];


bool isInside(int y, int x) {
    if(y >= n || y < 0) return false;
    if(x >= m || x < 0) return false;
    return true;
}


int scan(int y, int x, int direc) {
    int cy = y+dy[direc];
    int cx = x+dx[direc];
    int ret = 0;

    while(isInside(cy, cx) && map[cy][cx] != 6) {
        if(!visited[cy][cx] && map[cy][cx] == 0) {
            ret++;
            vistied[cy][cx] = true;
        }
        cy += dy[direc];
        cx += dx[direc];
    }

    return ret;
}

void unscan(int y, int x, int direc) {
    int cy = y+dy[direc];
    int cx = x+dx[direc];

    while(isInside(cy, cx) && map[cy][cx] != 6) {
        if(visited[cy][cx] && map[cy][cx] == 0) {
            visited[cy][cx] = false;
        }
        cy += dy[direc];
        cx += dx[direc];
    }
}

void dfs(int depth, int count) {
    if(depth == cp) {
        if(ans > blank-count) ans = blank-count;

        return;
    }

    if(cctv[depth] == 1) {
        for(int d = 0; d < 4; ++d) {
            int cnt = scan(cctvY[depth], cctvX[depth], d);
            dfs(depth+1, count+cnt);
            unscan(cctvY[depth], cctvX[depth], d);
        }
    } else if(cctv[depth] == 2) {
        for(int d = 0; d < 2; ++d) {
            int cnt = scan(cctvY[depth], cctvX[depth], d);
            int cnt2 = scan(cctvY[depth], cctvX[depth], (d+2)%4);
            dfs(depth+1, count+cnt+cnt2);
            unscan(cctvY[depth], cctvX[depth], d);
            unscan(cctvY[depth], cctvX[depth], (d+2)%4);
        }
    } else if(cctv[depth] == 3) {
        for(int d = 0; d < 4; ++d) {
            int cnt = scan(cctvY[depth], cctvX[depth], d);
            int cnt2 = scan(cctvY[depth], cctvX[depth], (d+1)%4);
            dfs(depth+1, count+cnt+cnt2);
            unscan(cctvY[depth], cctvX[depth], d);
            unscan(cctvY[depth], cctvX[depth], (d+1)%4);
        }
    } else if(cctv[depth] == 4) {
        for(int d = 0; d < 4; ++d) {
            int cnt = scan(cctvY[depth], cctvX[depth], d);
            int cnt2 = scan(cctvY[depth], cctvX[depth], (d+1)%4);
            int cnt3 = scan(cctvY[depth], cctvX[depth], (d+2)%4);
            dfs(depth+1, count+cnt+cnt2+cnt3);
            unscan(cctvY[depth], cctvX[depth], d);
            unscan(cctvY[depth], cctvX[depth], (d+1)%4);
            unscan(cctvY[depth], cctvX[depth], (d+2)%4);
        }
    } else if(cctv[depth] == 5) {
        int cnt = scan(cctvY[depth], cctvX[depth], 1);
        int cnt2 = scan(cctvY[depth], cctvX[depth], 2);
        int cnt3 = scan(cctvY[depth], cctvX[depth], 3);
        int cnt4 = scan(cctvY[depth], cctvX[depth], 0);
        dfs(depth+1, count+cnt+cnt2+cnt3+cnt4);
        unscan(cctvY[depth], cctvX[depth], 1);
        unscan(cctvY[depth], cctvX[depth], 2);
        unscan(cctvY[depth], cctvX[depth], 3);
        unscan(cctvY[depth], cctvX[depth], 0);
    }

}

int main(void) {
    cin >> n >> m;

    blank = 0;
    ans = 99999;
    int temp;
    cp = 0;
    
    for(int i = 0; i < n; ++i) {
        for(int j = 0; j < m; ++j) {
            cin >> temp;
            map[i][j] = temp;
            visited[i][j] = false;
            if(temp == 0) {
                blank++;
            } else if(temp == 6) {
                visited[i][j] = true;
            } else {
                visited[i][j] = true;
                cctvX[cp] = j;
                cctvY[cp] = i;
                cctv[cp] = temp;
                cp++;
            }
        }
    }

    dfs(0, 0);

    cout << ans << endl;
}