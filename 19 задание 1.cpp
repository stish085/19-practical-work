﻿// 19 задание 1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>
int main()
{
    std::string findtWord;
    std::cout << "Input word to find: \n";
    std::cin >> findtWord;
    std::ifstream inglishWord;
    inglishWord.open("C:\\practice\\words.txt");
    std::string word;
    int count=0;
    
    
        while (!(inglishWord.eof()))
        {
            inglishWord >> word;

            if (findtWord == word)
            {
                count++;
            }
        }
        std::cout << "Word : " << findtWord << " in quantity: " << count << std::endl;
        inglishWord.close();
        return 0;
    
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
