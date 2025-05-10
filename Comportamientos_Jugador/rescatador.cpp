#include "../Comportamientos_Jugador/rescatador.hpp"
#include "motorlib/util.h"

#include <iostream>

Action ComportamientoRescatador::think(Sensores sensores)
{
	Action accion = IDLE;

	switch (sensores.nivel)
	{
	case 0:
		accion = ComportamientoRescatadorNivel_0 (sensores);
		break;
	case 1:
		accion = ComportamientoRescatadorNivel_1 (sensores);
		break;
	case 2:
		// accion = ComportamientoRescatadorNivel_2 (sensores);
		break;
	case 3:
		// accion = ComportamientoRescatadorNivel_3 (sensores);
		break;
	case 4:
		// accion = ComportamientoRescatadorNivel_4 (sensores);
		break;
	}

	return accion;
}

int ComportamientoRescatador::interact(Action accion, int valor)
{
	return 0;
}


int VeoCasillaInteresanteR_N0 (char i, char c, char d, bool zap, int vi, int vc, int vd)
{
    // 1. Objetivo a la vista
    if (c == 'X') return 2;
    if (i == 'X') return 1;
    if (d == 'X') return 3;

    // 2. Zapatillas y destino
    if (!zap) {
        if (c == 'D') return 2;
        if (i == 'D') return 1;
        if (d == 'D') return 3;
    }

    // 3. Casillas transitables
    bool transitable[3] = {false, false, false};
    if (i == 'C' || i == 'D') transitable[0] = true;
    if (c == 'C' || c == 'D') transitable[1] = true;
    if (d == 'C' || d == 'D') transitable[2] = true;

    // 4. Emparejar visitas con casillas
    int visitas[3] = {vi, vc, vd};
    int mejor = 9999;
    int opcion[3] = {0, 0, 0};

    for (int k = 0; k < 3; ++k) {
        if (transitable[k] && visitas[k] <= mejor) {
            mejor = visitas[k];
            opcion[k] = 1;
        }
    }
    
    //std::cout << "Delante " << i << " " << c << " " << d << endl;
	//std::cout << "Visitas " << vi << " " << vc << " " << vd << endl;
	//std::cout << "Menor visitas: " << mejor << endl;
	//std::cout << "Opciones " << opcion[0] << " " << opcion[1] << " " << opcion[2] << endl << endl;


	if (opcion[1] && visitas[1] == mejor) return 2;
	if (opcion[0] && visitas[0] == mejor) return 1;
	if (opcion[2] && visitas[2] == mejor) return 3;
    return 0; // Nada interesante
}

int VeoCasillaInteresanteR_N1 (char i, char c, char d, bool zap, int posF, int posC, int df[5], int dc[5], int vi, int vc, int vd)
{
	return 0;
}

char CasillaViableR (char casilla, int dif, bool zap)
{
	if (abs(dif)<=1 or (zap and abs(dif)<=2))
		return casilla;
	else
		return 'P';
}

