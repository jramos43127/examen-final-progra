#pragma once

#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

template <typename T>
class BinarySearchTree
{
    class TreeNode
    {
    public:
        TreeNode() : parent(nullptr), leftChild(nullptr), rightChild(nullptr), data() {}
        TreeNode(T val) : parent(nullptr), leftChild(nullptr), rightChild(nullptr), data(val) {}

        T data;
        TreeNode* parent;
        TreeNode* leftChild;
        TreeNode* rightChild;
    };

public:
    BinarySearchTree() : root(nullptr), count(0) {}

    ~BinarySearchTree()
    {
        PostOrderDelete();
    }

    void Add(T value)
    {
        if (root == nullptr)
        {
            root = new TreeNode(value);
            count++;
            return;
        }

        TreeNode* current = root;
        while (true)
        {
            if (value > current->data)
            {
                if (current->rightChild == nullptr)
                {
                    current->rightChild = new TreeNode(value);
                    current->rightChild->parent = current;
                    count++;
                    return;
                }
                current = current->rightChild;
            }
            else if (value < current->data)
            {
                if (current->leftChild == nullptr)
                {
                    current->leftChild = new TreeNode(value);
                    current->leftChild->parent = current;
                    count++;
                    return;
                }
                current = current->leftChild;
            }
            else
            {
                // Valor duplicado, no se inserta
                return;
            }
        }
    }

    bool Search(T value) const
    {
        TreeNode* current = root;
        while (current != nullptr)
        {
            if (value == current->data)
                return true;
            else if (value < current->data)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
        return false;
    }

    void Delete(T value)
    {
        TreeNode* nodeToDelete = FindNode(value);
        if (nodeToDelete == nullptr) return;

        // Caso 1: Nodo hoja
        if (nodeToDelete->leftChild == nullptr && nodeToDelete->rightChild == nullptr)
        {
            DeleteLeaf(nodeToDelete);
        }
        // Caso 2: Un solo hijo
        else if (nodeToDelete->leftChild == nullptr || nodeToDelete->rightChild == nullptr)
        {
            DeleteNodeWithSingleChild(nodeToDelete);
        }
        // Caso 3: Dos hijos
        else
        {
            DeleteNodeWithTwoChildren(nodeToDelete);
        }
        count--;
    }

    void PostOrderDelete()
    {
        if (root == nullptr) return;

        stack<TreeNode*> nodes;
        stack<TreeNode*> toDelete;
        nodes.push(root);

        while (!nodes.empty())
        {
            TreeNode* current = nodes.top();
            nodes.pop();
            toDelete.push(current);

            if (current->leftChild) nodes.push(current->leftChild);
            if (current->rightChild) nodes.push(current->rightChild);
        }

        while (!toDelete.empty())
        {
            TreeNode* node = toDelete.top();
            toDelete.pop();
            delete node;
        }

        root = nullptr;
        count = 0;
    }

    void InOrderTraversal() const
    {
        stack<TreeNode*> s;
        TreeNode* current = root;

        while (current != nullptr || !s.empty())
        {
            while (current != nullptr)
            {
                s.push(current);
                current = current->leftChild;
            }

            current = s.top();
            s.pop();
            cout << current->data << " ";

            current = current->rightChild;
        }
        cout << endl;
    }

    int Size() const { return count; }
    bool Empty() const { return count == 0; }

private:
    TreeNode* root;
    int count;

    TreeNode* FindNode(T value) const
    {
        TreeNode* current = root;
        while (current != nullptr)
        {
            if (value == current->data)
                return current;
            else if (value < current->data)
                current = current->leftChild;
            else
                current = current->rightChild;
        }
        return nullptr;
    }

    void DeleteLeaf(TreeNode* node)
    {
        if (node->parent == nullptr)
        {
            root = nullptr;
        }
        else if (node->parent->leftChild == node)
        {
            node->parent->leftChild = nullptr;
        }
        else
        {
            node->parent->rightChild = nullptr;
        }
        delete node;
    }

    void DeleteNodeWithSingleChild(TreeNode* node)
    {
        TreeNode* child = (node->leftChild != nullptr) ? node->leftChild : node->rightChild;

        if (node->parent == nullptr)
        {
            root = child;
        }
        else if (node->parent->leftChild == node)
        {
            node->parent->leftChild = child;
        }
        else
        {
            node->parent->rightChild = child;
        }

        if (child != nullptr)
        {
            child->parent = node->parent;
        }
        delete node;
    }

    void DeleteNodeWithTwoChildren(TreeNode* node)
    {
        TreeNode* successor = FindMin(node->rightChild);

        node->data = successor->data;

        if (successor->rightChild != nullptr)
        {
            DeleteNodeWithSingleChild(successor);
        }
        else
        {
            DeleteLeaf(successor);
        }
    }

    TreeNode* FindMin(TreeNode* node) const
    {
        while (node->leftChild != nullptr)
        {
            node = node->leftChild;
        }
        return node;
    }
}; 