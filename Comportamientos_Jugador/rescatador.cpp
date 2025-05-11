#include "../Comportamientos_Jugador/rescatador.hpp"
#include "motorlib/util.h"

using namespace std;

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
		accion = ComportamientoRescatadorNivel_2 (sensores);
		break;
	case 3:
		accion = ComportamientoRescatadorNivel_3 (sensores);
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

void DireccionesDesdeRumboR(const int &rumbo, int df[3], int dc[3]) {
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


// ------------------------ NIVEL 0 ----------------------------------------------------

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



// ------------------------ NIVEL 1 ----------------------------------------------------

int InteresCasillaR(char cas)
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

int VeoCasillaInteresanteR_N1 (char i, char c, char d, bool zap, int vi, int vc, int vd)
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
        InteresCasillaR(i),
        InteresCasillaR(c),
        InteresCasillaR(d)
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
	
	//std::cout << "Delante " << i << " " << c << " " << d << endl;
	//std::cout << "Transitables " << transitable[0] << " " << transitable[1] << " " << transitable[2] << endl;
	//std::cout << "Visitas " << vi << " " << vc << " " << vd << endl;
	//std::cout << "Intereses " << interes[0] << " " << interes[1] << " " << interes[2] << endl;
	//std::cout << "Eleccion " << eleccion[0] << " " << eleccion[1] << " " << eleccion[2] << endl << endl;
    
    if (eleccion[1] && visitas[1] == mejor_visita && interes[1] == mejor_interes) return 2;
	if (eleccion[0] && visitas[0] == mejor_visita && interes[0] == mejor_interes) return 1;
	if (eleccion[2] && visitas[2] == mejor_visita && interes[2] == mejor_interes) return 3;
    return 0; // Nada interesante
}




// ------------------------ NIVEL 2 ----------------------------------------------------

PosicionRescatador SiguienteCasillaR(const PosicionRescatador &pr)
{
	PosicionRescatador proximo = pr;
	int df[3], dc[3];
	DireccionesDesdeRumboR(pr.direccion, df, dc);
	
	proximo.fil = pr.fil + df[1];
	proximo.col = pr.col + dc[1];
	
	return proximo;
}


bool CasillaFactibleR(const PosicionRescatador &pr, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura, Action accion)
{
	PosicionRescatador siguiente = SiguienteCasillaR(pr);
	
	bool factible_casilla = false, factible_altura = false;
	
	factible_casilla = terreno[siguiente.fil][siguiente.col] != 'P' && 
						terreno[siguiente.fil][siguiente.col] != 'M' && 
						terreno[siguiente.fil][siguiente.col] != 'B';

	if (factible_casilla && accion == RUN)
	{	
		siguiente = SiguienteCasillaR(siguiente);		
		factible_casilla = terreno[siguiente.fil][siguiente.col] != 'P' && 
							terreno[siguiente.fil][siguiente.col] != 'M' && 
							terreno[siguiente.fil][siguiente.col] != 'B';
							
		factible_altura = (abs(altura[siguiente.fil][siguiente.col] - altura[pr.fil][pr.col]) <= 1 || 
						(abs(altura[siguiente.fil][siguiente.col] - altura[pr.fil][pr.col]) <=2 && pr.zapatillas));
						
		return factible_casilla && factible_altura;
	}

	factible_altura = (abs(altura[siguiente.fil][siguiente.col] - altura[pr.fil][pr.col]) <= 1 || 
					(abs(altura[siguiente.fil][siguiente.col] - altura[pr.fil][pr.col]) <=2 && pr.zapatillas));
	
	return factible_casilla && factible_altura;
}


