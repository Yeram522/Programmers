from collections import deque
def solution(places):
    answer = []
    
    def bfs(sr,sc, place):
        dist = [[-1 for _ in range(5)] for _ in range(5)] # 거리 기록 배열
        queue = deque([(sr,sc)])
        dist[sr][sc] = 0  # 시작 위치 distance 0
        
        while queue:
            r,c = queue.popleft()
            
            # 맨해튼 거리 조건 체크, 시작 지점 제외!
            if (r,c) != (sr, sc) and place[r][c] == 'P' and dist[r][c] <= 2: # 사람이 있는데, 시작 거리와 2보다 작다면
                return False
            
            # 다음 지점으로 이동 체크
            for dr,dc in [(1,0),(-1,0),(0,1),(0,-1)]:
                nr = r + dr
                nc = c + dc
                
                # index 범위 만족, 방문하지 않은 곳, 파티션으로 막히지 않은 곳
                if 0<= nr < 5 and 0<= nc < 5 and dist[nr][nc] == -1 and place[nr][nc] != "X":
                    queue.append((nr,nc))
                    dist[nr][nc] = dist[r][c] + 1 # 거리 갱신
                    
        return True
    
    
    for place in places:
        # 1. 응시자 리스트 추출
        candidates = []
        for r in range(5):
            for c in range(5):
                if place[r][c] == 'P':
                    candidates.append((r,c))
                    
        # 2. 응시자 기준으로 bfs. 거리두기 조건에 만족하지 않으면 answer에 0 저장. 만족한다면 1 저장
        for candidate in candidates:
            if not bfs(candidate[0], candidate[1],place): # 하나라도 만족하지 않는 경우가 나온다면
                answer.append(0)
                break
        else: # 응시자들이 거리두기 조건을 모두 만족한다면
            answer.append(1)
                
            
    
    return answer