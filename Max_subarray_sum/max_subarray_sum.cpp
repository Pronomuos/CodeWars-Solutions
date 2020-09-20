#include <vector>

using namespace std;

int maxSequence(const vector<int>& arr){
    int max = 0;
    int sum = 0;
    for (int i : arr) {
        sum += i;
        sum = sum <= 0 ? 0 : sum;
        max = std::max(sum, max);
    }

    return max;
}
