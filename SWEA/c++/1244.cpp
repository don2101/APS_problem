/*
퀴즈 대회에 참가해서 우승을 하게 되면 보너스 상금을 획득할 수 있는 기회를 부여받는다.
우승자는 주어진 숫자판들 중에 두 개를 선택에서 정해진 횟수만큼 서로의 자리를 위치를 교환할 수 있다.
예를 들어, 다음 그림과 3, 2, 8, 8, 8 의 5개의 숫자판들이 주어지고 교환 횟수는 2회라고 하자.

교환전>
처음에는 첫번째 숫자판의 3과 마지막에 있는 8을 교환해서 8, 2, 8, 3, 8이 되었다.
다음으로, 두 번째 숫자판 2와 네 번째 숫자판의 8을 교환해서 8, 8, 8, 3, 2이 되었다.
정해진 횟수만큼 교환이 끝나면 숫자판의 위치에 부여된 가중치에 의해 상금이 계산된다.
숫자판의 오른쪽 끝에서부터 1원이고 왼쪽으로 한자리씩 갈수록 10의 배수만큼 커진다.
위의 예에서와 같이 최종적으로 숫자판들이 8,8,8,3,2의 순서가 되면 88832원의 보너스 상금을 획득한다.
여기서 주의할 것은 반드시 횟수만큼 교환이 이루어져야 하고 동일한 위치의 교환이 중복되어도 된다.
다음과 같은 경우 1회의 교환 횟수가 주어졌을 때 반드시 1회 교환을 수행하므로 결과값은 49가 된다.

94의 경우 2회 교환하게 되면 원래의 94가 된다.
정해진 횟수만큼 숫자판을 교환했을 때 받을 수 있는 가장 큰 금액을 계산해보자.

[입력]
가장 첫 줄은 전체 테스트 케이스의 수이다.
최대 10개의 테스트 케이스가 표준 입력을 통하여 주어진다.
각 테스트 케이스에는 숫자판의 정보와 교환 횟수가 주어진다.
숫자판의 정보는 정수형 숫자로 주어지고 최대 자릿수는 6자리이다.

[출력]
각 테스트 케이스마다, 첫 줄에는 “#C”를 출력해야 하는데 C는 케이스 번호이다.
같은 줄에 빈 칸을 하나 사이에 두고 교환 후 받을 수 있는 가장 큰 금액을 출력한다.
*/


/* 배운것 */
/*
1. dfs 문제에서 오래걸릴것 같다 싶으면 바로 백트래킹 생각.
2. 백트래킹에서 중요한것: 한번 계산한 연산, 부분은 다시 계산하지 않는다.
3. 절대 반복계산 하지 않는다.
*/




#include <iostream>

using namespace std;

int number;
int count;
int ans;
char array[6];
int maxValue;

void swap(int i, int j) {
	char temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

void dfs(int cnt, int s, int p) {
    if(cnt == 0) {
        int num = 0;
        for(int i = 0; i < p; ++i) {
        	num *= 10;
            num += array[i] - '0';
        }
        
        if(num > maxValue) {
        	maxValue = num;
            ans = maxValue;
        }
        return;
    }
    
    for(int i = s; i < p-1; ++i) {
        int big = array[i] - '0';
    	int high = i;
    	for(int j = i+1; j < p; ++j) {
        	if(big < array[j] - '0') {
            	big = array[j] - '0';
                high = j;
                break;
            }
        }
        if(i != high) {
        	s = i;
            break;
        }
    }
    
	for(int i = s+1; i < p; ++i) {
        swap(i, s);

        dfs(cnt - 1, s, p);

        swap(i, s);
    }
    
}

int main(void) {
	int t, tc = 0;
    
    scanf("%d", &t);
    
    while(++tc <= t) {
        ans = 0;
        count = 0;
        number = 0;
        maxValue = 0;
        
    	scanf("%d", &number);
        scanf("%d", &count);
        
        for(int i = 0; i < 6; ++i) array[i] = '0';
        
        int div = 100000;
        int p = 0;
        bool sw = false;
        while(div >= 1) {
        	if(number / div > 0 || sw) {
            	int num = number / div;
                array[p] = num + '0';
                ++p;
                number %= div;
                sw = true;
            }
            div /= 10;
        }
	    
        dfs(count, 0, p);
        printf("#%d %d\n", tc, ans);
    }
    
}