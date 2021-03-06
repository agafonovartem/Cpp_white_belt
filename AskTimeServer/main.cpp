//
//  main.cpp
//  AskTimeServer
//
//  Created by Артем on 06.04.2020.
//  Copyright © 2020 Артем. All rights reserved.
//

#include <iostream>
#include <system_error>
#include <exception>


using namespace std;

string AskTimeServer() {
    /* Для тестирования повставляйте сюда код, реализующий различное поведение этой функии:
       * нормальный возврат строкового значения
       * выброс исключения system_error
       * выброс другого исключения с сообщением.
    */
    if (true){
        throw std::system_error(std::error_code());
    }
    return "00:02:04";
}

class TimeServer {
public:
    string GetCurrentTime() {
        try{
            last_fetched_time = AskTimeServer();
            
        }catch(system_error& sys_err){
            cout << sys_err.what();
        }
        return last_fetched_time;
        /* Реализуйте этот метод:
            * если AskTimeServer() вернула значение, запишите его в last_fetched_time и верните
            * если AskTimeServer() бросила исключение system_error, верните текущее значение
            поля last_fetched_time
            * если AskTimeServer() бросила другое исключение, пробросьте его дальше.
        */
    }

private:
    string last_fetched_time = "00:00:00";
};

int main() {
    // Меняя реализацию функции AskTimeServer, убедитесь, что это код работает корректно
    TimeServer ts;
    try {
        cout << ts.GetCurrentTime() << endl;
    } catch (exception& e) {
        cout << "Exception got: " << e.what() << endl;
    }
    return 0;
}
