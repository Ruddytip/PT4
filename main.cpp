#include <iostream>
#include <ctime>

// Task 1
// Реализовать функцию перевода чисел из десятичной системы в двоичную, используя рекурсию.
// ============================================================== //
void Dec_to_Bin(const int data, std::string& str){
    str+= ((data % 2) == 0 ? "0" : "1");
    if ((data / 2) != 0)
        Dec_to_Bin(data / 2, str);
}
std::string Decimal_to_Binary(const int data){
    std::string str, out;
    Dec_to_Bin(data, str);
    out = str;
    for(int i = 0; i < str.length(); ++i)
        out[i] = str[str.length() - 1  - i];
    return out;
}
// ============================================================== //

// Task 2-1
// Реализовать функцию возведения числа [a] в степень [b] рекурсивно
// ============================================================== //
int power(const int a, const int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    return power(a, b - 1) * a;
}
// ============================================================== //

// Task 2-2
// Реализовать функцию возведения числа [a] в степень [b] рекурсивно, используя свойство чётности степени
// (то есть, если степень, в которую нужно возвести число, чётная, основание возводится в квадрат,
// а показатель делится на два, а если степень нечётная - результат умножается на основание, а показатель уменьшается на единицу)
// ============================================================== //
int power2(const int a, const int b){
    if (b == 0) return 1;
    if (b == 1) return a;
    if (b % 2 == 0 )
        return power2(a * a, b / 2);
    else
        return power2(a, b - 1) * a;
}
// ============================================================== //

// Task 3
// Реализовать нахождение количества маршрутов шахматного короля с учётом ограничений на перемещение из урока, с препятствиями
// (где единица - это наличие препятствия, а ноль - свободная для хода клетка)
// ============================================================== //
const int X = 5;
const int Y = 5;
void init_field(int data[X][Y]){
    srand(time(NULL));
    for(int j = 0; j < Y; ++j)
        for(int i = 0; i < X; ++i){
            data[i][j] = (rand() % 10 >= 7 ? -1 : 0);
        }
    data[0][0] = 0;
}
void print_field(const int data[X][Y]){
    for(int j = 0; j < Y; ++j){
        for(int i = 0; i < X; ++i){
            if(data[i][j] < 0)
                std::cout << "x  ";
            else
                std::cout << data[i][j] << "  ";
        }
        std::cout << std::endl;
    }
}
void check(const int x, const int y, int count, int data[X][Y]){
    if(data[x][y] == -1) return;
    if(count >= data[x][y] && count != 0) return;
    data[x][y] = count;
    if(x > 0)       check(x - 1, y, count + 1, data);
    if(y > 0)       check(x, y - 1, count + 1, data);
    if(x < X - 1)   check(x + 1, y, count + 1, data);
    if(x < Y  -1)   check(x, y + 1, count + 1, data);
}
void find_route(int data[X][Y]){
    check(0, 0, 0, data);
}
// ============================================================== //

int main(){
    // Task 1
    // int data(0);
    // std::cin >> data;
    // std::cout << Decimal_to_Binary(data) << std::endl;

    // Task 2-1
    // std::cout << power(2, 8);

    // Task 2-2
    // std::cout << power2(2, 10);

    // Task 3
    int field[X][Y];
    init_field(field);
    find_route(field);
    print_field(field);
    return 0;
}