#ifndef INHERITANCE_H
#define INHERITANCE_H
#include <iostream>
using namespace std;

//height comparison
class athlete{
    protected:
        string name;
        int height;

    public:
        athlete();
        athlete(int height, string name){
            this->height = height;
            this->name = name;
        }
        void setHeight(int h){
            height = h;
        }
        int getHeight(){
            return height;
        }
        void setName(string n){
            name = n;
        }
        string getName(){
            return name;
        }
};

class footballPlayer : public athlete{
    public:
        footballPlayer();
        footballPlayer(double fortyYard, int height, string name){
            this->fortyYard = fortyYard;
            this->name = name;
            this->height = height;
        }
        double fortyYard;
        void setTime(int t){
            fortyYard = t;
        }
        int getTime(){
            return fortyYard;
        }
};

class basketballPlayer : public athlete{
    public:
        basketballPlayer();
        basketballPlayer(int vertical, int height, string name){
            this->vertical = vertical;
            this->height = height;
            this->name = name;
        }
        int vertical;
        void setVertical(int v){
            vertical = v;
        }
        int getVertical(){
            return vertical;
        }
};

#endif