#pragma once

#include <vector>
#include <list>
#include <functional>

template <typename T>
class HashTableChaining {
protected:
    size_t tableSize;
    std::vector<std::list<T>> table;
    size_t numElements;

    size_t hash(const T& key) const {
        std::hash<T> hasher;
        return hasher(key) % tableSize;
    }

public:
    HashTableChaining(size_t size = 101) : tableSize(size), table(size), numElements(0) {}

    virtual ~HashTableChaining() = default;

    // inserta un elemento
    virtual bool insert(const T& value) {
        size_t index = hash(value);
        table[index].push_back(value);
        numElements++;
        return true;
    }

    // esto busca un elemento
    bool contains(const T& value) const {
        size_t index = hash(value);
        for (const auto& item : table[index]) {
            if (item == value) {
                return true;
            }
        }
        return false;
    }

    // esto elimina un elemento
    bool erase(const T& value) {
        size_t index = hash(value);
        auto& chain = table[index];

        for (auto it = chain.begin(); it != chain.end(); ++it) {
            if (*it == value) {
                chain.erase(it);
                numElements--;
                return true;
            }
        }
        return false;
    }

    size_t size() const { return numElements; }
    bool empty() const { return numElements == 0; }

    void clear() {
        for (auto& chain : table) {
            chain.clear();
        }
        numElements = 0;
    }
};#pragma once
