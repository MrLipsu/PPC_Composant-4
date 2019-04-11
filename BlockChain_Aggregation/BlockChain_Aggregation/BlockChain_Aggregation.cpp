// BlockChain_Aggregation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Mineur.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{

	Bloc b;
	string stop;
	b = miner(2, b);
	cout << "Le hash est :" << std::string(b.hash).substr(0, HASH_SIZE) << endl;
	cin >> stop;
	return 0;
}

