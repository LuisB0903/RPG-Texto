#include <iostream>
#include "dialogo.h"
#include "juego.h"

int main() {
    std::vector<Dialogo> dialogos = cargarDialogos("conversation.json");

    if (dialogos.empty()) {
        std::cerr << "No se pudieron cargar los diálogos. Saliendo..." << std::endl;
        return 1;
    }

    std::cout << "=== JUEGO NARRATIVO ===" << std::endl;
    jugar(dialogos);

    return 0;
}