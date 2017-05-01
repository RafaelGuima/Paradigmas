// point.cpp : Define o ponto de entrada para a aplicação de console.
//

#include "stdafx.h"
#include <cmath>
#include <iostream>

using namespace std;

class Point {

private:
	float x;
	float y;

public:
	Point() {};

	Point(float a, float b) {

		x = a;
		y = b;
	};

	float get_x() {
		return x;
	}
	float get_y() {
		return y;
	}

	void set_x(float var) {
		x = var;
	}
	void set_y(float var) {
		y = var;
	}

	void move(float dx, float dy) {

		x = x + dx;
		y = y + dy;
	}

	float distanceTo(Point p1) {
		
		return sqrt(pow(p1.x - x, 2) + pow(p1.y - y, 2));
	}

};


int main()
{
	float a, b;
	cout << "Escreva x e y do ponto p: ";
	cin >> a;
	cin >> b;
	Point p(a, b);

	Point* point_l;

	for (int i = 5; i > 0; i--) {

		cout << "Escreva x e y do ponto para a lista: ";
		cin >> a;
		cin >> b;
		point_l = new Point(a, b);
		cout << "Ponto adicionado na lista.";
	}


	for (int i = 5; i > 0; i--) {

		cout << "Comparando ponto p com " << i + 1 << " ponto da lista";
		cout << "Distancia do ponto p ao ponto " << i + 1 << " é " << p.distanceTo(point_l[i]);
	}
	
	cout << "Destruindo pontos.";
	delete[] point_l;

    return 0;
}

