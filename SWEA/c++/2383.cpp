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
4. 1초씩 증가하며 dist[]의 값을 1개씩 줄임
5. dist[]의 값이 0이 되고 !visited[]면 입구에 도착한 것으로 간주(while문 처음에 실행) => 기다리는 사람이 없을 경우 계단 위로 올림(waiting[] 1증가, dist[] = 계단 길이, visited[]=true)
6. dist[]가 0이 되고 visited[]면 계단을 내려온 것으로 간주 => remain 1 감소, waiting[] 1 감소
7. 상태: 필드에 있는 상태(!visited[], distance[] > 0), 입구에 도착한 상태(!visited[], distance == 0), 계단을 내려가는 상태(visited[], distance > 0), 계단을 다 대려간 상태(visited[], distance == 0)
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


int abs(int num) {
    if(num < 0) return -num;
    return num;
}


int distance(int px, int py, int sx, int sy) {
    return(abs(py-sy)+abs(px-sx));
}


int main(void) {
    int t, tc = 0;
    scanf("%d", &t);

    while(++tc <= t) {
        ans = 99999;
        scanf("%d", &n);
        int temp = 0;
        int stair = 0;
        int remain = 0;
        people = 0;
        
        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &temp);
                if(temp == 1) {
                    px[people] = j;
                    px[people] = i;
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
                if(i & 1<<j) {
                    peopleToStair[j] = 1;
                    dist[j] = distance(px[j], py[j], stx[1], sty[1]);
                } else {
                    peopleToStair[j] = 0;
                    dist[j] = distance(px[j], py[j], stx[0], sty[0]);
                }
            }

            for(int j = 0; j < people; ++j) visited[j] = false;
            remain = people;
            count = 0;
            waiting[0] = 0;
            waiting[1] = 0;

            while(remain > 0) {
                count++;
                for(int j = 0; j < people; ++j) {
                    if(dist[j] > 0) {
                        dist[j]--;
                    }

                    if(dist[j] == 0 && !visited[j]) {
                        if(waiting[peopleToStair[j]] < 3 && waiting[peopleToStair[j]] < st[peopleToStair[j]]) {
                            waiting[peopleToStair[j]]++;
                            dist[j] = st[peopleToStair[j]];
                            visited[j] = true;
                        }
                    }else if(dist[j] == 0 && visited[j]) {
                        remain--;
                        waiting[peopleToStair[j]]--;
                    }
                }
            }
            if(count < ans) ans = count;
        }

        printf("#%d %d\n", tc, ans);
    }
}