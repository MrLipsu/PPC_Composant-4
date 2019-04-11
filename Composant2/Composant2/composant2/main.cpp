#include "StdAfx.h"
#include "stdafx.h"
#include "composant1.h"
#include "composant2.h"
#include "bloc.h"
#include "Mineur.h"
#include <stdlib.h>
#include <vector>
#include <iostream> 

int main(int argc, _TCHAR* argv[])
{
	std::vector<UTXO> utxo;
	
	//// On reçoit les blocs du composant 1 avec getBlocs
	std::vector<Bloc> blocs = getBlocs();

	utxo = getAllUTXO(blocs);

	Bloc toMine = blocs.back();

	Bloc blocRemine;

	blocRemine = miner(2, toMine);
	
	system("pause");
	return 0;
}