#include <iostream>
#include <algorithm>
#include <iterator>
#include <set>
#include <queue>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
#include <stdlib.h>
#include <deque>
#include <queue>
#include <math.h>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

long long dfs(unordered_map<int, vector<int> > &dict, unordered_map<int, long long> &memo, int current){
	if (memo.count(current)){
		return memo[current];
	}
    if (dict[current][0] == -1) {
        return 1;
    }
    if (dict[current][0] == -2) {
        return 0;
    }
	long long total = 0;
	for (int w=0; w<dict[current].size(); w++){
        total += dfs(dict, memo, dict[current][w]);
	}
	memo[current] = total;
	return total;
}

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    freopen("input.in", "r", stdin);
    int n; cin >> n;
    int sect, sectNum, link1, link2, link3;
    string curr;
    while(n--){
        unordered_map<int, vector<int> > dict;
        unordered_map<int, long long> memo;
        cin >> sect;
        while(sect--){
            cin >> sectNum >> curr;
            if (curr.length() < 9){
                
                dict[sectNum].push_back(stoi(curr));
                cin >> link2 >> link3;
                dict[sectNum].push_back(link2);
                dict[sectNum].push_back(link3);
            }
            else{
                if (curr == "favourably"){
                    dict[sectNum].push_back(-1);
                }
                else{
                    dict[sectNum].push_back(-2);
                }
            }
        }
        long long totalCount = dfs(dict, memo, 1);
        cout << totalCount << "\n";
    }
}