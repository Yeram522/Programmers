from collections import deque
def solution(queue1, queue2):
    answer = 0
    q1 = deque(queue1)
    q2 = deque(queue2)
    q1_sum = sum(queue1)
    q2_sum = sum(queue2)
    n = len(queue1) 
    
    while n*4 > answer:
        if q1_sum == q2_sum:
            return answer
            
        if q1_sum > q2_sum:
            num = q1.popleft()
            q2.append(num)
            q1_sum -= num
            q2_sum += num
        elif q1_sum < q2_sum:
            num = q2.popleft()
            q1.append(num)
            q2_sum -= num
            q1_sum += num
            
        answer += 1
        
    return -1