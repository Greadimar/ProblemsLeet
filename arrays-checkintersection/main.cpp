#include <QCoreApplication>
#include <QDebug>
using namespace std;
class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        std::vector<int> result;
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int left = 0;
        int right = nums1.size();
        int lastFound = -1;
        while (left < right){
            for (int j = lastFound+1; j < nums2.size(); j++){
                if (nums1[left] == nums2[j]){
                    lastFound = j;
                    result.push_back(nums1[left]);
                    break;
                }
            }
            left++;
        }
        return result;
    }
    vector<int> intersectBest(vector<int>& nums1, vector<int>& nums2) {
           sort(nums1.begin(),nums1.end());
           sort(nums2.begin(),nums2.end());
           vector<int> results;
           int i = 0, j = 0;
           while(i < nums1.size() && j < nums2.size())
           {
               if(nums1[i] > nums2[j] ) j++;
               else if(nums1[i] < nums2[j] ) i++;
               else
               {
                   results.push_back(nums1[i++]);
                   j++;
               }
           }



           return results;
       }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    std::vector<int> n1{1,2,2,1};
    std::vector<int> n2{2};
    qDebug() << Solution().intersect(n1, n2);
    return a.exec();
}
