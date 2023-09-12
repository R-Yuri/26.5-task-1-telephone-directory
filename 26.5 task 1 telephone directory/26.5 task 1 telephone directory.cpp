// 26.5 task 1 telephone directory.cpp 

#include <iostream>
#include<map>
#include<string>


std::map<std::string, std::string> phoneBook;


//entering the phone number and last name of the subscriber in the phone directory
void addPerson(std::string& telefon , std::string& subscriber) { 
    char stop = 'n';
    std::pair<std::string, std::string> oPair();
    while (true) {
       
        std::cout << "enter subscriber number(69-70-30): " << std::endl;
        std::cin >> telefon;
        //std::cout << "telefon= " << telefon << std::endl;
        std::cout << "enter subscriber's last name:" << std::endl;
        std::cin >> subscriber;
        phoneBook.insert(std::pair<std::string, std::string>(telefon, subscriber));
        
        std::cout << "exit input mode y/n ?" << std::endl;
        std::cin >> stop;
        if (stop == 'y') {
            return;
        }
    }
}

//search for a subscriber by phone number
void findSubscriber(std::string& telefon, std::map<std::string,std::string>& phoneBook) {
    
    std::cout << "enter phone number (for example 69-70-30) : " << std::endl;
    std::cin >> telefon;
    
    std::map < std::string, std::string > ::iterator it = phoneBook.find(telefon); 
    std::cout << it->first << " " << it->second << std::endl;
}


void findPhone(std::string& subscriber, std::map<std::string, std::string>& phoneBook) {
    std::cout << "enter subscriber's last name:" << std::endl;
    std::cin >> subscriber;
    std::map<std::string, std::string>::iterator it = phoneBook.begin();
    bool found = false;
    while (it != phoneBook.end()) {
        if (it->second == subscriber) {
            std::cout << it->first << " " << it->second << std::endl;
            found = true;
        }
        it++;
    }
    if (!found) {
        std::cout << "Phone number not found." << std::endl;
    }
}




int main()
{
    phoneBook.insert(std::make_pair<std::string, std::string>("69-70-30", "Abramson"));
    phoneBook.insert(std::make_pair<std::string, std::string>("69-70-31", "Adamson"));
    phoneBook.insert(std::make_pair<std::string, std::string>("69-70-32", "Backer"));
    phoneBook.insert(std::make_pair<std::string, std::string>("69-70-33", "Backer"));
    phoneBook.insert(std::make_pair<std::string, std::string>("69-70-34", "Backer"));
    int request;
    std::string telefon;
    std::string subscriber;
    bool stop=false;
    while (true) {

        std::cout << "enter a system action request: " << std::endl;
        std::cout << "10 - print the phone book to the console" << std::endl;
        std::cout << "1 - Add a subscriber" << std::endl;
        std::cout << "2 - find a subscriber by phone number" << std::endl;
        std::cout << "3 - find a phone number by the name of the subscriber" << std::endl;

        std::cin >> request;
        if (request == 1) {
            addPerson(telefon,subscriber);
        }
        else if (request == 2) {

            findSubscriber(telefon, phoneBook);

        }
        else if (request == 3) {

            findPhone(subscriber, phoneBook);

        }
        else if (request == 10) {

            for (std::map<std::string,std::string>::iterator it=phoneBook.begin(); it!=phoneBook.end();it++)
            {
                std::cout << it->first << " " << it->second << std::endl;
            }

        }
        else {
            std::cout << "Input Error !" << std::endl;
            stop = true;
            return 0;
        }
       
    }
    return 0;
}
