// 19 задание 2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
int main()
{
    std::cout << "Hello World!\n";
    std::string  failePath;
    std::cout << "Input path to the file: ";
    std::getline(std::cin,failePath);
    std::ifstream faile;
    faile.open(failePath, std::ios::binary);
   
    faile.open("C:\\practice\\words.txt");
    if (!faile.is_open())
    {
        std::cout << "file not open";
        return 1;
    }
    const int bufferSize = 1024;
    char buffer[bufferSize];
    while (!faile.eof())
    {
        faile.read(buffer,bufferSize);
         int bytesRead = faile.gcount();
        std::cout.write(buffer, bytesRead);
    }
    faile.close();
    return 0;
}
