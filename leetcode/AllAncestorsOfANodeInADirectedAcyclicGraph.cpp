// Authored by Jie Huang
// 6/29/24
// 2192. All Ancestors of a Node in a Directed Acyclic Graph

#include "../resources/cpp_header.h"

void testcase1();
void testcase2();
void testcase3();

class AllAncestorsOfANodeInADirectedAcyclicGraph {
  public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>> &edges) {
        vector<int> graph[n];
        for (const auto &edge : edges) {
            graph[edge[0]].push_back(edge[1]);
        }
        vector<vector<int>> ret(n);
        auto bfs = [&](int i) {
            queue<int> q;
            q.push(i);
            vector<bool> visited(n, false);
            visited[i] = true;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                for (int next : graph[curr]) {
                    if (!visited[next]) {
                        visited[next] = true;
                        ret[next].push_back(i);
                        q.push(next);
                    }
                }
            }
        };
        for (int i = 0; i < n; ++i) {
            bfs(i);
        }
        return ret;
    }
};

AllAncestorsOfANodeInADirectedAcyclicGraph test;
Create c{};
Print p{};
Assert a{};

int main(int argc, char *argv[]) {
    testcase1();
    testcase2();
    testcase3();

    return 0;
}

void testcase1() {
    vector<vector<int>> input{{0, 3}, {0, 4}, {1, 3}, {2, 4}, {2, 7}, {3, 5}, {3, 6}, {3, 7}, {4, 6}};
    vector<vector<int>> output{{}, {}, {}, {0, 1}, {0, 2}, {0, 1, 3}, {0, 1, 2, 3, 4}, {0, 1, 2, 3}};
    a.assertEquals(test.getAncestors(8, input), output);
}

void testcase2() {
    vector<vector<int>> input{{0, 1}, {0, 2}, {0, 3}, {0, 4}, {1, 2}, {1, 3}, {1, 4}, {2, 3}, {2, 4}, {3, 4}};
    vector<vector<int>> output{{}, {0}, {0, 1}, {0, 1, 2}, {0, 1, 2, 3}};
    a.assertEquals(test.getAncestors(5, input), output);
}

void testcase3() {
}