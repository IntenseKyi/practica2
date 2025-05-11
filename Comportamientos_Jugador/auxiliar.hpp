#ifndef COMPORTAMIENTOAUXILIAR_H
#define COMPORTAMIENTOAUXILIAR_H

#include <iostream>
#include <chrono>
#include <time.h>
#include <thread>
#include <list>
#include <queue>
#include <map>

#include "comportamientos/comportamiento.hpp"


struct PosicionAuxiliar
{
	int fil;
	int col;
	int direccion;
	bool zapatillas;
	int coste_total;
	int estimacion;

	bool operator==(const PosicionAuxiliar &otro) const {
		return fil == otro.fil &&
			col == otro.col &&
			direccion == otro.direccion &&
			zapatillas == otro.zapatillas;
	}

	bool operator<(const PosicionAuxiliar &otro) const {
		if (fil != otro.fil) return fil < otro.fil;
		if (col != otro.col) return col < otro.col;
		if (direccion != otro.direccion) return direccion < otro.direccion;
		return zapatillas < otro.zapatillas;
	}
};

struct NodoA
{
	PosicionAuxiliar estado;
	list<Action> plan; // Acciones que llevan hasta esta posición

	bool operator==(const NodoA &otro) const {
		return estado == otro.estado;
	}

	bool operator<(const NodoA &otro) const {
		if (estado.coste_total != otro.estado.coste_total)
			return estado.coste_total > otro.estado.coste_total;
		if (estado.fil != otro.estado.fil)
			return estado.fil < otro.estado.fil;
		if (estado.col != otro.estado.col)
			return estado.col < otro.estado.col;
		if (estado.direccion != otro.estado.direccion)
			return estado.direccion < otro.estado.direccion;
		return estado.zapatillas < otro.estado.zapatillas;
	}
};



class ComportamientoAuxiliar : public Comportamiento
{

public:
  ComportamientoAuxiliar(unsigned int size = 0) : Comportamiento(size)
  {
    // Inicializar Variables de Estado Niveles 0,1,4
    last_action = IDLE;
    tiene_zapatillas = false;
    girosDcha = 0;

    mapa_visitas = vector<vector<int>>(100, vector<int>(100,0));
  }
  ComportamientoAuxiliar(std::vector<std::vector<unsigned char>> mapaR, std::vector<std::vector<unsigned char>> mapaC) : Comportamiento(mapaR,mapaC)
  {
    // Inicializar Variables de Estado Niveles 2,3
    tiene_plan = false;
    tiene_zapatillas = false;
  }
  ComportamientoAuxiliar(const ComportamientoAuxiliar &comport) : Comportamiento(comport) {}
  ~ComportamientoAuxiliar() {}

  Action think(Sensores sensores);

  int interact(Action accion, int valor);

  Action ComportamientoAuxiliarNivel_0(Sensores sensores);
  Action ComportamientoAuxiliarNivel_1(Sensores sensores);
  Action ComportamientoAuxiliarNivel_2(Sensores sensores);
  Action ComportamientoAuxiliarNivel_3(Sensores sensores);
  Action ComportamientoAuxiliarNivel_4(Sensores sensores);

  void InterpretaPlan(const PosicionAuxiliar &pr, const list<Action> &plan);

private:
  // Definir Variables de Estado
  Action last_action;
  bool tiene_zapatillas;
  int girosDcha;

  vector<vector<int>> mapa_visitas;
  
  // Nivel 2
  bool tiene_plan;
  list<Action> plan;
};

#endif
