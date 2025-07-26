import math

def is_square(x):
    if x < 0:
        return False
    s = math.isqrt(x)
    return s * s == x

def solve():
    import sys
    input = sys.stdin.read
    data = input().split()
    t = int(data[0])
    cases = list(map(int, data[1:t+1]))
    
    for n in cases:
        if n == 1:
            print(-1)
            continue
        
        total = n * (n + 1) // 2
        if is_square(total):
            print(-1)
            continue
        
        if n == 2:
            print("2 1")
            continue
        
        perm = [3, 2, 1]
        remaining = list(range(n, 3, -1))
        current_sum = 6
        i = 0
        
        while i < len(remaining):
            if i == len(remaining) - 1:
                perm.append(remaining[i])
                current_sum += remaining[i]
                i += 1
            else:
                x = remaining[i]
                next_sum = current_sum + x
                if is_square(next_sum):
                    remaining[i], remaining[i+1] = remaining[i+1], remaining[i]
                    x = remaining[i]
                    next_sum = current_sum + x
                
                perm.append(x)
                current_sum += x
                i += 1
        
        print(' '.join(map(str, perm)))

if __name__ == "__main__":
    solve()