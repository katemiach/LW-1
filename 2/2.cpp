#include <iostream>
#include <Windows.h>

int main() {
    // Перевірка наявності макросів в командному рядку
#ifdef UNICODE
    std::cout << "Encoding type defined by command line macros: UNICODE" << std::endl;
#else
    std::cout << "Encoding type defined by command line macros: ASCII" << std::endl;
#endif

    // Визначення довжини в байтах типу TCHAR
    std::cout << "Length in bytes of type TCHAR: " << sizeof(TCHAR) << std::endl;

    return 0;
}