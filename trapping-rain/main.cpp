#include <QCoreApplication>
#include <QDebug>
class Solution {
public:

    int trap( std::vector<int>&& height) {
        int left = 0, right = height.size() - 1;
           int res = 0;
           int leftMax = 0, rightMax = 0;
           while (left < right) {
               if (height[left] < height[right]) {
                   height[left] >= leftMax ? (leftMax = height[left]) : res += (leftMax - height[left]);
                   ++left;
               }
               else {
                   height[right] >= rightMax ? (rightMax = height[right]) : res += (rightMax - height[right]);
                   --right;
               }
           }
           return res;

    }

};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
   // qDebug() << Solution().trap(std::vector<int>{0,1,0,2,1,0,1,3,2,1,2,1});
      qDebug() << Solution().trap(std::vector<int>{0,7,1,4,6});
      qDebug() << Solution().trap(std::vector<int>{5,4,1,2});
    return a.exec();
}
