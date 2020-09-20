#include <utility>
#include <vector>
#include <set>

using namespace std;

vector<pair<int, int>> twos_difference(const vector<int> &vec) {
    vector<pair<int, int>> ans;
    vector<int> temp_vec = vec;
    sort (temp_vec.begin(), temp_vec.end());
    for (int i = 0; i < temp_vec.size(); i++)
        for (int j = i + 1; j < temp_vec.size(); j++)
            if (abs(temp_vec[i] - temp_vec[j]) == 2)
               ans.emplace_back(temp_vec[i], temp_vec[j]);

    return ans;

}
