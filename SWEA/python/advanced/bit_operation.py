

def bit_operation(num):
    output = ""
    for i in range(7, -1, -1):
        output += '1' if (num & 1<<i) else '0'
    
    return output

print(bit_operation(-16))