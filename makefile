# Mi asombroso Makefile

# (Objetivo) : (dependecias)
# 	(comando 1)
# 	(comando 2)

bin/proyecto.exe : src/main.cpp src/Grupo.cpp src/Materia.cpp src/Maestro.cpp 
	@echo Compilando codigo fuente.....
	g++ -o bin/proyecto $? -Iinclude

run: bin/proyecto.exe
	./bin/proyecto.exe

