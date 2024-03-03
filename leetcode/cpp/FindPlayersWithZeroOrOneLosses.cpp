// Authored by Jie Huang
// 1/15/24
// 2225. Find Players With Zero or One Losses

#include "cpp_header.h"

class FindPlayersWithZeroOrOneLosses {
  public:
    vector<vector<int>> findWinners(vector<vector<int>> &matches) {
        int losses[100001]{};

        for (int i = 0; i < matches.size(); i++) {
            int win = matches[i][0];
            int lose = matches[i][1];

            if (losses[win] == 0) {
                losses[win] = -1;
            }

            if (losses[lose] == -1) {
                losses[lose] = 1;
            } else {
                losses[lose]++;
            }
        }

        vector<int> noLoses{};
        vector<int> oneLose{};

        for (int i = 1; i < 100001; i++) {
            if (losses[i] == -1) {
                noLoses.push_back(i);
            } else if (losses[i] == 1) {
                oneLose.push_back(i);
            }
        }
        vector<vector<int>> ret{noLoses, oneLose};
        return ret;
    }
};

int main(int argc, char *argv[]) {
    FindPlayersWithZeroOrOneLosses test;
    vector<vector<int>> v{{1, 3}, {2, 3}, {3, 6}, {5, 6}, {5, 7}, {4, 5}, {4, 8}, {4, 9}, {10, 4}, {10, 9}};
    vector<vector<int>> v2{{2, 3}, {1, 3}, {5, 4}, {6, 4}};
    vector<vector<int>> ret = test.findWinners(v);
    Print p{};
    // p.print(ret);
    p.print(test.findWinners(v2));

    return 0;
}