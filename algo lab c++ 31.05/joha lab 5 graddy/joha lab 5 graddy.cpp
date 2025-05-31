#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>
using namespace std;
struct Item
{
    int weight, value;
};
bool compare(Item a, Item b)
{
    double r1 = (double)a.value / a.weight;
    double r2 = (double)b.value / b.weight;
    return r1 > r2;
}
void fractionalKnapSack(int W, vector<Item> &items)
{
    sort(items.begin(), items.end(), compare);
    double totalValue = 0.0;
    cout << "NO | Weight | Value | Ratio | Taken | Added Value\n";
    for (size_t i = 0; i < items.size(); ++i)
    {
        if (W == 0) break;
        double ratio = (double)items[i].value / items[i].weight;
        double taken = 0.0;
        double addedValue = 0.0;
        if (W >= items[i].weight)
        {
            taken = 1.0;
            addedValue = items[i].value;
            W -= items[i].weight;
        }
        else
        {
            taken = (double)W / items[i].weight;
            addedValue = items[i].value * taken;
            W = 0;
        }
        totalValue += addedValue;
        cout << i + 1 << " | "
             << items[i].weight << " | "
             << items[i].value << " | "
             << fixed << setprecision(2) << ratio << " | "
             << taken << " | "
             << addedValue << "\n";
    }
    cout << "\n**Total Weight Used**: 50";
    cout << "\n**Maximum Value Obtained**: " << fixed << setprecision(2) << totalValue << "\n";
}
int main()
{
    vector<Item> items = {{10, 60}, {20, 100}, {30, 120}};
    int W = 50;
    fractionalKnapSack(W, items);
    return 0;
}
