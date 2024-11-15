#include "pch.h"
#include "Taylor.h"

double Taylor(double epsil, double x, int *n, double last = 1)
{
    if (*n != 0)
        last = (-1) * last * (pow(x, 2) / *n);
    if (abs(last) < epsil)
        return 0;
    (*n)++;
    return Taylor(epsil, x, n, last) + last;
}

double Taylor(double epsil, double x, int count = 0, double last = 1)
{
    if (count != 0)
        last = (-1) * last * (pow(x, 2) / count);
    if (abs(last) < epsil)
        return 0;
    count++;
    return Taylor(epsil, x, count, last) + last;
}

int Lenght_digit(double a)
{
    std::stringstream stream;
    stream << a;
    return (int)stream.str().length();
}

int Lenght_digit(int a)
{
    std::stringstream stream;
    stream << a;
    return (int)stream.str().length();
}

void build_line(int lenght_head, int lenght, double arr[], int line)
{
    int c;
    c = int((lenght_head - lenght) / 2);
    for (int j = 0; j < c; j++)
        std::cout << ' ';
    std::cout << arr[line];
    c = lenght_head - c - lenght;
    for (int j = 0; j < c; j++)
        std::cout << ' ';
    std::cout << '|';
}

void build_line(int lenght_head, int lenght, int arr[], int line)
{
    int c;
    c = int((lenght_head - lenght) / 2);
    for (int j = 0; j < c; j++)
        std::cout << ' ';
    std::cout << arr[line];
    c = lenght_head - c - lenght;
    for (int j = 0; j < c; j++)
        std::cout << ' ';
    std::cout << '|';
}

void OutTaylor(double a, double b, double dx, double epsil)
{

    std::string head[] = {"x", "f(x)", "n", "e^(-x^2)"};
    int start_lenght_head[] = {1, 4, 1, 8};
    int lenght_head[4] = {1, 4, 1, 8}; // Для дальнейшего расчёта размеров таблицы
    int count = (b - a) / dx + 1;      // Сколько всего будет строк в таблице
    int count_ = (b - a) / dx + 1;     // Для дальнейшего использования (так как count изменится)

    double *x = new double[count]; // Создаём 4 массива для сохранения 4 столбцов
    double *f = new double[count];
    int *n = new int[count];
    double *e = new double[count];

    int *lenght_x = new int[count]; // Массивы, в которых хранятся длины значаний
    int *lenght_f = new int[count];
    int *lenght_n = new int[count];
    int *lenght_e = new int[count];

    int n_count; // для подсчёта количества элементов во время Taylor
    count = 0;   // Для дальнейшего заполнения массивов

    for (a; (b - a) >= 0.00001 || (a - b) <= 0.00001; a += dx)
    { // Заполнение массивов
        n_count = 0;

        x[count] = a;
        lenght_x[count] = Lenght_digit(a);
        lenght_head[0] = std::max(lenght_head[0], lenght_x[count]);

        f[count] = Taylor(epsil, a, &n_count);
        lenght_f[count] = Lenght_digit(f[count]);
        lenght_head[1] = std::max(lenght_head[1], lenght_f[count]);

        n[count] = n_count;
        lenght_n[count] = Lenght_digit(n_count);
        lenght_head[2] = std::max(lenght_head[2], lenght_n[count]);

        e[count] = pow(2.7182818, -pow(a, 2));
        lenght_e[count] = Lenght_digit(e[count]);
        lenght_head[3] = std::max(lenght_head[3], lenght_e[count]);

        count++;
    }

    for (int i = 0; i < 4; i++)
        lenght_head[i] += 2;

    // Вывод значений в таблицу
    int all_lenght_head = 5;
    for (int i : lenght_head)
    {
        all_lenght_head += i;
    }

    for (int i = 0; i < all_lenght_head; i++)
        std::cout << '_';
    std::cout << std::endl;

    std::cout << '|'; // Выводим шапку таблицы
    int c;            // Сколько клеток заполнять
    for (int i = 0; i < 4; i++)
    {
        c = int((lenght_head[i] - start_lenght_head[i]) / 2);
        for (int j = 0; j < c; j++)
            std::cout << ' ';
        std::cout << head[i];
        c = lenght_head[i] - c - start_lenght_head[i];
        for (int j = 0; j < c; j++)
            std::cout << ' ';
        std::cout << '|';
    }
    std::cout << std::endl;

    for (int i = 0; i < all_lenght_head; i++)
        std::cout << '_';
    std::cout << std::endl;

    // Выводим значения таблицы
    // line - номер строки (начиная с 0)

    for (int line = 0; line < count_; line++)
    {
        std::cout << '|';

        build_line(lenght_head[0], lenght_x[line], x, line); // Столбик x

        build_line(lenght_head[1], lenght_f[line], f, line); // Столбик f(x)

        build_line(lenght_head[2], lenght_n[line], n, line); // Столбик n

        build_line(lenght_head[3], lenght_e[line], e, line); // Столбик e^(-x^2)
        std::cout << std::endl;
    }

    for (int i = 0; i < all_lenght_head; i++)
        std::cout << '_';
}