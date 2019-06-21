#include <iostream>

using namespace std;

int tree[20000002];
int arr[1000001];
int n, m, k;
int a, b, c;


int initTree(int node, int start, int end) {
    if(start == end) return tree[node] = arr[start];
    int mid = (start+end)/2;

    return tree[node] = initTree(node*2, start, mid) + initTree(node*2+1, mid+1, end);
}


void changeNumber(int b, int c) {
    int number = tree[b];
    int diff = c - tree[b];

    for(int i = b; i >= 0; i/=2) {
        tree[i] = tree[i] + diff;
    }
}




int main(void) {
    cin >> n >> m >> k;

    for(int i = 1; i <= n; ++i) cin >> arr[i];
    initTree(1, 1, n);



    for(int i = 0; i < m+k; ++i) {
        cin >> a >> b >> c;

        // b번째 수를 c로 바꾼다
        if(a == 1) {
            //해당 번호를 바꿀 경우 나누기2 하면서 0까지 모두 바꾼다.
            changeNumber(b, c);
        }
        // b부터 c까지 합을 구한다.
        else {
            
        }

    }


    return 0;
}
