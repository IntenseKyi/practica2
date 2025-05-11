#include "../Comportamientos_Jugador/auxiliar.hpp"
#include <iostream>
#include "motorlib/util.h"

Action ComportamientoAuxiliar::think(Sensores sensores)
{
	Action accion = IDLE;

	switch (sensores.nivel)
	{
	case 0:
		accion = ComportamientoAuxiliarNivel_0 (sensores);
		break;
	case 1:
		accion = ComportamientoAuxiliarNivel_1 (sensores);
		break;
	case 2:
		accion = ComportamientoAuxiliarNivel_2 (sensores);
		break;
	case 3:
		accion = ComportamientoAuxiliarNivel_3 (sensores);
		break;
	case 4:
		// accion = ComportamientoAuxiliarNivel_4 (sensores);
		break;
	}

	return accion;
}

int ComportamientoAuxiliar::interact(Action accion, int valor)
{
	return 0;
}


char CasillaViableA (char casilla, int dif)
{
	if (abs(dif)<=1)
		return casilla;
	else
		return 'P';
}


void SituarSensorEnMapaA(vector<vector<unsigned char>> &m, vector<vector<unsigned char>> &a, Sensores sensores)
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

void DireccionesDesdeRumboA(const int &rumbo, int df[5], int dc[5]) {
    switch (rumbo) {
    case norte:
        df[0] = 0;  dc[0] = -1; // izq
        df[1] = -1; dc[1] = -1;  // izq+frente
        df[2] = -1;  dc[2] = 0;  // frente
        df[3] = -1; dc[3] = 1;  // der+frente
        df[4] = 0;  dc[4] = 1;  // der
        break;
    case noreste:
        df[0] = -1; dc[0] = -1;
        df[1] = -1; dc[1] = 0;
        df[2] = -1;  dc[2] = 1;
        df[3] = 0; dc[3] = 1;  
        df[4] = 1;  dc[4] = 1;  
        break;
    case este:
        df[0] = -1; dc[0] = 0;
        df[1] = -1;  dc[1] = 1;
        df[2] = 0;  dc[2] = 1;
        df[3] = 1; dc[3] = 1;  
        df[4] = 1;  dc[4] = 0;  
        break;
    case sureste:
        df[0] = -1; dc[0] = 1;
        df[1] = 0;  dc[1] = 1;
        df[2] = 1;  dc[2] = 1;
        df[3] = 1; dc[3] = 0;  
        df[4] = 1;  dc[4] = -1;  
        break;
    case sur:
        df[0] = 0;  dc[0] = 1;
        df[1] = 1;  dc[1] = 1;
        df[2] = 1;  dc[2] = 0;
        df[3] = 1; dc[3] = -1;  
        df[4] = 0;  dc[4] = -1;  
        break;
    case suroeste:
        df[0] = 1;  dc[0] = 1;
        df[1] = 1;  dc[1] = 0;
        df[2] = 1; dc[2] = -1;
        df[3] = 0; dc[3] = -1;  
        df[4] = -1;  dc[4] = -1;  
        break;
    case oeste:
        df[0] = 1;  dc[0] = 0;
        df[1] = 1;  dc[1] = -1;
        df[2] = 0; dc[2] = -1	;
        df[3] = -1; dc[3] = -1;  
        df[4] = -1; dc[4] = 0;  
        break;
    case noroeste:
        df[0] = 1;  dc[0] = -1;
        df[1] = 0; dc[1] = -1;
        df[2] = -1; dc[2] = -1;
        df[3] = -1; dc[3] = 0;  
        df[4] = -1;  dc[4] = 1;  
        break;
}

}



// ------------------------ NIVEL 0 ----------------------------------------------------

int VeoCasillaInteresanteA_N0 (char i, char c, char d, bool zap, int vi, int vc, int vd)
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
    
    std::cout << "Delante " << i << " " << c << " " << d << endl;
	std::cout << "Visitas " << vi << " " << vc << " " << vd << endl;
	std::cout << "Menor visitas: " << mejor << endl;
	std::cout << "Opciones " << opcion[0] << " " << opcion[1] << " " << opcion[2] << endl << endl;


	if (opcion[1] && visitas[1] == mejor) return 2;
	if (opcion[0] && visitas[0] == mejor) return 1;
	if (opcion[2] && visitas[2] == mejor) return 3;
    return 0; // Nada interesante
}



