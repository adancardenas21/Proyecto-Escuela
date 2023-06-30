#include <Grupo.h>
#include <iostream>

Grupo::Grupo(const std::string& nombre) : nombre(nombre) {}

std::string Grupo::getNombre() const {
    return nombre;
}

void Grupo::agregarAlumno(const std::string& alumno) {
    alumnos.push_back(alumno);
}

void Grupo::mostrarAlumnos() const {
    std::cout << "Lista de alumnos en el grupo " << nombre << ":" << std::endl;
    for (std::vector<std::string>::const_iterator it = alumnos.begin(); it != alumnos.end(); ++it) {
        std::cout << *it << std::endl;
    }
}
