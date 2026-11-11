# Inventari amb arbre binari de cerca

## Objectiu

Carregar transaccions de productes i agrupar-les per data en un BST. Cada node associa una data a una llista de paquets, cosa que permet representar diverses transaccions del mateix dia.

## Compilar i executar

Des de la carpeta de l'exercici:

```bash
g++ -std=c++17 main.cpp -o inventario
./inventario
```

En Windows, utilitzeu `-o inventario.exe` i `./inventario.exe`.

El programa inicia un cas de prova amb `transaccions_cas_de_prova.txt`. L'opció 1 del menú permet carregar aquest mateix fitxer a l'inventari interactiu. Per a les consultes d'un fitxer extern cal aportar `fitxer_de_queries.txt`; aquest conjunt de consultes no s'inclou en la selecció.

## Operacions

- Inserció de transaccions per data.
- Recorregut en ordre creixent o decreixent.
- Import total amb el percentatge d'IVA del cas de pràctica.
- Import dins d'un interval de dates, amb filtre opcional per producte.
- Consulta de mida, alçada i fulles de l'arbre.

Les dates utilitzen el format `YYYY-MM-DD`, que manté l'ordre cronològic en les comparacions lexicogràfiques d'aquest exercici.

## Dades

```csv
date_time,product_id,amount,price
2022-01-01,A,2,10.0
2022-01-01,B,1,5.0
2022-01-02,A,3,2.0
```

Aquest CSV és el fixture sintètic del test. Les tres transaccions generen dues claus de data i un import abans d'IVA de 31. Amb el factor 1,21 del test, el total esperat és 37,51.

## Verificació i límits

El test contrasta totals, intervals, filtres de producte i còpies del contenidor. L'arbre conserva diversos valors d'una mateixa data sense augmentar el nombre de claus.

L'arbre no es reequilibra i les consultes d'interval recorren l'estructura. El menú espera fitxers CSV amb el format indicat. El cas original d'exemple utilitza un límit textual `2022-02-31`; no representa una data real i no s'ha de reutilitzar com a validació de calendari.
