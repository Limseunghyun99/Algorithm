#include <iostream>
#include <sstream>
using namespace std;

class Student{
    private:
        int age, standard;
        string first_name, last_name;
    public:
        void set_age(int input_age){
            this->age=input_age;
        }
        void set_standard(int input_standard){
            this->standard = input_standard;
        }
        void set_first_name(string input_first){
            this->first_name=input_first;
        }
        void set_last_name(string input_last){
            this->last_name = input_last;
        }
        
        int get_age(){
            return this->age;
        }
        int get_standard(){
            return this->standard;
        }
        string get_first_name(){
            return this->first_name;
        }
        string get_last_name(){
            return this->last_name;
        }
        string to_string(){
            string tmp = std::to_string(this->age);
            tmp += ",";
            tmp += this->first_name;
            tmp += ",";
            tmp += this->last_name;
            tmp += ",";
            tmp += std::to_string(this->standard);
            return tmp;
        }
};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}
