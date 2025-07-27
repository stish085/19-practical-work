// 19 задание 4.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <string>

int main()
{
    std::cout << "Hello World!\n";
    std::string path;
    std::cout << "Enter the path to the file: \n";
    std::getline(std::cin,path);

    std::ifstream faile;
    faile.open(path, std::ios::binary);
    if (!faile.is_open())
    {
        std::cout << "file not open";
        return 1;
    }
    char header[4];
    faile.read(header,4);
    if (faile.gcount() < 4)
    {
        std::cout << "the file is too short for a PNG file";
        return 1;

    }

        if ( ((signed char)header[0]==-119) && header[1] == 'P' && header[2] == 'N' && header[3] == 'G')
        { 
            std::cout << "A file is  a PNG image";
        }
        else
        {
            std::cout << "A file is not a PNG image ";
        }
        faile.close();
        return 0;
        
}

