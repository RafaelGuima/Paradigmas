// JogoDePontos.cpp : Define o ponto de entrada para a aplicação de console.
//
#include "stdafx.h"
#include "EntryLine.cpp"
#include "Jogador.cpp"
#include "Atividade.cpp"
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <iterator>
#include <algorithm>


using namespace std;

bool cmpPlayerName(Jogador p1, Jogador p2) {
	return p1.getNome() < p2.getNome();
}


int main()
{
	ifstream data("data.csv");

	string line;

	Jogador player;
	vector<Jogador> pVect;

	Atividade activity;
	vector<Atividade> aVect;

	EntryLine linha;
	vector<EntryLine> lVect;

	string name, description, score;
	

	while (getline(data, line)) {

		stringstream linestream(line);

		getline(linestream, name, ',');
		player.setNome(name);
		linha.setNome(name);

		getline(linestream, description, ',');
		activity.setDescricao(description);
		linha.setDescricao(description);

		getline(linestream, score, ',');
		player.setPontos(stoi(score, nullptr, 10));
		activity.setPontos(stoi(score, nullptr, 10));
		linha.setPontos(stoi(score, nullptr, 10));

		pVect.push_back(player);
		aVect.push_back(activity);
		lVect.push_back(linha);
	}

	//Eliminando jogadores repetidos
	for (size_t i = 0; i < pVect.size(); i++) {

		for (size_t j = i; j < pVect.size(); j++) {

			if (j == i) continue;

			else {
				if (pVect.at(i).getNome().compare(pVect.at(j).getNome()) == 0) {
					pVect.at(i).setPontos((pVect.at(i).getPontos() + pVect.at(j).getPontos()));
					pVect.erase(pVect.begin() + j);
					j--;
				}
			}
		}
	}

	//Eliminando atividades repetidas
	for (size_t i = 0; i < aVect.size(); i++) {

		for (size_t j = i; j < aVect.size(); j++) {

			if (j == i) continue;

			else {
				if (aVect.at(i).getDescricao().compare(aVect.at(j).getDescricao()) == 0) {
					aVect.erase(aVect.begin() + j);
					j--;
				}
			}
		}
	}

	int menu;
	do {
		cout << "Digite numero da acao desejada.\n1-Imprimir todos os atributos em ordem decrescente de pontos.\n2-Imprimir lista de jogadores com suas pontuacoes em ordem crescente.\n3-Imprimir lista de jogadores com suas pontuacoes em ordem alfabetica.\n4-(Extra)Imprimir atividades e o quanto atribuem de pontos.\n0-Para sair do programa.\n";
		cin >> menu;

		switch (menu)
		{

		case 1:
			sort(lVect.begin(), lVect.end());
			cout << "\nImprimindo linhas do arquivo em ordem decrescente de pontuacoes.";
			for (size_t i = 0; i < lVect.size(); i++) {
				cout << lVect.at(i).getNome() << ", " << lVect.at(i).getDescricao() << ", " << lVect.at(i).getPontos();
			}
			break;


		case 2:
			sort(pVect.begin(), pVect.end());
			cout << "\nImprimindo lista de jogadores e suas pontuacoes em ordem crescente de pontos.";
			for (size_t i = 0; i < pVect.size(); i++) {
				cout << pVect.at(i).getNome() << " que possui " << pVect.at(i).getPontos() << " pontos";
			}
			break;


		case 3:
			sort(pVect.begin(), pVect.end(), cmpPlayerName);
			cout << "\nImprimindo lista de jogadores e suas pontuacoes em ordem alfabetica.";
			for (size_t i = 0; i < pVect.size(); i++) {
				cout << pVect.at(i).getNome() << " que possui " << pVect.at(i).getPontos() << " pontos";
			}
			break;


		case 4:
			cout << "\nImprimindo lista de atividades e suas pontuacoes.";
			for (size_t i = 0; i < aVect.size(); i++) {
				cout << aVect.at(i).getDescricao() << " que atribui " << aVect.at(i).getPontos() << " pontos";
			}
			break;


		default:
			cout << "Entrada invalida/Saindo do programa.";
			break;
		}
	} while (menu != 0);

	cout << "\n";
	system("pause");
    return 0;
}