void SituarSensorEnMapaR(vector<vector<unsigned char>> &m, vector<vector<unsigned char>> &a, Sensores sensores)
{
	m[sensores.posF][sensores.posC] = sensores.superficie[0];
	a[sensores.posF][sensores.posC] = sensores.cota[0];
	
	int pos = 1;
	switch(sensores.rumbo)
	{
	case norte:
		m[sensores.posF-1][sensores.posC-1] = sensores.superficie[1];
		m[sensores.posF-1][sensores.posC] = sensores.superficie[2];
		m[sensores.posF-1][sensores.posC+1] = sensores.superficie[3];
		m[sensores.posF-2][sensores.posC-2] = sensores.superficie[4];
		m[sensores.posF-2][sensores.posC-1] = sensores.superficie[5];
		m[sensores.posF-2][sensores.posC] = sensores.superficie[6];
		m[sensores.posF-2][sensores.posC+1] = sensores.superficie[7];
		m[sensores.posF-2][sensores.posC+2] = sensores.superficie[8];
		m[sensores.posF-3][sensores.posC-3] = sensores.superficie[9];
		m[sensores.posF-3][sensores.posC-2] = sensores.superficie[10];
		m[sensores.posF-3][sensores.posC-1] = sensores.superficie[11];
		m[sensores.posF-3][sensores.posC] = sensores.superficie[12];
		m[sensores.posF-3][sensores.posC+1] = sensores.superficie[13];
		m[sensores.posF-3][sensores.posC+2] = sensores.superficie[14];
		m[sensores.posF-3][sensores.posC+3] = sensores.superficie[15];
		
		a[sensores.posF-1][sensores.posC-1] = sensores.cota[1];
		a[sensores.posF-1][sensores.posC] = sensores.cota[2];
		a[sensores.posF-1][sensores.posC+1] = sensores.cota[3];
		a[sensores.posF-2][sensores.posC-2] = sensores.cota[4];
		a[sensores.posF-2][sensores.posC-1] = sensores.cota[5];
		a[sensores.posF-2][sensores.posC] = sensores.cota[6];
		a[sensores.posF-2][sensores.posC+1] = sensores.cota[7];
		a[sensores.posF-2][sensores.posC+2] = sensores.cota[8];
		a[sensores.posF-3][sensores.posC-3] = sensores.cota[9];
		a[sensores.posF-3][sensores.posC-2] = sensores.cota[10];
		a[sensores.posF-3][sensores.posC-1] = sensores.cota[11];
		a[sensores.posF-3][sensores.posC] = sensores.cota[12];
		a[sensores.posF-3][sensores.posC+1] = sensores.cota[13];
		a[sensores.posF-3][sensores.posC+2] = sensores.cota[14];
		a[sensores.posF-3][sensores.posC+3] = sensores.cota[15];
		
		break;
	case noreste:
		m[sensores.posF-1][sensores.posC] = sensores.superficie[1];
		m[sensores.posF-1][sensores.posC+1] = sensores.superficie[2];
		m[sensores.posF][sensores.posC+1] = sensores.superficie[3];
		m[sensores.posF-2][sensores.posC] = sensores.superficie[4];
		m[sensores.posF-2][sensores.posC+1] = sensores.superficie[5];
		m[sensores.posF-2][sensores.posC+2] = sensores.superficie[6];
		m[sensores.posF-1][sensores.posC+2] = sensores.superficie[7];
		m[sensores.posF][sensores.posC+2] = sensores.superficie[8];
		m[sensores.posF-3][sensores.posC] = sensores.superficie[9];
		m[sensores.posF-3][sensores.posC+1] = sensores.superficie[10];
		m[sensores.posF-3][sensores.posC+2] = sensores.superficie[11];
		m[sensores.posF-3][sensores.posC+3] = sensores.superficie[12];
		m[sensores.posF-2][sensores.posC+3] = sensores.superficie[13];
		m[sensores.posF-1][sensores.posC+3] = sensores.superficie[14];
		m[sensores.posF][sensores.posC+3] = sensores.superficie[15];
		
		a[sensores.posF-1][sensores.posC] = sensores.cota[1];
		a[sensores.posF-1][sensores.posC+1] = sensores.cota[2];
		a[sensores.posF][sensores.posC+1] = sensores.cota[3];
		a[sensores.posF-2][sensores.posC] = sensores.cota[4];
		a[sensores.posF-2][sensores.posC+1] = sensores.cota[5];
		a[sensores.posF-2][sensores.posC+2] = sensores.cota[6];
		a[sensores.posF-1][sensores.posC+2] = sensores.cota[7];
		a[sensores.posF][sensores.posC+2] = sensores.cota[8];
		a[sensores.posF-3][sensores.posC] = sensores.cota[9];
		a[sensores.posF-3][sensores.posC+1] = sensores.cota[10];
		a[sensores.posF-3][sensores.posC+2] = sensores.cota[11];
		a[sensores.posF-3][sensores.posC+3] = sensores.cota[12];
		a[sensores.posF-2][sensores.posC+3] = sensores.cota[13];
		a[sensores.posF-1][sensores.posC+3] = sensores.cota[14];
		a[sensores.posF][sensores.posC+3] = sensores.cota[15];
	
		break;
	case este:
		m[sensores.posF-1][sensores.posC+1] = sensores.superficie[1];
		m[sensores.posF][sensores.posC+1] = sensores.superficie[2];
		m[sensores.posF+1][sensores.posC+1] = sensores.superficie[3];
		m[sensores.posF-2][sensores.posC+2] = sensores.superficie[4];
		m[sensores.posF-1][sensores.posC+2] = sensores.superficie[5];
		m[sensores.posF][sensores.posC+2] = sensores.superficie[6];
		m[sensores.posF+1][sensores.posC+2] = sensores.superficie[7];
		m[sensores.posF+2][sensores.posC+2] = sensores.superficie[8];
		m[sensores.posF-3][sensores.posC+3] = sensores.superficie[9];
		m[sensores.posF-2][sensores.posC+3] = sensores.superficie[10];
		m[sensores.posF-1][sensores.posC+3] = sensores.superficie[11];
		m[sensores.posF][sensores.posC+3] = sensores.superficie[12];
		m[sensores.posF+1][sensores.posC+3] = sensores.superficie[13];
		m[sensores.posF+2][sensores.posC+3] = sensores.superficie[14];
		m[sensores.posF+3][sensores.posC+3] = sensores.superficie[15];
		
		a[sensores.posF-1][sensores.posC+1] = sensores.cota[1];
		a[sensores.posF][sensores.posC+1] = sensores.cota[2];
		a[sensores.posF+1][sensores.posC+1] = sensores.cota[3];
		a[sensores.posF-2][sensores.posC+2] = sensores.cota[4];
		a[sensores.posF-1][sensores.posC+2] = sensores.cota[5];
		a[sensores.posF][sensores.posC+2] = sensores.cota[6];
		a[sensores.posF+1][sensores.posC+2] = sensores.cota[7];
		a[sensores.posF+2][sensores.posC+2] = sensores.cota[8];
		a[sensores.posF-3][sensores.posC+3] = sensores.cota[9];
		a[sensores.posF-2][sensores.posC+3] = sensores.cota[10];
		a[sensores.posF-1][sensores.posC+3] = sensores.cota[11];
		a[sensores.posF][sensores.posC+3] = sensores.cota[12];
		a[sensores.posF+1][sensores.posC+3] = sensores.cota[13];
		a[sensores.posF+2][sensores.posC+3] = sensores.cota[14];
		a[sensores.posF+3][sensores.posC+3] = sensores.cota[15];
		
		break;
	case sureste:
		m[sensores.posF][sensores.posC+1] = sensores.superficie[1];
		m[sensores.posF+1][sensores.posC+1] = sensores.superficie[2];
		m[sensores.posF+1][sensores.posC] = sensores.superficie[3];
		m[sensores.posF][sensores.posC+2] = sensores.superficie[4];
		m[sensores.posF+1][sensores.posC+2] = sensores.superficie[5];
		m[sensores.posF+2][sensores.posC+2] = sensores.superficie[6];
		m[sensores.posF+2][sensores.posC+1] = sensores.superficie[7];
		m[sensores.posF+2][sensores.posC] = sensores.superficie[8];
		m[sensores.posF][sensores.posC+3] = sensores.superficie[9];
		m[sensores.posF+1][sensores.posC+3] = sensores.superficie[10];
		m[sensores.posF+2][sensores.posC+3] = sensores.superficie[11];
		m[sensores.posF+3][sensores.posC+3] = sensores.superficie[12];
		m[sensores.posF+3][sensores.posC+2] = sensores.superficie[13];
		m[sensores.posF+3][sensores.posC+1] = sensores.superficie[14];
		m[sensores.posF+3][sensores.posC] = sensores.superficie[15];
		
		a[sensores.posF][sensores.posC+1] = sensores.cota[1];
		a[sensores.posF+1][sensores.posC+1] = sensores.cota[2];
		a[sensores.posF+1][sensores.posC] = sensores.cota[3];
		a[sensores.posF][sensores.posC+2] = sensores.cota[4];
		a[sensores.posF+1][sensores.posC+2] = sensores.cota[5];
		a[sensores.posF+2][sensores.posC+2] = sensores.cota[6];
		a[sensores.posF+2][sensores.posC+1] = sensores.cota[7];
		a[sensores.posF+2][sensores.posC] = sensores.cota[8];
		a[sensores.posF][sensores.posC+3] = sensores.cota[9];
		a[sensores.posF+1][sensores.posC+3] = sensores.cota[10];
		a[sensores.posF+2][sensores.posC+3] = sensores.cota[11];
		a[sensores.posF+3][sensores.posC+3] = sensores.cota[12];
		a[sensores.posF+3][sensores.posC+2] = sensores.cota[13];
		a[sensores.posF+3][sensores.posC+1] = sensores.cota[14];
		a[sensores.posF+3][sensores.posC] = sensores.cota[15];
	
		break;
	case sur:
		m[sensores.posF+1][sensores.posC+1] = sensores.superficie[1];
		m[sensores.posF+1][sensores.posC] = sensores.superficie[2];
		m[sensores.posF+1][sensores.posC-1] = sensores.superficie[3];
		m[sensores.posF+2][sensores.posC+2] = sensores.superficie[4];
		m[sensores.posF+2][sensores.posC+1] = sensores.superficie[5];
		m[sensores.posF+2][sensores.posC] = sensores.superficie[6];
		m[sensores.posF+2][sensores.posC-1] = sensores.superficie[7];
		m[sensores.posF+2][sensores.posC-2] = sensores.superficie[8];
		m[sensores.posF+3][sensores.posC+3] = sensores.superficie[9];
		m[sensores.posF+3][sensores.posC+2] = sensores.superficie[10];
		m[sensores.posF+3][sensores.posC+1] = sensores.superficie[11];
		m[sensores.posF+3][sensores.posC] = sensores.superficie[12];
		m[sensores.posF+3][sensores.posC-1] = sensores.superficie[13];
		m[sensores.posF+3][sensores.posC-2] = sensores.superficie[14];
		m[sensores.posF+3][sensores.posC-3] = sensores.superficie[15];
		
		a[sensores.posF+1][sensores.posC+1] = sensores.cota[1];
		a[sensores.posF+1][sensores.posC] = sensores.cota[2];
		a[sensores.posF+1][sensores.posC-1] = sensores.cota[3];
		a[sensores.posF+2][sensores.posC+2] = sensores.cota[4];
		a[sensores.posF+2][sensores.posC+1] = sensores.cota[5];
		a[sensores.posF+2][sensores.posC] = sensores.cota[6];
		a[sensores.posF+2][sensores.posC-1] = sensores.cota[7];
		a[sensores.posF+2][sensores.posC-2] = sensores.cota[8];
		a[sensores.posF+3][sensores.posC+3] = sensores.cota[9];
		a[sensores.posF+3][sensores.posC+2] = sensores.cota[10];
		a[sensores.posF+3][sensores.posC+1] = sensores.cota[11];
		a[sensores.posF+3][sensores.posC] = sensores.cota[12];
		a[sensores.posF+3][sensores.posC-1] = sensores.cota[13];
		a[sensores.posF+3][sensores.posC-2] = sensores.cota[14];
		a[sensores.posF+3][sensores.posC-3] = sensores.cota[15];
		
		break;
	case suroeste:
		m[sensores.posF+1][sensores.posC] = sensores.superficie[1];
		m[sensores.posF+1][sensores.posC-1] = sensores.superficie[2];
		m[sensores.posF][sensores.posC-1] = sensores.superficie[3];
		m[sensores.posF+2][sensores.posC] = sensores.superficie[4];
		m[sensores.posF+2][sensores.posC-1] = sensores.superficie[5];
		m[sensores.posF+2][sensores.posC-2] = sensores.superficie[6];
		m[sensores.posF+1][sensores.posC-2] = sensores.superficie[7];
		m[sensores.posF][sensores.posC-2] = sensores.superficie[8];
		m[sensores.posF+3][sensores.posC] = sensores.superficie[9];
		m[sensores.posF+3][sensores.posC-1] = sensores.superficie[10];
		m[sensores.posF+3][sensores.posC-2] = sensores.superficie[11];
		m[sensores.posF+3][sensores.posC-3] = sensores.superficie[12];
		m[sensores.posF+2][sensores.posC-3] = sensores.superficie[13];
		m[sensores.posF+1][sensores.posC-3] = sensores.superficie[14];
		m[sensores.posF][sensores.posC-3] = sensores.superficie[15];
		
		a[sensores.posF+1][sensores.posC] = sensores.cota[1];
		a[sensores.posF+1][sensores.posC-1] = sensores.cota[2];
		a[sensores.posF][sensores.posC-1] = sensores.cota[3];
		a[sensores.posF+2][sensores.posC] = sensores.cota[4];
		a[sensores.posF+2][sensores.posC-1] = sensores.cota[5];
		a[sensores.posF+2][sensores.posC-2] = sensores.cota[6];
		a[sensores.posF+1][sensores.posC-2] = sensores.cota[7];
		a[sensores.posF][sensores.posC-2] = sensores.cota[8];
		a[sensores.posF+3][sensores.posC] = sensores.cota[9];
		a[sensores.posF+3][sensores.posC-1] = sensores.cota[10];
		a[sensores.posF+3][sensores.posC-2] = sensores.cota[11];
		a[sensores.posF+3][sensores.posC-3] = sensores.cota[12];
		a[sensores.posF+2][sensores.posC-3] = sensores.cota[13];
		a[sensores.posF+1][sensores.posC-3] = sensores.cota[14];
		a[sensores.posF][sensores.posC-3] = sensores.cota[15];
		
		break;
	case oeste:
		m[sensores.posF+1][sensores.posC-1] = sensores.superficie[1];
		m[sensores.posF][sensores.posC-1] = sensores.superficie[2];
		m[sensores.posF-1][sensores.posC-1] = sensores.superficie[3];
		m[sensores.posF+2][sensores.posC-2] = sensores.superficie[4];
		m[sensores.posF+1][sensores.posC-2] = sensores.superficie[5];
		m[sensores.posF][sensores.posC-2] = sensores.superficie[6];
		m[sensores.posF-1][sensores.posC-2] = sensores.superficie[7];
		m[sensores.posF-2][sensores.posC-2] = sensores.superficie[8];
		m[sensores.posF+3][sensores.posC-3] = sensores.superficie[9];
		m[sensores.posF+2][sensores.posC-3] = sensores.superficie[10];
		m[sensores.posF+1][sensores.posC-3] = sensores.superficie[11];
		m[sensores.posF][sensores.posC-3] = sensores.superficie[12];
		m[sensores.posF-1][sensores.posC-3] = sensores.superficie[13];
		m[sensores.posF-2][sensores.posC-3] = sensores.superficie[14];
		m[sensores.posF-3][sensores.posC-3] = sensores.superficie[15];
		
		a[sensores.posF+1][sensores.posC-1] = sensores.cota[1];
		a[sensores.posF][sensores.posC-1] = sensores.cota[2];
		a[sensores.posF-1][sensores.posC-1] = sensores.cota[3];
		a[sensores.posF+2][sensores.posC-2] = sensores.cota[4];
		a[sensores.posF+1][sensores.posC-2] = sensores.cota[5];
		a[sensores.posF][sensores.posC-2] = sensores.cota[6];
		a[sensores.posF-1][sensores.posC-2] = sensores.cota[7];
		a[sensores.posF-2][sensores.posC-2] = sensores.cota[8];
		a[sensores.posF+3][sensores.posC-3] = sensores.cota[9];
		a[sensores.posF+2][sensores.posC-3] = sensores.cota[10];
		a[sensores.posF+1][sensores.posC-3] = sensores.cota[11];
		a[sensores.posF][sensores.posC-3] = sensores.cota[12];
		a[sensores.posF-1][sensores.posC-3] = sensores.cota[13];
		a[sensores.posF-2][sensores.posC-3] = sensores.cota[14];
		a[sensores.posF-3][sensores.posC-3] = sensores.cota[15];
		
		break;
	case noroeste:
		m[sensores.posF][sensores.posC-1] = sensores.superficie[1];
		m[sensores.posF-1][sensores.posC-1] = sensores.superficie[2];
		m[sensores.posF-1][sensores.posC] = sensores.superficie[3];
		m[sensores.posF][sensores.posC-2] = sensores.superficie[4];
		m[sensores.posF-1][sensores.posC-2] = sensores.superficie[5];
		m[sensores.posF-2][sensores.posC-2] = sensores.superficie[6];
		m[sensores.posF-2][sensores.posC-1] = sensores.superficie[7];
		m[sensores.posF-2][sensores.posC] = sensores.superficie[8];
		m[sensores.posF][sensores.posC-3] = sensores.superficie[9];
		m[sensores.posF-1][sensores.posC-3] = sensores.superficie[10];
		m[sensores.posF-2][sensores.posC-3] = sensores.superficie[11];
		m[sensores.posF-3][sensores.posC-3] = sensores.superficie[12];
		m[sensores.posF-3][sensores.posC-2] = sensores.superficie[13];
		m[sensores.posF-3][sensores.posC-1] = sensores.superficie[14];
		m[sensores.posF-3][sensores.posC] = sensores.superficie[15];
		
		a[sensores.posF][sensores.posC-1] = sensores.cota[1];
		a[sensores.posF-1][sensores.posC-1] = sensores.cota[2];
		a[sensores.posF-1][sensores.posC] = sensores.cota[3];
		a[sensores.posF][sensores.posC-2] = sensores.cota[4];
		a[sensores.posF-1][sensores.posC-2] = sensores.cota[5];
		a[sensores.posF-2][sensores.posC-2] = sensores.cota[6];
		a[sensores.posF-2][sensores.posC-1] = sensores.cota[7];
		a[sensores.posF-2][sensores.posC] = sensores.cota[8];
		a[sensores.posF][sensores.posC-3] = sensores.cota[9];
		a[sensores.posF-1][sensores.posC-3] = sensores.cota[10];
		a[sensores.posF-2][sensores.posC-3] = sensores.cota[11];
		a[sensores.posF-3][sensores.posC-3] = sensores.cota[12];
		a[sensores.posF-3][sensores.posC-2] = sensores.cota[13];
		a[sensores.posF-3][sensores.posC-1] = sensores.cota[14];
		a[sensores.posF-3][sensores.posC] = sensores.cota[15];
		
		break;
		
	default:
		break;

	}
} 

