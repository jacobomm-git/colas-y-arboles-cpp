# Cua FIFO de comandes

## Objectiu

Implementar una cua genèrica amb nodes enllaçats i aplicar-la a una llista de comandes. Cada entrada conté identificador, descripció, quantitat i hora.

## Compilar i executar

Des de la carpeta d'aquest exercici:

```bash
g++ -std=c++17 main.cpp Comanda.cpp -o pedidos
./pedidos
```

En Windows, utilitzeu `-o pedidos.exe` i `./pedidos.exe`. El fitxer `fichero.txt` ha de ser al directori de treball quan es carreguin les dades del menú.

## Estructura

`CuaEncadenada<T>` manté un node sentinella, un punter al principi i un al final. `enqueue` afegeix al final; `dequeue` elimina el primer element. L'ordre és FIFO.

```text
sentinella → primera comanda → segona comanda → última comanda
                                                  ↑ rear
```

Les insercions i extraccions no necessiten recórrer tots els nodes. Les còpies construeixen nodes propis per evitar que dos contenidors comparteixin la mateixa memòria.

## Verificació

El test del repositori comprova la cua buida, l'ordre de sortida, la reutilització després de buidar-la i la independència del constructor de còpia i de l'assignació. També s'ha provat el menú carregant les dades, llistant, retirant una comanda i sortint.
