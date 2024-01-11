# 전깃줄
# 서로 교차하지 않으려면 첫번째 전깃줄 B보다 두번째 전기줄 B가 커야함

n = int(input()) # 전깃줄 수
arr = [list(map(int, input().split())) for _ in range(n)]
arr.sort(key=lambda x:x[0]) # A전봇대 기준으로 정렬 -> A 때문에 교차할 일은 없음
dp = [1] * n

# 교차되지 않는 전깃줄이 최대로 이어지는 값 찾기
for i in range(1, n):
    for j in range(i):
        if arr[i][1] > arr[j][1]:
            dp[i] = max(dp[i], dp[j]+1)
answer = n - max(dp) # 전체 전깃줄 수 - 최대로 이어지는 전깃줄 수
print(answer)