int ObtenerCosteR(char tipo, int diferencia_altura, Action accion) 
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
        case RUN:
            if (tipo == 'A')      { base = 150; ajuste_altura = 15; }
            else if (tipo == 'T') { base = 35;  ajuste_altura = 5;  }
            else if (tipo == 'S') { base = 3;   ajuste_altura = 2;  }
            else                  { base = 1; }
            break;
        case TURN_L:
            if (tipo == 'A')      base = 30;
            else if (tipo == 'T') base = 5;
            else if (tipo == 'S') base = 1;
            else                  base = 1;
            break;
        case TURN_SR:
            if (tipo == 'A')      base = 16;
            else if (tipo == 'T') base = 3;
            else if (tipo == 'S') base = 1;
            else                  base = 1;
            break;
    }

    if (accion == WALK || accion == RUN) 
    {
        if (diferencia_altura > 0) base += ajuste_altura;
        else if (diferencia_altura < 0) base -= ajuste_altura;
    }

    return base;
}

int CalculoEnergiaR(const PosicionRescatador &actual, const PosicionRescatador &siguiente, 
					const vector<vector<unsigned char>> &terreno, 
					const vector<vector<unsigned char>> &altura, Action accion)
{
	char terreno_origen = terreno[actual.fil][actual.col];
	int altura_origen = altura[actual.fil][actual.col];
	int altura_destino = altura[siguiente.fil][siguiente.col];
	int diferencia = altura_destino - altura_origen;

	int energia = ObtenerCosteR(terreno_origen, diferencia, accion);
	return actual.coste_total + energia;
}


PosicionRescatador AplicarAccionR(const PosicionRescatador &pr, const vector<vector<unsigned char>> &terreno, const vector<vector<unsigned char>> &altura, Action accion)
{
	PosicionRescatador resultado = pr;
	
	if (accion == TURN_SR)
	{
		resultado.direccion = (resultado.direccion + 1) % 8;
	} else if (accion == TURN_L)
	{
		resultado.direccion = (resultado.direccion + 6) % 8;
	} else if (accion == WALK || accion == RUN)
	{
		if (CasillaFactibleR(pr, terreno, altura, accion))
		{
			resultado = SiguienteCasillaR(pr);
			if (accion == RUN) resultado = SiguienteCasillaR(resultado);
		}
	}
	
	resultado.coste_total = CalculoEnergiaR(pr, resultado, terreno, altura, accion);
	return resultado;
}


void ComportamientoRescatador::InterpretaPlan(const PosicionRescatador &pr, const list<Action> &plan)
{
	for (int i = 0; i < mapaConPlan[0].size(); i++)
		for (int j = 0; j < mapaConPlan.size(); j++)
			mapaConPlan[i][j] = 0;
			
	PosicionRescatador posicion = pr;
	
	for (Action accion : plan)
	{
		if (accion == WALK || accion == RUN)
		{
			int pasos = (accion == RUN) ? 2 : 1;
			for (int paso = 0; paso < pasos; paso++)
			{
				int df[3], dc[3];
    			DireccionesDesdeRumboR(posicion.direccion, df, dc);
    			
    			posicion.fil = posicion.fil + df[1];
    			posicion.col = posicion.col + dc[1];
			
				mapaConPlan[posicion.fil][posicion.col] = (accion == WALK) ? 1 : 3;
			}
		} else if (accion == TURN_SR)
		{
			posicion.direccion = (posicion.direccion + 1) % 8;
		} else if (accion == TURN_L)
		{
			posicion.direccion = (posicion.direccion + 6) % 8;
		}
	}
}



void ComportamientoRescatador::RepresentaPlan(const list<Action> &plan, bool zap)
{
	for (Action paso : plan) 
	{
		switch (paso) 
		{
		case WALK:     cout << "W "; break;
		case RUN:      cout << "R "; break;
		case TURN_SR:  cout << "r "; break;
		case TURN_L:   cout << "L "; break;
		case CALL_ON:  cout << "C "; break;
		case CALL_OFF: cout << "c "; break;
		case IDLE:     cout << "I "; break;
		default:       cout << "-_ "; break;
		}
	}

	cout << "(longitud: " << plan.size();
	if (zap) cout << " [Z]";
	cout << ")" << endl;
}



