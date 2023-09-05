#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N, M;//배열크기, 나눌 수
	cin >> N >> M;

	//벡터 초기화
	vector<long> S(N + 1, 0);
	vector<long> C(M, 0);

	long answer = 0;
    cin >> S[0];
	//1. 기본배열
	for (int i = 1; i <= N; i++)
	{
		int temp = 0;
		cin >> temp;

		//2. 구간 합 구하기
		S[i] = S[i - 1] + temp;
	}

	for (int i = 0; i < N; i++)
	{
		int remainder = S[i] % M;

		if (remainder == 0)
		{
			answer++;
		}

		C[remainder]++;
	}

	for (int i = 0; i < M; i++)
	{
		if (C[i] > 0)
		{
			answer = answer + (C[i] * (C[i] - 1) / 2);
		}
	}

	cout << answer << "\n";
	return 0;
}