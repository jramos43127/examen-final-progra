#include "BinarySearchTree.h"

double log_base_n(double x, double base)
{
	return std::log(x) / std::log(base);
}

int MinimaAlturaDeArbol(int numeroDeNodos, int maximoDeHijosPorNodo)
{
	int maximoDeHijosMenos1PorNumeroDeNodosMasUno = ((maximoDeHijosPorNodo - 1) * numeroDeNodos + 1);
	int altura = ceil(log_base_n(maximoDeHijosMenos1PorNumeroDeNodosMasUno, maximoDeHijosPorNodo)) - 1;
	return altura;
}