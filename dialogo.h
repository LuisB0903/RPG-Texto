#pragma once
#include <string>
#include <vector>

struct Opcion {
    std::string texto;
    int siguiente;
};

struct Dialogo {
    int id;
    std::string personaje;
    std::string texto;
    std::vector<Opcion> opciones;
};

std::vector<Dialogo> cargarDialogos(const std::string& archivo);
const Dialogo* encontrarDialogo(const std::vector<Dialogo>& dialogos, int id);