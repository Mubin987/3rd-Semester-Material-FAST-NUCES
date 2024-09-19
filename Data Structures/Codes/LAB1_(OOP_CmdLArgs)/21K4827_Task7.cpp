#include <iostream>
using namespace std;
class car{
        string color;
        int model;
        int *p;
        public:
                car(string c , int m){
                        color= c;
                        p= new int;
                        model =m;
                }
                void setc(string c){
                        color = c;
                }
                void setm(int m){
                        model = m;
                }
                void setp(int p1){
                        *p = p1;
                }
                void print(){
                cout << *p << endl;
                cout << color << endl;
                cout << model << endl;
                
        }
        car( car &c1){
                p = new int;
                color=c1.color;
                model= c1.model;
                *p = *(c1.p);
              
        }
        ~car(){
            delete p;
            cout<<"Delete operation performed"<<endl;    
        }
};
int main(){
        car c1("red" , 1234);
        car c2(c1);
        car c3=c1;
        c1.setp(1);
        c2.setp(2);
        c3.setp(3);
        c1.print();
        c2.print();
        c3.print();
}
