#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; //주어지는 수의 개수
	cin >> N;

	vector <int> A(N, 0);
	for (int i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	int count = 0;
	

	sort(A.begin(), A.end()); // 오름차순으로 정렬

	for (int k = 0; k < N; k++)
	{
		long find = A[k];
		int i = 0;
		int j = N - 1;
		while (i < j)
		{
			if (A[i] + A[j] < find)
			{
				i++;
			}
			else if (A[i] + A[j] > find)
			{
				j--;
			}
			else if (A[i] + A[j] == find)
			{
				if (i != k && j != k)
				{
					count++;
					break;
				}
				else if (i == k)
				{
					i++;
				}
				else if (j == k)
				{
					j--;
				}
				
			}
		}
	}
	

	cout << count << "\n";

	return 0;
}