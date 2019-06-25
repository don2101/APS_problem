#include <iostream>
#include <vector>

using namespace std;


int m, n;
int a, b;
vector<int> node[32001];
int inDegree[32001];
int queue[32001];
bool visited[32001];


int main(void) {
    scanf("%d %d", &n, &m);

    for(int i = 0; i <=n; ++i) {
        visited[i] = false;
        inDegree[i] = 0;
    }

    for(int i = 0; i < m; ++i) {
        scanf("%d %d", &a, &b);
        node[a].push_back(b);
        inDegree[b]++;
    }

    int qr = 0;
    int qf = 0;

    for(int i = 1; i <= n; ++i) {
        if(inDegree[i] == 0) {
            queue[qr++] = i;
            visited[i] = true;
        }
    }

    while(qr != qf) {
        int present = queue[qf++];
        // 현재 node 출력
        printf("%d ", present);
        
        // 현재 node와 연결된 node를 queue에 넣고, 간선을 지운다
        int size = node[present].size();

        for(int i = 0; i < size; ++i) {
            if(!visited[node[present][i]]) {
                queue[qr++] = node[present][i];
                visited[node[present][i]] = true;
            }
        }
    }

}