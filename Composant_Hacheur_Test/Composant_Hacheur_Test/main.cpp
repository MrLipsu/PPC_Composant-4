#include <iostream>
#include <string>
#include "Hacheur.h"

#include <string>

using namespace std;

void test_hash() {
	Hacheur hacheur = Hacheur();
	string input = "Hello word";
	string output = hacheur.hacher(input);
	string expected_output = "aea1d1146a00e1c55e49c7837c224ecfb76ca0337fd4bb6dc09e892ca0190119";
	cout << "output: " << output << endl;
	if (output.compare(expected_output) == 0) {
		cout << "La methode hash fonctionne parfaitement" << endl;
	} else {
		cout << "ATTENTION : La methode hash ne fonctionne pas bien!" << endl;
	}
}

void test_verifier_hash() {
	Hacheur hacheur = Hacheur();
	string input = "Hello word";
	string expected_output = "aea1d1146a00e1c55e49c7837c224ecfb76ca0337fd4bb6dc09e892ca0190119";
	string unexpected_output = "d7a8fbb307d7809469ca9abcb0082e4f8d5651e46d3cdb762d02d0bf37c9e592";

	if (hacheur.verifier_hachage(input, expected_output)) {
		cout << "La methode verifier_hash fonctionne pour un bon output" << endl;
	} else {
		cout << "ATTENTION : La methode verifier_hash ne fonctionne pas bien avec un bon output" << endl;
	}

	if (!hacheur.verifier_hachage(input, unexpected_output)) {
		cout << "La methode verifier_hash fonctionne pour un mauvais output" << endl;
	} else {
		cout << "ATTENTION : La methode verifier_hash ne fonctionne pas bien avec un mauvais output" << endl;
	}
}

int main() {
	test_hash();
	test_verifier_hash();
	getchar(); 
}