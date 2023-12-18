import sys
input = sys.stdin.readline

l, c = map(int, input().split())
words = sorted(list(map(str, input().split())))
answer = []

def back_tracking(cnt, idx):
    if cnt == l:
        v_cnt, c_cnt = 0, 0

        for i in range(l):
            if answer[i] in ['a', 'e', 'i', 'o', 'u']:
                v_cnt += 1
            else:
                c_cnt += 1

        if v_cnt >= 1 and c_cnt >= 2:
            print("".join(answer))

        return

    for i in range(idx, c):
        answer.append(words[i])
        back_tracking(cnt + 1, i + 1)
        answer.pop()

back_tracking(0, 0)