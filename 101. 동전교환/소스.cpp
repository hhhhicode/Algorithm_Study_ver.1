#include <iostream>

class Changer
{
private:
	int coinCate;
	int* coins;
	int totalMoney;
	int* changePool;

public:
	void init()
	{
		std::cin >> coinCate;
		coins = new int[coinCate];
		for (int i = 0; i < coinCate; i++)
			std::cin >> coins[i];
		std::cin >> totalMoney;
		changePool = new int[totalMoney + 1];
		for (int i = 0; i <= totalMoney; i++)
		for (int i = 0; i <= totalMoney; i++)
		{
			changePool[i] = i;//
		}
	}

	void chageCoin()
	{
		for (int i = 0; i < coinCate; i++)
		{
			for (int j = coins[i]; j <= totalMoney; j++)
			{
				int thisCoins = changePool[j];
				int thereCoins = changePool[j - coins[i]] + 1;
				if(thisCoins > thereCoins)
					changePool[j] = thereCoins;
			}
		}
	}

	void printMinCoins()
	{
		std::cout << changePool[totalMoney];
	}

	void solution()
	{
		init();
		chageCoin();
		printMinCoins();
	}
};

int main()
{
	using namespace std;

	Changer().solution();

	return 0;
}