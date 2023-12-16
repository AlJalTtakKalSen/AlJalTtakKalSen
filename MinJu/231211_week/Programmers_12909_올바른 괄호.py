def solution(s):
    answer = True
    arr = []   
  
    for i in s:
        if i == '(':  
            arr.append(i) 
        else: 
            if arr == []: 
                answer = False
                break
            else:
                arr.pop() 

    if arr != []: 
        answer = False

    return answer