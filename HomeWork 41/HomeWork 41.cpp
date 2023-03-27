#include <iostream>
#include <string>
#include <vector>

// Шаблонный класс, инкапсулирующий динамический массив.
template <typename T>
class DynamicArray {
private:
    T* m_data;      // Указатель на массив.
    size_t m_size;  // Размер массива.

public:
    // Конструкторы.
    DynamicArray() : m_data(nullptr), m_size(0) {}
    DynamicArray(size_t size) : m_data(new T[size]), m_size(size) {}
    DynamicArray(std::initializer_list<T> list) : DynamicArray(list.size()) {
        size_t i = 0;
        for (const auto& element : list) {
            m_data[i++] = element;
        }
    }

    // Деструктор.
    ~DynamicArray() {
        delete[] m_data;
    }

    // Оператор доступа по индексу.
    T& operator[](size_t index) {
        return m_data[index];
    }

    // Метод получения размера массива.
    size_t size() const {
        return m_size;
    }
};

// Класс Point.
class Point {
private:
    int m_x;
    int m_y;

public:
    Point() : m_x(0), m_y(0) {}
    Point(int x, int y) : m_x(x), m_y(y) {}

    // Методы получения и установки координат точки.
    int x() const {
        return m_x;
    }

    int y() const {
        return m_y;
    }

    void setX(int x) {
        m_x = x;
    }

    void setY(int y) {
        m_y = y;
    }
};

// Адаптированный класс Point для DynamicArray.
using PointArray = DynamicArray<Point>;

// Функция для сжатия строки текста.
std::string compressText(const std::string& text) {
    std::vector<std::string> words;
    std::string currentWord;

    // Разбиение текста на слова.
    for (char c : text) {
        if (c == ' ') {
            if (!currentWord.empty()) {
                words.push_back(currentWord);
                currentWord.clear();
            }
        }
        else {
            currentWord += c;
        }
    }

    // Добавление последнего слова, если оно есть.
    if (!currentWord.empty()) {
        words.push_back(currentWord);
    }

    // Сжатие текста.
    std::string compressedText;
    for (size_t i = 0; i < words.size(); ++i) {
        compressedText += words[i];
        if (i != words.size() - 1) {
            compressedText += ' ';
        }
    }

    return compressedText;
}


int main()
{
    std::string text = "    Hi,   i    am     Andrey,    how     are    you?    ";
    std::cout << compressText(text);
}