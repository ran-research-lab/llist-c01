// Su nombre aqui


#include <vector>
#include "LList.h"
using namespace std;

// Variables and macros for assertions, DO NOT CHANGE ****
int totalAssertions = 0;
int passedAssertions  = 0;
#define expect( chk )  \
    totalAssertions++; \
    if (!(chk)) \
        printf("Assertion (%s) failed %s at line %d \n", #chk, __FILE__,__LINE__); \
    else { \
        printf("Passed line %d: %s \n", __LINE__, #chk); \
        passedAssertions++; \
    }
#define assertionReport() { \
     printf("Passed %d of %d assertions\n",passedAssertions,totalAssertions); \
     cout << endl; \
    }
//*******************************************************



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

}
