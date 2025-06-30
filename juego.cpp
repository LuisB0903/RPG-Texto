#include "juego.h"
#include <iostream>

void jugar(const std::vector<Dialogo>& dialogos) {
    int dialogoActual = 1;

    while (dialogoActual != -1) {
        const Dialogo* dialogo = encontrarDialogo(dialogos, dialogoActual);

        if (!dialogo) {
            std::cerr << "Error: Diálogo no encontrado con ID " << dialogoActual << std::endl;
            break;
        }

        std::cout << "\n[" << dialogo->personaje << "]\n";
        std::cout << dialogo->texto << "\n\n";

        if (dialogo->opciones.empty()) {
            std::cout << "(Presiona Enter para continuar...)" << std::endl;
            std::cin.ignore();
            std::cin.get();
            dialogoActual = -1;
        } else {
            for (size_t i = 0; i < dialogo->opciones.size(); ++i) {
                std::cout << i + 1 << ". " << dialogo->opciones[i].texto << std::endl;
            }

            int seleccion;
            std::cout << "\nElige una opción: ";
            std::cin >> seleccion;

            if (seleccion < 1 || seleccion > static_cast<int>(dialogo->opciones.size())) {
                std::cout << "Opción inválida. Intenta de nuevo." << std::endl;
                continue;
            }

            dialogoActual = dialogo->opciones[seleccion - 1].siguiente;
        }
    }

    std::cout << "\nFin de la historia. Gracias por jugar!" << std::endl;
}