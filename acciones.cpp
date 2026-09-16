#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices)
{
    int mejorGanancia = 0;

    for (int i = 0; i < prices.size(); i++)
    {
        for (int j = i + 1; j < prices.size(); j++)
        {
            int ganancia = prices[j] - prices[i];

            if (ganancia > mejorGanancia)
            {
                mejorGanancia = ganancia;
            }
        }
    }

    return mejorGanancia;
}

int main()
{
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    int resultado = maxProfit(prices);

    cout << "Ganancia maxima: " << resultado << endl;

    return 0;
}
