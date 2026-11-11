# Estructures de dades en C++

Dos exercicis seleccionats: una cua enl·laçada aplicada a comandes i un inventari indexat per data amb un arbre binari de cerca. El repositori inclou el codi, dades petites d'exemple i comprovacions dels casos principals.

| Exercici | Estructura | Aplicació |
| --- | --- | --- |
| [01 · Cua de comandes](01-cola-pedidos/README.md) | Cua FIFO genèrica amb nodes enllaçats | Processar comandes en l'ordre d'arribada. |
| [02 · Inventari BST](02-inventario-bst/README.md) | Arbre binari de cerca amb diversos valors per clau | Agrupar transaccions per data i consultar imports. |

## Relació amb l'administració de sistemes

Les cues ajuden a raonar sobre l'ordre de processament de tasques o esdeveniments. Els arbres permeten estudiar indexació, cerca i recorreguts sobre registres. La gestió de memòria, les còpies independents i els casos de contenidors buits també són útils per entendre el comportament de programes i eines de sistemes.

## Compilar les comprovacions

Cal un compilador compatible amb C++17. S'ha comprovat amb GCC sobre Windows.

```bash
mkdir -p build
g++ -std=c++17 -Wall -Wextra tests/test_estructuras.cpp -o build/test_estructuras
./build/test_estructuras tests/inventario.csv
```

En Windows es pot utilitzar `-o build/test_estructuras.exe` i executar `./build/test_estructuras.exe tests/inventario.csv`.

Les comprovacions cobreixen l'ordre FIFO, l'extracció en buit, les còpies independents, l'alçada i les fulles del BST, les claus repetides i el càlcul d'imports a partir d'un CSV sintètic.

## Preparació respecte de la pràctica

La versió publicada corregeix errors observats en els contenidors buits, la còpia i destrucció de nodes, el recorregut de fulles, l'alçada, un setter de data i la lectura de fitxers amb una línia final buida. Les correccions i els tests tenen un commit separat de la incorporació de cada exercici.

El BST no és equilibrat: l'ordre d'inserció pot produir un arbre amb alçada lineal. La versió AVL inacabada no forma part d'aquesta selecció. L'inventari conserva imports en `float` com a la pràctica, i no valida tots els formats possibles de dades d'entrada.

Vegeu [l'autoria i procedència](AUTORIA.md).
