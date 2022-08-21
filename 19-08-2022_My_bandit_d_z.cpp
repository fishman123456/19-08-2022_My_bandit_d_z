
// 19-08-2022_odnorukiy_bandit.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//https://www.cyberforum.ru/cpp-beginners/thread1770413.html
// Домашнее задание:
// Создать имитацию игры "Однорукий бандит". Например , 
// При нажатии кнопки enter происходит иимтация вращения трёх барабанов ( естевственно,
// количество вращений каждого из них выбирается случайно),
// на которых изображены разные значки, и если выпадает определенная комбинация,
// то игрок получает какой-то выигрыш.


#include <iostream>
#include <random>
#include <ctime>
#include <windows.h>
#include <locale.h>
using namespace std;

const char symbols[] = { 
    char(0x03), char(0x04), char(0x05),char(0x06), 
   char(0x17), char(0x18), char(0x19), char(0x1A)
};

size_t  dim = sizeof(symbols) / sizeof(symbols[0]);

size_t make_move(
    const size_t& big_prize = 5000, // приз за 3
    const size_t& a_waste = 10    // плата за ход
)
{
    system("cls");  // очистка экрана, только windows
    char s_1 = symbols[rand() % dim]; // случайный 1 символ
    char s_2 = symbols[rand() % dim]; // случайный 2 символ
    char s_3 = symbols[rand() % dim]; // случайный 3 символ
    cout << "\n\t" << s_1 << "\t \b\b"; // вывод на экран 1 символ
    cout << "\t" << s_2 << "\t \b\b";   // вывод на экран 1 символ
    cout << "\t" << s_3 << "\t \n\n";   // вывод на экран 1 символ
    if ((s_1 == s_2) && (s_2 == s_3) && (s_1 == s_3)) // условия для выигрыша
        return big_prize - a_waste; // возвращаем приз - цена за ход
    else
    {
        return  0 - a_waste; // если нет выигрыша возвращаем минус цена за ход
    }
  //  return a_waste; 
}

int main()
{
    setlocale(LC_ALL, "Rus");
    srand(time(NULL));
    unsigned long  cash = 1000;      // начальная сумма
    cout << " Для игры  <Enter>, выход <z>" << endl;
    while (cin.get() != 'z')
    {
        cash += make_move();
        cout << "деньги: " << cash << "\n\n";
        if (cash <= 0)
            //cout << "\nВы прое... все деньги  ";
            break;
    }
    cout << "\nИгра окончена ваши деньги  " << cash << "$\n";
    //cin.get();
}