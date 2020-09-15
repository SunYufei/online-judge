n = int(input())


def is_prime(t):
    for j in range(2, int(t**0.5) + 1):
        if t % j == 0:
            return False
    return True


i = 2
while i <= n:
    while is_prime(i) and n % i == 0:
        print(i)
        n //= i
    i += 1
