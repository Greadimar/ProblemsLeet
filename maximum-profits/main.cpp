#include <QCoreApplication>
#include <QtDebug>
using namespace std;
class Solution {
public:
    bool isVortex(const vector<int>& prices, int idx){
        if (prices[idx] > prices[idx+1]) return true;
        else return false;
    }
    bool isBottom(const vector<int>& prices, int idx){
        if (prices[idx] < prices[idx+1]) return true;
        else return false;
    }
    int maxProfit(const vector<int>& prices) {

        int profit = 0;
        if (prices.size() == 0) return profit;
        int curVal = 0;
        int starti = -1;

        for (int i = 0; i < prices.size() - 1; i++){
            if (isBottom(prices, i)){
                curVal = prices[i];
                starti = i;
                break;
            }
        }
        if (starti <= -1) return 0;

        for (int i = starti + 1; i < prices.size() - 1; i++){
            if (prices[i] < curVal) curVal = prices[i];
            if (isVortex(prices, i)){
                profit += prices[i] - curVal;
                curVal = prices[++i];
            }
        }
        if (prices[prices.size()-1] > curVal) profit += prices[prices.size()-1] - curVal;
        return  profit;
        }


    int maxProfitFast(vector<int>& p)
    {
        if(p.size()==1)
            return 0;
        int profit=0;
        int op=p[0];
        for(int i=0;i<p.size();i++)
        {
            while(i+1<p.size() && p[i]<p[i+1])
            i++;
            if(op<p[i])
            {
                profit+=p[i]-op;
            }
              op=p[i+1];
        }
        return  profit;
    }
};
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    auto r = Solution().maxProfit(std::vector<int>{3,2,6,5,0,4});
    qDebug() << r;
    return a.exec();
}
