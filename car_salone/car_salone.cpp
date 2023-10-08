#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

class  car_dealership {
    std::multimap<std::string,std::string> catalog;
    std::string name; std::string date; std::string v_of_engine; std::string price;
public:
    //�������� ������ � �������
    void AddCar() {
        std::cout << "������� �������� ������: \n";
        getline(std::cin,name);

        std::cout << "������� ��� �������: \n";
        getline(std::cin, date);
        catalog.insert(make_pair(name,date));

        std::cout << "������� ����� ���������: \n";
        getline(std::cin, v_of_engine);
        catalog.insert(make_pair(name,v_of_engine));

        std::cout << "������� ����: \n";
        getline(std::cin, price);
        catalog.insert(make_pair(name, price));

        
    }

    //���������� �������
    void Show() {
        std::string currentName;
        int count = 0;
        std::string array[3] = {"��� �������: ","����� ���������: ","����: "};
        std::cout << "------�������-----" << std::endl<<std::endl;
        for (auto it = catalog.begin(); it != catalog.end(); it++) {
            if (count == 3) {
                count = 0;
            }
            std::string n = it->first;
            std::string spec = it->second;

            if (n != currentName) {
                if (it != catalog.begin()) {
                    std::cout << std::endl;
                }
                std::cout << "-----" << n << "-----" << std::endl;
                currentName = n;
            }

            std::cout <<array[count]<<spec<<std::endl;
            count++;
        }
    }

    //������� �� �������
    void DeleteCar(){
        
        std::cout << "������� �������� ���������� ������� �� ������ �������"<<std::endl;
        getline(std::cin, name);

        auto itr = catalog.begin();
        while ( itr != catalog.end()) {
            if (itr->first == name) {
                itr = catalog.erase(itr);
            }
            else {
                ++itr;
            }
        }
    }

    //������������� �� ����������
    void Sort(){
        int choose;
        std::cout << "�������� �������� �� ������ �� ������ �������������: \n";
        std::cout << " 1.��� �������" << std::endl;
        std::cout << " 2.����� ���������" << std::endl;
        std::cout << " 3.����" << std::endl;
        std::cout << " ����� -> ";
        std::cin >> choose;
        std::cin.ignore();
        switch (choose)
        {
        case 1:
            std::cout << "������� ��� �������:" << std::endl;
            getline(std::cin, date);
            std::for_each(catalog.begin(), catalog.end(), [&](auto& pair) {
                type_of_sort(date, pair);
                });
            break;
        case 2:
            std::cout << "������� ����� ���������:" << std::endl;
            getline(std::cin, v_of_engine);
            std::for_each(catalog.begin(), catalog.end(), [&](auto& pair) {
                type_of_sort(v_of_engine, pair);
                });
            break;
        case 3:
            std::cout << "������� ����:" << std::endl;
            getline(std::cin, price);
            std::for_each(catalog.begin(), catalog.end(), [&](auto& pair) {
                type_of_sort(price, pair);
                });
            break;
        default:
            break;
        }
        
    }
    //�� ��� ��������� ����������
    void type_of_sort(std::string type_of_sort, std::pair<std::string, std::string> pair) {
        std::string array[3] = { "��� �������: ","����� ���������: ","����: " };
        int count = 0;
        std::cout << std::endl;
        if (pair.second == type_of_sort) {
            std::cout << "------" << pair.first << "------" << std::endl;
            for (auto it = catalog.begin(); it != catalog.end(); it++) {
                if (count == 3) {
                    count = 0;
                }
                if (pair.first == it->first) {
                    std::cout << array[count]<< it->second << std::endl;
                    count++;
                }
            }
        }
    }
};

class Menu : public car_dealership {
    int choice = 0;
public:
    void menu() {
        do {
            std::cout << "------------------------------------\n";
            std::cout << "�������� ����������� ��������:\n"
                << "1. �������� ������ � �������\n"
                << "2. ���������� �������\n"
                << "3. ������������� �������\n"
                << "4. ������� ������ �� ��������\n"
                << "5. �����\n\n"
                << "����� -> ";
            std::cin >> choice;
            std::cin.ignore();
            switch (choice)
            {
            case 1:
                AddCar();
                break;
            case 2:
                Show();
                break;
            case 3:
                Sort();
                break;
            case 4:
                DeleteCar();
                break;
            case 5:
                exit(0);
                break;
            default:
                break;
            }
        } while (choice != 5);
    }
};



int main()
{
    setlocale(LC_ALL, "ru");
    Menu m;
    car_dealership c;
    //c.AddCar();
    m.menu();

    

}

