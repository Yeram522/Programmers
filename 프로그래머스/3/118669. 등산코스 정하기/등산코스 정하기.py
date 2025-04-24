from heapq import heappop, heappush 
def solution(n, paths, gates, summits):
    INF = 10**9
    
    # 그래프 구성
    graph = [[] for _ in range(n+1)]
    for a, b, cost in paths:
        graph[a].append([b, cost])
        graph[b].append([a, cost])
    
    # O(1) 접근을 위한 set 변환
    gates_set = set(gates)
    summits_set = set(summits)
    
    # intensity를 기록할 배열
    intensity = [INF] * (n+1)
    
    # 출발점 설정 - 모든 게이트에서 동시에 시작
    pq = []
    for gate in gates:
        intensity[gate] = 0
        heappush(pq, (0, gate))  # (intensity, 노드)
    
    while pq:
        current_intensity, node = heappop(pq)
        
        # 현재 intensity가 기록된 값보다 크면 무시
        if current_intensity > intensity[node]:
            continue
            
        # 산봉우리에 도착했으면 더 이상 탐색하지 않음
        if node in summits_set:
            continue
        
        for next_node, path_intensity in graph[node]:
            # 출발지는 방문하지 않음 (시작점 제외)
            if next_node in gates_set:
                continue
                
            # 경로의 최대 intensity 계산
            new_intensity = max(current_intensity, path_intensity)
            
            # 더 작은 intensity를 찾은 경우에만 업데이트
            if new_intensity < intensity[next_node]:
                intensity[next_node] = new_intensity
                heappush(pq, (new_intensity, next_node))
    
    # 답 구하기
    answer = [INF, INF]
    for summit in sorted(summits):  # 산봉우리 번호 오름차순 정렬
        if intensity[summit] < answer[1]:
            answer = [summit, intensity[summit]]
    
    return answer