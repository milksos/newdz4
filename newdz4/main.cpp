#include <iostream>
#include "TQueue.h"

void runQueueTests() {
    int total_tests = 0;
    int passed_tests = 0;

    // Тест базового конструктора
    try {
        TQueue<int> queue;
        std::cout << "Создана пустая очередь\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании базового конструктора\n";
    }

    // Тест конструктора с заданной вместимостью
    try {
        TQueue<int> queue(100);
        std::cout << "Создана пустая очередь с вместимостью 100\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании конструктора с заданной вместимостью\n";
    }

    // Тест добавления элементов в очередь (enqueue)
    try {
        TQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        std::cout << "Очередь после добавления элементов: ";
        queue.print(); // Ожидаемый вывод: 10 20 30
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции enqueue\n";
    }

    // Тест получения элемента из начала очереди (front)
    try {
        TQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        int frontElement = queue.front();
        std::cout << "Элемент в начале очереди: " << frontElement << "\n"; // Ожидаемый вывод: 10
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции front\n";
    }

    // Тест получения элемента из начала очереди (константная версия front)
    try {
        const TQueue<int> queue = []() { TQueue<int> q; q.enqueue(100); q.enqueue(200); return q; }();
        int frontElement = queue.front();
        std::cout << "Элемент в начале константной очереди: " << frontElement << "\n"; // Ожидаемый вывод: 100
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании константной версии front\n";
    }

    // Тест удаления элемента из начала очереди (dequeue)
    try {
        TQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.dequeue();
        std::cout << "Очередь после удаления элемента из начала: ";
        queue.print(); // Ожидаемый вывод: 20
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции dequeue\n";
    }

    // Тест dequeue для пустой очереди
    try {
        TQueue<int> queue;
        queue.dequeue();
        std::cout << "Ошибка: операция dequeue для пустой очереди не вызвала исключение\n";
        total_tests++;
    }
    catch (const std::underflow_error&) {
        std::cout << "Ожидаемое исключение при попытке удалить элемент из пустой очереди\n";
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Неожиданная ошибка при тестировании операции dequeue для пустой очереди\n";
    }

    // Тест проверки на пустоту (empty)
    try {
        TQueue<int> queue;
        bool isEmpty = queue.empty();
        std::cout << "Очередь пуста: " << (isEmpty ? "истина" : "ложь") << "\n"; // Ожидаемый вывод: истина
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции empty\n";
    }

    // Тест очистки очереди (clear)
    try {
        TQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.clear();
        bool isEmpty = queue.empty();
        std::cout << "Очередь после очистки пуста: " << (isEmpty ? "истина" : "ложь") << "\n"; // Ожидаемый вывод: истина
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции clear\n";
    }

    // Тест получения текущего размера очереди (size)
    try {
        TQueue<int> queue;
        queue.enqueue(10);
        queue.enqueue(20);
        queue.enqueue(30);
        size_t queueSize = queue.size();
        std::cout << "Текущий размер очереди: " << queueSize << "\n"; // Ожидаемый вывод: 3
        total_tests++;
        passed_tests++;
    }
    catch (...) {
        std::cout << "Ошибка при тестировании операции size\n";
    }

    // Вывод общего количества тестов и количества успешных тестов
    std::cout << "\nОбщее количество тестов: " << total_tests << "\n";
    std::cout << "Количество успешных тестов: " << passed_tests << "\n";
}

int main() {
    setlocale(LC_ALL, "Russian");
    runQueueTests();
    return 0;
}