/*
친구들과 디저트 카페 투어를 할 계획이다.
[Fig. 1]과 같이 한 변의 길이가 N인 정사각형 모양을 가진 지역에 디저트 카페가 모여 있다.
 
원 안의 숫자는 해당 디저트 카페에서 팔고 있는 디저트의 종류를 의미하고
카페들 사이에는 대각선 방향으로 움직일 수 있는 길들이 있다.
디저트 카페 투어는 어느 한 카페에서 출발하여

[Fig. 2]와 같이 대각선 방향으로 움직이고 사각형 모양을 그리며 출발한 카페로 돌아와야 한다.

디저트 카페 투어를 하는 도중 해당 지역을 벗어나면 안 된다.
또한, 친구들은 같은 종류의 디저트를 다시 먹는 것을 싫어한다.

즉, [Fig. 3]과 같이 카페 투어 중에 같은 숫자의 디저트를 팔고 있는 카페가 있으면 안 된다.
 
[Fig. 4]와 같이 하나의 카페에서 디저트를 먹는 것도 안 된다.

[Fig. 5]와 같이 왔던 길을 다시 돌아가는 것도 안 된다.
 
친구들과 디저트를 되도록 많이 먹으려고 한다.
디저트 가게가 모여있는 지역의 한 변의 길이 N과 디저트 카페의 디저트 종류가 입력으로 주어질 때,
임의의 한 카페에서 출발하여 대각선 방향으로 움직이고
서로 다른 디저트를 먹으면서 사각형 모양을 그리며 다시 출발점으로 돌아오는 경우,
디저트를 가장 많이 먹을 수 있는 경로를 찾고, 그 때의 디저트 수를 정답으로 출력하는 프로그램을 작성하라.
만약, 디저트를 먹을 수 없는 경우 -1을 출력한다.

[제약사항]
1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는 데 C/C++/Java 모두 3초
2. 디저트 카페가 모여있는 지역의 한 변의 길이 N은 4 이상 20 이하의 정수이다. (4 ≤ N ≤ 20)
3. 디저트 종류를 나타나는 수는 1 이상 100 이하의 정수이다.

[입력]
입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T가 주어지고, 그 다음 줄부터 T개의 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 디저트 카페가 모여있는 지역의 한 변의 길이 N이 주어진다.
그 다음 N 줄에는 N * N 크기의 디저트 카페에서 팔고 있는 디저트 종류에 대한 정보가 주어진다.

[출력]
테스트 케이스 개수만큼 T개의 줄에 각각의 테스트 케이스에 대한 답을 출력한다.
각 줄은 "#t"로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (t는 1부터 시작하는 테스트 케이스의 번호이다)
출력해야 할 정답은 가능한 경우 중 디저트를 가장 많이 먹을 때의 디저트 수 이다.
만약, 디저트를 먹을 수 없는 경우 정답은 -1이다.
*/

/*
사용 로직
1. dfs
2. 백트래킹
3. 배열 대각선 제어
*/

/*
배운것
1. 함수 인자를 넘겨줄 때 다시 한번 더 확인
2. isInside를 먼저 수행(segmentation fault, index out of range 발생 가능)
3. 문제의 경우의 수를 다시 한번 더 생각하고 풀기
*/



#include <iostream>

using namespace std;

int map[20][20];
bool desert[101];
bool visited[20][20];
int ans;
int n;
int dx[4] = {1, -1, -1, 1};
int dy[4] = {1, 1, -1, -1};
bool visitedDirec[4];

bool isInside(int y, int x) {
    if(y >= n || y < 0) return false;
    if(x >= n || x < 0) return false;

    return true;
}

void dfs(int y, int x, int sy, int sx, int count, int direc) {
    if(y == sy && x == sx && count > 0) {
        if(ans < count) ans = count;
        return;
    }

    desert[map[y][x]] = true;
    ++count;
    visited[y][x] = true;
    int newDirec = (direc+1)%4;

    if(y+dy[direc] == sy && x+dx[direc] == sx) dfs(y+dy[direc], x+dx[direc], sy, sx, count, direc);
    if(y+dy[newDirec] == sy && x+dx[newDirec] == sx) dfs(y+dy[newDirec], x+dx[newDirec], sy, sx, count, newDirec);

    if(isInside(y+dy[direc], x+dx[direc])) {
        if (!visited[y + dy[direc]][x + dx[direc]] &&
            !desert[map[y + dy[direc]][x + dx[direc]]]) {
            dfs(y + dy[direc], x + dx[direc], sy, sx, count, direc);
        }
    }

    if(isInside(y+dy[newDirec], x+dx[newDirec])) {
        if(!visited[y+dy[newDirec]][x+dx[newDirec]] &&
           !desert[map[y+dy[newDirec]][x+dx[newDirec]]] &&
           !visitedDirec[newDirec]) {
            visitedDirec[newDirec] = true;
            dfs(y+dy[newDirec], x+dx[newDirec], sy, sx, count, newDirec);
            visitedDirec[newDirec] = false;
        }
    }

    desert[map[y][x]] = false;
    visited[y][x] = false;

    return;
}

int main(void) {
    int t, tc = 0;
    scanf("%d", &t);

    while(++tc <= t) {
        ans = -1;
        scanf("%d", &n);

        for(int i = 0; i < n; ++i) {
            for(int j = 0; j < n; ++j) {
                scanf("%d", &map[i][j]);
                visited[i][j] = false;
            }
        }

        for(int i = 0; i <= 100; ++i) desert[i] = false;
        for(int i = 0; i < 4; ++i) visitedDirec[i] = false;

        for(int i = 0; i < n-1; ++i) {
            for(int j = 0; j < n-1; ++j) {
                visitedDirec[0] = true;
                dfs(i, j, i, j, 0, 0);
                visitedDirec[0] = false;
            }
        }

        printf("#%d %d\n", tc, ans);
    }
}