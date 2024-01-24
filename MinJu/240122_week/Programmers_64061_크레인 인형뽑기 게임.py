# 크레인 인형뽑기 게임
def solution(board, moves):
    answer = 0
    stack = []
    for move in moves:  # 이동 동작 수행
        for i in range(len(board)):
            # 해당 칸이 빈 칸이 아니라면
            if board[i][move - 1] > 0:
                # 마지막 원소가 현재 원소랑 같으면 마지막 원소 제거한 후 개수 카운트
                if stack and stack[-1] == board[i][move - 1]:
                    stack.pop()
                    answer += 2  # 2개 폭파
                # 아니면 스택에 해당 원소 추가
                else:
                    stack.append(board[i][move - 1])
                board[i][move - 1] = 0  # 수행이 끝났다면 빈 칸으로

                break
    print(board)
    return answer