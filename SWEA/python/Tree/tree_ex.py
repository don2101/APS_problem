def preorder(tree, node) :
    if tree[node] > 0:
        print(tree[node], end=" ")
        preorder(tree, node*2)
        preorder(tree, node*2 + 1)

n = int(input())

tree = [0] * 64
numbers = [1, 2, 1, 3, 2, 4, 3, 5, 3, 6, 4, 7, 5, 8, 5, 9, 6, 10 ,6 ,11, 7, 12, 11, 13]
length = len(numbers)

for i in range(0, length, 2) :
    parent = numbers[i]
    child = numbers[i+1]

    if parent == 1 :
        tree[1] = 1
    
    pos = -1
    for j in range(64) :
        if tree[j] == parent :
            pos = j
            break
    
    if tree[pos*2] == 0 :
        tree[pos*2] = child
    else : tree[pos*2 + 1] = child
    
preorder(tree, 1)