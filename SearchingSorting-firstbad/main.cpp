#include <QCoreApplication>
#include <QDebug>
bool isBadVersion(int version){
    return (version >= 2);
}
class Solution {
public:
    int firstBadVersion(int n) {
        int right = n;
        int shift = n/2;
        if (shift == 0) shift++;
        while(true){
            if (isBadVersion(right)){
                if (shift == 1) {
                    if (!isBadVersion((right-1)))
                        return right;
                }
                right = right - shift;
            }
            else {
                shift = shift/2;
                if (shift == 0) shift++;
                right += shift;
            }
        }
        return 0;
    }

    int firstBadVersionBest(int n) {

         int left = 0;
         int right = n;
         int mid;

         while (left < right) {

             mid = left + (right - left) / 2;

             if (isBadVersion(left + (right - left) / 2)) {
                 right = mid;
             } else {
                 left = mid + 1;
             }

         }

         return left;
     }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    qDebug() << Solution().firstBadVersion(4);
    return a.exec();
}
