#include <bits/stdc++.h> 

using namespace std;

//https://open.kattis.com/problems/primesieve
//Not an optimized solution, but AC nonetheless.
//This problem gave me lots of trouble because I did my first sieve solution with vector<int> instead of vector<bool> and it gave me MLE.
//I miscalculated by not realizing that simply changing my vector type will allow my solution to be AC, so I went on to try segmented sieve just to TLE.

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    int n, query; cin >> n >> query;
    vector<bool> arr(n+1, true);
    int total = n-1;
    arr[1] = false; //edge case
    int curr;
    for (int q=2; q<=n; q++){
        if (arr[q]){
            for (int w=2; q*w<=n; w++){
                if (arr[q*w]){
                    arr[q*w] = false;
                    total--;
                }
            }
        }
    }
    int num;
    cout << total << "\n";
    for (int q=0; q<query; q++){
        cin >> num;
        cout << arr[num] << "\n"; //C++ auto converts bool to int when printing
    }
}
