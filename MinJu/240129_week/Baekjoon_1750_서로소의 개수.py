# 서로소의 개수

n = int(input())
s = [int(input()) for _ in range(n)]
result = 0

def gcd(a, b):
    while b != 0:
        a, b = b, a%b
    return a

dp = [0] * (max(s)+1)

for i in range(n):
    for j in range(1, (max(s)+1)):
        if dp[j]:
            dp[gcd(j, s[i])] += dp[j]
    dp[s[i]] += 1

print(dp[1]%10000003)

