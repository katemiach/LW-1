#include <iostream>
#include <locale.h>
#include <tchar.h>
#include <Windows.h>

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

    // Виведення ПІБ членів сім'ї за допомогою функції _tprintf
    _tprintf(_T("Iм'я: %s\n"), nameWide);
    _tprintf(_T("Прiзвище: %s\n"), surnameWide);
    _tprintf(_T("По батьковi: %s\n"), patronymicWide);

    // Виведення ПІБ членів сім'ї за допомогою потоку wcout
    std::wcout << L"Iм'я: " << nameWide << std::endl;
    std::wcout << L"Прiзвище: " << surnameWide << std::endl;
    std::wcout << L"По батьковi: " << patronymicWide << std::endl;

    // Виведення ПІБ членів сім'ї за допомогою функції MessageBox
    MessageBox(NULL, nameWide, L"Ім'я", MB_OK);
    MessageBox(NULL, surnameWide, L"Прізвище", MB_OK);
    MessageBox(NULL, patronymicWide, L"По батькові", MB_OK);

    delete[] nameWide;
    delete[] surnameWide;
    delete[] patronymicWide;

    return 0;
}