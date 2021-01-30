#include <iostream>
#include "list.h"
#include "inheritance.h"
using namespace std;

int main(){
    LinkedList list;
    LinkedList empty;
    athlete a1;
    a1.setHeight(176);
    a1.setName("James Kerr");
    list.insert(&a1);

    basketballPlayer bPlayer;
    bPlayer.setVertical(45);
    bPlayer.setHeight(175);
    bPlayer.setName("John Kane");
    list.insert(&bPlayer);  

    footballPlayer fPlayer;
    fPlayer.setTime(4.3);
    fPlayer.setHeight(175);
    fPlayer.setName("John Kane");
    list.insert(&fPlayer);

    list.printList();

    list.mergeSort();
};