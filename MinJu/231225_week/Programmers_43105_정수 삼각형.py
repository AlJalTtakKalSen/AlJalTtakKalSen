# 정수 삼각형

# 거쳐간 숫자의 최댓값

# [i][j]로 이동 -> [i-1][j-1] 또는 [i-1][j]에서 이동

def solution(triangle):
    dp = [[0] * len(triangle) for _ in range(len(triangle))]
    dp[0][0] = triangle[0][0]

    for i in range(0, len(triangle) - 1):
        for j in range(len(triangle[i])):
            dp[i+1][j] = max(dp[i+1][j], dp[i][j] + triangle[i+1][j])
            dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + triangle[i+1][j+1])
    return max(dp[-1]) # 마지막 줄 원소 중 최댓값