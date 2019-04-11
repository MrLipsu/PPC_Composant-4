// composant2.cpp : définit le point d'entrée pour l'application console.
//

#include "stdafx.h"
#include "composant1.h"
#include "composant6.h"
#include "Bloc.h"
#include <stdlib.h>
#include <vector>
#include <iostream> 


std::vector<UTXO> getUTXO(Bloc b)
{
	std::vector<UTXO> vec;
	vec.push_back(b.tx1.UTXOs[0]);
	vec.push_back(b.tx1.UTXOs[1]);

	return vec;
}

std::vector<UTXO> getAllUTXO(std::vector<Bloc> vb)
{
	std::vector<UTXO> utxotmp;
	std::vector<UTXO> utxo;
	int j = 0;

	for each( Bloc b in vb)
	{		
		utxotmp = getUTXO(b);
		utxo.push_back(utxotmp[0]);
		//j++;

		if(utxotmp[1].montant != 0)
		{
			utxo.push_back(utxotmp[1]);
			//j++;
		}
	}

	return utxo;
}

float verifyAmount(unsigned char key[4])
{
	std::vector<UTXO> utxo;
	int j = 0;
	// On reçoit les blocs du composant 1 avec getBlocs
	std::vector<Bloc> blocs = getBlocs();
	float montant = 0.0f;

	utxo = getAllUTXO(blocs);

	for each( UTXO xo in utxo)
	{
		if((xo.dest[0] == key[0]) && (xo.dest[1] == key[1]) && (xo.dest[2] == key[2]) && (xo.dest[3] == key[3]))
		{
			montant += xo.montant;
		}
	}

	return montant;
}


TX createTransaction(unsigned char privateKey[4], unsigned char publicKey[4], float montant)
{
	TX transaction;

	if(montant >= verifyAmount(getPublicKey(privateKey)))
	{
		transaction.UTXOs[0].dest[0] = publicKey[0];
		transaction.UTXOs[0].dest[1] = publicKey[1];
		transaction.UTXOs[0].dest[2] = publicKey[2];
		transaction.UTXOs[0].dest[3] = publicKey[3];
		transaction.UTXOs[0].montant = montant;

		transaction.UTXOs[1].dest[0] = getPublicKey(privateKey)[0];
		transaction.UTXOs[1].dest[1] = getPublicKey(privateKey)[1];
		transaction.UTXOs[1].dest[2] = getPublicKey(privateKey)[2];
		transaction.UTXOs[1].dest[3] = getPublicKey(privateKey)[3];
		transaction.UTXOs[1].montant = verifyAmount(getPublicKey(privateKey)) - montant;
	}

	return transaction;
}