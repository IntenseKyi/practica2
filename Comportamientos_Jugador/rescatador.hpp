#ifndef COMPORTAMIENTORESCATADOR_H
#define COMPORTAMIENTORESCATADOR_H

#include <iostream>
#include <chrono>
#include <time.h>
#include <thread>
#include <list>
#include <queue>
#include <map>

#include "comportamientos/comportamiento.hpp"


struct PosicionRescatador
{
	int fil;
	int col;
	int direccion;
	bool zapatillas;
	int coste_total;

	bool operator==(const PosicionRescatador &otro) const {
		return fil == otro.fil &&
			col == otro.col &&
			direccion == otro.direccion &&
			zapatillas == otro.zapatillas;
	}

	bool operator<(const PosicionRescatador &otro) const {
		if (fil != otro.fil) return fil < otro.fil;
		if (col != otro.col) return col < otro.col;
		if (direccion != otro.direccion) return direccion < otro.direccion;
		return zapatillas < otro.zapatillas;
	}
};

struct NodoR
{
	PosicionRescatador estado;
	list<Action> plan; // Acciones que llevan hasta esta posición

	bool operator==(const NodoR &otro) const {
		return estado == otro.estado;
	}

	bool operator<(const NodoR &otro) const {
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



class ComportamientoRescatador : public Comportamiento
{

public:
  ComportamientoRescatador(unsigned int size = 0) : Comportamiento(size)
  {
    // Inicializar Variables de Estado Niveles 0,1,4
    last_action = IDLE;
    tiene_zapatillas = false;
    giro45Izq = 0;
    
    for (int i = 0; i < 100; i++)
      for (int j = 0; j < 100; j++)
        mapa_visitas[i][j] = 0;

    
  }
  ComportamientoRescatador(std::vector<std::vector<unsigned char>> mapaR, std::vector<std::vector<unsigned char>> mapaC) : Comportamiento(mapaR,mapaC)
  {
    // Inicializar Variables de Estado Niveles 2,3
    tiene_plan = false;
    tiene_zapatillas = false;
  }
  ComportamientoRescatador(const ComportamientoRescatador &comport) : Comportamiento(comport) {}
  ~ComportamientoRescatador() {}

  Action think(Sensores sensores);

  int interact(Action accion, int valor);

  Action ComportamientoRescatadorNivel_0(Sensores sensores);
  Action ComportamientoRescatadorNivel_1(Sensores sensores);
  Action ComportamientoRescatadorNivel_2(Sensores sensores);
  Action ComportamientoRescatadorNivel_3(Sensores sensores);
  Action ComportamientoRescatadorNivel_4(Sensores sensores);

  void InterpretaPlan(const PosicionRescatador &pr, const list<Action> &plan);
  void RepresentaPlan(const list<Action> &plan, bool zap);

private:
  // Variables de Estado
  Action last_action;
  bool tiene_zapatillas;
  int giro45Izq;
  int mapa_visitas[100][100];
  
  // Nivel 2
  bool tiene_plan;
  list<Action> plan;
};

#endif
