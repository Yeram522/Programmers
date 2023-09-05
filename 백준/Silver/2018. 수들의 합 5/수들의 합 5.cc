#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;

	int count = 1;
	int start_point = 1;
	int end_point = 1;
	int sum = 1;

	while (end_point != N)
	{
		if (sum < N)
		{
			end_point++;
			sum += end_point;
		}
		else if (sum > N)
		{
			sum -= start_point;

			start_point++;
		}
		else if (sum == N)
		{
			count++;
			end_point++;
			sum += end_point;
		}
	}

	cout << count << "\n";
	
	return 0;
}