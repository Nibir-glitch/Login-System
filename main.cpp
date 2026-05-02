#include<iostream>
#include<string>
#include<fstream>
#include<map>
using namespace std;

void showMenu(){
    cout<<"Welcome!!!"<<endl;
    cout<<"Enter your choice..."<<endl;
    cout<<"Press 1 for login."<<endl;
    cout<<"Press 2 for sign up."<<endl;
    cout<<"If your forgot your password then press 3 for recovery."<<endl;
    cout<<"Press 4 to exit."<<endl;
}

class Person{
    private:
        string userName;
        string Email;
        string password;
    public:
        Person(){}
        void login();
        void signUp();
        void forgetPass();
};

int main(){
    showMenu();
    while(1){
        char op;
        cin>>op;
        cin.ignore();
        Person obj;
        switch(op){
            case '1':
                obj.login();
                break;
            case '2':
                obj.signUp();
                break;
            case '3':
                obj.forgetPass();
                break;
            case '4':
                return 0;
            default:
                cout<<"Invalid input."<<endl;
                showMenu();
                break;
        }
    }
}

void Person::login(){
    fstream fp;
    fp.open("Info.txt",ios::in);
    cout<<"--------------LOGIN-----------------"<<endl;
    string uname, pass;
    cout<<"Enter username: ";
    cin>>uname;
    cout<<endl;
    cout<<"Enter Password: ";
    cin>>pass;
    cout<<endl;
    string USERNAME, EMAIL, PASSWORD;
    while(!fp.eof()){
        getline(fp,USERNAME,',');
        getline(fp,EMAIL,',');
        getline(fp,PASSWORD,'\n');
        if(USERNAME == uname){
            if(PASSWORD == pass){
                cout<<"Login successful!"<<endl;
                return;
            } else {
                cout<<"Wrong password!"<<endl;
            }
        }
    }
    cout<<"Username with "<<uname<<" doesn't exist! You need to sign up";
    fp.close();
}

void Person::signUp(){
    string uname, email, pass;
    cout<<"Enter your Username: ";
    cin>>uname;
    cout<<"Enter your Email: ";
    cin>>email;
    fstream check;
    check.open("Info.txt",ios::in);
    string u,e,p;
    while(!check.eof()){
        getline(check,u,',');
        getline(check,e,',');
        getline(check,p,'\n');
        if(u==uname) {
            cout<<"Username already exists. Try again!"<<endl;
            showMenu();
            return;
        } else if(e==email){
            cout<<"Email already exists. Try a new email."<<endl;
            showMenu();
            return;
        }
    }
    cout<<"Enter the Password: ";
    cin>>pass;
    fstream fp;
    fp.open("Info.txt",ios::app);
    fp<<uname<<","<<email<<","<<pass<<'\n';
    fp.close();
    cout<<"Sign up successful.\nWelcome "<<uname<<endl;
}

void Person::forgetPass(){
    string uname, email;
    cout<<"Enter your username: ";
    cin>>uname;
    cout<<"Enter your email with which you had signed up: ";
    cin>>email;
    fstream fp;
    fp.open("Info.txt", ios::in);
    string USERNAME, EMAIL, PASS;
    while(!fp.eof()){
        getline(fp,USERNAME,',');
        getline(fp,EMAIL,',');
        getline(fp,PASS,'\n');
        if(USERNAME == uname && EMAIL == email){
            cout<<"Password is: "<<PASS<<endl;
            return;
        }
    }
    cout<<"This account doesn't exist."<<endl;
}
