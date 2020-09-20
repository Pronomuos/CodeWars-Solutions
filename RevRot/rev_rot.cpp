#include <string>
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;


class RevRot {
public:
    static std::string revRot(const std::string &strng, unsigned int sz) {
       if (strng.empty() || strng.size() < sz || sz <= 0)
            return "";

        vector<int> temp_vec;
        for (char num : strng)
            temp_vec.push_back(num - '0');

        size_t count = strng.size()/sz;
        for (size_t i = 0; i < count; i++) {
            int sum = 0;
            for (size_t j = i * sz; j < (i * sz) + sz; j++)
                sum += pow(temp_vec[j], 3);

            if (!(sum % 2))
                reverse(&temp_vec[i * sz], &temp_vec[i * sz + sz]);
            else {
                int temp = temp_vec[i * sz];
                for (size_t j = i * sz; j < (i * sz) + sz - 1; j++)
                    temp_vec[j] = temp_vec[j + 1];
                temp_vec[i * sz + sz - 1] = temp;
            }
        }

        string str;
        for (size_t i = 0; i < count * sz; i++)
            str += std::to_string(temp_vec[i]);

        return str;
    }

};
