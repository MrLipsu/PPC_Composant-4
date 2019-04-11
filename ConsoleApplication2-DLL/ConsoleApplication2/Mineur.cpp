#include "stdafx.h"
#include "Mineur.h"
#include "Hacheur.h"
#include <iostream>
#include <vector>
#include "Bloc.h"
using std::string;
using std::cout;
using std::endl;

int nbZerosCounter(std::string str) {
	int nbZeros = 0;
	for (int i = str.size() - 1; i >= 0; i--) {
		if (str[i] == '0') nbZeros++;
		else break;
	}
	return nbZeros;
}


Bloc miner(unsigned int difficulty, Bloc b) {
	string strHash;
	int nbZeros;
	do {
		Hacheur hacheur = Hacheur();
		b.nonce++;
		cout << "string:" << b.ToString() << endl;
		strHash = hacheur.hacher(b.ToString());
		cout << "hash:" << strHash << endl;
		nbZeros = nbZerosCounter(strHash);
	} while ((unsigned) nbZeros < difficulty);
	for (int i = 0; i < HASH_SIZE; i++) {
		b.hash[i] = strHash[i];
	}
	return b;
}

