#include <iostream>
#define MAX 1000000000
#define MIN -1000000000

using namespace std;

int numbers[11];
int oper[128];
long long maxValue;
long long minValue;
int n;


void dfs(long long num, int seq) {
    if(seq == n) {
        if(num > maxValue) maxValue = num;
        if(num < minValue) minValue = num;
        return;
    }

    if(oper['+'] > 0) {
        oper['+']--;
        dfs(num+numbers[seq], seq+1);
        oper['+']++;
    }
    else if(oper['-'] > 0) {
        oper['-']--;
        dfs(num-numbers[seq], seq+1);
        oper['-']++;
    }
    else if(oper['*'] > 0) {
        oper['*']--;
        dfs(num*numbers[seq], seq+1);
        oper['*']++;
    }
    else if(oper['/'] > 0) {
        oper['/']--;
        if(num < 0) {
            dfs(-((-num)/numbers[seq]), seq+1);
        } else {
            dfs(num/numbers[seq], seq+1);
        }
        oper['/']++;
    }
}

int main(void) {
    cin >> n;
    maxValue = MIN;
    minValue = MAX;
    for(int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    cin >> oper['+'] >> oper['-'] >> oper['*'] >> oper['/'];

    dfs(numbers[0], 1);

    cout << maxValue << minValue << endl;
}