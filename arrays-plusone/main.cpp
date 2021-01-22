#include <QCoreApplication>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
         int t = digits.size()-1;
         while (t >= 0){
             if (digits[t] == 9){
                 digits[t] = 0;
             }
             else{
                 digits[t]++;
                 return digits;
             }
             t--;
         }
         digits.insert(digits.begin(), 1);
         return digits;
    }
    vector<int> plusOneBest(vector<int>& digits) {
         int t = digits.size()-1;
         while (t >= 0){
             if (digits[t] == 9){
                 digits[t] = 0;
             }
             else{
                 digits[t]++;
                 return digits;
             }
             t--;
         }
         digits.insert(digits.begin(), 1);
         return digits;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    return a.exec();
}
