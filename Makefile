# Flag de compilation conditionnel
ifdef MAP
CXXFLAGS += -DMAP
endif

# Nom de l'exécutable
trajets: build/main.o build/Catalogue.o build/ElemTrajet.o build/Trajet.o build/config.o build/TS.o build/TC.o
	g++ $(CXXFLAGS) -o trajets build/main.o build/Catalogue.o build/ElemTrajet.o build/Trajet.o build/config.o build/TS.o build/TC.o

# Compilation des fichiers objets
build/main.o: src/main.cpp include/Catalogue.h include/ElemTrajet.h include/Trajet.h include/config.h | build
	g++ $(CXXFLAGS) -c src/main.cpp -Iinclude -o build/main.o

build/Catalogue.o: src/Catalogue.cpp include/Catalogue.h include/ElemTrajet.h | build
	g++ $(CXXFLAGS) -c src/Catalogue.cpp -Iinclude -o build/Catalogue.o

build/ElemTrajet.o: src/ElemTrajet.cpp include/ElemTrajet.h include/Trajet.h | build
	g++ $(CXXFLAGS) -c src/ElemTrajet.cpp -Iinclude -o build/ElemTrajet.o

build/Trajet.o: src/Trajet.cpp include/Trajet.h | build
	g++ $(CXXFLAGS) -c src/Trajet.cpp -Iinclude -o build/Trajet.o

build/config.o: src/config.cpp include/config.h | build
	g++ $(CXXFLAGS) -c src/config.cpp -Iinclude -o build/config.o

build/TS.o: src/TS.cpp include/TS.h | build
	g++ $(CXXFLAGS) -c src/TS.cpp -Iinclude -o build/TS.o

build/TC.o: src/TC.cpp include/TC.h | build
	g++ $(CXXFLAGS) -c src/TC.cpp -Iinclude -o build/TC.o

# Création du dossier build
build:
	mkdir -p build

# Nettoyage
clean:
	rm -rf build trajets
