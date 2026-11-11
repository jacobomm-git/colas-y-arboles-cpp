#include <cassert>
#include <cmath>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include "../01-cola-pedidos/CuaEncadenada.h"
#include "../02-inventario-bst/Inventari.h"

int main(int argc, char** argv) {
    assert(argc == 2);
    CuaEncadenada<int> cola;
    assert(cola.isEmpty());
    bool error = false;
    try { cola.dequeue(); } catch (const std::out_of_range&) { error = true; }
    assert(error);
    cola.enqueue(10);
    cola.enqueue(20);
    CuaEncadenada<int> copia(cola);
    cola.dequeue();
    assert(cola.getFront() == 20 && copia.getFront() == 10);
    CuaEncadenada<int> asignada;
    asignada = copia;
    asignada.dequeue();
    assert(asignada.getFront() == 20 && copia.getFront() == 10);
    cola.dequeue();
    assert(cola.isEmpty());
    cola.enqueue(30);
    assert(cola.getFront() == 30);

    BSTArbre<int, int> tree;
    assert(tree.empty() && tree.size() == 0 && tree.height() == 0);
    for (int key : {4, 2, 7, 1, 3, 6, 8}) tree.insert(key, key * 10);
    tree.insert(4, 41);
    assert(tree.size() == 7 && tree.height() == 3);
    assert(tree.valuesOf(4).size() == 2);
    assert(tree.getLeafNodes().size() == 4);
    BSTArbre<int, int> treeCopy(tree);
    treeCopy.insert(9, 90);
    assert(tree.size() == 7 && treeCopy.size() == 8);
    BSTArbre<int, int> treeAssigned;
    treeAssigned = treeCopy;
    assert(treeAssigned.valuesOf(9).front() == 90);
    BSTArbre<int, int> emptyCopy(BSTArbre<int, int>{});
    assert(emptyCopy.empty());

    Inventari<BSTArbre<std::string, FoodPackage>> inventari(0.21f);
    assert(inventari.size() == 0 && inventari.height() == 0);
    assert(inventari.priceInTimeInterval({"2022-01-01", "2022-12-31"}) == 0.0f);
    inventari.loadFromFile(argv[1]);
    // Cálculo independiente sobre las tres filas del fixture sintético.
    const float expected = (2 * 10.0f + 1 * 5.0f + 3 * 2.0f) * 1.21f;
    assert(inventari.size() == 2);
    assert(std::abs(inventari.priceInTotal() - expected) < 0.001f);
    assert(std::abs(inventari.priceInTimeInterval({"2022-01-01", "2022-01-01"}) - 25 * 1.21f) < 0.001f);
    assert(std::abs(inventari.priceInTimeIntervalByProduct({"2022-01-01", "2022-01-02"}, "A") - 26 * 1.21f) < 0.001f);
    Inventari<BSTArbre<std::string, FoodPackage>> inventoryCopy(inventari);
    assert(std::abs(inventoryCopy.priceInTotal() - expected) < 0.001f);
    std::cout << "Verificades: FIFO, copia independent, BST i totals d'inventari.\n";
}
