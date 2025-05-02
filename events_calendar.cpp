#include <iostream>
#include <cctype>
#include <vector>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

string month() {
    string mon;
    int day;
    cout << "\nYou've chosen to add an event, now choose a month\n  Jan Feb Mar\n  Apr May Jun\n  Jul Aug Sep\n  Oct Nov Dec\n";

    map<string, int> months = {
        {"Jan", 31}, {"Feb", 28}, {"Mar", 31}, {"Apr", 30},
        {"May", 31}, {"Jun", 30}, {"Jul", 31}, {"Aug", 31},
        {"Sep", 30}, {"Oct", 31}, {"Nov", 30}, {"Dec", 31}
    };

    while (true) {
        cout << "\nEnter the month: ";
        cin >> mon;

        if (!mon.empty()) {
            mon[0] = toupper(mon[0]);
            transform(mon.begin() + 1, mon.end(), mon.begin() + 1, ::tolower);
        }

        if (months.find(mon) == months.end()) {
            cout << "Invalid month. Try again.\n";
            continue;
        }

        cout << "Enter day: ";
        cin >> day;

        if (day >= 1 && day <= months[mon]) {
            return mon + " " + to_string(day) + " " + to_string(2025);
        } else {
            cout << "Invalid day for month " << mon << ". Try again.\n";
        }
    }
}

string type()
{
    char reply;
    map <char, int> ans = 
    {
        {'b', 1}, {'a' , 2}, {'f', 3}, {'x' , 4}
    };

    while(true)
    {
        cout << "Enter 'B' for Birthday, 'A' for Anniversary, 'F' for festival and 'X' for miscellaneous events: ";
        cin >> reply;

        reply = tolower(reply);

        if(ans.find(reply) == ans.end())
        {
            cout << "Invalid input, try again\n";
            continue;
        }

        else if(reply == 'b') return "Birthday";
        else if(reply == 'a') return "Anniversary";
        else if(reply == 'f') return "Festival";
        else return "Miscellaneous";
    }
}

struct node
{
    
    string date;
    string data;
    string type;
    node *next;

    node (string _date, string _data, string _type) : date(_date), data(_data), type(_type), next(nullptr){} //constructor
};

class events
{
    public:
        node *head;
        events() : head(nullptr) {}

        void addEvents(string &date, string &data, string &type)
        {
            node* newNode = new node(date, data, type);
            if (!head) 
            {
                head = newNode;
            } 
            else 
            {
                node *temp = head;
                while (temp->next) 
                {
                    temp = temp->next;
                }
                temp->next = newNode;
            }
        }

        void displayEvents()
        {
            node* temp = head;
            while (temp) 
            {
                cout << "____________________________\n";
                cout << "\nDate:  " << temp->date <<'\n';
                cout << "Type:  " << temp->type << '\n';
                cout <<"Event: " << temp->data << "\n";
                cout << "____________________________\n";

                temp = temp->next;
            }
            cout << "End of events\n";

        }

        void displayBirthday()
        {
            node *temp = head;
            while(temp)
            {
                if(temp->type == "Birthday")
                {
                    cout << "____________________________\n";
                    cout << "\nDate:  " << temp->date <<'\n';
                    cout << "Type:  " << temp->type << '\n';
                    cout <<"Event: " << temp->data << "\n";
                    cout << "____________________________\n";
                }
                temp = temp->next;
            }
            cout << "End of Birthdays\n";
        }

        void displayAnniversary()
        {
            node *temp = head;
            while(temp)
            {
                if(temp->type == "Anniversary")
                {
                    cout << "____________________________\n";
                    cout << "\nDate:  " << temp->date <<'\n';
                    cout << "Type:  " << temp->type << '\n';
                    cout <<"Event: " << temp->data << "\n";
                    cout << "____________________________\n";
                }
                temp = temp->next;
            }
            cout << "End of Anniversaries\n";
        }
        void displayFestival()
        {
            node *temp = head;
            while(temp)
            {
                if(temp->type == "Festival")
                {
                    cout << "____________________________\n";
                    cout << "\nDate:  " << temp->date <<'\n';
                    cout << "Type:  " << temp->type << '\n';
                    cout <<"Event: " << temp->data << "\n";
                    cout << "____________________________\n";
                }
                temp = temp->next;
            }
            cout << "End of Festivals\n";
        }
        void displayMisc()
        {
            node *temp = head;
            while(temp)
            {
                if(temp->type == "Miscellaneous")
                {
                    cout << "____________________________\n";
                    cout << "\nDate:  " << temp->date <<'\n';
                    cout << "Type:  " << temp->type << '\n';
                    cout <<"Event: " << temp->data << "\n";
                    cout << "____________________________\n";
                }
                temp = temp->next;
            }
            cout << "End of Miscellaneous events\n";
        }

        void deleteEvents() 
        {
            node *temp;
            while (head) 
            {
                temp = head;
                head = head->next;
                delete temp;
            }
            cout << "All events deleted!\n";
        }
};

int main(void)
{
    cout << "\n\n\n****************************************************EVENT CALENDAR 2025****************************************************\n";
    events event;
    while(1)
    {
        char ans;
        cout << "\n\nEnter 'Y' to add an event, 'N' to stop adding events, 'T' to display events with a tag,\n'D' to delete the list and 'E' to end the program: ";
        cin >> ans;
        ans = tolower(ans);
    
        if (ans == 'y') 
        {
            string date = month();
            string data = occasion();
            string eventType = type();
            event.addEvents(date, data, eventType);

            event.displayEvents();
        }

        else if(ans == 'n')
        {
            cout << "Here is the list of all events in 2025\n";
            event.displayEvents();
        }

        else if(ans == 't')
        {
            char tag;
            cout << "These are the events tag:\n 1. Birthday(b)\n 2. Anniversay(a)\n 3. Festival(f)\n 4. Miscellaneous(x)\n";
            cout << "Enter the tag: ";
            cin >> tag;

            if(tag == 'b')
            {
                cout<<"\nHere is the list of all days with Birthday(s): \n";
                event.displayBirthday();
            }
            else if(tag == 'a')
            {
                cout<<"\nHere is the list of all days with Anniversary(ies): \n";
                event.displayAnniversary();
            }
            else if(tag == 'f')
            {
                cout<<"\nHere is the list of all days with Festival(s): \n";
                event.displayFestival();
            }
            else if (tag == 'x')
            {
                cout<<"\nHere is the list of all days with Miscellaneous Event(s): \n";
                event.displayMisc();
            }
            else
            {
                cout << "Please enter only 'b' , 'a', 'f' or 'x'\n";
            }
        }

        else if(ans == 'd')
        {
            cout << "Now deleting all the events in 2025...\n";
            event.deleteEvents();
            
        }
        
        else if(ans == 'e') {
            cout << "Exiting Event Calendar...\n";
            break; // Ends the loop
        }
        
        else
        {
            cout << "Please enter only 'Y', 'N' or 'D'\n";
        }
    }
}
