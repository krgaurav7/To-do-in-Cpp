#include<iostream>
#include<list>
#include<string>
#include<ctime>
#include <chrono>
#include <iomanip>// for put time
using namespace std;
using namespace chrono;

class TodoItem
{
private:
    int id;
    string description;
    bool completed;

public:
    TodoItem() : id(0), description(""), completed(false) {} // constructor 

    ~TodoItem() {} // destructor

    bool create ( string new_description){

        id = rand()%1000+1;
        description = new_description;
        return true;
    }

    int getId(){
        return id;
    }

    string getDescription(){
        return description;
    }

    bool isCompleted(){
        return completed;
    }

    void setCompleted(bool val){
        completed = val;
    }
};


int main()
    {
        string input_description;
        int input_ID;
        char input_Option;
        std::string v = __VERSION__;
        list<TodoItem> todoItems;
        list<TodoItem>::iterator it;

        srand(time(NULL));

        todoItems.clear();

        // this is for test that created list is fine or not
        // TodoItem test;
        // test.create("Do 5 DSA Question Today!");
        // todoItems.push_back(test);

        while(1)
        {

            system("cls");
            cout << "TO Do List in C++ " << v <<endl;

            for(it = todoItems.begin(); it!= todoItems.end(); it++){

                string completed = it->isCompleted()  ? "done" : "not doned";

                cout << it->getId() << " | " << it->getDescription() << " | " << completed<< endl;
            }

            if(todoItems.empty())
            {
                auto now = system_clock::now(); //convet time
                time_t now_time = system_clock::to_time_t(now); // convert to time t
                cout << "Add a Todo fo Today " << put_time(localtime(&now_time), "%Y-%m-%d %H:%M:%S") <<endl;
            } 
            cout << " " << endl;
            cout << "Enter a for add a New Todo !" <<endl;
            cout << "Enter c for complete a TOdo !" <<endl;
            cout <<  "Enter q for quit " << endl;

            cout << "Choice : ";

            cin >> input_Option;
            cout << " " << endl;

            if(input_Option == 'q')
            {
                cout << "Thanks for quit, have a great Day !" << endl;
                cout << "Lets we meet again next day BUDDY!" << endl;
                break;
            }
             else if (input_Option == 'c')
            {
                cout << "Enter ID of your To do you want to mark Complete : " ;
                cin >>input_ID;
                for(it = todoItems.begin(); it!= todoItems.end(); it++)
                {
                    if(it->getId() == input_ID)
                    {
                        it->setCompleted(true);
                        cout << input_ID << " : Marked Completed" << endl;
                        break;
                    } else 
                    {
                    cout << "You entered wrong ID" << endl;
                    }
                }
            } else if (input_Option == 'a')
            {
                cout <<"Enter How many task you want to Enter" <<endl;
                int num;
                cin >> num;
                while (num != 0)
                {
                cout <<"Now add your New Task !" << endl;
                cin.clear();
                cin.ignore();
                getline(cin, input_description);
                TodoItem newItem;
                newItem.create(input_description);
                todoItems.push_back(newItem);
                num--;
                }
            }

            // it just to check every thig right during writing code 
            // for(it = todoItems.begin(); it!= todoItems.end(); it++){

            //     string completed = it->isCompleted()  ? "done" : "not doned";

            //     cout << it->getId() << " | " << it->getDescription() << " | " << completed<< endl;
            // }
            // break;
        }

        return 0;
        
    }