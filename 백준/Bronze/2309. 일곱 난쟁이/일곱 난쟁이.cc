// Online C++ compiler to run C++ program online
#include<bits/stdc++.h>
using namespace std;

vector <int> input;
vector <int> result;
int cnt = 0;
void print(vector<int> list)
{
    for(auto element : list)
    {
        cout << element << endl;
    }
    
   // cout << "\n";
}
void combi(int start, vector<int> array, int sum)
{
    if(array.size() == 7)
    {
        //print(array);
        cnt++;
       // cout<<sum<<endl;
        if(sum == 100)
        {
            result = array;
        }
        
        return;
    }
    
    for(int i = start + 1; i < 9 ; i++)
    {
        array.push_back(input[i]);
        combi(i, array, sum + input[i]);
        array.pop_back();
    }
    
    return;
}

int main() {
    vector<int> combination;
    
    for (int i = 0; i < 9; i++) { //벡터에 입력값 추가
    	int a;
        cin>>a;
		input.push_back(a);
	}
    
    sort(input.begin(), input.end());
    combi(-1, combination, 0);
    //cout<< "total :" << cnt << endl;
    
    //result
    print(result);
    return 0;
}