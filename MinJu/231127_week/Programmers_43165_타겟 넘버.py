def dfs(numbers, target, current_sum, idx):
    if idx == len(numbers):
        return 1 if current_sum == target else 0

    plus = dfs(numbers, target, current_sum + numbers[idx], idx + 1)
    minus = dfs(numbers, target, current_sum - numbers[idx], idx + 1)

    return plus + minus

def solution(numbers, target):
    return dfs(numbers, target, 0, 0)
