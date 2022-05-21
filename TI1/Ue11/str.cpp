#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string a,b;
    int lenA,lenB;
    Solution(){
        a = "abec";
        b = "dbc";
        lenA = a.size();
        lenB = b.size();
    }

    string LCS(int m, int n){ 
        if(-1 == m || -1 == n) return ""; 
        if(a[m] == b[n]){
            return LCS(m - 1, n - 1) + a[m];
        } 
        else{
            string x = LCS(m - 1, n), y = LCS(m, n - 1);
            return x.length() > y.length()? x : y; 
        } 
    }

    string SCS1_1(){
        string ans,lcs = LCS(lenA-1,lenB-1); 
        int i = 0, j = 0;
        for(char ch:lcs){
            while(i < lenA && a[i] != ch)
                ans += a[i++];
            while(j < lenB && b[j] != ch)
                ans += b[j++];
            ans+=ch,++i,++j;
        }
        return ans;

    }

    string SCS1_2(){
        string ans,lcs = LCS(lenA-1,lenB-1); 
        int i = 0, j = 0;
        for(char ch:lcs){
            while(j < lenB && b[j] != ch)
                ans += b[j++];
            while(i < lenA && a[i] != ch)
                ans += a[i++];
            ans+=ch,++i,++j;
        }
        return ans;

    }
    
    string SCS2(string str1, string str2) {
        
        vector<vector<int> > dp(lenA + 1, vector<int>(lenB + 1, 0));
        vector<vector<int> > path(lenA + 1, vector<int>(lenB + 1, 0));
        for (int i = 1; i <= lenA; ++i) path[i][0] = 1;
        for (int j = 1; j <= lenB; ++j) path[0][j] = 2;
        for (int i = 1; i <= lenA; ++i) {
            for (int j = 1; j <= lenB; ++j) {
                dp[i][j] = dp[i - 1][j];
                path[i][j] = 1;
                if (dp[i][j - 1] > dp[i][j]) {
                    dp[i][j] = dp[i][j - 1];
                    path[i][j] = 2;
                }
                if (str1[i - 1] == str2[j - 1] && dp[i - 1][j - 1] + 1 > dp[i][j]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                    path[i][j] = 3;
                }
            }
        }

        for(int x = 0 ; x < lenA; x++){
            for(int y = 0; y < lenB; y++){
                cout<<path[x][y]<<" ";
            }
            cout<<endl;
        }
        cout<<"=="<<endl;

        string res;
        int i = lenA;
        int j = lenB;
        while (path[i][j] != 0) {
            if (path[i][j] == 1) {
                res += str1[--i];
            } else if (path[i][j] == 2) {
                res += str2[--j];
            } else {
                res += str1[--i];
                --j;
            }
        }

        

        reverse(res.begin(), res.end());
        return res;
    }
};

int main(){
    Solution s;
    string c1,c2;
    c1 = s.SCS2(s.a,s.b);
    c2 = s.SCS2(s.b,s.a);

    cout<<"SCS1_1 = "<<s.SCS1_1()<<endl;
    cout<<"SCS1_2 = "<<s.SCS1_2()<<endl;
    cout<<"SCS2_1 = "<<c1<<endl;
    cout<<"SCS2_2 = "<<c2<<endl;
    
    return 0;
}
