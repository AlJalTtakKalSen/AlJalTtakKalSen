# 포도주 시식
# 1. 선택 시 해당 잔 모두 마신 후 원래 위치에 갖다놓기
# 2. 연속으로 놓여있는 세 잔 모두 마실 수 X

# 최대로 마실 수 있는 포도주의 양 구하기

n = int(input())  # 포도주 잔의 개수
arr = [int(input()) for _ in range(n)]  # 포도주 양

dp = [0] * n  # dp[i] : i번째 포도주까지 마셨을 때 최대로 마실 수 있는 포도주의 양
dp[0] = arr[0]

if n > 1:
    dp[1] = arr[0] + arr[1]  # 1번째까지 계산
if n > 2:
    dp[2] = max(arr[0] + arr[2], arr[1] + arr[2], dp[1])  # 2번째까지 계산

for i in range(3, n):
    dp[i] = max(dp[i - 1], dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]) # 점화식
    # 현재 포도주 X, 현재+이전 O 전전 X, 현재+전전O 이전 X
answer = max(dp)
print(answer)
