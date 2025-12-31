#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Define las estructuras de datos para mayor claridad
typedef vector<pair<int,int>> ResultadosPartido;
typedef vector<ResultadosPartido> MatrizResultados;

// Estructura para representar a un equipo con estadísticas relevantes
struct Equipo {
    int id;             // ID del equipo
    int puntos;         // Puntos totales obtenidos
    int golesAFavor;    // Total de goles marcados
    int golesEnContra;  // Total de goles recibidos
};

// Función para leer los resultados de los partidos en la matriz
void leerMatrizResultados(MatrizResultados& matriz) {
    int numEquipos = matriz.size();
    for (int i = 0; i < numEquipos; ++i) {
        for (int j = 0; j < numEquipos; ++j) {
            cin >> matriz[i][j].first;     // Gol a favor del equipo i
            cin >> matriz[i][j].second;    // Gol a favor del equipo j
        }
    }
}

// Función para calcular las estadísticas y posiciones de los equipos
vector<Equipo> calcularPosiciones(const MatrizResultados& matriz) {
    int numEquipos = matriz.size();
    vector<Equipo> posiciones(numEquipos);
    
    // Inicializa los IDs de los equipos
    for (int i = 0; i < numEquipos; ++i) 
        posiciones[i].id = i + 1;
    
    // Calcula las estadísticas de los equipos
    for (int i = 0; i < numEquipos; ++i) {
        for (int j = 0; j < numEquipos; ++j) {
            if (i != j) {
                // Actualiza los puntos
                if(matriz[i][j].first > matriz[i][j].second) 
                    posiciones[i].puntos += 3;
                else if (matriz[i][j].first == matriz[i][j].second) 
                    posiciones[i].puntos += 1;
                
                // Actualiza los goles a favor y en contra
                posiciones[i].golesAFavor += matriz[i][j].first;
                posiciones[i].golesEnContra += matriz[i][j].second;
            }
        }
    }

    // Finaliza las posiciones
    for (int j = 0; j < numEquipos; ++j) {
        for (int i = 0; i < numEquipos; ++i) {
            if (i != j) {
                // Actualiza los puntos para los partidos como visitante
                if(matriz[i][j].second > matriz[i][j].first) 
                    posiciones[j].puntos += 3;
                else if (matriz[i][j].first == matriz[i][j].second) 
                    posiciones[j].puntos += 1;
                
                // Actualiza los goles a favor y en contra para los partidos como visitante
                posiciones[j].golesAFavor += matriz[i][j].second;
                posiciones[j].golesEnContra += matriz[i][j].first;
            }
        }
    }
    return posiciones;
}

// Función de comparación para ordenar los equipos según puntos, diferencia de goles e ID de equipo
bool compararEquipos(Equipo equipo1, Equipo equipo2) {
    if (equipo1.puntos == equipo2.puntos) {
        if ((equipo1.golesAFavor - equipo1.golesEnContra) == (equipo2.golesAFavor - equipo2.golesEnContra)) 
            return equipo1.id < equipo2.id;
        else 
            return (equipo1.golesAFavor - equipo1.golesEnContra) > (equipo2.golesAFavor - equipo2.golesEnContra);
    }
    else 
        return equipo1.puntos > equipo2.puntos;
}

// Función para escribir las posiciones finales
void escribirPosiciones(const vector<Equipo>& posiciones) {
    int numEquipos = posiciones.size();
    for(int i = 0; i < numEquipos; ++i) {
        cout << posiciones[i].id << " ";
        cout << posiciones[i].puntos << " ";
        cout << posiciones[i].golesAFavor << " ";
        cout << posiciones[i].golesEnContra << endl;
    }
}

// Función principal para orquestar el proceso
int main() {
    int numEquipos;
    cin >> numEquipos;
    
    MatrizResultados resultadosPartidos(numEquipos, ResultadosPartido(numEquipos));
    leerMatrizResultados(resultadosPartidos);
    
    vector<Equipo> posiciones = calcularPosiciones(resultadosPartidos);
    sort(posiciones.begin(), posiciones.end(), compararEquipos);
    
    escribirPosiciones(posiciones);
    
}
