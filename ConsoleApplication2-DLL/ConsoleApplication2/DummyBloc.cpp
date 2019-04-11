#include "stdafx.h"
#include <iostream>
#include "Bloc.h"
#include <string>


std::string Bloc::ToString() {
	return "foooooooo" + std::to_string(nonce);
}



