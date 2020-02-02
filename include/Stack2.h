//Copyright 2020 <boikov3>

#ifndef TEMPLATE1_STACK2_H
#define TEMPLATE1_STACK2_H

#include <iostream>
#include <exception>
#include "Node.h"




template<typename T>
class Stack2 {
private:
    Node<T> *node = nullptr;

public:

    Stack2() = default;

    Stack2(const Stack2 &stack) = delete;
    Stack2(Stack2 &&stack) = default;
    auto operator=(Stack2 &&stack) noexcept -> Stack2 & = default;

    template<typename ... Args>
    void push_emplace(Args &&... value) {
        auto item = node;
        node = new Node<T>{{std::forward<Args>(value)...}, item};
    }

    void push(T &&value) {
        auto item = node;
        node = new Node<T>{std::forward<T>(value), item};
    }

    const T &head() const {
        if (!node)
            throw std::logic_error("no stack");
        else
            return node->value;
    }

    T pop() {
        if (!node)
            throw std::logic_error("no stack");
        else {
            auto remote = node->value;
            node = node->prev;
            return remote;
        }
    }
};


#endif //TEMPLATE1_STACK2_H
