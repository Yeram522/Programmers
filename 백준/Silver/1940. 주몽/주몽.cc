#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M; //재료의 개수, 갑옷이 완성되는 번호의 합
	cin >> N;
	cin >> M; 

	vector <int> A(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int count = 0;
	int start_index = 0;
	int end_index = N-1;

	sort(A.begin(), A.end()); // 오름차순으로 정렬

	while (start_index < end_index) 
	{
		if (A[start_index] + A[end_index] < M)
		{
			start_index++;
		}
		else if (A[start_index] + A[end_index] > M)
		{
			end_index--;
		}
		else if (A[start_index] + A[end_index] == M)
		{
			count ++;
			start_index ++;
			end_index --;
		}
	}

	cout << count << "\n";

	return 0;
}