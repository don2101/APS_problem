tree_node = [[-1, -1, -1] for _ in range(10001)]
tree_data = [[] for _ in range(100001)]



def make_tree_right(current):
    print(tree_node[current], current)
    
    if not tree_node[current]:
        return
    
    # 노드 의 현재 위치 바로 다음 y에 해당하는 값을 찾는다
    height = tree_node[current][1] - 1

    while not tree_data[height]:
        height -= 1

    # 그 값 중에서 현재 보다 x가 낮은 값을 왼쪽 자식으로
    # 현재보다 x가 크고 부모 보다 낮은 x 값을 오른쪽 자식으로
    left = None
    right = None

    #left limit right limit 추가
    
    for node in tree_data[height]:
        if node[0] > tree_node[current][0]:
            right = node
        
        if node[0] < tree_node[current][0] and node[0] > tree_node[(current//2)//2][0]:
            left = node
    
    tree_node[current*2] = left
    tree_node[current*2 + 1] = right

    make_tree_left(current*2)
    make_tree_right(current*2 + 1)


def make_tree_left(current):
    if not tree_node[current]:
        return
    # 노드 의 현재 위치 바로 다음 y에 해당하는 값을 찾는다

    print(tree_node[current], current)


    height = tree_node[current][1] - 1
    while not tree_data[height]:
        height -= 1
    print(height)

    # 그 값 중에서 현재 보다 x가 낮은 값을 왼쪽 자식으로
    # 현재보다 x가 크고 부모 보다 낮은 x 값을 오른쪽 자식으로
    left = None
    right = None
    
    for node in tree_data[height]:
        if node[0] < tree_node[current][0]:
            left = node
        
        if node[0] > tree_node[current][0] and node[0] < tree_node[current//2][0]:
            right = node

    tree_node[current*2] = left
    tree_node[current*2 + 1] = right

    make_tree_left(current*2)
    make_tree_right(current*2 + 1)


def preorder(answer, current):
    if not tree_node[current]: return
    
    answer[0].append(tree_node[current][2])
    preorder(answer, current*2)
    preorder(answer, current*2 + 1)
    

def postorder(answer, current):
    if not tree_node[current] or tree_node[current][0] == -1: return
    
    postorder(answer, current*2)
    postorder(answer, current*2 + 1)
    answer[1].append(tree_node[current][2])


def solution(nodeinfo):
    answer = [[], []]
    
    max_height = 0
    root_node = []

    length = len(nodeinfo)

    for i in range(length):
        # nodeinfo 순회 하면서 y에 해당하는 곳에 x, y, node_num 저장
        nodeinfo[i].append(i+1)
        tree_data[nodeinfo[i][1]].append(nodeinfo[i])
        
        if max_height < nodeinfo[i][1]:
            max_height = nodeinfo[i][1]
            root_node = nodeinfo[i]
    

    tree_node[1] = root_node
    left = None
    right = None

    max_height = tree_node[1][1] - 1

    while not tree_data[max_height]:
        max_height -= 1

    for node in tree_data[max_height]:
        if node[0] < tree_node[1][0]:
            left = node
        
        if node[0] > tree_node[1][0]:
            right = node
    
    tree_node[2] = left
    tree_node[3] = right

    make_tree_left(2)
    make_tree_right(3)

    preorder(answer, 1)
    postorder(answer, 1)

    print(answer)

    return answer


solution([[5,3],[11,5],[13,3],[3,5],[6,1],[1,3],[8,6],[7,2],[2,2]])