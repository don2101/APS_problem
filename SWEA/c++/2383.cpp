/*
1. n*n 방에 사람들이 최대한 빠른시간 내에 내려가야 한다.
2. 아래층으로 내려가는 시간 = 계단 입구까지 도달하는 시간 + 내려가는데 걸리는 시간
    2.1. 이동시간 = y좌표 차이 + x좌표 차이
    2.2. 입구까지 도달했다: 입구 좌표에 도달했다.
    2.3. 내려가는데 걸리는 시간 = 1분 + 기다리는 시간 + 계단 수
    2.4. 계단 위에 최대 3명
3. 4 <= n <= 10, 1 <= 사람 <= 10, 2 <= 계단 길이 <= 10
*/

/*
풀이
1. 부분 집합, 시뮬레이션 문제
2. 부분 집합을 사용하여 사람들을 계단으로 분배 => 1초씩 감소하며 이동, 계단을 내려간다
3. 계단(stx[], sty[])으로 분배 하며 각 사람(px[], py[])마다 거리를 dist[]에 초기화
4. walkToStair(): 계단으로 걸어가는 사람들의 거리를 1 감소. 계단에 도착할 경우 visited 처리
5. downToStair(): 계단에서 내려가는 사람들의 거리를 1 감소. 계단을 모두 내려갔거나(dist==0) 계단에 도착한 사람일 경우 거리를 1 감소
    5.1. 계단에 막 도착한 사람이 있을 경우(dist==0 && visited[]) dist를 계단수로 초기화
    5.2. 계단을 내려가는 도중이면(dist>=2 && visited[]) dist 1 감소
    5.3. 계단을 내려가기 직전이면(dist==1 && visited[]) dist를 2감소시키고 remain 1 감소
    5.4. 계단을 다 내려간 사람이 있을경우, 이전 index에서 이미 입구에서 기다리고 있던 사람을 올린다
8. remain을 사람 수로 초기화, time = 0으로 초기화, visited[] = false, waiting[] = 0, peopleToStair[]재설정 하여 remain이 0이 될 때 까지 반복
*/

#include <iostream>

using namespace std;

int px[10];
int py[10];
int people;
int stx[2];
int sty[2];
int st[2];
int waiting[2];
int dist[10];
bool visited[10];
int peopleToStair[10];
int count;
int ans;
int n;
int remain;


int abs(int num) {
    if(num < 0) return -num;
    return num;
}


int distance(int px, int py, int sx, int sy) {
    return(abs(py-sy)+abs(px-sx));
}


void walkToStair() {
    for(int j = 0; j < people; ++j) {
        if(dist[j] > 0 && !visited[j]) {
            dist[j]--;
        }

        if(dist[j] == 0 && !visited[j]) {
            visited[j] = true;
        }
    }
}


void downOnStair() {
    for(int j = 0; j < people; ++j) {
        if(dist[j] == 0 && visited[j]) {
            if(waiting[peopleToStair[j]] < 3 && waiting[peopleToStair[j]] < st[peopleToStair[j]]) {
                dist[j] = st[peopleToStair[j]];
                waiting[peopleToStair[j]]++;
            }
        } else if(dist[j] >= 2 && visited[j]) {
            dist[j]--;
        } else if(dist[j] == 1 && visited[j]) {
            dist[j] -= 2;
            remain--;
            waiting[peopleToStair[j]]--;
            for(int i = 0; i < j; ++i) {
                if(dist[i] == 0 && visited[i]) {
                    if(waiting[peopleToStair[i]] < 3 && waiting[peopleToStair[i]] < st[peopleToStair[i]]) {
                        dist[i] = st[peopleToStair[i]];
                        waiting[peopleToStair[i]]++;
                    }
                }
            }
        }
    }
}

int main(void) {
    int t, tc = 0;
    scanf("%d", &t);

    while(++tc <= t) {
        ans = 99999;
        scanf("%d", &n);
        int temp = 0;
        int stair = 0;
        remain = 0;
        people = 0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &temp);
                if(temp == 1) {
                    px[people] = j;
                    py[people] = i;
                    people++;
                } else if(temp >= 2 && temp <= 10) {
                    stx[stair] = j;
                    sty[stair] = i;
                    st[stair] = temp;
                    stair++;
                }
            }
        }
        
        for(int i = 0; i < 1<<people; ++i) {
            for(int j = 0; j < people; ++j) {
                int value = 1<<j;
                if(i & value) {
                    peopleToStair[j] = 1;
                    dist[j] = distance(px[j], py[j], stx[1], sty[1]);
                } else {
                    peopleToStair[j] = 0;
                    dist[j] = distance(px[j], py[j], stx[0], sty[0]);
                }
            }

            for(int j = 0; j < people; ++j) {
                visited[j] = false;
            }
            
            remain = people;
            count = 0;
            waiting[0] = 0;
            waiting[1] = 0;

            while(remain > 0) {
                count++;
                downOnStair();
                walkToStair();
            }
            if(count < ans) ans = count;

        }

        printf("#%d %d\n", tc, ans);
    }
}