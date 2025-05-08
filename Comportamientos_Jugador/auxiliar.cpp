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
		// accion = ComportamientoAuxiliarNivel_2 (sensores);
		break;
	case 3:
		// accion = ComportamientoAuxiliarNivel_3 (sensores);
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

int VeoCasillaInteresanteA_N0 (char i, char c, char d)
{
	if (c == 'X') return 2;
	else if (i == 'X') return 1;
	else if (d == 'X') return 3;
	else if (c == 'C') return 2;
	else if (i == 'C') return 1;
	else if (d == 'C') return 3;
	else return 0;
}

int VeoCasillaInteresanteA_N1 (char i, char c, char d, bool zap)
{
	if (!zap)
	{
		if (c == 'D') return 2;
		else if (i == 'D') return 1;
		else if (d == 'D') return 3;
	}
	if (c != 'M' && c != 'P')
	{
		if (!(!zap && c == 'B')) return 2;
	}
	else if (i != 'M' && i != 'P' && i != 'B')
	{
		if (!(!zap && c == 'B')) return 1;
	}
	else if (d != 'M' && d != 'P' && d != 'B')
	{
		if (!(!zap && c == 'B')) return 3;
	}
	else return 0;
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

void DireccionesDesdeRumboA(const Orientacion &rumbo, int df[3], int dc[3]) {
    if (rumbo == norte) {
        df[0] = 0; dc[0] = -1; // izq
        df[1] = -1; dc[1] = 0; // frente
        df[2] = 0; dc[2] = 1;  // der
    } else if (rumbo == noreste) {
        df[0] = -1; dc[0] = -1;
        df[1] = -1; dc[1] = 1;
        df[2] = 1; dc[2] = 1;
    } else if (rumbo == este) {
        df[0] = -1; dc[0] = 0;
        df[1] = 0; dc[1] = 1;
        df[2] = 1; dc[2] = 0;
    } else if (rumbo == sureste) {
        df[0] = -1; dc[0] = 1;
        df[1] = 1; dc[1] = 1;
        df[2] = 1; dc[2] = -1;
    } else if (rumbo == sur) { 
        df[0] = 0; dc[0] = 1;
        df[1] = 1; dc[1] = 0;
        df[2] = 0; dc[2] = -1;
    } else if (rumbo == suroeste) {
        df[0] = 1; dc[0] = 1;
        df[1] = 1; dc[1] = -1;
        df[2] = -1; dc[2] = -1;
    } else if (rumbo == oeste) {
        df[0] = 1; dc[0] = 0;
        df[1] = 0; dc[1] = -1;
        df[2] = -1; dc[2] = 0;
    } else if (rumbo == noroeste) {
        df[0] = 1; dc[0] = -1;
        df[1] = -1; dc[1] = -1;
        df[2] = -1; dc[2] = 1;
    }
}

int CasillaMasDesconocidaA(char i, char c, char d,
                                                    int fila, int col,
                                                    const Orientacion &rumbo,
                                                    const vector<vector<unsigned char>> &mapaResultado) {
    int desconocidos[3] = {0, 0, 0};
    int df[3], dc[3];
    DireccionesDesdeRumboA(rumbo, df, dc);

    for (int k = 0; k < 3; ++k) {
        int nf = fila + df[k];
        int nc = col + dc[k];
        if (nf >= 0 && nf < mapaResultado.size() &&
            nc >= 0 && nc < mapaResultado[0].size()) {
            if (mapaResultado[nf][nc] == '?') {
                desconocidos[k] = 1;
            }
        }
    }

    if (desconocidos[1]) return 2; // Frente
    if (desconocidos[0]) return 1; // Izquierda
    if (desconocidos[2]) return 3; // Derecha
    return 0;
}


//=====================================================================================//

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_0(Sensores sensores)
{
    // Acción inicial por defecto
    Action accion = IDLE;

	//Actualizo variables de estado
	SituarSensorEnMapaA(mapaResultado, mapaCotas, sensores);
    if (sensores.superficie[0] == 'D') tiene_zapatillas = true;
    
    //Tiene que girar a la izquierda
    if (girarIzq > 0)
    {
    	girarIzq--;
    	return TURN_SR;
    }

	//Definicion comportamiento
	if (sensores.agentes[2] == 'r') {
		// Si hay un auxiliar delante, evitamos la colisión
		accion = IDLE;
	} else if (sensores.superficie[0] == 'X')	//Llego al objetivo
	{
		accion = IDLE;
	} else if (giro45Izq != 0)	//Estoy haciendo TURN_SL
	{
		accion = TURN_SR;
		giro45Izq--;
	} else 
	{
		char i = CasillaViableA(sensores.superficie[1], sensores.cota[1]-sensores.cota[0]);
		char c = CasillaViableA(sensores.superficie[2], sensores.cota[2]-sensores.cota[0]);
		char d = CasillaViableA(sensores.superficie[3], sensores.cota[3]-sensores.cota[0]);
	
		int pos = VeoCasillaInteresanteA_N0(i, c, d);
		switch(pos)
		{
		case 2:
			accion = WALK;
			break;
		case 1:
			giro45Izq = 1;
			girarIzq = 5;
			accion = TURN_SR;
			break;
		case 3:
			accion = TURN_SR;
			break;
		case 0:
			girarIzq = 5;
			accion = TURN_SR;
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
    
    //Tiene que girar a la izquierda
    if (girarIzq > 0)
    {
    	girarIzq--;
    	return TURN_SR;
    }

	//Definicion comportamiento
	if (sensores.agentes[2] == 'r') {
		// Si hay un auxiliar delante, evitamos la colisión
		accion = IDLE;
	} else if (giro45Izq != 0)	//Estoy haciendo TURN_SL
	{
		accion = TURN_SR;
		giro45Izq--;
	} else 
	{
		char i = CasillaViableA(sensores.superficie[1], sensores.cota[1]-sensores.cota[0]);
		char c = CasillaViableA(sensores.superficie[2], sensores.cota[2]-sensores.cota[0]);
		char d = CasillaViableA(sensores.superficie[3], sensores.cota[3]-sensores.cota[0]);
	
		int pos = CasillaMasDesconocidaA(i, c, d, sensores.posF, sensores.posC, sensores.rumbo, mapaResultado);
		
		switch(pos)
		{
		case 2:
			accion = WALK;
			break;
		case 1:
			giro45Izq = 1;
			girarIzq = 5;
			accion = TURN_SR;
			break;
		case 3:
			accion = TURN_SR;
			break;
		case 0:
			int pos2 = VeoCasillaInteresanteA_N1(i, c, d, tiene_zapatillas);
		    
			switch(pos2)
			{
			case 2:
				accion = WALK;
				
				break;
			case 1:
				giro45Izq = 1;
				girarIzq = 5;
				accion = TURN_SR;
				break;
			case 3:
				accion = TURN_SR;
				
				break;
			case 0:
				girarIzq = 5;
				accion = TURN_SR;
				break;
			}
		    break;
		}
	}
	
	last_action = accion;
    return accion;
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_2(Sensores sensores)
{
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_3(Sensores sensores)
{
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_4(Sensores sensores)
{
}
