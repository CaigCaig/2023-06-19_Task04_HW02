#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>

class Address {
private:
    std::string city;
    std::string street;
    int home_num;
    int apart_num;
public:
    std::string get_output_address() {
        return (city + ", " + street + ", " + std::to_string(home_num) + ", " + std::to_string(apart_num) + "\n");
    }
    std::string get_city() { return city; }
    void Set_Address(std::string city, std::string street, int home_num, int apart_num) {
        this->city = city;
        this->street = street;
        this->home_num = home_num;
        this->apart_num = apart_num;
    }
    Address(std::string city, std::string street, int home_num, int apart_num) {
        this->city = city;
        this->street = street;
        this->home_num = home_num;
        this->apart_num = apart_num;
    }
    Address() {
        this->city = "City";
        this->street = "Street";
        this->home_num = 0;
        this->apart_num = 0;
    };
};

int str_to_int(std::string s) {
    int num;
    if (s == "") {
        std::cout << "Данные для работы программы отсутствуют!\n";
        system("pause");
        exit(2);
    }
    try {
        num = static_cast<int>(std::stoi(s));
    }
    catch (const std::invalid_argument&) {
        std::cout << "Данные не корректны!\n";
        system("pause");
        exit(3);
    }
    if (!num) {
        std::cout << "Размер массива не может быть равен 0!\n";
        system("pause");
        exit(4);
    }
    return num;
}

void sort(Address* address, int size) {
    for (auto j = size - 1; j > 0; --j) {
        for (auto i = size - 1; i > size - 1 - j; --i) {
            if (address[i].get_city() < address[i - 1].get_city()) std::swap(address[i], address[i - 1]);
        }
    }
}

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);


    std::ifstream fin{ "in.txt" };
    if (!fin.is_open()) {
        std::cout << "Файл in.txt отсутствует!\n";
        system("pause");
        exit(1);
    }
    std::string tmps1, tmps2, tmps3;
    int size_array = 0;
    fin >> tmps1;
    size_array = str_to_int(tmps1);

    std::ofstream fout{ "out.txt" };

    Address* address = new Address[size_array];
    int tmpi1, tmpi2;
    fout << size_array << std::endl;
    for (auto i = 0; i < size_array; i++) {
        fin >> tmps1;
        fin >> tmps2;
        fin >> tmps3;
        tmpi1 = str_to_int(tmps3);
        fin >> tmps3;
        tmpi2 = str_to_int(tmps3);
        address[i].Set_Address(tmps1, tmps2, tmpi1, tmpi2);
    }

    sort(address, size_array);

    for (auto i = 0; i < size_array; i++) {
      fout << address[i].get_output_address();
    }

    delete[] address;
    fin.close();
    fout.close();
}
