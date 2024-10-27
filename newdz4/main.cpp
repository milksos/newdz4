#include <iostream>
#include "TQueue.h"

void runQueueTests() {
    int total_tests = 0;
    int passed_tests = 0;

    // ���� �������� ������������
    try {
        TQueue<int> queue;
        std::cout << "������� ������ �������\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� ������������\n";
    }

    // ���� ������������ � �������� ������������
    try {
        TQueue<int> queue(100);
        std::cout << "������� ������ ������� � ������������ 100\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ ������������ � �������� ������������\n";
    }

    // ���� ���������� ��������� � ������� (enqueue)
    try {
        TQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        std::cout << "������� ����� ���������� ���������: ";
        queue.print(); // ��������� �����: 10 20 30
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� enqueue\n";
    }

    // ���� ��������� �������� �� ������ ������� (front)
    try {
        TQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        int frontElement = queue.front();
        std::cout << "������� � ������ �������: " << frontElement << "\n"; // ��������� �����: 10
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� front\n";
    }

    // ���� ��������� �������� �� ������ ������� (����������� ������ front)
    try {
        const TQueue<int> queue = []() { TQueue<int> q; q.enqueue(100); q.enqueue(200); return q; }();
        int frontElement = queue.front();
        std::cout << "������� � ������ ����������� �������: " << frontElement << "\n"; // ��������� �����: 100
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ ����������� ������ front\n";
    }

    // ���� �������� �������� �� ������ ������� (dequeue)
    try {
        TQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.dequeue();
        std::cout << "������� ����� �������� �������� �� ������: ";
        queue.print(); // ��������� �����: 20
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� dequeue\n";
    }

    // ���� dequeue ��� ������ �������
    try {
        TQueue<int> queue;
        queue.dequeue();
        std::cout << "������: �������� dequeue ��� ������ ������� �� ������� ����������\n";
        total_tests++;
    }
    catch (const std::underflow_error&) {
        std::cout << "��������� ���������� ��� ������� ������� ������� �� ������ �������\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "����������� ������ ��� ������������ �������� dequeue ��� ������ �������\n";
    }

    // ���� �������� �� ������� (empty)
    try {
        TQueue<int> queue;
        bool isEmpty = queue.empty();
        std::cout << "������� �����: " << (isEmpty ? "������" : "����") << "\n"; // ��������� �����: ������
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� empty\n";
    }

    // ���� ������� ������� (clear)
    try {
        TQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.clear();
        bool isEmpty = queue.empty();
        std::cout << "������� ����� ������� �����: " << (isEmpty ? "������" : "����") << "\n"; // ��������� �����: ������
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� clear\n";
    }

    // ���� ��������� �������� ������� ������� (size)
    try {
        TQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        size_t queueSize = queue.size();
        std::cout << "������� ������ �������: " << queueSize << "\n"; // ��������� �����: 3
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "������ ��� ������������ �������� size\n";
    }

    // ����� ������ ���������� ������ � ���������� �������� ������
    std::cout << "\n����� ���������� ������: " << total_tests << "\n";
    std::cout << "���������� �������� ������: " << passed_tests << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    runQueueTests();
    return 0;
}