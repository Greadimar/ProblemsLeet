#include <QCoreApplication>
class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        k = k % nums.size();
         std::vector<int> temp(k);
        int shift = nums.size() - k;
        for (int i = 0; i < k; i++){
            temp[i] = (nums[i + shift]);
        }
        for (int i = nums.size()-1; i >= k; i--){
            nums[i] =nums[i-k];
        }
        for (int i = 0; i < k; i++){
            nums[i] = temp[i];
        }
    }
};



int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
