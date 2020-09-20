using namespace std;

vector<int> deleteNth (vector<int> arr, int n) {
    vector<int> storage (1e5, 0);
    vector<int> temp_arr;

    for (int el : arr)
        if (++storage[el] <= n)
            temp_arr.push_back(el);

    return temp_arr;
}