// ------------------------ NIVEL 1 ----------------------------------------------------

int InteresCasillaA(char cas)
{
	int devuelve;
	switch(cas)
	{
	case 'C':
		devuelve = 0;
		break;
	case 'S':
	case 'D':
		devuelve = 1;
		break;
	default:
		devuelve = 2;
		break;
	}
	
	return devuelve;
}

int VeoCasillaInteresanteA_N1 (char i, char c, char d, bool zap, int vi, int vc, int vd)
{

    // Zapatillas y destino
    if (!zap) {
        if (c == 'D') return 2;
        if (i == 'D') return 1;
        if (d == 'D') return 3;
    }

    // 3. Casillas transitables
    bool transitable[3] = {false, false, false};
    if (i == 'C' || i == 'D' || i == 'S' || i == 'X') transitable[0] = true;
    if (c == 'C' || c == 'D' || c == 'S' || c == 'X') transitable[1] = true;
    if (d == 'C' || d == 'D' || d == 'S' || d == 'X') transitable[2] = true;
    
    int interes[3] = {
        InteresCasillaA(i),
        InteresCasillaA(c),
        InteresCasillaA(d)
    };

    // 4. Emparejar visitas con casillas
    int casillas[3] = {i, c, d};
    int visitas[3] = {vi, vc, vd};
    
    
    // Inicialización
    int mejor_interes = 3;
    int mejor_visita = 9999;
    
    bool eleccion[3] = {false, false, false};
    
    for (int k = 0; k < 3; ++k) {
        if (transitable[k])
        {
        	if (interes[k] <= mejor_interes)
        	{
        		if (visitas[k] <= mejor_visita)
        		{
        			mejor_interes = interes[k];
        			mejor_visita = visitas[k];
        		
        			eleccion[k] = true;
        		}
        	}
        
        
		}
    }
	
	std::cout << "Delante " << i << " " << c << " " << d << endl;
	std::cout << "Transitables " << transitable[0] << " " << transitable[1] << " " << transitable[2] << endl;
	std::cout << "Visitas " << vi << " " << vc << " " << vd << endl;
	std::cout << "Intereses " << interes[0] << " " << interes[1] << " " << interes[2] << endl;
	std::cout << "Eleccion " << eleccion[0] << " " << eleccion[1] << " " << eleccion[2] << endl;
	std::cout << "M.Visita " << mejor_visita << " M.Interes " << mejor_interes << endl << endl;
    
    if (eleccion[1] && visitas[1] == mejor_visita && interes[1] == mejor_interes) return 2;
	if (eleccion[0] && visitas[0] == mejor_visita && interes[0] == mejor_interes) return 1;
	if (eleccion[2] && visitas[2] == mejor_visita && interes[2] == mejor_interes) return 3;
    return 0; // Nada interesante
}


// ------------------------ NIVEL 3 ----------------------------------------------------

PosicionAuxiliar SiguienteCasillaA(const PosicionAuxiliar &pa)
{
	PosicionAuxiliar siguiente = pa;
	switch (pa.direccion)
	{
	case norte:
		if (pa.fil>0) siguiente.fil = pa.fil - 1;
		break;
	case noreste:
		if (pa.fil>0) siguiente.fil = pa.fil - 1;
		if (pa.col<99) siguiente.col = pa.col + 1;
		break;
	case este:
		if (pa.col<99) siguiente.col = pa.col + 1;
		break;
	case sureste:
		if (pa.fil<99) siguiente.fil = pa.fil + 1;
		if (pa.col<99) siguiente.col = pa.col + 1;
		break;
	case sur:
		if (pa.fil<99) siguiente.fil = pa.fil + 1;
		break;
	case suroeste:
		if (pa.fil<99) siguiente.fil = pa.fil + 1;
		if (pa.col>0) siguiente.col = pa.col - 1;
		break;
	case oeste:
		if (pa.col>0) siguiente.col = pa.col - 1;
		break;
	case noroeste:
		if (pa.fil>0) siguiente.fil = pa.fil - 1;
		if (pa.col>0) siguiente.col = pa.col - 1;
	}
	return siguiente;
}


