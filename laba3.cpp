#include <iostream> 
#include <cmath>
#include <vector>
using namespace std;

// Функция для ввода int
int int_num()
{
    int number;
    std::cout << "Write number: ";
    std::cin >> number;
    
    if (!std::cin)
    {
        std::cout << "Error, wrong input" << std::endl;
    }
    else
    {
        return number;
    }
}

/* Точка координат.
Создайте сущность Точка, расположенную на двумерной плоскости, которая описывается:
• Координата Х: число
• Координата Y: число
• Может возвращать текстовое представление вида “{X;Y}”
Необходимо создать три точки с разными координатами и вывести на экран их текстовое
представление. */

class point
{
private:
    /* data */
public:
    int x_pos;
    int y_pos;

    void print()
    {
        printf("{%d; %d}", x_pos, y_pos);
    }

    void change(int x_new, int y_new)
    {
        x_pos = x_new;
        y_pos = y_new;
    }
};


/* Прямая.
Создайте сущность Линия, расположенную на двумерной плоскости, которая описывается:
• Координата начала: Точка
• Координата конца: Точка
• Может возвращать текстовое представление вида “Линия от {X1;Y1} до {X2;Y2}”
Для указания координат нужно использовать сущность Точка, разработанную в задании 1.1. Создайте
линии со следующими характеристиками:
1. Линия 1 с началом в т. {1;3} и концом в т.{23;8}.
2. Линия 2, горизонтальная, на высоте 10, от точки 5 до точки 25.
3. Линия 3, которая начинается всегда там же, где начинается линия 1, и заканчивается
всегда там же, где заканчивается линия 2. Таким образом, если положение первой или
второй линии меняется, то меняется и третья линия.
4. После создания всех трех объектов измените координаты первой и второй линий, причем
сделайте это таким образом, чтобы положение третьей линии соответствовало
требованиям пункта 3.
5. Измените координаты первой линии так, чтобы при этом не изменились, координаты
третьей линии.*/

class straight

{
private:
    /* data */
public:
    point str_begin;
    point str_last;

    void print()
    {
        cout << "Line from ";
        str_begin.print();
        cout << " to "; 
        str_last.print();
    }

    void change(point new_p_begin, point new_p_last)
    {
        str_begin = new_p_begin;
        str_last = new_p_last;
    }
};

/* Студент.
Создайте сущность Студент, которая описывается:
• Имя: строка
• Оценки: массив целых чисел.
• Может возвращать текстовое представление вида “Имя: [оценка1, оценка2,…,оценкаN]”
Необходимо выполнить следующие задачи:
1. Создать студента Васю с оценками: 3,4,5.
2. Создать студента Петю и скопировать оценки Васи, присвоив содержимое поля с
оценками Васи полю с оценками Пети.
3. Заменить первую оценку Пети на число 5. Вывести на экран строковое представление
Васи и Пети. Объяснить результат
4. Создать студента Андрея и скопировать ему оценки Васи так, чтобы изменение оценок
Васи не влияло на Андрея.*/

void showvector(vector<int> g)
{
    vector<int>::iterator it;
    for (it = g.begin(); it != g.end(); ++it)
        cout << *it << " ";
}
class student
{
private:
    string name;
    vector<int> grades;
public:
    student(string s_name, vector<int> s_grades)
    {
        name = s_name;
        grades = s_grades;
    }
    void print()
    {
        cout << name << ": ";
        showvector(grades);
        cout << "\n";
    }
    void change()
    {
        auto iter = grades.cbegin();
        grades.erase(iter);
        grades.insert(iter, 5);
    }
};


/* Создаем Точку.
Измените сущность Точка из задачи 1.1. В соответствии с новыми требованиями создать объект
Точки можно только путем указания обеих координат:X и Y.
Необходимо выполнить следующие задачи:
• Создайте и выведите на экран точку с координатами 3;5
• Создайте и выведите на экран точку с координатами 25;6
• Создайте и выведите на экран точку с координатами 7;8
    Создаем Линию.
Измените сущность Линия из задачи 2.1. Новые требования включают:
• Создание Линии возможно с указанием Точки начала и Точки конца (Точки из задачи 4.1)
• Создание Линии возможно с указанием координат начала и конца как четырех чисел
(x1,y1,x2,y2)
Создайте линии со следующими характеристиками:
1. Линия 1 с началом в т. {1;3} и концом в {23;8}.
2. Линия 2, горизонтальная, на высоте 10, от точки 5 до точки 25.
3. Линия 3 которая начинается всегда там же где начинается линия 1, и заканчивается
всегда там же, где заканчивается линия 2.*/

