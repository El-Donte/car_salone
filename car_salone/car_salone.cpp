#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>

class  car_dealership {
    std::multimap<std::string,std::string> catalog;
    std::string name; std::string date; std::string v_of_engine; std::string price;
public:
    //добавить машину в каталог
    void AddCar() {
        std::cout << "Введите название машины: \n";
        getline(std::cin,name);

        std::cout << "Введите год выпуска: \n";
        getline(std::cin, date);
        catalog.insert(make_pair(name,date));

        std::cout << "Введите объем двигателя: \n";
        getline(std::cin, v_of_engine);
        catalog.insert(make_pair(name,v_of_engine));

        std::cout << "Введите цену: \n";
        getline(std::cin, price);
        catalog.insert(make_pair(name, price));

        
    }

    //отобразить каталог
    void Show() {
        std::string currentName;
        int count = 0;
        std::string array[3] = {"год выпуска: ","объем двигателя: ","цена: "};
        std::cout << "------каталог-----" << std::endl<<std::endl;
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

    //удалить из каталог
    void DeleteCar(){
        
        std::cout << "Введите название автомобиля который вы хотите удалить"<<std::endl;
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

    //отсортировать по параметрам
    void Sort(){
        int choose;
        std::cout << "Выберите параметр по котору вы хотите отсортировать: \n";
        std::cout << " 1.год выпуска" << std::endl;
        std::cout << " 2.объем двигателя" << std::endl;
        std::cout << " 3.цена" << std::endl;
        std::cout << " Выбор -> ";
        std::cin >> choose;
        std::cin.ignore();
        switch (choose)
        {
        case 1:
            std::cout << "введите год выпуска:" << std::endl;
            getline(std::cin, date);
            std::for_each(catalog.begin(), catalog.end(), [&](auto& pair) {
                type_of_sort(date, pair);
                });
            break;
        case 2:
            std::cout << "введите объем двигателя:" << std::endl;
            getline(std::cin, v_of_engine);
            std::for_each(catalog.begin(), catalog.end(), [&](auto& pair) {
                type_of_sort(v_of_engine, pair);
                });
            break;
        case 3:
            std::cout << "введите цену:" << std::endl;
            getline(std::cin, price);
            std::for_each(catalog.begin(), catalog.end(), [&](auto& pair) {
                type_of_sort(price, pair);
                });
            break;
        default:
            break;
        }
        
    }
    //то что выполняет сортировку
    void type_of_sort(std::string type_of_sort, std::pair<std::string, std::string> pair) {
        std::string array[3] = { "год выпуска: ","объем двигателя: ","цена: " };
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
            std::cout << "Выберите необходимое действие:\n"
                << "1. Добавить машину в каталог\n"
                << "2. Отобразить каталог\n"
                << "3. Отсортировать каталог\n"
                << "4. Удалить машину из каталога\n"
                << "5. Выход\n\n"
                << "Выбор -> ";
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

