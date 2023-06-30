#ifndef GRUPO_H
#define GRUPO_H

#include <string>
#include <vector>

class Grupo {
private:
    std::string nombre;
    std::vector<std::string> alumnos;

public:
    Grupo(const std::string& nombre);

    std::string getNombre() const;

    void agregarAlumno(const std::string& alumno);

    void mostrarAlumnos() const;
};

#endif
