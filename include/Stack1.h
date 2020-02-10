// Copyright 2020 <boikov3>

#ifndef TEMPLATE1_STACK1_H
#define TEMPLATE1_STACK1_H

#include <iostream>
#include "exception"
#include "Node.h"

template<typename T>
class Stack1 {
private:
    Node<T> *node = nullptr;  //вершина стэка

public:

    Stack1() = default;

    Stack1(const Stack1 &stack) = delete; //конструктор копирования
    Stack1(Stack1 &&stack) = default;      // конструктор перемещения (constructible)
    auto operator=(Stack1 &&stack) noexcept -> Stack1 & = default; // (assignable)

    void push(T &&value) {
        if (!node) {
            node = new Node<T>(value, nullptr);
        } else {
            Node<T> *elem = new Node<T>(node->value, node->prev);
            node->value = value;        // "новая" вершина
            node->prev = elem;
        }
    }

    void push(const T &value) {
        if (!node) {
            node = new Node<T>(value,nullptr);
        } else {
            auto *elem = new Node<T>(node->value, node->prev);
            node->value = value;        // "новая" вершина
            node->prev = elem;
        }
    }

    const T &head() const {
        if (node == nullptr)
            throw std::logic_error("no stack");
        else
            return node->value;
    }

    void pop() {
        if (node == nullptr)
            throw std::logic_error("no stack");
        else if (node != nullptr)
            node = node->prev;
    }
};

#endif //TEMPLATE1_STACK1_H
