#include <bitset>
#include <string>
#include <sstream>
#include <vector>
#include <fstream>

class Solution {
//private:
//    std::vector<std::string> result;
//
//    void helper(int i, int k, int num, std::bitset<4> HOUR, std::bitset<6> MINUTE) {
//        if (i > num) {
//            auto hour = HOUR.to_ulong();
//            auto minute = MINUTE.to_ulong();
//            std::ostringstream time;
//            time << hour << ":";
//            if (minute < 10) time << "0";
//            time << minute;
//            result.push_back(time.str());
//            return;
//        }
//        if (k < 4) {
//            helper(i, k + 1
//        for (int j = 0; j < 4; ++j) {
//            if (!HOUR[j]) {
//                helper(i + 1, num, HOUR.set(j), MINUTE);
//                HOUR.reset(j);
//            }
//        }
//        for (int j = 0; j < 6; ++j) {
//            if (!MINUTE.test(j)) {
//                helper(i + 1, num, HOUR, MINUTE.set(j));
//                MINUTE.reset(j);
//            }
//        }
//    }
private:
    unsigned int countSetBits(unsigned int n) { 
        unsigned int count = 0; 
        while (n) 
        { 
             count += n & 1; 
             n >>= 1; 
        } 
        return count; 
    }

public:
    std::vector<std::string> readBinaryWatch(int num) {
        std::vector<std::string> result;
        for (unsigned int i = 0; i < 12; ++i) {
            for (unsigned int j = 0; j < 60; ++j) {
                if (countSetBits(i) + countSetBits(j) == num) {
                    std::ostringstream time;
                    time << i << ":";
                    if (j < 10) time << 0;
                    time << j;
                    result.push_back(time.str());
                }
            }
        }
        return result;
    }
};

int main() {
    std::ofstream fout("/home/wyx/result.txt");
    Solution s;
    auto result = s.readBinaryWatch(2);
    for (const auto &time : result) {
        fout << time << "\n";
    }
    fout.close();
    return 0;
}

