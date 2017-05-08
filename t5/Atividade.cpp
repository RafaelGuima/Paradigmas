#include "stdafx.h"

using namespace std;
#include <string>

class Atividade {

private:
	string descricao;
	int pontos;
public:

	string getDescricao() {
		return descricao;
	}
	int getPontos() {
		return pontos;
	}

	void setDescricao(string descricao) {
		this->descricao = descricao;
	}
	void setPontos(int pontos) {
		this->pontos = pontos;
	}
};