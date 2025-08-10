// main.cpp
#include <iostream>
#include "BinarySearchTree.h"
using namespace std;

// Declaraciones de las funciones auxiliares del .cpp
double log_base_n(double x, double base);
int MinimaAlturaDeArbol(int numeroDeNodos, int maximoDeHijosPorNodo);

int main() {
    BinarySearchTree<int> bst;

    cout << "Agregando valores al arbol...\n";
    bst.Add(50);
    bst.Add(30);
    bst.Add(70);
    bst.Add(20);
    bst.Add(40);
    bst.Add(60);
    bst.Add(80);

    cout << "Recorrido InOrder: ";
    bst.InOrderTraversal(); // Debe imprimir: 20 30 40 50 60 70 80

    cout << "Tamaño del arbol: " << bst.Size() << endl;
    cout << "Buscando el valor 40: " << (bst.Search(40) ? "Encontrado" : "No encontrado") << endl;
    cout << "Buscando el valor 100: " << (bst.Search(100) ? "Encontrado" : "No encontrado") << endl;

    cout << "\nEliminando nodo hoja (20)...\n";
    bst.Delete(20);
    bst.InOrderTraversal();

    cout << "Eliminando nodo con un hijo (30)...\n";
    bst.Delete(30);
    bst.InOrderTraversal();

    cout << "Eliminando nodo con dos hijos (50)...\n";
    bst.Delete(50);
    bst.InOrderTraversal();

    cout << "\nTamaño final del arbol: " << bst.Size() << endl;

    // Probar función MinimaAlturaDeArbol
    int nodos = 7;
    int hijos = 2;
    cout << "La minima altura de un arbol con " << nodos << " nodos y maximo "
        << hijos << " hijos por nodo es: "
        << MinimaAlturaDeArbol(nodos, hijos) << endl;

    return 0;
}
