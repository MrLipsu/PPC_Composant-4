#include "stdafx.h"
#include "Hacheur.h"
#include <iostream>
#include <vector>
#include "Bloc.h"

#ifdef MINEUR_EXPORTS

#define MINEUR_INTERFACE __declspec(dllexport)
#else

#define MINEUR_INTERFACE __declspec(dllimport)
#endif

MINEUR_INTERFACE Bloc miner(unsigned int difficulty, Bloc b);

int nbZerosCounter(std::string str);
