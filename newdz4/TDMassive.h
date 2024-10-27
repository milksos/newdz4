// ���� TDMassive.h
#ifndef TDMASSIVE_H
#define TDMASSIVE_H

#include <cstddef>
#include <stdexcept>
#include <cstring>
#include <iostream>
#include <string>

#define STEP_CAPACITY 15
#define MAX_CAPACITY 100000

// ��������� ��������� �������
enum State { empty, busy, deleted };

// ��������� ����� TDMassive
// ���������� ������������� ������� � ������������ ����������, �������� � ������ ���������
// ����� ������������ ��������� ���������: ������, ������� � ���������

template <typename T>
class TDMassive {
    T* _data; // ��������� �� ������ ������
    State* _states; // ��������� �� ������ ���������
    size_t _capacity; // ������� ����������� �������
    size_t _size; // ������� ������ (���������� ���������)
    size_t _deleted; // ���������� ��������� ���������

public:
    TDMassive(); // ����������� �� ���������
    explicit TDMassive(size_t n); // ����������� � �������� ������������
    ~TDMassive(); // ����������

    bool empty() const noexcept; // ��������, ���� �� ������
    bool full() const noexcept; // ��������, ����� �� ������
    size_t size() const noexcept; // ��������� �������� �������
    size_t capacity() const noexcept; // ��������� ������� �����������
    void clear(); // ������� �������
    void push_back(T value); // ���������� �������� � ����� �������
    void remove_by_index(size_t pos); // �������� �������� �� �������
    T& operator[](size_t index); // �������� ������� � �������� �� �������
    const T& operator[](size_t index) const; // ����������� �������� ������� � �������� �� �������
};

// ���������� ������� TDMassive
// ����������� �� ���������
// �������������� ������ � ������������ ������ STEP_CAPACITY
template <typename T>
TDMassive<T>::TDMassive() : _size(0), _capacity(STEP_CAPACITY), _deleted(0) {
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = State::empty;
    }
}

// ����������� � �������� ������������
// �������������� ������ � �������� ������������ n
template <typename T>
TDMassive<T>::TDMassive(size_t n) : _capacity(n), _size(0), _deleted(0) {
    if (_capacity == 0) {
        _capacity = STEP_CAPACITY;
    }
    _data = new T[_capacity];
    _states = new State[_capacity];
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = State::empty;
    }
}

// ����������
// ����������� ���������� ������
template <typename T>
TDMassive<T>::~TDMassive() {
    delete[] _data;
    delete[] _states;
}

// �������� �� �������
// ���������� true, ���� ������ ����
template <typename T>
bool TDMassive<T>::empty() const noexcept {
    return _size == 0;
}

// �������� �� �������������
// ���������� true, ���� ������ �����
template <typename T>
bool TDMassive<T>::full() const noexcept {
    return _size >= _capacity;
}

// ��������� �������� �������
// ���������� ���������� ��������� � �������
template <typename T>
size_t TDMassive<T>::size() const noexcept {
    return _size;
}

// ��������� ������� �����������
// ���������� ����������� �������
template <typename T>
size_t TDMassive<T>::capacity() const noexcept {
    return _capacity;
}

// ������� �������
// ������������� ��� �������� ��� ������ � �������� ������
template <typename T>
void TDMassive<T>::clear() {
    _size = 0;
    _deleted = 0;
    for (size_t i = 0; i < _capacity; i++) {
        _states[i] = State::empty;
    }
}

// ���������� �������� � ����� �������
// ��������� ������� � ����� �������, ���� ���� ��������� �����, ����� ����������� �����������
template <typename T>
void TDMassive<T>::push_back(T value) {
    if (full()) {
        size_t new_capacity = _capacity * 2;
        if (new_capacity > MAX_CAPACITY) {
            throw std::logic_error("��������� ������������ �����������");
        }

        T* new_data = new T[new_capacity];
        State* new_states = new State[new_capacity];
        for (size_t i = 0; i < _capacity; i++) {
            new_data[i] = _data[i];
            new_states[i] = _states[i];
        }
        delete[] _data;
        delete[] _states;
        _data = new_data;
        _states = new_states;
        _capacity = new_capacity;
        for (size_t i = _size; i < _capacity; i++) {
            _states[i] = State::empty;
        }
    }
    _data[_size] = value;
    _states[_size] = State::busy;
    _size++;
}

// �������� �������� �� �������
// ������������� ��������� �������� ��� "���������"
template <typename T>
void TDMassive<T>::remove_by_index(size_t pos) {
    if (pos >= _size || _states[pos] == State::deleted) {
        throw std::out_of_range("�������� ������: " + std::to_string(pos));
    }
    _states[pos] = State::deleted;
    _deleted++;
}

// �������� ������� � �������� �� �������
// ������������ �������
template <typename T>
T& TDMassive<T>::operator[](size_t index) {
    if (index >= _size || _states[index] == State::deleted) {
        throw std::out_of_range("������ ��� ���������: " + std::to_string(index));
    }
    return _data[index];
}

// �������� ������� � �������� �� �������
// ����������� �������
template <typename T>
const T& TDMassive<T>::operator[](size_t index) const {
    if (index >= _size || _states[index] == State::deleted) {
        throw std::out_of_range("������ ��� ���������: " + std::to_string(index));
    }
    return _data[index];
}

#endif // TDMASSIVE_H