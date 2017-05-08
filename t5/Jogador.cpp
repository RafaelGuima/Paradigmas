#include "stdafx.h"

using namespace std;
#include <string>

class Jogador {
	
private:
	string nome;
	int pontos;
public:

	string getNome(){
		return nome;
	}
	int getPontos() {
		return this->pontos;
	}

	void setNome(string nome) {
		this->nome = nome;
	}
	void setPontos(int pontos) {
		this->pontos = pontos;
	}


	bool operator<(Jogador j) {
		return this->pontos < j.getPontos();
	}
};
