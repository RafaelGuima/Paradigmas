#include "stdafx.h"

using namespace std;
#include <string>

class EntryLine {

private:
	string nome;
	string descricao;
	int pontos;
public:

	string getNome() {
		return nome;
	}
	string getDescricao() {
		return descricao;
	}
	int getPontos() {
		return this->pontos;
	}

	void setNome(string nome) {
		this->nome = nome;
	}
	void setDescricao(string descricao) {
		this->descricao = descricao;
	}
	void setPontos(int pontos) {
		this->pontos = pontos;
	}


	bool operator<(EntryLine e) {
		return this->pontos > e.getPontos;
	}
};