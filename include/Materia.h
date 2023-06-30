#ifndef MATERIA_H
#define MATERIA_H

#include <string>
#include <vector>
#include <Maestro.h>
#include <Grupo.h>

class Materia {
private:
    std::string nombre;
    std::vector<Maestro> maestros;
    std::vector<Grupo> grupos;

public:
    Materia(const std::string& nombre);

    std::string getNombre() const;

    std::string setNombre() const;

    void agregarMaestro(const Maestro& maestro);

    void agregarAlumno(const std::string& alumno, const std::string& nombreGrupo);

    void mostrarGrupos() const;

    void mostrarAlumnos() const;

    const std::vector<Grupo>& getGrupos() const;

    const std::vector<Maestro>& getMaestros() const;
};

#endif
