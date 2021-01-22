#include <QCoreApplication>

class Solution {
public:
        int singleNumber(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            if (nums.size() == 1) return nums[0];
            for (int i = 0; i < nums.size()-1; i+=2){
                if (nums[i] != nums[i+1]) return nums[i];
            }
            return nums[nums.size()-1];
        }
        int singleNumberBest(std::vector<int>& nums) {
            std::sort(nums.begin(), nums.end());
            int element = 0;
            for(int i = 0; i < nums.size(); i++)
            {
                element = element ^ nums[i];
            }
            return element;
        }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
