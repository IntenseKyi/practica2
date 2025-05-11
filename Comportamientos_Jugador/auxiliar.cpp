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

void DireccionesDesdeRumboA(const Orientacion &rumbo, int df[5], int dc[5]) {
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
}

Action ComportamientoAuxiliar::ComportamientoAuxiliarNivel_4(Sensores sensores)
{
}
