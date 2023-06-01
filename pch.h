//
// pch.h
//

#pragma once

#include "gtest/gtest.h"
#include <iostream>
#include <memory>


template<typename T>
class Queue {
private:
    struct Node {
        T data;
        std::unique_ptr<Node> next;

        Node(const T& value) : data(value), next(nullptr) {}
    };

    std::unique_ptr<Node> frontPtr;
    Node* rearPtr;
    size_t size;

public:
    Queue() : frontPtr(nullptr), rearPtr(nullptr), size(0) {}

    void Enqueue(const T& value) {
        std::unique_ptr<Node> newNode = std::make_unique<Node>(value);

        if (IsEmpty()) {
            frontPtr = std::move(newNode);
            rearPtr = frontPtr.get();
        }
        else {
            rearPtr->next = std::move(newNode);
            rearPtr = rearPtr->next.get();
        }

        size++;
    }

    void Dequeue() {
        if (IsEmpty()) {
            std::cout << "Queue is empty. Cannot dequeue." << std::endl;
            return;
        }

        std::unique_ptr<Node> tempNode = std::move(frontPtr);
        frontPtr = std::move(tempNode->next);

        if (frontPtr == nullptr) {
            rearPtr = nullptr;
        }

        size--;
    }

    const T& Peek() const {
        if (IsEmpty()) {
            throw std::runtime_error("Queue is empty. Cannot peek.");
        }

        return frontPtr->data;
    }

    size_t GetSize() const {
        return size;
    }

    bool IsEmpty() const {
        return size == 0;
    }

    Queue(const std::unique_ptr<Node>& frontPtr, Node* rearPtr, const size_t& size)
        : frontPtr(frontPtr), rearPtr(rearPtr), size(size)
    {
    }
};