bool CasillaFactibleA(const PosicionAuxiliar &pa, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura, Action accion)
{
	PosicionAuxiliar siguiente = SiguienteCasillaA(pa);
	
	bool factible_casilla = false, factible_zapatillas = false, factible_altura = false;
	
	factible_casilla = terreno[siguiente.fil][siguiente.col] != 'P' && 
						terreno[siguiente.fil][siguiente.col] != 'M';
						
	factible_zapatillas = terreno[siguiente.fil][siguiente.col] != 'B' || 
						(terreno[siguiente.fil][siguiente.col] == 'B' &&
						pa.zapatillas);

	factible_altura = (abs(altura[siguiente.fil][siguiente.col] - altura[pa.fil][pa.col]) <= 1 || 
					(abs(altura[siguiente.fil][siguiente.col] - altura[pa.fil][pa.col]) <=2 && pa.zapatillas));
	
	return factible_casilla && factible_zapatillas && factible_altura;
}


int ObtenerCosteA(char tipo, int diferencia_altura, Action accion) 
{
    int base = 0, ajuste_altura = 0;

    switch (accion) 
    {
        case WALK:
            if (tipo == 'A')      { base = 100; ajuste_altura = 10; }
            else if (tipo == 'T') { base = 20;  ajuste_altura = 5;  }
            else if (tipo == 'S') { base = 2;   ajuste_altura = 1;  }
            else                  { base = 1; }
            break;
        case TURN_SR:
            if (tipo == 'A')      base = 16;
            else if (tipo == 'T') base = 3;
            else if (tipo == 'S') base = 1;
            else                  base = 1;
            break;
    }

    if (accion == WALK) 
    {
        if (diferencia_altura > 0) base += ajuste_altura;
        else if (diferencia_altura < 0) base -= ajuste_altura;
    }

    return base;
}


int CalculoEnergiaA(const PosicionAuxiliar &actual, const PosicionAuxiliar &siguiente, 
					const vector<vector<unsigned char>> &terreno, 
					const vector<vector<unsigned char>> &altura, Action accion)
{
	char terreno_origen = terreno[actual.fil][actual.col];
	int altura_origen = altura[actual.fil][actual.col];
	int altura_destino = altura[siguiente.fil][siguiente.col];
	int diferencia = altura_destino - altura_origen;

	int energia = ObtenerCosteA(terreno_origen, diferencia, accion);
	return actual.coste_total + energia;
}


PosicionAuxiliar AplicarAccionA(const PosicionAuxiliar &pa, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura, Action accion)
{
	PosicionAuxiliar resultado = pa;
	
	if (accion == TURN_SR)
	{
		resultado.direccion = (resultado.direccion + 1) % 8;
	} else if (accion == WALK)
	{
		if (CasillaFactibleA(pa, terreno, altura, accion))
		{
			resultado = SiguienteCasillaA(pa);
		}
	}
	
	if (resultado.fil < 0 || resultado.fil >= 100 ||
		resultado.col < 0 || resultado.col >= 100) {
		resultado.coste_total = 999999; // costazo para descartarlo
		return resultado;
	}
	
	
	resultado.coste_total = CalculoEnergiaA(pa, resultado, terreno, altura, accion);
	return resultado;
}


void ComportamientoAuxiliar::InterpretaPlan(const PosicionAuxiliar &pa, const list<Action> &plan)
{
	for (int i = 0; i < mapaConPlan[0].size(); i++)
		for (int j = 0; j < mapaConPlan.size(); j++)
			mapaConPlan[i][j] = 0;
			
	PosicionAuxiliar posicion = pa;
	
	for (Action accion : plan)
	{
		if (accion == WALK)
		{
			int df[3], dc[3];
			DireccionesDesdeRumboA(posicion.direccion, df, dc);
			
			posicion.fil = posicion.fil + df[1];
			posicion.col = posicion.col + dc[1];
		
			if (posicion.fil >= 0 && posicion.fil < mapaConPlan.size() &&
				posicion.col >= 0 && posicion.col < mapaConPlan[0].size()) {
				mapaConPlan[posicion.fil][posicion.col] = 2;
			}
		
		} else if (accion == TURN_SR)
		{
			posicion.direccion = (posicion.direccion + 1) % 8;
		}
	}
}

