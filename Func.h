#pragma once

#include "Person.h"
#include "Addressbooks.h"
#include <iostream>

using std::cout;
using std::cin;
using std::string;
using std::endl;

void showMenu();
void addPerson(Addressbooks*);
void showPerson(const Addressbooks*);
int isExist(const Addressbooks*, string);
void deletePerson(Addressbooks*);
void findPerson(Addressbooks*);
void modifyPerson(Addressbooks*);
void cleanPerson(Addressbooks*);