list<Action> PlanDijkstra(const PosicionRescatador &inicio, const PosicionRescatador &destino,
							const vector<vector<unsigned char>> &terreno,
							const vector<vector<unsigned char>> &altura) 
{
    priority_queue<NodoR> abiertos;
    map<PosicionRescatador, int> mejor_coste;

    NodoR nodo_actual;
    nodo_actual.estado = inicio;
    nodo_actual.estado.coste_total = 0;

    abiertos.push(nodo_actual);
    mejor_coste[inicio] = 0;

    while (!abiertos.empty()) 
    {

        nodo_actual = abiertos.top();
        abiertos.pop();

        const PosicionRescatador &estado_actual = nodo_actual.estado;

        // Comprobamos si hemos llegado al destino
        if (estado_actual.fil == destino.fil && estado_actual.col == destino.col) 
        {
            return nodo_actual.plan;  // Devuelve la secuencia de acciones
        }

        // Si ya tenemos una ruta mejor conocida para este estado, ignoramos esta
        if (mejor_coste.count(estado_actual) && 
        	estado_actual.coste_total > mejor_coste[estado_actual]) 
        {
            continue;
        }

        // Marcar que recogemos zapatillas si estamos en casilla 'D'
        PosicionRescatador estado_base = estado_actual;
        if (terreno[estado_base.fil][estado_base.col] == 'D') 
        {
            estado_base.zapatillas = true;
        }

        // Probar todas las acciones posibles desde este estado
        vector<Action> posibles = {WALK, RUN, TURN_L, TURN_SR};
        for (Action &accion : posibles) 
        {
            NodoR siguiente_nodo;
            siguiente_nodo.estado = AplicarAccionR(estado_base, terreno, altura, accion);
            siguiente_nodo.plan = nodo_actual.plan;
            siguiente_nodo.plan.push_back(accion);

            int nuevo_coste = siguiente_nodo.estado.coste_total;

            if (!mejor_coste.count(siguiente_nodo.estado) || nuevo_coste < mejor_coste[siguiente_nodo.estado]) 
            {
                mejor_coste[siguiente_nodo.estado] = nuevo_coste;
                abiertos.push(siguiente_nodo);
            }
        }
    }

    // Si no hay camino al destino, se devuelve vacío
    return {};
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

		i = (i != 'P' && sensores.agentes[1] != 'a') ? i : 'P';
		c = (c != 'P' && sensores.agentes[2] != 'a') ? c : 'P';
		d = (d != 'P' && sensores.agentes[3] != 'a') ? d : 'P';
		

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
    // Acción inicial por defecto
    Action accion = IDLE;

	//Actualizo variables de estado
	
	SituarSensorEnMapaR(mapaResultado, mapaCotas, sensores);
    if (sensores.superficie[0] == 'D') tiene_zapatillas = true;

	//Definicion comportamiento
	if (giro45Izq != 0)	//Estoy haciendo TURN_SL
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

		
		

		int pos = VeoCasillaInteresanteR_N1(i, c, d, tiene_zapatillas, vi, vc, vd);
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


Action ComportamientoRescatador::ComportamientoRescatadorNivel_2(Sensores sensores)
{
	Action accion = IDLE;

	// Recoge zapatillas si está encima de una
	if (sensores.superficie[0] == 'D') tiene_zapatillas = true;

	if (!tiene_plan) 
	{
		// Definir origen y destino con tu estructura
		PosicionRescatador origen, destino;
		origen.fil = sensores.posF;
		origen.col = sensores.posC;
		origen.direccion = sensores.rumbo;
		origen.zapatillas = tiene_zapatillas;
		origen.coste_total = 0;

		destino.fil = sensores.destinoF;
		destino.col = sensores.destinoC;

		// Ejecutar Dijkstra personalizado
		plan = PlanDijkstra(origen, destino, mapaResultado, mapaCotas);

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


Action ComportamientoRescatador::ComportamientoRescatadorNivel_3(Sensores sensores)
{
	Action accion = IDLE;

	return accion;
}

Action ComportamientoRescatador::ComportamientoRescatadorNivel_4(Sensores sensores)
{
}