void DireccionesDesdeRumboR(const Orientacion &rumbo, int df[3], int dc[3]) {
    switch (rumbo) {
    case norte:
        df[0] = -1; dc[0] = -1;  // izq+frente
        df[1] = -1;  dc[1] = 0;  // frente
        df[2] = -1; dc[2] = 1;  // der+frente
        break;
    case noreste:
        df[0] = -1; dc[0] = 0;
        df[1] = -1;  dc[1] = 1;
        df[2] = 0; dc[2] = 1;  
        break;
    case este:
        df[0] = -1;  dc[0] = 1;
        df[1] = 0;  dc[1] = 1;
        df[2] = 1; dc[2] = 1;  
        break;
    case sureste:
        df[0] = 0;  dc[0] = 1;
        df[1] = 1;  dc[1] = 1;
        df[2] = 1; dc[2] = 0;  
        break;
    case sur:
        df[0] = 1;  dc[0] = 1;
        df[1] = 1;  dc[1] = 0;
        df[2] = 1; dc[2] = -1;  
        break;
    case suroeste:
        df[0] = 1;  dc[0] = 0;
        df[1] = 1; dc[1] = -1;
        df[2] = 0; dc[2] = -1;  
        break;
    case oeste:
        df[0] = 1;  dc[0] = -1;
        df[1] = 0; dc[1] = -1	;
        df[2] = -1; dc[2] = -1;  
        break;
    case noroeste:
        df[0] = 0; dc[0] = -1;
        df[1] = -1; dc[1] = -1;
        df[2] = -1; dc[2] = 0;  
        break;
}

}


