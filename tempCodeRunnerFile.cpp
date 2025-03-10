#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        stack<int> acc;
        int sum = 0;
        int width = 0;
        int n = height.size();
        for (int i = 0; i < n; i++) {
            if (stk.empty() || height[i] < stk.top()) {
                // cout << "pushed " << height[i] << endl;
                stk.push(height[i]);
                acc.push(1);
                width++;
                continue;
            }
            // cout << "did not push " << height[i] << " first" << endl;
            int res = 0;
            int lst;
            int tmp = 1;
            while (!stk.empty() && stk.top() < height[i]) {
                res += acc.top() * (height[i] - stk.top());
                lst = stk.top();
                // cout << "popping " << stk.top() << ", width for it = " << acc.top() << endl;
                tmp++;
                // cout << "poped " << lst << endl;
                stk.pop();
                acc.pop();
            }
            if (stk.empty()) {
                // cout << "poped till empty, width = " << width << endl;
                // cout << "last height = " << lst << endl;
                res -= width * (height[i] - lst);
                width = 0;
                sum += res;
                tmp = 1;
            }
            else {
                 sum += res;
            }
            width++;
            stk.push(height[i]);
            acc.push(tmp);
            // cout << "pushed later " << height[i] << endl;
            // cout << "current sum = " << sum << endl;
        }
        return sum;
    }
};

int main() {
    Solution sol;
    int n;
    vector<int> height;
    cin >> n;
    for (int i=0; i<n; i++) {
        int tmp;
        cin >> tmp;
        height.push_back(tmp);
    }
    cout << sol.trap(height) << endl;
    return 0; 
}