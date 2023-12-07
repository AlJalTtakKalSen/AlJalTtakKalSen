n, k = map(int, input().split())
coins = [int(input()) for _ in range(n)]

dp = [0 for _ in range(k+1)] # 0원부터 k원까지 만들 수 있는 경우의 수
dp[0] = 1 # 0원을 만드려면 아무 것도 선택 안하는 경우

for coin in coins:
    for i in range(1, k+1):
        if i - coin >= 0:
            dp[i] += dp[i-coin] # dp[i] = dp[i] + dp[i-coin]
            # i-coin을 만드는 조합에 coin을 더하면 i

print(dp[k])