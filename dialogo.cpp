#include "dialogo.h"
#include <fstream>
#include <iostream>
#include "json.hpp"

using json = nlohmann::json;

std::vector<Dialogo> cargarDialogos(const std::string& archivo) {
    std::vector<Dialogo> dialogos;
    std::ifstream input(archivo);

    if (!input.is_open()) {
        std::cerr << "Error al abrir el archivo: " << archivo << std::endl;
        return dialogos;
    }

    json datos;
    input >> datos;

    for (const auto& dialogoJson : datos["dialogos"]) {
        Dialogo dialogo;
        dialogo.id = dialogoJson["id"];
        dialogo.personaje = dialogoJson["personaje"];
        dialogo.texto = dialogoJson["texto"];

        for (const auto& opcionJson : dialogoJson["opciones"]) {
            Opcion opcion;
            opcion.texto = opcionJson["texto"];
            opcion.siguiente = opcionJson["siguiente"];
            dialogo.opciones.push_back(opcion);
        }

        dialogos.push_back(dialogo);
    }

    return dialogos;
}

const Dialogo* encontrarDialogo(const std::vector<Dialogo>& dialogos, int id) {
    for (const auto& dialogo : dialogos) {
        if (dialogo.id == id) {
            return &dialogo;
        }
    }
    return nullptr;
}