/* Пистолет стреляет.
• Создайте сущность Пистолет, которая описывается следующим образом:
• Имеет Количество патронов (целое число)
• Может быть создан с указанием начального количества патронов
• Может быть создан без указания начального количества патронов, в этом случае он
изначально заряжен пятью патронами.
• Может Стрелять, что приводит к выводу на экран текста “Бах!” в том случае, если
количество патронов больше нуля, иначе делает “Клац!”. После каждого выстрела (когда
вывелся “Бах!”) количество патронов уменьшается на один.
Создайте пистолет с тремя патронами и выстрелите из него пять раз. */
class guns
{
    private:
        int size;
    public:
        void create_gun_5()
        {
            size = 5;
        }

        void create_gun_n(int n)
        {
            size = n;
        }

        void shoot()
        {
            if (size >= 1)
            {
                cout << "Boom!!!\n";
                size = size - 1;
            } 
            else
            {
                cout << "Click!!! No ammo!!!\n";
            }
        }
};

/* Вариант 1 - Лобанов Роман 
Каждая функция в main() это решение 1 задачи*/
int main()
{
    //Задание 1
    cout << "Task 1\n";
    point p1 {1,5};
    point p2 {2,6};
    point p3 {-1,-5};
    cout << "Set points:" << "\n";
    p1.print();
    cout << "\n";
    p2.print();
    cout << "\n";
    p3.print();
    cout << "\n";

    //Задание 2
    cout << "\nTask 2\n";
    
    point p_begin_str1 {1, 3};
    point p_last_str1 {23, 8};
    straight str1 {p_begin_str1, p_last_str1};

    cout << "1 point\n";
    str1.print();

    point p_begin_str2 {5, 10};
    point p_last_str2 {25, 10};
    straight str2 {p_begin_str2, p_last_str2};

    cout << "\n\n2 point\n";
    str2.print();

    straight str3 {p_begin_str1, p_last_str2};
    cout << "\n\n3 point\n";
    str3.print();

    cout << "\n\n4 point\n";
    cout << "Change 1 line on {5, 5} - {10, 10}, 2 line on {6, 6} - {12, 12}\n";
    p_begin_str1.change(5, 5);
    p_last_str1.change(10, 10);
    p_begin_str2.change(6, 6);
    p_last_str2.change(12, 12);

    cout << "Changed 1 line \n";
    str1.change(p_begin_str1, p_last_str1); 
    str1.print();
    cout << "\n";
    cout << "Changed 2 line \n";
    str2.change(p_begin_str2, p_last_str2);
    str2.print();
    cout << "\n";
    cout << "Changed 3 line \n";
    str3.change(p_begin_str1, p_last_str2);
    str3.print();
    cout << "\n";

    cout << "\n5 point\n";
    p_last_str1.change(100, 100);
    str1.change(p_begin_str1, p_last_str1);
    cout << "Changed 1 line\n";
    str1.print();
    cout << "\n3 line\n";
    str3.print();
    cout << "\n";

    //Задание 3
    cout << "\nTask 3\n";
    vector<int> grades = {3, 4, 5};
    student Vasya {"Vasya", grades};
    Vasya.print();
    student Petya {"Petya", grades};
    Petya.print();
    auto iter = grades.cbegin();
    grades.erase(iter);
    grades.insert(iter, 5);
    cout << "Changed grades: ";
    showvector(grades);
    cout << "\n";
    Vasya.print();
    Petya.print();
    Vasya.change();
    vector<int> grades_A = {5, 5, 5};
    student Andrew {"Andrew", grades_A};
    cout << "All students:\n";
    Vasya.print();
    Petya.print();
    Andrew.print();
    cout << "\n";

    //Задание 4
    cout << "Task 4"
    point zad4_p1 = {3, 5};
    point zad4_p2 = {25, 6};
    point zad4_p3 = {7, 8};
    zad4_p1.print();
    cout << "\n";
    zad4_p2.print();
    cout << "\n";
    zad4_p3.print();
    cout << "\n";

    //Задание 5
    cout << "\nTask 5\n";
    guns g1;
    g1.create_gun_n(3); 
    g1.shoot();
    g1.shoot();
    g1.shoot();
    g1.shoot();
    g1.shoot();
    return 0;
}