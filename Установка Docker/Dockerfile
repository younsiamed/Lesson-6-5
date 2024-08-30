# Используем базовый образ Ubuntu 16.04
FROM ubuntu:16.04

# Устанавливаем необходимые пакеты
RUN apt-get update && apt-get install -y \
    gcc \
    nano \
    && rm -rf /var/lib/apt/lists/*

# Создаем рабочую директорию
WORKDIR /app

# Копируем исходный код
COPY hello.c .

# Компилируем приложение
RUN gcc -o hello hello.c

# Запускаем приложение
CMD ["./hello"]
