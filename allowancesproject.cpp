#include<iostream>
#include<string>
#include<fstream>

using namespace std;
class info{
    string category,username,password;
public:
    void getdata(string category,string username,string password){
        this-> category=category;
        this-> username=username;
        this-> password=password;
    }
    string set_category(){
        return category;
    }
    string set_username(){
        return username;
    }
    string set_password(){
        return password;
    }
};
int expanse_st(){
       int total,total_TA,Days,DA,TA_to,TA_fro,reg_fee;
st_DA:{
    cout<<"\nenter DA(<=550):";
       cin>>DA;
    if(DA<=550){
    st_TA:{
        cout<<"\nenter TA:from source to destination:\n";
        cin>>TA_to;
        cout<<":from destination to source:";
        cin>>TA_fro;
        total_TA = TA_to + TA_fro;
        if(total_TA<=4500){
        st_D:{
            cout<<"\nenter no. of days(max=6days):";
            cin>>Days;
            if(Days<=6){
                
                cout<<"\nenter registration fee:";
                cin>>reg_fee;
                total = DA + total_TA + reg_fee;
                cout<<"total TA:"<<total;
                return total;
            }
            else{
                cout<<"no. of days<=6";
                goto st_D;
            }
        }
        }
        else{
            cout<<"total TA<=4500 for student";
            goto st_TA;
        }
    }
    }
    else{
        cout<<"DA<=550 for student";
        goto st_DA;
    }
}
    
}
int expanse_f(){
       int total,total_TA,Days,DA,TA_to,TA_fro,reg_fee;
f_DA:{
    cout<<"\nenter DA(<=750):";
       cin>>DA;
    if(DA<=750){
    f_TA:{
        cout<<"\nenter TA:from source to destination:\n";
        cin>>TA_to;
        cout<<":from destination to source:";
        cin>>TA_fro;
        total_TA = TA_to + TA_fro;
        if(total_TA<=6000){
        f_D:{
            cout<<"\nenter no. of days(max=6days):";
            cin>>Days;
            if(Days<=6){
                
                cout<<"\nenter registration fee:";
                cin>>reg_fee;
                total = DA + total_TA + reg_fee;
                cout<<"total TA:"<<total;
                return total;
            }
            else{
                cout<<"no. of days<=6";
                goto f_D;
            }
        }
        }
        else{
            cout<<"total TA<=6000 for faculty";
            goto f_TA;
        }
    }
    }
    else{
        cout<<"DA<=650 for faculty";
        goto f_DA;
    }
}
    
}
int login(string category,string username,string password )
{
    string word;
    // Creation of ifstream class object to read the file
      ifstream fin;
      // by default open mode = ios::in mode
      fin.open("info1.txt",ios::in);
              // extracting words from the file
    int i=1,c_category=1,c_username=2,c_password=3;
  while(fin>>word){
             if((i%3==1 && category==word))
                     c_category=0;
             if((i%3==2 && username==word))
                 c_username=0;
             if(i%3==0 && password==word)
                 c_password=0;
             if(c_username==c_password)
                 return 1;
             i++;
         }
         return 0;
     }

int sign_up(string category,string username,string password)
{
    // Creation of ofstream class object
      ofstream fout;
    
      fout.open("info1.txt",ios::app);
          // Read a Line from standard input
          // Write line in file
          fout<<category<<"\t"<<username<<"\t"<<password<< endl;
      // Close the File
      fout.close();
      return 0;
}

int main()
{
    string category,username,password;
    int loginsuccess;
    info xyz;
    cout<<"!!!WELCOME!!!\n";
    cout<<"LOGIN INTERFACE\n";
    cout<<"following categories are:\n"<<"student\nfaculty\nfinance_officer\naudit_officer";
    cout<<"\nEnter your category:";
    cin>>category;
    cout<<"\nEnter username:";
    cin>>username;
    cout<<"\nEnter password:";
    cin>>password;
    xyz.getdata(category,username,password);
        //for login
    loginsuccess=login(xyz.set_category(),xyz.set_username(),xyz.set_password());
    if(loginsuccess==1)
    {
        cout<<"login successfully";
        //further process
        if(xyz.set_category()=="student"){
            string event_name;
            cout<<"enter event_name:";
            cin>>event_name;
            ofstream fout;
            fout.open("info2.txt",ios::app);
            fout<<xyz.set_category()<<" "<<xyz.set_username()<<" "<<event_name<<" "<<expanse_st()<<"\n";
            fout.close();
        }
        else if(xyz.set_category()=="faculty"){
            string event_name;
            cout<<"enter event_name:";
            cin>>event_name;
            ofstream fout;
            fout.open("info2.txt",ios::app);
            fout<<xyz.set_category()<<" "<<xyz.set_username()<<" "<<event_name<<" "<<expanse_f()<<"\n";
            fout.close();
        }
        else if(xyz.set_category()=="finance_officer"){
            //finance officer
        }
        else if(xyz.set_category()=="audit_officer"){
            //audit officer
        }
    }
    else
    {
        cout<<"\nplease check your credentials or signup as a new user by pressing -1\n";
        int input;
        cin>>input;
        if(input==-1){
        int success=sign_up(xyz.set_category(),xyz.set_username(),xyz.set_password());
        if(success==0)
            cout<<"your account has been created\n";
        else
            cout<<"something went wrong";
        }
        else
            return 0;
    }
}


