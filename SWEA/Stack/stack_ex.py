"""
올바른 괄호 검사
"""

inp = input()

stack = [0] * 100
bracket = [0] * 256

bracket[ord('(')] = 1
bracket[ord(')')] = 2
bracket[ord('{')] = 3
bracket[ord('}')] = 4
bracket[ord('[')] = 5
bracket[ord(']')] = 6


top = -1

isBracket = True

top += 1
stack[top] = inp[0]

for i in range(1, len(inp)) :
    if inp[i] == ')' or inp[i] == '}' or inp[i] == ']' :
        if bracket[ord(stack[top])] == bracket[ord(inp[i])] - 1 :
            stack[top] = 0
            top -= 1
        else :
            isBracket = False
            break

    else :
        top += 1; stack[top] = inp[i]
    

print(isBracket)