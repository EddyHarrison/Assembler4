#include <iostream> 
#include <cstdlib>
using namespace std;
int main()
{
    setlocale(LC_ALL, "Russian");
    char str1[100];
    char symbol[1];
    int temp = 0;
    while (true) {
        cout << ("Введите строку:\t");
        cin.getline(str1, 100, '\n');
        int len_str = strlen(str1);//нахождение длины строки
        cout << ("Введите символ:\t");
        cin.getline(symbol, 100, '\n');
        int len = strlen(symbol);//нахождение длины строки
        for (int i = 0; i <= len_str; i++) {
            if (str1[i] == ' ') {
                temp += 1;
            }
        }
        if (temp == len_str) {
            cout << "Вы ввели строку из пробелов\n";
        }
        else {
            if (str1[0] == '@') {
                return 0;
            }
            if (len_str == 0) {
                cout << "Строка не была введена\n";
            }
            else {
                _asm {
                    ; init_prog     //начало программы
                    xor eax, eax    //очистка регистра
                    xor ecx, ecx    //очистка регистра
                    lea ebx, str1   //помещаем регистр ebx ссылку на строку
                    mov al, symbol   //помещаем в al наш символ,который удаляем
                    start_prog :
                    cmp[ebx + ecx], al //условие на проверку: если символ в строке равен нашему символу, то удаляем его
                        jne end_loop // если нет, то переходим к метке
                        mov[ebx + ecx], ' ' // заменяем символ на пробел
                        end_loop : 
                        add ecx, 1 //добавляем ед. чтоб перейти к след символу строки
                        cmp ecx, len_str // если длина строки больше счетчика, то переходим в начало програмы, иначе выходим
                        jne start_prog
                }
                cout << str1 << "\n";
            }
        }
    }
}