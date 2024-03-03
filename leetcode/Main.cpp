// Authored by Jie Huang
// 1/15/24
// Used to test files

#include "FindPlayersWithZeroOrOneLosses.cpp"

int main(int argc, char* argv[]){
    FindPlayersWithZeroOrOneLosses test;
    vector<vector<int>> v{{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    vector<vector<int>> ret = test.findWinners(v);
    for(vector<int> iter : v){
        for(int it : iter){
            cout << it << " ";
        }
        cout << endl;
    }
    cout << endl;

    return 0;
}