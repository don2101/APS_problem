/*
선표는 게임을 통해 사칙 연산을 공부하고 있다.
N개의 숫자가 적혀 있는 게임 판이 있고, +, -, x, / 의 연산자 카드를 숫자 사이에 끼워 넣어 다양한 결과 값을 구해보기로 했다.
수식을 계산할 때 연산자의 우선 순위는 고려하지 않고 왼쪽에서 오른쪽으로 차례대로 계산한다.
예를 들어 1, 2, 3 이 적힌 게임 판에 +와 x를 넣어 1 + 2 * 3을 만들면 1 + 2를 먼저 계산하고 그 뒤에 * 를 계산한다.
즉 1+2*3의 결과는 9이다.

주어진 연산자 카드를 사용하여 수식을 계산했을 때 그 결과가 최대가 되는 수식과 최소가 되는 수식을 찾고, 두 값의 차이를 출력하시오.
 
[제약사항]
1. 시간 제한 : 최대 50 개 테스트 케이스를 모두 통과하는 데 C / C++ / Java 모두 3 초
2. 게임 판에 적힌 숫자의 개수 N 은 3 이상 12 이하의 정수이다. ( 3 ≤ N ≤ 12 )
3. 연산자 카드 개수의 총 합은 항상 N - 1 이다.
4. 게임 판에 적힌 숫자는 1 이상 9 이하의 정수이다.
5. 수식을 완성할 때 각 연산자 카드를 모두 사용해야 한다..
6. 숫자와 숫자 사이에는 연산자가 1 개만 들어가야 한다.
7. 완성된 수식을 계산할 때 연산자의 우선 순위는 고려하지 않고, 왼쪽에서 오른쪽으로 차례대로 계산한다.
8. 나눗셈을 계산 할 때 소수점 이하는 버린다.
9. 입력으로 주어지는 숫자의 순서는 변경할 수 없다.
10. 연산 중의 값은 -100,000,000 이상 100,000,000 이하임이 보장된다.

[입력]
입력의 맨 첫 줄에는 총 테스트 케이스의 개수 T 가 주어지고,
그 다음 줄부터 T 개의 테스트 케이스가 주어진다.
각 테스트 케이스의 첫 번째 줄에는 숫자의 개수 N 이 주어진다.
다음 줄에는 '+', '-', '*', '/' 순서대로 연산자 카드의 개수가 공백을 사이에 두고 주어진다.
다음 줄에는 수식에 들어가는 N 개의 숫자가 순서대로 공백을 사이에 두고 주어진다.

[출력]
테스트 케이스 개수만큼 T 개의 줄에 각각의 테스트 케이스에 대한 답을 출력한다.
각 줄은 "#t" 로 시작하고 공백을 하나 둔 다음 정답을 출력한다. ( t 는 1 부터 시작하는 테스트 케이스의 번호이다. )
정답은 연산자 카드를 사용하여 만들 수 있는 수식으로 얻은 결과값 중 최댓값과 최솟값의 차이이다.
*/

/*
사용 로직
1. operator별로 갯수를 분류
2. dfs
*/

#include<iostream>
#define MAX_NUMBER 100000000

using namespace std;

int ans;
int n;
int oper[128];
int numbers[12];
int maxNumber;
int minNumber;

void dfs(int number, int seq) {
	if(seq >= n) {
    	if(maxNumber < number) maxNumber = number;
        if(minNumber > number) minNumber = number;
        
        return;
    }
    
	int newNumber = numbers[seq];
    
    if(oper['+'] > 0) {
    	oper['+']--;
    	dfs(number+newNumber, seq+1);
        oper['+']++;
    }
    if(oper['-'] > 0) {
    	oper['-']--;
    	dfs(number-newNumber, seq+1);
        oper['-']++;
    }
    if(oper['*'] > 0) {
    	oper['*']--;
    	dfs(number*newNumber, seq+1);
        oper['*']++;
    }
    if(oper['/'] > 0) {
    	oper['/']--;
    	dfs(number/newNumber, seq+1);
        oper['/']++;
    }
    
}

int main(void) {
	int t, tc = 0;
    scanf("%d", &t);
    
    while(++tc <= t) {
    	minNumber = MAX_NUMBER;
        maxNumber = -MAX_NUMBER;
    	scanf("%d", &n);
    	scanf("%d %d %d %d", &oper['+'], &oper['-'], &oper['*'], &oper['/']);
    	
        for(int i = 0; i < n; ++i) {
        	scanf("%d", &numbers[i]);
        }
        
        dfs(numbers[0], 1);
        
        ans = maxNumber-minNumber;
        printf("#%d %d\n", tc, ans);
    }
    

}