/**
 * 7793. 오 나의 여신님
 * 1. BFS 문제
 * 2. 악마의 영역과 탐색 가능한 영역을 BFS로 확장
 * 3. 탐색 가능 영역 먼저 확장 이후 악마의 영역 확장
 * 4. 악마의 영역은 탐색 가능 영역을 침범 가능
 * 5. queue에서 꺼낸 탐색 가능 영역이 악마의 영역이면 확장 X
 * 6. 천사에 도달할 경우 depth를 출력
 * 7. 그전에 queue가 바닥나면 GAME OVER 출력
 */
#include <iostream>

using namespace std;

int ans;
char map[50][50];
int m, n;
int depth;
int aqx[2500];
int aqy[2500];
int dqx[2500];
int dqy[2500];
int aqr, aqf;
int dqr, dqf;
bool visited[50][50];


void expandAngel() {

}

void expandDevil() {
    
}

int main(int argc, char** argv)
{
    int t, tc = 0;

    cin >> t;

    while(++tc <= t) {
        ans = 0;
        depth = 0;

        cin >> n >> m;

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < m; ++j) {
                cin >> map[i][j];
            }
        }

        
        

    }
}