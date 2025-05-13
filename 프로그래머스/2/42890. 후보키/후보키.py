from collections import deque
def solution(relation):
    answer = 0
    candidates = set()
    def check_candidate(keys):
        nonlocal answer
        
        tuples = set()
        for i in range(len(relation)):
            temp = tuple(relation[i][key] for key in keys) 
            if temp in tuples:
                return False
            tuples.add(temp)
            
        candidates.add(tuple(keys))
        
        return True
    
            
    q = deque([(0,[])])
    
    while(q):
        count, combi = q.popleft() # q를 이용한 BFS 구현
        
        for i in range(count, len(relation[0])):
            combi.append(i)
            if not any(set(item).issubset(combi) for item in candidates): # 최소성 검사
                if not check_candidate(combi): # 유일성 검사
                    q.append((i+1, combi.copy())) 
                else:
                    answer += 1
            
            combi.pop()
        
    
    return answer