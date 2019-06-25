#include <iostream>
#include <stdio.h>

#define MAX(x, y) x > y ? x : y
#define MIN(x, y) x < y ? x : y

using namespace std;

int numbers[1000001];
int n, m;
int c, a, b;


int findSet(int a) {
    if(numbers[a] == a) return a;
    numbers[a] = findSet(numbers[a]);

    return numbers[a];
}

void unionSet(int a, int b) {
    numbers[findSet(b)] = findSet(a);
}


int main(void) {
    scanf("%d %d", &n, &m);

    for(int i = 0; i <= n; ++i) numbers[i] = i;

    for(int i = 0; i < m; ++i) {
        scanf("%d %d %d", &c, &a, &b);

        int small = MIN(a, b);
        int big = MAX(a, b);
        // Union
        if(c == 0) {    
            unionSet(small, big);
        }
        // Find
        else {
            if(findSet(small) == findSet(big)) printf("YES\n");
            else printf("NO\n");
        }

    }
}