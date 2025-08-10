#include "HashTableChaining.h"

// aqui creamos nuestra clase HashSet que hereda de HashTableChaining
template <typename T>
class HashSet : public HashTableChaining<T> {
public:
    // aqui estamos haciendo que herede todos los constructores de la clase padre
    using HashTableChaining<T>::HashTableChaining;

    // aqui modificamos el método insert para que no permita duplicados
    // el override lo que hace es reemplazar el método de la clase padre
    bool insert(const T& value) override {
        if (!this->contains(value)) {
            return HashTableChaining<T>::insert(value);
        }
        return false;
    }
};