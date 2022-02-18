#include <iostream>
#include "Person.h"
#include "Addressbooks.h"
#include "Func.h"

using namespace std;

int main(){
    int select = 0;

    Addressbooks abs;


    while(true){
        showMenu();
        cin >> select;
        
        switch (select)
        {
        case 1:
            addPerson(&abs);
            break;
        case 2:
            showPerson(&abs);
            break;
        case 3:
            deletePerson(&abs);
            break;
        case 4:
            findPerson(&abs);
            break;
        case 5:
            modifyPerson(&abs);
            break;
        case 6:
            cleanPerson(&abs);
            break;
        case 0:
            cout << "Welcome to use next!" << endl;
            return 0;
            break;
        default:
            cout << "Input Invalid!" << endl;
            break;
        }

    }

    return 0;
}


