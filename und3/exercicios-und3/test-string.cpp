#include <iostream>
#include <string>

using std::cout, std::endl, std::string;

class test{
    string str;
    string str2;
public:
    test(const string& s1, const string& s2){
        str = s1;
        str2 = s2;
    }
    string getStr() const{
        return str;
    }
    void printInfo(){
        cout << "str: " << str << endl;
        cout << "str2: " << str2 << endl;
    }
};

int main(void){
    test t("Hello World", "CU CU CU CU CU      CU");
    t.printInfo();

    return 0;
}