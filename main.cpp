// Su nombre aqui


#include <vector>
#include "LList.h"
#include <iostream>
using namespace std;

// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
        printf("\x1B[31mAssertion (%s) failed %s at line %d\033[0m\t\t\n", #chk, __FILE__,__LINE__); \
    else { \
        printf("\x1B[32mPassed line %d: %s\033[0m\t\t\n", __LINE__, #chk); \
        passedAssertions++; \
    }
#define assertionReport() { \
     printf("==========================================\n"); \
     printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
     printf("\n"); \
    }
//*******************************************************


// You can erase the assertions and just leave the ones for the 
// new member functions that you are creating.

int main() {

    LList L;

    // Lets test the insertion and moving through the list
    L.append(10);
    L.append(20);
    expect(L.to_string()=="<|10,20>");
    
    L.next();
    expect(L.to_string()=="<10|20>");

    L.next();
    expect(L.to_string()=="<10,20|>");
    
    L.next();
    expect(L.to_string()=="<10,20|>");
    
    // Lets append one and then remove it
    L.append(30);
    expect(L.to_string()=="<10,20|30>");
    expect(L.remove() == 30);
    expect(L.to_string()=="<10,20|>");
    L.prev();
    L.prev();
    expect(L.to_string()=="<|10,20>");
    
    // Does clear work?
    L.clear();
    L.append(70);
    expect(L.to_string()=="<|70>");

    // How about insert ...
    L.insert(66);
    expect(L.to_string()=="<|66,70>");
    L.moveToEnd();
    L.insert(77);
    L.moveToEnd();
    expect(L.to_string()=="<66,70,77|>");

    L.moveToPos(0);
    expect(L.to_string()=="<|66,70,77>");

    L.moveToPos(2);
    expect(L.to_string()=="<66,70|77>");

    L.moveToEnd();
    expect(L.to_string()=="<66,70,77|>");

    LList M;
    M = L;
    expect(M.to_string()=="<66,70,77|>");
    M.append(42);
    expect(M.to_string()=="<66,70,77|42>");
    expect(L.to_string()=="<66,70,77|>");

    assertionReport();    

    
}

