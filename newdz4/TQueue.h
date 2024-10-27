#ifndef TQUEUE_H
#define TQUEUE_H

#include "TDMassive.h"
#include <iostream>
#include <stdexcept>

// Класс TQueue для реализации очереди
// Использует TDMassive для хранения элементов

template <typename T>
class TQueue {
    TDMassive<T> _data; // Внутренний массив для хранения данных очереди
    size_t _front; // Индекс начала очереди
    size_t _rear; // Индекс конца очереди

public:
    // Конструкторы
    TQueue();
    explicit TQueue(size_t capacity);

    // Основные операции очереди
    void enqueue(T value); // Добавление элемента в конец очереди
    void dequeue(); // Удаление элемента из начала очереди
    T& front(); // Получение элемента из начала очереди
    const T& front() const; // Получение элемента из начала очереди (константная версия)

    // Вспомогательные методы
    bool empty() const noexcept; // Проверка, пуста ли очередь
    size_t size() const noexcept; // Получение текущего размера очереди
    void clear(); // Очистка очереди

    // Печать очереди для отладки
    void print() const;
};

// Реализация методов TQueue
// Конструктор по умолчанию
template <typename T>
TQueue<T>::TQueue() : _data(), _front(0), _rear(0) {}

// Конструктор с заданной вместимостью
template <typename T>
TQueue<T>::TQueue(size_t capacity) : _data(capacity), _front(0), _rear(0) {}

// Добавление элемента в конец очереди
template <typename T>
void TQueue<T>::enqueue(T value) {
    if (_rear >= _data.capacity()) {
        throw std::overflow_error("Очередь переполнена, невозможно выполнить enqueue");
    }
    _data.push_back(value);
    _rear++;
}

// Удаление элемента из начала очереди
template <typename T>
void TQueue<T>::dequeue() {
    if (empty()) {
        throw std::underflow_error("Очередь пуста, невозможно выполнить dequeue");
    }
    _data.remove_by_index(_front);
    _front++;
}

// Получение элемента из начала очереди (непостоянная версия)
template <typename T>
T& TQueue<T>::front() {
    if (empty()) {
        throw std::underflow_error("Очередь пуста, невозможно получить front");
    }
    return _data[_front];
}

// Получение элемента из начала очереди (константная версия)
template <typename T>
const T& TQueue<T>::front() const {
    if (empty()) {
        throw std::underflow_error("Очередь пуста, невозможно получить front");
    }
    return _data[_front];
}

// Проверка на пустоту очереди
template <typename T>
bool TQueue<T>::empty() const noexcept {
    return _front == _rear;
}

// Получение текущего размера очереди
template <typename T>
size_t TQueue<T>::size() const noexcept {
    return _rear - _front;
}

// Очистка очереди
template <typename T>
void TQueue<T>::clear() {
    _data.clear();
    _front = 0;
    _rear = 0;
}

// Печать очереди для отладки
template <typename T>
void TQueue<T>::print() const {
    for (size_t i = _front; i < _rear; i++) {
        std::cout << _data[i] << " ";
    }
    std::cout << "\n";
}

#endif // TQUEUE_H