// void CasillaMasDesconocidaR(char i, char c, char d,
//                                                     int fila, int col,
//                                                     const Orientacion &rumbo,
//                                                     const vector<vector<unsigned char>> &mapaResultado,
// 													bool desconocidos[3]) {
//     int df[5], dc[5];
//     DireccionesDesdeRumboR(rumbo, df, dc);

//     for (int k = 1; k < 4; k++) {
//         int nf = fila + df[k];
//         int nc = col + dc[k];
//         if (nf >= 0 && nf < mapaResultado.size() &&
//             nc >= 0 && nc < mapaResultado[0].size()) {
// 			desconocidos[k-1] = mapaResultado[nf][nc] == '?';
//         }
// 	}
// }



int CasillaMasDesconocidaR(char i, char c, char d,
							int fila, int col,
							const Orientacion &rumbo,
							const vector<vector<unsigned char>> &mapaResultado,
							int vi, int vc, int vd) {
	int desconocidos[3] = {0, 0, 0};
	int df[3], dc[3];

	//std::cout << "Desconozco-Visitas i: " << vi << " c: " << vc << " d: " << vd << "\n";
	
	DireccionesDesdeRumboR(rumbo, df, dc);
	int menor_visita = -1;
	
	int i_desconocidos = 0;
	for (int k = 0; k < 3; k++) {
		int nf = fila + df[k];
		int nc = col + dc[k];
		if (nf >= 0 && nf < mapaResultado.size() &&
		nc >= 0 && nc < mapaResultado[0].size()) {
			if (mapaResultado[nf][nc] == '?') {
				desconocidos[i_desconocidos] = 1;
			}
		}
		i_desconocidos++;
	}

	if (desconocidos[1] && vc == menor_visita) return 2; // Frente
	if (desconocidos[0] && vi == menor_visita) return 1; // Izquierda
	if (desconocidos[2] && vd == menor_visita) return 3; // Derecha
	return 0;
}



