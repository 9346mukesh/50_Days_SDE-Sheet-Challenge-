#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> threesum(vector<int>& nums, int n, int target) {
    sort(nums.begin(), nums.end());

    vector<vector<int>> ans;

    for(int i = 0; i < n; i++) {

        if(i > 0 && nums[i] == nums[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;

        while(j < k) {

            int sum = nums[i] + nums[j] + nums[k];

            if(sum == target) {

                ans.push_back({nums[i], nums[j], nums[k]});

                j++;
                k--;

                while(j < k && nums[j] == nums[j - 1])
                    j++;

                while(j < k && nums[k] == nums[k + 1])
                    k--;
            }
            else if(sum < target) {
                j++;
            }
            else {
                k--;
            }
        }
    }

    return ans;
}

int main() {

    int n;
    cin >> n;

    vector<int> nums(n);

    for(int i = 0; i < n; i++) {
        cin >> nums[i];
    }

    int target;
    cin >> target;

    vector<vector<int>> triplets = threesum(nums, n, target);

    if(triplets.empty()) {
        cout << "No Triplets Found";
        return 0;
    }

    for(int i = 0; i < triplets.size(); i++) {
        for(int j = 0; j < triplets[i].size(); j++) {
            cout << triplets[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}