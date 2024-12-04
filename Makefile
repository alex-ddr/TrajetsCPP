# Nom de l'exécutable
tp2: build/main.o build/Catalogue.o build/ElemTrajet.o build/Trajet.o build/config.o
	g++ -o tp2 build/main.o build/Catalogue.o build/ElemTrajet.o build/Trajet.o build/config.o

# Compilation des fichiers objets
build/main.o: src/main.cpp include/Catalogue.h include/ElemTrajet.h include/Trajet.h include/config.h | build
	g++ -c src/main.cpp -Iinclude -o build/main.o

build/Catalogue.o: src/Catalogue.cpp include/Catalogue.h include/ElemTrajet.h | build
	g++ -c src/Catalogue.cpp -Iinclude -o build/Catalogue.o

build/ElemTrajet.o: src/ElemTrajet.cpp include/ElemTrajet.h include/Trajet.h | build
	g++ -c src/ElemTrajet.cpp -Iinclude -o build/ElemTrajet.o

build/Trajet.o: src/Trajet.cpp include/Trajet.h | build
	g++ -c src/Trajet.cpp -Iinclude -o build/Trajet.o

build/config.o: src/config.cpp include/config.h | build
	g++ -c src/config.cpp -Iinclude -o build/config.o

# Création du dossier build
build:
	mkdir -p build

# Nettoyage
clean:
	rm -rf build tp2