//=============================================================================================//

Action ComportamientoRescatador::ComportamientoRescatadorNivel_0(Sensores sensores)
{
    // Acción inicial por defecto
    Action accion = IDLE;

	//Actualizo variables de estado
	
	SituarSensorEnMapaR(mapaResultado, mapaCotas, sensores);
    if (sensores.superficie[0] == 'D') tiene_zapatillas = true;

	//Definicion comportamiento
	if (sensores.superficie[0] == 'X') {
		// Si hay un auxiliar delante, evitamos la colisión
		accion = IDLE;
	} else if (giro45Izq != 0)	//Estoy haciendo TURN_SL
	{
		accion = TURN_SR;
		giro45Izq--;
	} else if (sensores.agentes[2] == 'a')	//Llego al objetivo
	{
		accion = TURN_L;
	} else
	{
		char i = CasillaViableR(sensores.superficie[1], sensores.cota[1]-sensores.cota[0], tiene_zapatillas);
		char c = CasillaViableR(sensores.superficie[2], sensores.cota[2]-sensores.cota[0], tiene_zapatillas);
		char d = CasillaViableR(sensores.superficie[3], sensores.cota[3]-sensores.cota[0], tiene_zapatillas);

		int df[3], dc[3];
    	DireccionesDesdeRumboR(sensores.rumbo, df, dc);
		
		int vi = mapa_visitas[sensores.posF + df[0]][sensores.posC + dc[0]];	// Visitas Izquierda
		int vc = mapa_visitas[sensores.posF + df[1]][sensores.posC + dc[1]];	// Visitas Centro
		int vd = mapa_visitas[sensores.posF + df[2]][sensores.posC + dc[2]];	// Visitas Derecha

		
		

		int pos = VeoCasillaInteresanteR_N0(i, c, d, tiene_zapatillas, vi, vc, vd);
		switch(pos)
		{
		case 2:
			accion = WALK;
			mapa_visitas[sensores.posF][sensores.posC]++;
			break;
		case 1:
			giro45Izq = 1;
			accion = TURN_L;
			break;
		case 3:
			accion = TURN_SR;
			break;
		case 0:
		if (c == 'C' || c == 'D'){
			mapa_visitas[sensores.posF][sensores.posC]++;
				accion = WALK;
			} else accion = TURN_L;
			break;
		}
	}
	
	last_action = accion;
    return accion;
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_1(Sensores sensores)
{
    Action accion = IDLE;

    // Actualizo variables de estado
    mapa_visitas[sensores.posF][sensores.posC]++;
	std::cout << "Mapa " << mapa_visitas[sensores.posF][sensores.posC] << endl;
    SituarSensorEnMapaR(mapaResultado, mapaCotas, sensores);
    if (sensores.superficie[0] == 'D') tiene_zapatillas = true;
	
	//Definicion comportamiento
	if (sensores.agentes[2] == 'a') {
		// Si hay un auxiliar delante, evitamos la colisión
		accion = TURN_L;
	} else if (giro45Izq != 0)	//Estoy haciendo TURN_SL
	{
		accion = TURN_SR;
		giro45Izq--;
	} else
	{
		// Exploración reactiva: decidir por qué dirección avanzar
		char i = CasillaViableR(sensores.superficie[1], sensores.cota[1]-sensores.cota[0], tiene_zapatillas);
		char c = CasillaViableR(sensores.superficie[2], sensores.cota[2]-sensores.cota[0], tiene_zapatillas);
		char d = CasillaViableR(sensores.superficie[3], sensores.cota[3]-sensores.cota[0], tiene_zapatillas);
		
		int df[5], dc[5];
    	DireccionesDesdeRumboR(sensores.rumbo, df, dc);
		
		int vi = mapa_visitas[sensores.posF + df[1]][sensores.posC + dc[1]];	// Visitas Izquierda
		int vc = mapa_visitas[sensores.posF + df[2]][sensores.posC + dc[2]];	// Visitas Centro
		int vd = mapa_visitas[sensores.posF + df[3]][sensores.posC + dc[3]];	// Visitas Derecha

		int pos = CasillaMasDesconocidaR(i, c, d, sensores.posF, sensores.posC, sensores.rumbo, mapaResultado, vi, vc, vd);

		switch (pos) 
		{
		case 2:
			accion = WALK;
		    
		    break;
		case 1:
			giro45Izq = 1;
		    accion = TURN_L;
		    
		    break;
		case 3:
			accion = TURN_SR;
		    
		    break;
		case 0:
			// (char i, char c, char d, bool zap, int posF, int posC, int df[3], int dc[3], int vi, int vc, int vd)
		    int pos2 = VeoCasillaInteresanteR_N1(i, c, d, tiene_zapatillas, sensores.posF, sensores.posC, df, dc, vi, vc, vd);
		    
			switch(pos2)
			{
			case 2:
				accion = WALK;
				
				break;
			case 1:
				giro45Izq = 1;
				accion = TURN_L;
				
				break;
			case 3:
				accion = TURN_SR;
				
				break;
			case 0:
				accion = TURN_L;
				break;
			}
		    break;
		}
	}

    last_action = accion;
    return accion;
}


Action ComportamientoRescatador::ComportamientoRescatadorNivel_2(Sensores sensores)
{
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_3(Sensores sensores)
{
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_4(Sensores sensores)
{
}
