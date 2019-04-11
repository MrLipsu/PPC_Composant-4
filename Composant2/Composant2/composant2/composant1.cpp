#include "stdafx.h"
#include "Bloc.h"
#include <stdlib.h> 
#include <iostream> 
#include <vector>

std::vector<Bloc> getBlocs() // on simule la fonction de composant 1 et on renvoie une liste de blocs dans un vector pour que notre composant puisse travailler
{
	Bloc a;
	Bloc b;
	Bloc c;

	UTXO txo;

	txo.montant = 4;
	a.tx1.UTXOs.push_back(txo);
	txo.montant = 3;
	a.tx1.UTXOs.push_back(txo);

	txo.montant = 5;
	b.tx1.UTXOs.push_back(txo);
	txo.montant = 6;
	b.tx1.UTXOs.push_back(txo);

	txo.montant = 1;
	c.tx1.UTXOs.push_back(txo);
	txo.montant = 2;
	c.tx1.UTXOs.push_back(txo);

	std::vector<Bloc> v;
	v.push_back(a);
	v.push_back(b);
	v.push_back(c);

	return v;
}