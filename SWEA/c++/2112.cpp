/*
성능이 우수한 보호 필름을 제작하려고 한다.
보호 필름은 [Fig. 1]와 같은 엷은 투명한 막을 D장 쌓아서 제작된다.
막은 [Fig. 1]과 같이 동일한 크기를 가진 바(bar) 모양의 셀들이 가로 방향으로 W개 붙여서 만들어진다.
이렇게 제작된 필름은 두께 D, 가로 크기 W의 보호 필름이라고 한다.

각 셀들은 특성 A 또는 특성 B를 가지고 있다. 보호 필름의 성능은 셀들의 특성이 어떻게 배치됨에 따라 결정된다.
[Fig. 1]은 셀 6개를 이어서 만든 막의 단면이다.
[Fig. 2]는 셀 8개로 이루어진 엷은 막 6장을 쌓아서 만든 두께 6, 가로크기 8인 보호 필름의 단면이다.  A, B는 각 셀들이 가진 특성 A, 특성 B를 의미한다.

보호 필름의 성능을 검사하기 위해 합격기준 K라는 값을 사용한다.
충격은 보호 필름 단면의 세로 방향으로 가해지므로, 세로 방향 셀들의 특성이 중요하다. (충격방향은 [Fig. 3]의 빨간색 화살표 참조)
단면의 모든 세로방향에 대해서 동일한 특성의 셀들이 K개 이상 연속적으로 있는 경우에만 성능검사를 통과하게 된다.
[Fig. 3]과 같이 보호 필름의 단면이 주어지고 합격기준 K값이 3으로 주어지는 경우를 생각해 보자.(예제 입력 1번과 동일)
세로방향 ①, ②, ③, ⑤, ⑥, ⑦, ⑧번 위치에는 동일한 특성을 지닌 셀이 3개 이상 연속적으로 있다. ([Fig. 3]의 빨간색 사각형 참조)
하지만 ④번 위치는 동일한 특성을 지닌 셀이 3개 이상 연속적으로 있지 않으므로 성능검사를 통과할 수 없다.

성능검사에 통과하기 위해서 약품을 사용하여야 한다.
약품은 막 별로 투입할 수 있으며 이 경우 투입하는 막의 모든 셀들은 하나의 특성으로 변경된다.
특정 막에 약품 A를 투입하면 막 내의 모든 셀들이 특성 A로 변경되며, 약품 B를 넣게 되면 특성이 모두 특성 B로 변경된다.
[Fig. 4]는 세 번째 막에 약품 A를 투입하여 특성 A로 변경하고, 여섯 번째 막에 약품 B를 투입하여 특성 B로 변경시킨 경우이다.

약품 투입횟수 두 번으로 ①~⑧번까지의 모든 세로방향에 대해서 동일한 특성의 셀들이 연속적으로 3개 이상 있기 때문에 성능검사를 통과하였다. (합격기준 K=3)
[Fig. 3]의 경우 약품을 투입하여 성능검사를 통과시키는 방법은 여러 방법이 있을 수 있지만 투입횟수의 최소값은 2이다.
따라서 성능검사를 통과하기 위한 최소 약품투입 횟수는 2가 된다.
두께 D, 가로크기 W인 보호 필름 단면의 정보와 합격기준 K가 주어졌을 때, 약품 투입 횟수를 최소로 하여 성능검사를 통과할 수 있는 방법을 찾고,
이때의 약품 투입 횟수를 출력하라. ([Fig. 3] 예제의 경우 정답은 2가 된다.)
약품을 투입하지 않고도 성능검사를 통과하는 경우에는 0을 출력한다.

[제약사항]
1. 시간제한 : 최대 50개 테스트 케이스를 모두 통과하는데, C/C++/Java 모두 5초
2. 보호 필름의 두께 D는 3이상 13이하의 정수이다. (3≤D≤13)
3. 보호 필름의 가로크기 W는 1이상 20이하의 정수이다. (1≤W≤20)
4. 합격기준 K는 1이상 D이하의 정수이다. (1≤K≤D)
5. 셀이 가질 수 있는 특성은 A, B 두 개만 존재한다.

[입력]
첫 줄에 총 테스트 케이스의 개수 T가 주어진다.
두 번째 줄부터 T개의 테스트 케이스가 차례대로 주어진다.
각 테스트 케이스의 첫 줄에는 보호 필름의 두께 D, 가로크기 W, 합격기준 K가 차례로 주어진다.
그 다음 D줄에 보호 필름 단면의 정보가 주어진다. 각 줄에는 셀들의 특성 W개가 주어진다. (특성A는 0, 특성B는 1로 표시된다.)

[출력]
테스트 케이스의 개수만큼 T줄에 T개의 테스트 케이스 각각에 대한 답을 출력한다.
각 줄은 “#x”로 시작하고 공백을 하나 둔 다음 정답을 출력한다. (x는 1부터 시작하는 테스트 케이스의 번호이다)
출력해야 할 정답은 성능검사를 통과할 수 있는 약품의 최소 투입 횟수이다. 약품을 투입하지 않고도 성능검사를 통과하는 경우에는 0을 출력한다.
*/

/*
사용 로직
1. dfs
2. 백트래킹
3. 조건문 제어
4. 조합
5. 구간 확인
*/


#include <iostream>

using namespace std;

int ans;
int d, w, k;
int map[13][20];
bool chemical[13];

bool test(int col) {
    bool ret = false;
	for(int i = 0; i < d-(k-1); ++i) {
    	ret = true;
        for(int j = 0; j < k-1; ++j) {
        	if(map[i+j][col] != map[i+j+1][col]) {
                ret = false;
            }
        }
        if(ret) break;
    }
    return ret;
}

void dfs(int start, int count, int cnt) {
    if(count <= 0) {
    	bool success;
        for(int i = 0; i < w; ++i) {
        	success = test(i);
            if(!success) break;
        }
        if(success) {
        	if(ans > cnt) ans = cnt;
        }
        return;
    }
    
    int selected = -1;
	for(int i = start; i < d; ++i) {
    	if(chemical[i]) {
        	selected = i;
            break;
        }
    }
    
    int tempMap[20];
    for(int i = 0; i < w; ++i) tempMap[i] = map[selected][i];
    
    for(int i = 0; i < w; ++i) map[selected][i] = 1;
    dfs(selected+1, count-1, cnt);
    for(int i = 0; i < w; ++i) map[selected][i] = 0;
    dfs(selected+1, count-1, cnt);
    
    for(int i = 0; i < w; ++i) map[selected][i] = tempMap[i];
}



int main(void) {
	int t, tc = 0;
    scanf("%d", &t);
    
    while(++tc <= t) {
        ans = 99999;
    	scanf("%d %d %d", &d, &w, &k);
        
        for(int i = 0; i < d; ++i) {
        	for(int j = 0; j < w; ++j) {
            	scanf("%d", &map[i][j]);
            }
        }
        
        bool success;
        for(int i = 0; i < w; ++i) {
        	success = test(i);
            if(!success) break;
        }
        
        if(!success) {
        	for(int comb = 1; comb < 1<< d; ++comb) {
                for(int j = 0; j < d; ++j) chemical[j] = false;
                int count = 0;
                
                for(int j = 0; j < d; ++j) {
                	if(comb & 1<<j) {
                    	count++;
                        chemical[j] = true;
                    }
                }
                
                if(count > ans) continue;
                dfs(0, count, count);
            }
        } else {
        	ans = 0;
        }

    	printf("#%d %d\n", tc, ans);
    }
    
}