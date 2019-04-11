#include "StdAfx.h"
#include "composant6.h"


unsigned char* getPublicKey(unsigned char privateKey[4])
{
	unsigned char fin[4];

	fin[0] = 'a';
	fin[1] = 'a';
	fin[2] = 'a';
	fin[3] = 'a';

	if((privateKey[0] == 'a') && (privateKey[1] == 'a') && (privateKey[2] == 'a') && (privateKey[3] == 'a'))
	{
		fin[0] = 'a';
		fin[1] = 'b';
		fin[2] = 'c';
		fin[3] = 'd';
	}

	return fin;
}