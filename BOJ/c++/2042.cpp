#include <iostream>
#include <stdio.h>

using namespace std;

long long tree[3000000];
long long arr[1000001];
int n, m, k;
int a, b, c;


long long initTree(int node, int start, int end) {
    // start 부터 end까지 진행
    // 만약 start == end(leaf 노드)이면 해당 node번호에 값을 집어넣는다.
    if(start == end) return tree[node] = arr[start];
    long long mid = (start+end)/2;
    
    tree[node] = initTree(node*2, start, mid) + initTree(node*2+1, mid+1, end);
    return tree[node];
}


void changeNumber(int node, int start, int end, int b, int diff) {
    // root노드에서 부터 내려오면서 갱신한다.
    // node는 tree에서 수정할 인덱스를 가리킨다. start와 end는 arr의 인덱스를 가리킨다.
    // 만약 b가 start와 end사이에 있다면(해당 노드가 b라는 index를 포함한다면) 해당 노드에 diff를 적용
    
    // b가 start와 end 사이에 있지 않다면 아무것도 안한다.
    if(start <= b && b <= end) {
        tree[node] += diff;
    } else return;
    
    
    if(start != end) {
        int mid = (start+end) / 2;
        changeNumber(node*2, start, mid, b, diff);
        changeNumber(node*2+1, mid+1, end, b, diff);
    }
}


long long sumNumber(int node, int left, int right, int start, int end) {
    // root 노드에서 시작해서 내려간다
    // left, right는 arr에서 더하는 index범위. start, end는 arr의 탐색 범위
    // 1. start와 end가 left, right가 사이에 있다 => 다 더한다.
    // 2.                          완전 벗어나 있다. => 0 return
    // 3.                          부분 겹친다. => 윈쪽, 오른쪽 나눠서 진행

    // 2번 경우
    if(right < start || left > end) {
        return 0;
    }
    
    // 1번 경우
    if(left <= start && end <= right) {
        return tree[node];
    }
    
    // 3번 경우
    int mid = (start+end) / 2;
    long long leftSum = sumNumber(node*2, left, right, start, mid);
    long long rightSum = sumNumber(node*2+1, left, right, mid+1, end);

    return leftSum + rightSum;
}


int main(void) {
    scanf("%d %d %d", &n, &m, &k);

    for(int i = 1; i <= n; ++i) scanf("%lld", &arr[i]);
    initTree(1, 1, n);

    for(int i = 0; i < m+k; ++i) {
        scanf("%d %d %d", &a, &b, &c);
        // b번째 수를 c로 바꾼다
        if(a == 1) {
            arr[b] = c;
            changeNumber(1, 1, n, b, c-arr[b]);
        }
        // b부터 c까지 합을 구한다.
        else {
            long long result = sumNumber(1, b, c, 1, n);
            printf("%lld\n", result);
        }
    }

    return 0;
}
