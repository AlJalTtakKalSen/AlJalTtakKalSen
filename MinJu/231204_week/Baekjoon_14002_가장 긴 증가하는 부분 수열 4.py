n = int(input())
data = list(map(int, input().split()))
dp = [1] * (n+1) # 가장 긴 수열 길이 

for i in range(len(data)):
    for j in range(i): # 해당 배열 원소 직전까지 
        if data[j] < data[i]: # 이전 원소보다 크면 
            dp[i] = max(dp[i], dp[j]+1) # 이전 원소에 저장된 가장 긴 수열 길이 +1 과 수열 길이를 비교

print(max(dp)) # 최장 길이 
x = max(dp)

result = []
for i in range(n-1, -1, -1):
    if dp[i] == x: # dp[i]가 가장 긴 길이와 같으면
        result.append(data[i]) # 추가 
        x -= 1 # 1씩 감소
result.reverse() # 큰수부터 뽑았으므로 
print(*result)