#include <exception>
#include <iostream>
#include <string>
#include <ostream>

using std::string, std::cout, std::endl, std::ostream;


class math_exception{
    string msg;
public:
    math_exception(string m) : msg(m) {
        cout << "math_exception: " << msg << endl;
    }
    string get_msg() const { return msg; }
};

class division_exception : public math_exception{
public:
    division_exception(string m) : math_exception(m) {}
};

class value_excetion : public math_exception{
public:
    value_excetion(string m) : math_exception(m) {}

    friend ostream& operator<<(ostream& os, const value_excetion& e){
        os << "value_excetion: " << e.get_msg();
        return os;
    }
};

void func(float op1, float op2){
    if(op1==0){
        throw new division_exception("division exception");
    }else{
        if(op1 < 0){
            throw new value_excetion("value exception");
        }
    }
    cout << "op1/op2 = " << op1/op2 << endl;
}

int main(void){
    try{
        func(0, 1);
        cout << "ok!" << endl;
    }catch(division_exception *e){
        cout << e->get_msg() << endl;
    }catch(value_excetion *e){
        cout << e->get_msg() << endl;
    }
}