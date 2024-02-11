# 무한 수열

n, p, q = map(int, input().split())
dict = {}
dict[0] = 1

def dfs(x):

    # 값이 저장되어 있으면 그대로 반환
    if x in dict:
        return dict[x]
    # 그렇지 않다면, 계산
    else:
        dict[x] = dfs(x//p) + dfs(x//q)
        return dict[x]
print(dfs(n))