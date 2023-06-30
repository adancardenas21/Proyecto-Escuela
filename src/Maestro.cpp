#include <Maestro.h>

Maestro::Maestro(const std::string& nombre) : nombre(nombre) {}

std::string Maestro::getNombre() const {
    return nombre;
}
