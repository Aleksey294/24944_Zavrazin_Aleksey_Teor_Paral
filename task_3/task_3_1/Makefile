# Компилятор
CXX = g++

# Флаги компиляции
CXXFLAGS = -std=c++17 -O2 -pthread -Wall

# Имя исполняемого файла
TARGET = benchmark

# Исходный файл
SRC = main.cpp

# Сборка по умолчанию
all: $(TARGET)

# Правило сборки
$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Запуск программы
run: $(TARGET)
	./$(TARGET)

# Очистка
clean:
	rm -f $(TARGET)