tree_node = [[-1, -1, -1, -1, -1, -1, -1, -1, -1] for _ in range(10001)]

def swap(arr, i, j):
    temp = arr[j]
    arr[j] = arr[i]
    arr[i] = temp


def find_left_left(current, next_nodes):
    # 왼쪽의 왼쪽 자식
    length = len(next_nodes)
    
    for node in next_nodes:
        if current[0] > node[0]:
            current[]

def find_left_right(nodes):
    # 왼쪽의 오른쪽 자식

def find_right_left(nodes):
    # 오른쪽의 오른쪽 자식

def find_right_right(nodes):
    # 오른쪽의 오른쪽 자식

def find_max(nodes, index_num):
    max_y = nodes[index_num-1][1]
    
    max_nodes = []

    start_idx = index_num-1
    # 최대값 찾기
    while max_y == nodes[start_idx][1]:
        max_nodes.append(nodes[start_idx])

        start_idx += 1

    return max_nodes


def make_tree_left(nodes, current, index_num):
    # [x, y, num, px, py, pn, cx, cy, cn]
    # 모든 배열에서 자기보다 작고 y가 가장 큰 노드를 추출
    # l일 경우 자기보다 작은놈 골라서 왼쪽 자식으로
    # r일 경우 자기보다 큰놈 골라서 오른쪽 자식으로

    next_nodes = find_max(nodes, index_num)
    
    

def solution(nodeinfo):
    answer = [[]]
    nodes = [[-1, -1, -1] for _ in range(len(nodeinfo))]
    
    cnt = 0

    for node in nodeinfo:
        nodes[cnt][0] = node[0]
        nodes[cnt][1] = node[1]
        nodes[cnt][2] = cnt + 1
        
        current = cnt
        for i in range(cnt-1, -1, -1):
            if nodes[i][1] < nodes[current][1]:
               temp = nodes[current]
               nodes[current] = nodes[i]
               nodes[i] = temp

               current -= 1
                
            else: break
        
        cnt += 1

    print(nodes)
    
    
    return answer


solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]])