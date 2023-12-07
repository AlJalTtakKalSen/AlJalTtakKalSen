n, k = map(int, input().split())
coins = list(int(input()) for _ in range(n))

dp = [10001] * (k+1) # 10000보다 큰 수로 초기화
dp[0] = 0 

for coin in coins:
    for i in range(coin, k+1):
        # 현재 값에서 코인 값을 배줬을 때 사용 개수에 코인 개수 하나를 더한 값과 이전 조합을 비교
        dp[i] = min(dp[i], dp[i-coin]+1) # dp[i-coin] + 1이 최소가 아닐 수 있음 
if dp[k] == 10001:
    print(-1)
else:
    print(dp[k])