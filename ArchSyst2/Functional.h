#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "Menu.h"
#include "Register.h"

struct row {
    std::string oper;
    std::string first;
    std::string second;
};

void start() {
    int answer;
    std::ifstream index_;
    index_.open("index.txt");
    int size_(0);
    index_ >> size_;
    index_.close();
    do {
        answer = MainMenu();
        
        switch (answer) {
        case 0: {std::cout << "**********************Show file**********************" << std::endl;
            std::ifstream in("file.txt");
            std::string temp;
            if (in.is_open())
            {
                int i(0);
                while (in >> temp)
                {
                    std::cout << temp << " ";
                    i++;
                    if (i % 3 == 0) std::cout << std::endl;
                }
            }
            in.close();     
            _getch(); break; }

        case 1: {std::cout << "**********************Clear file**********************" << std::endl;
            std::ofstream out;
            out.open("file.txt");
            out.close();
            size_ = 0;
            _getch(); break; }

        case 2: {std::cout << "**********************Add new option**********************" << std::endl;
            std::ofstream out;          
            out.open("file.txt", std::ios::app); 
            row temp;
            std::cout << "Enter operation : \t"; std::cin >> temp.oper; std::cout << std::endl;
            std::cout << "Enter first operand : \t"; std::cin >> temp.first; std::cout << std::endl;
            std::cout << "Enter second operand : \t"; std::cin >> temp.second; std::cout << std::endl;
            if (out.is_open()){
                out << temp.oper <<" "<< temp.first << " " << temp.second << std::endl;
            }
            out.close();
            size_++;
            _getch(); break; }

        case 3: {std::cout << "**********************Run program**********************" << std::endl;
            std::ifstream in("file.txt");
            std::string temp;
            std::vector<row> IR; IR.resize(size_);
            if (in.is_open()){
                int i(0),j(0);
                while (in >> temp) {
                    if(j % 3 == 0) IR[i].oper=temp;
                    else if (j % 3 == 1) IR[i].first = temp;
                    else { IR[i].second = temp; i++; }
                    j++;
                }
            }
            in.close();
            int N = 12;
            Register R1,R2,AC;
            R1.Set(N, "R1", rand() % N);
            R2.Set(N, "R2", rand() % N);
            AC.Set(N, "AC", rand() % N);
            for (int i(0); i < IR.size(); i++) {
                std::cout << IR[i].oper << " " << IR[i].first << " " << IR[i].second << std::endl;
                std::cout << AC.name_ << " "; AC.OutputVec();
                std::cout << R1.name_ << " "; R1.OutputVec();
                std::cout << R2.name_ << " "; R2.OutputVec();
                int PC = i, TC = 1; char PS = AC.GetSign();
                std::cout << "PC\t" << PC+1 << std::endl;
                std::cout << "TC\t" << TC << std::endl;
                std::cout << "PS\t" << PS << std::endl;
                _getch();
                if (IR[i].oper == "mov") {
                    int number = std::stoi(IR[i].second);
                    int index = IR[i].first[1]-int('0');
                    if (index == 1)
                        R1.Update(number);
                    else if (index == 2)
                        R2.Update(number);
                    AC.Update(number);
                }
                else {
                    if (IR[i].oper == "add") {
                        std::vector<int> left, right; left.resize(N); right.resize(N);
                        if (IR[i].first == "R1")left = R1.value_vec;
                        else if (IR[i].first == "R2")left = R2.value_vec;
                        else { 
                            int value = std::stoi(IR[i].first);
                            left = R2.Convert(value);
                        }

                        if (IR[i].second == "R1")right = R1.value_vec;
                        else if (IR[i].second == "R2")right = R2.value_vec;
                        else {
                            int value = std::stoi(IR[i].second);
                            right = R2.Convert(value);
                        }

                        AC.value_vec = AC.Add(left,right);
                    }

                }
                std::cout << IR[i].oper << " " << IR[i].first << " " << IR[i].second << std::endl;
                std::cout << AC.name_ << " "; AC.OutputVec();
                std::cout << R1.name_ << " "; R1.OutputVec();
                std::cout << R2.name_ << " "; R2.OutputVec();
                PC = i; TC = 2; PS = AC.GetSign();
                std::cout << "PC\t" << PC+1 << std::endl;
                std::cout << "TC\t" << TC << std::endl;
                std::cout << "PS\t" << PS << std::endl;
                _getch();

            }
            _getch(); break; }

        case 4:  break;

        }
    } while (answer != 4);
    std::ofstream ind_;
    ind_.open("index.txt");
    ind_ << size_;
    ind_.close();

}