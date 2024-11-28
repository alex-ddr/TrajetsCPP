# Nom de l'exécutable
tp2: build/main.o build/Catalogue.o build/ElemTrajet.o build/Trajet.o build/functions.o
	g++ -o tp2 build/main.o build/Catalogue.o build/ElemTrajet.o build/Trajet.o build/functions.o

# Compilation des fichiers objets
build/main.o: src/main.cpp include/Catalogue.h include/ElemTrajet.h include/Trajet.h include/functions.h | build
	g++ -c src/main.cpp -Iinclude -o build/main.o

build/Catalogue.o: src/Catalogue.cpp include/Catalogue.h include/ElemTrajet.h | build
	g++ -c src/Catalogue.cpp -Iinclude -o build/Catalogue.o

build/ElemTrajet.o: src/ElemTrajet.cpp include/ElemTrajet.h include/Trajet.h | build
	g++ -c src/ElemTrajet.cpp -Iinclude -o build/ElemTrajet.o

build/Trajet.o: src/Trajet.cpp include/Trajet.h | build
	g++ -c src/Trajet.cpp -Iinclude -o build/Trajet.o

build/functions.o: src/functions.cpp include/functions.h | build
	g++ -c src/functions.cpp -Iinclude -o build/functions.o

# Création du dossier build
build:
	mkdir -p build

# Nettoyage
clean:
	rm -rf build tp2