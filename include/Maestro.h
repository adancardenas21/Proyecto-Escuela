#ifndef MAESTRO_H
#define MAESTRO_H

#include <string>

class Maestro {
private:
    std::string nombre;

public:
    Maestro(const std::string& nombre);

    std::string getNombre() const;
};

#endif
