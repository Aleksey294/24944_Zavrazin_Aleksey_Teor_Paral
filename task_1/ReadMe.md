Sin Array (float / double)
Описание задания

Программа заполняет массив из 
107
10
7
 элементов значениями функции синуса так, что один период синуса 
[0,2π]
[0,2π] равномерно распределён по всей длине массива.
После заполнения вычисляется сумма всех элементов массива и выводится в терминал.

Тип элементов массива (float или double) выбирается на этапе сборки с помощью CMake.

Сборка проекта
Требования

CMake ≥ 3.10

Компилятор с поддержкой C++17

Сборка с типом float (по умолчанию)
cmake -B build
cmake --build build
./build/sin_array

Сборка с типом double
cmake -B build -DUSE_DOUBLE=ON
cmake --build build
./build/sin_array

Выбор типа массива

Тип массива задаётся CMake-опцией:

USE_DOUBLE=OFF → используется float

USE_DOUBLE=ON → используется double

В коде это реализовано следующим образом:

#ifdef USE_DOUBLE
using real_t = double;
#else
using real_t = float;
#endif
