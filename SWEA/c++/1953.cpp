/*
1. 탈주범이 지하터널에 존재, 터널끼리 연결되있는 경우 이동 가능
2. 탈주범이 시간당 1 이동할때, 있을 수 있는 위치의 갯수를 계산
3. 터널의 종류 1: +자 2, 3: 세로, 가로, 4 ~ 7: 기역자 돌린것
4. 뚜껑의 위치는 좌표로 주어진다. 터널은 1 ~ 7 사이 숫자로 주어진다
5. 터널 세로: N, 가로: M. 5 <= N, M <= 50. 소요시간: L, 1 <= L <= 20
6. 맨홀 뚜껑은 터널이 위치한 곳에 주어진다.
*/

/*
풀이
1. 모든 간선을 다 찾을 필요 없고, 간선간 비용이 동일하므로 BFS 문제
2. BFS: 최초의 위치를 저장하고, qr != qf 일동안 로직 수행. 터널에 의해 도달 가능한 곳을 저장 visited 처리된 위치는 저장하지 않는다.
3. 위치 도달 => (visited가 처리되지 않았으면) visited처리, ans 증가 => makeNext()
4. void makeNext(int y, int x): y, x 위치의 터널을 조사하여 도달 가능한 위치를 qx, qy에 저장, depth+1을 qd에 저장
    4.1 범위를 벗어나는 경우가 있으므로 isInside 처리
    4.2 isConnected(int direc, int end): 두 노드가 연결되어 있는지를 반환. 연결을 확인할 pipe와 방향을 bit연산
    4.3 pipe[n]: n번째 방향을 1, 2, 4, 8로 저장
5. qx, qy, qd(전역): BFS 수행을 위해 x, y좌표, depth를 저장할 배열 queue.
*/

#include <iostream>

using namespace std;

int map[50][50];
bool visited[50][50];
int n, m, r, c, l;
int qx[5001];
int qy[5001];
int qd[5001];
int pipe[8] = {0, 15, 5, 10, 3, 6, 12, 9};
int multiple[4] = {1, 2, 4, 8};
int qr, qf;
int ans;

int dx[4] = {0, 1, 0, -1};
int dy[4] = {-1, 0, 1, 0};


bool isInside(int y, int x) {
    if(y < 0 || y >= n) return false;
    if(x < 0 || x >= m) return false;
    return true;
}

void push(int y, int x, int d) {
    qx[qr] = x;
    qy[qr] = y;
    qd[qr] = d;
    qr++;
}

int popX() { return qx[qf]; }
int popY() { return qy[qf]; }
int popD() { return qd[qf]; }

bool isConnected(int direc, int end) {
    if(direc & pipe[end]) return true;
    return false;
}

void makeNext(int y, int x, int depth) {
    if(map[y][x] == 1) {
        for(int d = 0; d < 4; ++d) {
            if(isInside(y+dy[d], x+dx[d])) {
                if(!visited[y+dy[d]][x+dx[d]] && isConnected(multiple[(d+2)%4], map[y+dy[d]][x+dx[d]])) push(y+dy[d], x+dx[d], depth);
            }
        }
    } else if(map[y][x] == 2) {
        if(isInside(y+dy[0], x+dx[0])) {
            if(!visited[y+dy[0]][x+dx[0]] && isConnected(multiple[2], map[y+dy[0]][x+dx[0]])) push(y+dy[0], x+dx[0], depth);
        }
        if(isInside(y+dy[2], x+dx[2])) {
            if(!visited[y+dy[2]][x+dx[2]] && isConnected(multiple[0], map[y+dy[2]][x+dx[2]])) push(y+dy[2], x+dx[2], depth);
        }
    } else if(map[y][x] == 3) {
        if(isInside(y+dy[1], x+dx[1])) {
            if(!visited[y+dy[1]][x+dx[1]] && isConnected(multiple[3], map[y+dy[1]][x+dx[1]])) push(y+dy[1], x+dx[1], depth);
        }
        if(isInside(y+dy[3], x+dx[3])) {
            if(!visited[y+dy[3]][x+dx[3]] && isConnected(multiple[1], map[y+dy[3]][x+dx[3]])) push(y+dy[3], x+dx[3], depth);
        }
    } else {
        int direc = map[y][x]-4;
        
        if(isInside(y+dy[direc], x+dx[direc])) {
            if(!visited[y+dy[direc]][x+dx[direc]] && isConnected(multiple[(direc+2)%4], map[y+dy[direc]][x+dx[direc]])) push(y+dy[direc], x+dx[direc], depth);
        }
        if(isInside(y+dy[(direc+1)%4], x+dx[(direc+1)%4])) {
            if(!visited[y+dy[(direc+1)%4]][x+dx[(direc+1)%4]] && isConnected(multiple[(direc+3)%4], map[y+dy[(direc+1)%4]][x+dx[(direc+1)%4]])) push(y+dy[(direc+1)%4], x+dx[(direc+1)%4], depth);
        }
    }
}

int main(void) {
    int t, tc = 0;
    scanf("%d", &t);

    while(++tc <= t) {
        ans = 0;
        scanf("%d %d %d %d %d", &n, &m, &r, &c, &l);
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                scanf("%d", &map[i][j]);
                visited[i][j] = false;
            }
        }

        qr = 0;
        qf = 0;
        push(r, c, 0);

        while(qf != qr) {
            int i = popY();
            int j = popX();
            int depth = popD();
            qf++;
            
            if(visited[i][j]) continue;
            visited[i][j] = true;
            ans++;
            
            if(depth < l-1) {
                makeNext(i, j, depth+1);
            }
        }

        printf("#%d %d\n", tc, ans);
    }
}