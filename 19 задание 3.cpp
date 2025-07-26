// 19 задание 3.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <fstream>

int main()
{
    std::cout << "Hello User !\n";
    std::ifstream faile;
    faile.open("C:\\practice\\statement.txt");

    if (!faile.is_open())
    {
        std::cout << "file not open";
        return 1;
    }
    
        std::string surmame, name, answer, lastNameSurmame,data;
        int payments=0, amountOfPayments = 0, cursor, bigPayments =0;
        std::cout << "Faile : "<<std::endl;
        while (!(faile.eof()))
        {   
           
           
           
            faile >> name >> surmame >> payments >> data;
            std::cout << name << " " << surmame << ": "  << payments<< std::endl;
            std::cout << std::endl;
            amountOfPayments += payments;
            if (payments>bigPayments)
            {   
                bigPayments = payments;
                answer = "";
                answer = name + " " + surmame + ": " + std::to_string(payments);
            }
           

        }
        faile.close();
        std::cout << "The sum of all payments: "<< amountOfPayments<<std::endl;
        std::cout << std::endl;
        std::cout << "made the largest payout: " << answer;
        std::cout << std::endl;
        return 0;

}

