#include <Materia.h>
#include <iostream>

Materia::Materia(const std::string& nombre) : nombre(nombre) {
    grupos.push_back(Grupo("A"));
    grupos.push_back(Grupo("B"));
}

std::string Materia::getNombre() const {
    return nombre;
}



void Materia::agregarMaestro(const Maestro& maestro) {
    maestros.push_back(maestro);
}

void Materia::agregarAlumno(const std::string& alumno, const std::string& nombreGrupo) {
    for (std::vector<Grupo>::iterator it = grupos.begin(); it != grupos.end(); ++it) {
        if (it->getNombre() == nombreGrupo) {
            it->agregarAlumno(alumno);
            break;
        }
    }
}

void Materia::mostrarGrupos() const {
    std::cout << "Grupos de la materia " << nombre << ":" << std::endl;
    for (std::vector<Grupo>::const_iterator it = grupos.begin(); it != grupos.end(); ++it) {
        std::cout << it->getNombre() << std::endl;
    }
}

void Materia::mostrarAlumnos() const {
    std::cout << "Lista de alumnos en la materia " << nombre << ":" << std::endl;
    for (std::vector<Grupo>::const_iterator it = grupos.begin(); it != grupos.end(); ++it) {
        std::cout << "Grupo " << it->getNombre() << ":" << std::endl;
        it->mostrarAlumnos();
    }
}

const std::vector<Grupo>& Materia::getGrupos() const {
    return grupos;
}

const std::vector<Maestro>& Materia::getMaestros() const {
    return maestros;
}
