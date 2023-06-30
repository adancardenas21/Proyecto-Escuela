#include <iostream>
#include <string>
#include <vector>
#include <Materia.h>
#include <Maestro.h>

int main() {
    std::vector<Materia> materias;
    std::vector<Maestro> maestros;

    int opcion = 0;
    while (opcion != 6) {
        std::cout << "----- MENU ----- " << std::endl;
        std::cout << "1. Registrar materia" << std::endl;
        std::cout << "2. Registrar profesor" << std::endl;
        std::cout << "3. Registrar alumnos" << std::endl;
        std::cout << "4. Mostrar informaci�n" << std::endl;
        std::cout << "5. Modificar materia" <<std::endl;
        std::cout << "6. Salir" << std::endl;
        std::cout << "Seleccione una opci�n: ";
        std::cin >> opcion;
        std::cin.ignore();

        switch (opcion) {
            case 1: {
                // Registro de materia
                std::string nombreMateria;
                std::cout << "Ingrese el nombre de la materia: ";
                std::getline(std::cin, nombreMateria);

                Materia materia(nombreMateria);
                materias.push_back(materia);

                std::cout << "Materia registrada exitosamente." << std::endl;
                break;
            }
            case 2: {
                // Registro de profesor
                if (materias.empty()) {
                    std::cout << "No hay materias registradas. Registre una materia primero." << std::endl;
                    break;
                }

                std::string nombreProfesor;
                std::cout << "Ingrese el nombre del profesor: ";
                std::getline(std::cin, nombreProfesor);

                Maestro profesor(nombreProfesor);
                maestros.push_back(profesor);

                std::cout << "Materias disponibles:" << std::endl;
                for (size_t i = 0; i < materias.size(); ++i) {
                    std::cout << i + 1 << ". " << materias[i].getNombre() << std::endl;
                }

                int opcionMateria = 0;
                std::cout << "Seleccione la materia a la que pertenece el profesor: ";
                std::cin >> opcionMateria;
                std::cin.ignore();

                if (opcionMateria >= 1 && opcionMateria <= materias.size()) {
                    Materia& materia = materias[opcionMateria - 1];
                    materia.agregarMaestro(profesor);

                    std::cout << "Profesor registrado exitosamente en la materia " << materia.getNombre() << "." << std::endl;
                } else {
                    std::cout << "Opci�n de materia inv�lida." << std::endl;
                }
                break;
            }
            case 3: {
                // Registro de alumnos
                if (materias.empty()) {
                    std::cout << "No hay materias registradas. Registre una materia primero." << std::endl;
                    break;
                }

                std::string nombreAlumno;
                std::cout << "Ingrese el nombre del alumno: ";
                std::getline(std::cin, nombreAlumno);

                std::cout << "Materias disponibles:" << std::endl;
                for (size_t i = 0; i < materias.size(); ++i) {
                    std::cout << i + 1 << ". " << materias[i].getNombre() << std::endl;
                }

                int opcionMateria = 0;
                std::cout << "Seleccione la materia a la que pertenece el alumno: ";
                std::cin >> opcionMateria;
                std::cin.ignore();

                if (opcionMateria >= 1 && opcionMateria <= materias.size()) {
                    Materia& materia = materias[opcionMateria - 1];

                    std::cout << "Grupos disponibles de la materia " << materia.getNombre() << ":" << std::endl;
                    materia.mostrarGrupos();

                    int opcionGrupo = 0;
                    std::cout << "Seleccione el grupo al que pertenece el alumno (A/B): ";
                    char grupo;
                    std::cin >> grupo;
                    std::cin.ignore();

                    if (grupo == 'A' || grupo == 'B') {
                        std::string nombreGrupo(1, grupo);
                        materia.agregarAlumno(nombreAlumno, nombreGrupo);
                        std::cout << "Alumno registrado exitosamente en el grupo " << nombreGrupo << " de la materia " << materia.getNombre() << "." << std::endl;
                    } else {
                        std::cout << "Opci�n de grupo inv�lida." << std::endl;
                    }
                } else {
                    std::cout << "Opci�n de materia inv�lida." << std::endl;
                }
                break;
            }
            case 4: {
                // Mostrar informaci�n
                std::cout << "Informaci�n de la escuela:" << std::endl;
                for (std::vector<Materia>::const_iterator itMateria = materias.begin(); itMateria != materias.end(); ++itMateria) {
                    std::cout << "Materia: " << itMateria->getNombre() << std::endl;
                    std::cout << "Profesores: ";
                    const std::vector<Maestro>& profesores = itMateria->getMaestros();
                    for (std::vector<Maestro>::const_iterator itProfesor = profesores.begin(); itProfesor != profesores.end(); ++itProfesor) {
                        std::cout << itProfesor->getNombre() << " ";
                    }
                    std::cout << std::endl;

                    itMateria->mostrarAlumnos();

                    std::cout << std::endl;
                }
                break;
            }
            case 5: {
                std::string nombreMateria;
                std::cout << "Ingrese el nombre de la materia: "<<std::endl;               
                std::getline(std::cin, nombreMateria);

                for (Materia& materia : materias) {
                    if (materia.getNombre() == nombreMateria) {
                        std::string nombreMateria;
                        std::cout << "Ingrese el nuevo nombre de la materia: ";
                        std::getline(std::cin, nombreMateria);

                          Materia materia(nombreMateria);
                      materias.push_back(materia);




                          
                        std::cout << "Nombre de la materia modificado correctamente." << std::endl;
                        break;

                    }
            }
}
            case 6:
                std::cout << "Saliendo del programa..." << std::endl;
                break;
            default:
                std::cout << "Opci�n inv�lida. Intente nuevamente." << std::endl;
                break;
        
    }

    return 0;
}
}

