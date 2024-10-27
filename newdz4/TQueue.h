#ifndef TQUEUE_H
#define TQUEUE_H

#include "TDMassive.h"
#include <iostream>
#include <stdexcept>

// ����� TQueue ��� ���������� �������
// ���������� TDMassive ��� �������� ���������

template <typename T>
class TQueue {
    TDMassive<T> _data; // ���������� ������ ��� �������� ������ �������
    size_t _front; // ������ ������ �������
    size_t _rear; // ������ ����� �������

public:
    // ������������
    TQueue();
    explicit TQueue(size_t capacity);

    // �������� �������� �������
    void enqueue(T value); // ���������� �������� � ����� �������
    void dequeue(); // �������� �������� �� ������ �������
    T& front(); // ��������� �������� �� ������ �������
    const T& front() const; // ��������� �������� �� ������ ������� (����������� ������)

    // ��������������� ������
    bool empty() const noexcept; // ��������, ����� �� �������
    size_t size() const noexcept; // ��������� �������� ������� �������
    void clear(); // ������� �������

    // ������ ������� ��� �������
    void print() const;
};

// ���������� ������� TQueue
// ����������� �� ���������
template <typename T>
TQueue<T>::TQueue() : _data(), _front(0), _rear(0) {}

// ����������� � �������� ������������
template <typename T>
TQueue<T>::TQueue(size_t capacity) : _data(capacity), _front(0), _rear(0) {}

// ���������� �������� � ����� �������
template <typename T>
void TQueue<T>::enqueue(T value) {
    if (_rear >= _data.capacity()) {
        throw std::overflow_error("������� �����������, ���������� ��������� enqueue");
    }
    _data.push_back(value);
    _rear++;
}

// �������� �������� �� ������ �������
template <typename T>
void TQueue<T>::dequeue() {
    if (empty()) {
        throw std::underflow_error("������� �����, ���������� ��������� dequeue");
    }
    _data.remove_by_index(_front);
    _front++;
}

// ��������� �������� �� ������ ������� (������������ ������)
template <typename T>
T& TQueue<T>::front() {
    if (empty()) {
        throw std::underflow_error("������� �����, ���������� �������� front");
    }
    return _data[_front];
}

// ��������� �������� �� ������ ������� (����������� ������)
template <typename T>
const T& TQueue<T>::front() const {
    if (empty()) {
        throw std::underflow_error("������� �����, ���������� �������� front");
    }
    return _data[_front];
}

// �������� �� ������� �������
template <typename T>
bool TQueue<T>::empty() const noexcept {
    return _front == _rear;
}

// ��������� �������� ������� �������
template <typename T>
size_t TQueue<T>::size() const noexcept {
    return _rear - _front;
}

// ������� �������
template <typename T>
void TQueue<T>::clear() {
    _data.clear();
    _front = 0;
    _rear = 0;
}

// ������ ������� ��� �������
template <typename T>
void TQueue<T>::print() const {
    for (size_t i = _front; i < _rear; i++) {
        std::cout << _data[i] << " ";
    }
    std::cout << "\n";
}

#endif // TQUEUE_H