int HeuristicaA(const PosicionAuxiliar &origen, const PosicionAuxiliar &destino)
{
    int dist_manhattan = abs(origen.fil - destino.fil) + abs(origen.col - destino.col);

    // Cálculo de la dirección objetivo
    int df = destino.fil - origen.fil;
    int dc = destino.col - origen.col;

    int direccion_deseada = origen.direccion;

    if (df < 0 && dc == 0) direccion_deseada = norte;
    else if (df < 0 && dc > 0) direccion_deseada = noreste;
    else if (df == 0 && dc > 0) direccion_deseada = este;
    else if (df > 0 && dc > 0) direccion_deseada = sureste;
    else if (df > 0 && dc == 0) direccion_deseada = sur;
    else if (df > 0 && dc < 0) direccion_deseada = suroeste;
    else if (df == 0 && dc < 0) direccion_deseada = oeste;
    else if (df < 0 && dc < 0) direccion_deseada = noroeste;

    int giros_necesarios = (8 + direccion_deseada - origen.direccion) % 8;
    int penalizacion_giros = giros_necesarios * 1;  // Peso por cada giro

    return dist_manhattan + penalizacion_giros;
}


list<Action> BusquedaA(const PosicionAuxiliar &inicio, const PosicionAuxiliar &destino,
                             const vector<vector<unsigned char>> &terreno,
                             const vector<vector<unsigned char>> &altura)
{
    priority_queue<NodoA> frontera;
    map<PosicionAuxiliar, int> coste_acumulado;

    NodoA nodo_inicial;
    nodo_inicial.estado = inicio;
    nodo_inicial.estado.coste_total = 0;
    nodo_inicial.estado.estimacion = HeuristicaA(inicio, destino);

    frontera.push(nodo_inicial);
    coste_acumulado[inicio] = 0;

    while (!frontera.empty())
    {
        NodoA actual = frontera.top();
        frontera.pop();

        const PosicionAuxiliar &pos_actual = actual.estado;

        if (pos_actual.fil == destino.fil && pos_actual.col == destino.col)
        {
            return actual.plan;
        }

        if (coste_acumulado.count(pos_actual) && pos_actual.coste_total > coste_acumulado[pos_actual])
        {
            continue;
        }

        PosicionAuxiliar base = pos_actual;
        
        if (base.fil >= 0 && base.fil < terreno.size() &&
			base.col >= 0 && base.col < terreno[0].size() &&
			terreno[base.fil][base.col] == 'D') {
			base.zapatillas = true;
		}

        vector<Action> acciones = {WALK, TURN_SR};
        for (const Action &accion : acciones)
        {
            NodoA sucesor;
            sucesor.estado = AplicarAccionA(base, terreno, altura, accion);
            int nuevo_coste = sucesor.estado.coste_total;

            if (!coste_acumulado.count(sucesor.estado) || nuevo_coste < coste_acumulado[sucesor.estado])
            {
                coste_acumulado[sucesor.estado] = nuevo_coste;
                sucesor.plan = actual.plan;
                sucesor.plan.push_back(accion);
                sucesor.estado.estimacion = nuevo_coste + HeuristicaA(sucesor.estado, destino);
                frontera.push(sucesor);
            }
        }
    }

    return {};  // No se encontró camino posible
}





