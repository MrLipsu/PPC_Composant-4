#include "stdafx.h"
#include "bloc.h"
#include <stdlib.h> 
#include <iostream> 
#include <vector>

std::vector<UTXO> getUTXO(Bloc b);
std::vector<UTXO> getAllUTXO(std::vector<Bloc> vb);
float verifyAmount(unsigned char key[4]);