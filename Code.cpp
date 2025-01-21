#include<iostream>
#include<fstream>
#include<windows.h>
#include<sstream>

using namespace std;

class Login
{
   private:
   string loginID, Password;
   public:
   Login():loginID(""),Password(""){}

   void setID(string id)
   {
     loginID = id;
   }
   void setpassword(string pw)
   {
     Password = pw;
   }
   string getId()
   {
     return loginID;
   }
   string getpw()
   {
     return Password;
   }
};

void registration(Login log) 
{
    system("cls");
    string id,pw;
    cout<<"\tEnter the login id : ";
    cin>>id;
    log.setID(id);
    start:
    cout<<"\tEnter the strong 8-Digit password : ";
    cin>>pw;
    if(pw.length()>=8)
    {
        log.setpassword(pw);
    }
    else
    {
        cout<<"\tEnter 8 minimum character";
        goto start;
    }
    ofstream outfile("C:/projects practice/login.txt",ios :: app);
    if(!outfile)
    {
      cout<<"\tError: File Can't Open"<<endl;
    }
    else
    {
      outfile<<"\t"<<log.getId()<<" : "<<log.getpw()<<endl<<endl;
      cout<<"\tUser Registrered Successfully!"<<endl;
    }
    outfile.close();
    Sleep(3000);
}

void login()
{
  system("cls");
  string id,pw;
  cout<<"\tEnter login id : ";
  cin>>id;
  cout<<"\tEnter password : ";
  cin>>pw;
  ifstream infile("C:/projects practice/login.txt");
  if(!infile)
  {
    cout<<"\tError:File Can't be Open!"<<endl;
  }
  else
  {
    string line;
    bool found  = false;
    while(getline(infile,line))
    {
      stringstream ss;
      ss<<line;
      string userId,userPW;
      char delimeter;
      ss>>userId>>delimeter>>userPW;
      if(id == userId && pw == userPW)
      {
        found = true;
        cout<<"\tPlease wait"<<endl;
        for(int i = 0;i<3;i++)
        {
          cout<<".";
          Sleep(800);
        }
        system("cls");
        cout<<"\tWelcome to this page"<<endl;
      }
    }
    if(!found)
    {
      cout<<"Error : Incorrect Login ID or Password!"<<endl;
    }
  }
  infile.close();
  Sleep(3000);
}

int main()
{
    Login log;
    bool exit = false;
    while(!exit)
    {
        system("cls");
        int val;
        cout<<"Welcome To Registration & Login Form"<<endl;
        cout<<"\t..................................."<<endl;
        cout<<"\t1.Register"<<endl;
        cout<<"\t2.Login"<<endl;
        cout<<"\t3.Exit"<<endl;
        cout<<"Enter choice : ";
        cin>>val;
        

        if(val == 1)
        {
          registration(log);
        }
        else if(val == 2)
        {
          login();
        }
        else if (val == 3)
        {
          system("cls");
          exit= true;
          cout<<"\tGood Luck!"<<endl;
          Sleep(3000);
        }
        Sleep(3000);
    }
}
