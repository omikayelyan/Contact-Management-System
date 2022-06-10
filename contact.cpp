#include <iostream>
#include <fstream>

class Information
{
public:
  Information(){};
  ~Information(){};
  void add();
  void list(); 
  void search();
  void edit();
  void delete_inf();
  private:    
  std::string _name;
  std::string _surname;
  std::string _birth;
  std::string _id;
  std::string _number;
  std::string _email;
};

void Information::add()
{
    std::cout << "Name:" << std::endl;
    std::cin >> _name;
    std::cout << "Surname:" << std::endl;
    std::cin >> _surname;
    std::cout << "Birthday:" << std::endl;
    std::cin >> _birth;
    std::cout << "Passpord/Id:" << std::endl;
    std::cin >> _id;
    std::cout << "Phone Number:" << std::endl;
    std::cin >> _number;
    std::cout << "Email:" << std::endl;
    std::cin >> _email;
    std::ofstream myfile("project.txt",std::ios::app);
    if(myfile.is_open())
    {
    myfile << _id << ' ';
    myfile << _name << ' ';
    myfile << _surname << ' ';
    myfile << _birth << ' ';
    myfile << _number << ' ';
    myfile << _email << ' ';
    myfile << '\n';
    myfile.close();
    }
  else 
  std::cout << "Unable to open file";
  return;
}

void Information::list()
{
    std::string line;
    std::ifstream myfile("project.txt");
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {
            std::cout << line << std::endl;
        }
        myfile.close();
    }
    return;
}

void Information::search()
{
    std::ifstream myfile("project.txt");
    std::cout << "Enter Id for more information:";
    std::cin >> _id;
    std::string str;
    std::string line;
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {
            int i = 0;
            str = "";
            while(line[i] != ' ')
            {
                str += line[i];
                ++i;
            }
            if(_id == str)
            {
                std::cout << line << std::endl;
            }
            else 
            {
                std::cout << "Write another ID";
            }    
        }
        myfile.close();
    }
}

void Information::edit()
{
    std::ifstream myfile("project.txt");
    std::cout << "Enter Id for more information:";
    int i = 0;
    std::cin >> _id;
    std::string str;
    std::string line;
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {
            str += line[i];
            ++i;
        }
        if(_id == str)
        {
            ++i;
            while(line[i] != ' ')
            {
                _name += line[i];
                ++i;
            }
            ++i;
            while(line[i] != ' ')
            {
                _surname += line[i];
                ++i;
            }
            ++i;
            while(line[i] != ' ')
            {
                _birth += line[i];
                ++i;
            }
            ++i;
            while(line[i] != ' ')
            {
                _number += line[i];
                ++i;
            }
            ++i;
            while(line[i] != ' ')
            {
                _email += line[i];
                ++i;
            }
            ++i;
        }
    }
    std::ifstream filee("project.txt");
    std::ofstream tmp;
    tmp.open("tmp.txt",std::ios::app);
    std::string str2;
    std::string line1;
    if(filee.is_open())
    {
        while(getline(filee,line1))
        {
            int i = 0;
            str2 = "";
            while(line[i] != ' ')
            {
                str2 += line1[i];
                ++i;
            }
            if(_id != str2)
            {
                tmp << line1 << std::endl;
            }
        }
        tmp.close();
        filee.close();
        remove("project.txt");
        rename("tmp.txt","project.txt");
    }
    std::string str1;
    int num;
    std::cout << "What do you want to edit?" << std::endl;
    std::cout << " [1] Name \n [2] Surname \n [3] Birthday \n [4] ID \n [5] Phone number \n [6] Email" << std::endl;
    std::cin >> num;
    std::cout << "What you want to change?" << std::endl;
    std::cin >> str1;
    switch(num)
    {
        case 1:
        _name = str1;
        break;
        case 2:
        _surname = str1;
        break;
        case 3:
        _birth = str1;
        break;
        case 4:
        _id = str1;
        break;
        case 5:
        _number = str1;
        break;
        case 6:
        _email = str1;
        break;
    }
    std::ofstream file("project.txt",std::ios::app);
    if(file.is_open())
    {
    file << _id << ' ';
    file << _name << ' ';
    file << _surname << ' ';
    file << _birth << ' ';
    file << _number << ' ';
    file << _email << ' ';
    file << '\n';
    file.close();
    }
    return;
}

void Information::delete_inf()
{
    std::ifstream myfile("project.txt");
    std::ofstream tmp;
    tmp.open("tmp.txt");
    std::cout << "Enter Id for more information:";
    std::cin >> _id;
    std::string str;
    std::string line;
    if(myfile.is_open())
    {
        while(getline(myfile,line))
        {
            int i = 0;
            str = "";
            while(line[i] != ' ')
            {
                str += line[i];
                ++i;
            }
            if(_id != str)
            {
                tmp << line << std::endl;
            }
        }
        tmp.close();
        myfile.close();
        remove("project.txt");
        rename("tmp.txt","project.txt");
    }
}

int main () 
{
  Information obj;
  int option;
  do
    {
    std::cout << "[1] Add a new contact" << std::endl;
    std::cout << "[2] List all contacts" << std::endl;
    std::cout << "[3] Search for contact" << std::endl; 
    std::cout << "[4] Edit a contact" << std::endl;
    std::cout << "[5] Delete a contact" << std::endl;
    std::cout << "[0] Exit" << std::endl;
    std::cin >> option;
    switch(option)
    {
        case 1:
        obj.add();
        break;
        case 2:
        obj.list();
        break;
        case 3:
        obj.search();
        break;
        case 4:
        obj.edit();
        break;
        case 5:
        obj.delete_inf();
        break;
    }
    }
    while(option != 0);
}