//=====================================================================================//

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_0(Sensores sensores)
{
    // Acción inicial por defecto
    Action accion = IDLE;

	//Actualizo variables de estado
	SituarSensorEnMapaA(mapaResultado, mapaCotas, sensores);
    if (sensores.superficie[0] == 'D') tiene_zapatillas = true;
    

	//Definicion comportamiento
	if (sensores.superficie[0] == 'X') {
		// Si hay un auxiliar delante, evitamos la colisión
		accion = IDLE;
	} else if (girosDcha != 0)	//Estoy haciendo TURN_SL
	{
		accion = TURN_SR;
		girosDcha--;
	} else if (sensores.agentes[2] == 'r')	//Llego al objetivo
	{
		girosDcha = 3;
		accion = TURN_SR;
	} else 
	{
		char i = CasillaViableA(sensores.superficie[1], sensores.cota[1]-sensores.cota[0]);
		char c = CasillaViableA(sensores.superficie[2], sensores.cota[2]-sensores.cota[0]);
		char d = CasillaViableA(sensores.superficie[3], sensores.cota[3]-sensores.cota[0]);
	
		int df[5], dc[5];
    	DireccionesDesdeRumboA(sensores.rumbo, df, dc);
		
		int vi = mapa_visitas[sensores.posF + df[1]][sensores.posC + dc[1]];	// Visitas Izquierda
		int vc = mapa_visitas[sensores.posF + df[2]][sensores.posC + dc[2]];	// Visitas Centro
		int vd = mapa_visitas[sensores.posF + df[3]][sensores.posC + dc[3]];	// Visitas Derecha

		
		i = (i != 'P' && sensores.agentes[1] != 'r') ? i : 'P';
		c = (c != 'P' && sensores.agentes[2] != 'r') ? c : 'P';
		d = (d != 'P' && sensores.agentes[3] != 'r') ? d : 'P';


		int pos = VeoCasillaInteresanteA_N0(i, c, d, tiene_zapatillas, vi, vc, vd);
		switch(pos)
		{
		case 2:
			mapa_visitas[sensores.posF][sensores.posC]++;
			accion = WALK;
			break;
		case 1:
			girosDcha = 6;
			accion = TURN_SR;
			break;
		case 3:
			accion = TURN_SR;
			break;
		case 0:
			if (c == 'C' || c == 'D'){
				mapa_visitas[sensores.posF][sensores.posC]++;
				accion = WALK;
			}
			else accion = TURN_SR;
			break;
		}
	}
	
	last_action = accion;
    return accion;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_1(Sensores sensores)
{
	// Acción inicial por defecto
    Action accion = IDLE;

	//Actualizo variables de estado
	SituarSensorEnMapaA(mapaResultado, mapaCotas, sensores);
    if (sensores.superficie[0] == 'D') tiene_zapatillas = true;
    

	//Definicion comportamiento
	if (girosDcha != 0)	//Estoy haciendo TURN_SL
	{
		accion = TURN_SR;
		girosDcha--;
	} else if (sensores.agentes[2] == 'r')	//Llego al objetivo
	{
		girosDcha = 1;
		accion = TURN_SR;
	} else 
	{
		char i = CasillaViableA(sensores.superficie[1], sensores.cota[1]-sensores.cota[0]);
		char c = CasillaViableA(sensores.superficie[2], sensores.cota[2]-sensores.cota[0]);
		char d = CasillaViableA(sensores.superficie[3], sensores.cota[3]-sensores.cota[0]);
	
		int df[5], dc[5];
    	DireccionesDesdeRumboA(sensores.rumbo, df, dc);
		
		int vi = mapa_visitas[sensores.posF + df[1]][sensores.posC + dc[1]];	// Visitas Izquierda
		int vc = mapa_visitas[sensores.posF + df[2]][sensores.posC + dc[2]];	// Visitas Centro
		int vd = mapa_visitas[sensores.posF + df[3]][sensores.posC + dc[3]];	// Visitas Derecha

		int pos = VeoCasillaInteresanteA_N1(i, c, d, tiene_zapatillas, vi, vc, vd);
		switch(pos)
		{
		case 2:
			mapa_visitas[sensores.posF][sensores.posC]++;
			accion = WALK;
			break;
		case 1:
			girosDcha = 6;
			accion = TURN_SR;
			break;
		case 3:
			accion = TURN_SR;
			break;
		case 0:
			if (c == 'C' || c == 'D'){
				mapa_visitas[sensores.posF][sensores.posC]++;
				accion = WALK;
			}
			else accion = TURN_SR;
			break;
		}
	}
	
	last_action = accion;
    return accion;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_2(Sensores sensores)
{
	Action accion = IDLE;

	return accion;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_3(Sensores sensores)
{
	Action accion = IDLE;

	// Recoge zapatillas si está encima de una
	if (sensores.superficie[0] == 'D') tiene_zapatillas = true;

	if (!tiene_plan) 
	{
		// Definir origen y destino con tu estructura
		PosicionAuxiliar origen, destino;
		origen.fil = sensores.posF;
		origen.col = sensores.posC;
		origen.direccion = sensores.rumbo;
		origen.zapatillas = tiene_zapatillas;
		origen.coste_total = 0;

		destino.fil = sensores.destinoF;
		destino.col = sensores.destinoC;

		// Ejecutar Busqueda de A* personalizado
		plan = BusquedaA(origen, destino, mapaResultado, mapaCotas);

		// Visualizar si es necesario (ajustar nombre si la función cambió)
		InterpretaPlan(origen, plan);  // <- si renombraste la función de pintar mapa
		tiene_plan = true;
	}

	// Ejecutar el plan paso a paso
	if (tiene_plan && !plan.empty()) {
		accion = plan.front();
		plan.pop_front();
	}

	// Si acabó el plan, volver a planear
	if (plan.empty()) {
		tiene_plan = false;
	}

	return accion;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_4(Sensores sensores)
{
}
