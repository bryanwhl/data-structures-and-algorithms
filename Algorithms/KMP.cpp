#include <bits/stdc++.h> 

using namespace std;

//populates lps vector with the appropriate indexes
void computeLPSArray(string pat, int M, vector<int> &lps) { 
    lps[0] = 0;
  
    int j = 0;
    
    for (int i=1; i<M; i++) { 
        if (pat[i] == pat[j]) { 
            j++;
            lps[i] = j; 
        } 
        else
        { 
            if (j != 0) {
            	while (j != 0){
            		j = lps[j - 1];
            		if (pat[i] == pat[j]){
            			j++;
            			lps[i] = j;
            			break;
					}
				}
				if (j == 0){
					lps[i] = 0;
				}
            } 
            else
            { 
                lps[i] = 0; 
            } 
        } 
    }
}

// Prints occurrences of txt[] in pat[] 
void KMP(string pat, string txt) 
{ 
    int M = pat.length(); 
    int N = txt.length(); 
  
    vector<int> lps(M); 
  
    computeLPSArray(pat, M, lps); 
  
    int i = 0;
    int j = 0;
    while (i < N) { 
        if (pat[j] == txt[i]) { 
            j++; 
            i++; 
        } 
  
        if (j == M) { 
            cout << i-j << " ";
            j = lps[j-1]; 
        } 
  
        else if (i < N && pat[j] != txt[i]) { 
            if (j != 0) 
                j = lps[j-1]; 
            else
                i = i + 1; 
        } 
    } 
} 

int main(){
    ios::sync_with_stdio(false); cin.tie(NULL);
    //auto start = high_resolution_clock::now(); 
    //freopen("input.in", "r", stdin);
    string pat, txt;
    while (getline(cin, pat)){
        getline(cin, txt);
        KMP(pat, txt); 
        cout << "\n";
    }
    return 0; 
}
