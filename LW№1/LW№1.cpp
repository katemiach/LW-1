#include <iostream>
#include <Windows.h> // Підключення для роботи з TCHAR

int main() {
    // Перевірка типу кодування за замовчуванням
#ifdef _UNICODE
    std::cout << "The default encoding type: UNICODE" << std::endl;
#else
    std::cout << "The default encoding type: ASCII" << std::endl;
#endif

    // Визначення довжини в байтах типу TCHAR
    std::cout << "Length in bytes of type TCHAR: " << sizeof(TCHAR) << std::endl;

    return 0;
}