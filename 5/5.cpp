#include <iostream>
#include <locale.h>
#include <tchar.h>
#include <Windows.h>
#include <algorithm>
#include <vector>
#include <cstring>

// Функція порівняння для qsort
int compareWideStrings(const void* a, const void* b) {
    const wchar_t* s1 = static_cast<const wchar_t*>(a);
    const wchar_t* s2 = static_cast<const wchar_t*>(b);
    return wcscmp(s1, s2);
}

// Функція порівняння для std::sort
bool compareWideStringVectors(const std::wstring& a, const std::wstring& b) {
    return a < b;
}

int main() {
    // Встановлення локального режиму для української мови
    _tsetlocale(LC_ALL, _T("Ukrainian"));

    // Задання ПІБ членів сім'ї в ASCII
    const char* name = "Тетяна";
    const char* surname = "М'яч";
    const char* patronymic = "Анатолiївна";

    // Конвертація рядків в UNICODE за допомогою MultiByteToWideChar
    int nameLen = MultiByteToWideChar(CP_ACP, 0, name, -1, NULL, 0);
    int surnameLen = MultiByteToWideChar(CP_ACP, 0, surname, -1, NULL, 0);
    int patronymicLen = MultiByteToWideChar(CP_ACP, 0, patronymic, -1, NULL, 0);

    wchar_t* nameWide = new wchar_t[nameLen];
    wchar_t* surnameWide = new wchar_t[surnameLen];
    wchar_t* patronymicWide = new wchar_t[patronymicLen];

    MultiByteToWideChar(CP_ACP, 0, name, -1, nameWide, nameLen);
    MultiByteToWideChar(CP_ACP, 0, surname, -1, surnameWide, surnameLen);
    MultiByteToWideChar(CP_ACP, 0, patronymic, -1, patronymicWide, patronymicLen);

    // Створення масиву рядків у UNICODE
    const wchar_t* strings[] = { nameWide, surnameWide, patronymicWide };
    const int numStrings = sizeof(strings) / sizeof(strings[0]);

    // Виведення вихідного масиву рядків
    std::wcout << L"Вихiдний масив рядкiв:" << std::endl;
    for (int i = 0; i < numStrings; ++i) {
        std::wcout << strings[i] << std::endl;
    }
    std::wcout << std::endl;

    // Сортування масиву за допомогою qsort
    std::wcout << L"Масив рядкiв, упорядкований за допомогою qsort:" << std::endl;
    wchar_t** stringsCopy = new wchar_t* [numStrings];
    for (int i = 0; i < numStrings; ++i) {
        stringsCopy[i] = new wchar_t[wcslen(strings[i]) + 1];
        wcscpy_s(stringsCopy[i], wcslen(strings[i]) + 1, strings[i]);
    }
    qsort(stringsCopy, numStrings, sizeof(wchar_t*), compareWideStrings);
    for (int i = 0; i < numStrings; ++i) {
        std::wcout << stringsCopy[i] << std::endl;
    }
    for (int i = 0; i < numStrings; ++i) {
        delete[] stringsCopy[i];
    }
    delete[] stringsCopy;
    std::wcout << std::endl;

    // Сортування масиву за допомогою std::sort
    std::wcout << L"Масив рядкiв, упорядкований за допомогою std::sort:" << std::endl;
    std::vector<std::wstring> stringVector(strings, strings + numStrings);
    std::sort(stringVector.begin(), stringVector.end(), compareWideStringVectors);
    for (const auto& str : stringVector) {
        std::wcout << str.c_str() << std::endl;
    }
    std::wcout << std::endl;

    // Зворотне перетворення масиву з Unicode в ASCII
    std::wcout << L"Масив рядкiв пiсля зворотного перетворення з Unicode в ASCII:" << std::endl;
    for (int i = 0; i < numStrings; ++i) {
        int len = WideCharToMultiByte(CP_ACP, 0, strings[i], -1, NULL, 0, NULL, NULL);
        char* asciiStr = new char[len];
        WideCharToMultiByte(CP_ACP, 0, strings[i], -1, asciiStr, len, NULL, NULL);
        std::cout << asciiStr << std::endl;
        delete[] asciiStr;
    }

    delete[] nameWide;
    delete[] surnameWide;
    delete[] patronymicWide;

    return 0;
}