#include <QCoreApplication>
#include <unordered_map>
#include <QDebug>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        std::unordered_map<int, int> map;
        for (int i = 0; i < nums.size(); i++){
            map.insert({nums[i], i});
        }
        for (int i = 0; i < nums.size(); i++){
            auto it = map.find(target - nums[i]);
            if (it != map.end()){
                if (it->second == i) continue;
                return {i, it->second};
            }
        }
        return {};
    }
    vector<int> twoSumBest(vector<int>& nums, int target)
       {
           for(int i = 0; i < nums.size(); ++i)
           {
               for(int j = i + 1; j < nums.size(); ++j)
               {
                   if(nums[i] + nums[j] == target)
                   {
                       return {i,j};
                   }
               }
           }
           return vector<int>{};
       }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::vector<int>  t{3,2,4};
    qDebug() << Solution().twoSum(t, 6);
    return a.exec();
}
