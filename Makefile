# Nom de l'exécutable
tp2: main.o Catalogue.o ElemTrajet.o Trajet.o functions.o
		g++ -o tp2 main.o Catalogue.o ElemTrajet.o Trajet.o functions.o

# Compilation des fichiers objets
main.o: main.cpp include/Catalogue.h include/ElemTrajet.h include/Trajet.h include/functions.h
		g++ -c main.cpp -Iinclude

Catalogue.o: src/Catalogue.cpp include/Catalogue.h include/ElemTrajet.h
		g++ -c src/Catalogue.cpp -Iinclude

ElemTrajet.o: src/ElemTrajet.cpp include/ElemTrajet.h include/Trajet.h
		g++ -c src/ElemTrajet.cpp -Iinclude

Trajet.o: src/Trajet.cpp include/Trajet.h
		g++ -c src/Trajet.cpp -Iinclude

functions.o: src/functions.cpp include/functions.h
		g++ -c src/functions.cpp -Iinclude

# Nettoyage
clean:
		rm -f *.o tp2
