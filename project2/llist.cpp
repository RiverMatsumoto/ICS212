/*************************************************
//  NAME: River Matsumoto
//
//  HOMEWORK: project2
//
//  CLASS: ICS212
//
//  INSTRUCTOR: Ravi Narayan
//
//  DATE: November 26, 2022
//
//  FILE: llist.cpp
//
//  DESCRIPTION: The implementation of llist
//
//  REFERENCES: None.
//
 * **********************************************/

#include "llist.h"
#include <iostream>
#include <cstring>

/*************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   The constructor of the llist
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/

llist::llist()
{
#ifdef DEBUGMODE
    std::cout << "===>DEBUG Reached llist default constructor" << std::endl;
#endif

    start = NULL;
    strncpy(filename, "defaultFilename", 20);
    readfile();
}

/*************************************************
//
//  Function name: ~llist
//
//  DESCRIPTION:   The destructor of the llist
//
//  Parameters:    none
//
//  Return values:  none
//
// **********************************************/

llist::~llist()
{
#ifdef DEBUGMODE
    std::cout << "===>DEBUG Called destructor" << std::endl;
#endif
    writefile();
    cleanup();
}

/*************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   The constructor of the llist
//
//  Parameters:    filename (char[]): The filename to write to
//
//  Return values:  none
//
// **********************************************/

llist::llist(char filename[])
{
#ifdef DEBUGMODE
    std::cout << "===>DEBUG Reached llist constructor" << std::endl;
    std::cout << "===>DEBUG filename = " << filename << std::endl;
#endif

    start = NULL;
    strncpy(this->filename, filename, 20);
    readfile();
}

/*************************************************
//
//  Function name: llist
//
//  DESCRIPTION:   The copy constructor of the llist
//
//  Parameters:    copy (const llist&): The llist we are copying the data from
//
//  Return values:  none
//
// **********************************************/
llist::llist(const llist& copy)
{
#ifdef DEBUGMODE
    std::cout << "===>DEBUG Called copy constructor" << std::endl;
#endif

    strncpy(filename, copy.filename, 20);

    int accountno;
    char name[30];
    char address[60];
    struct record* copyCurrent = copy.start;

    while(copyCurrent != NULL)
    {
        accountno = copyCurrent->accountno;
        strncpy(name, copyCurrent->name, 30);
        strncpy(address, copyCurrent->address, 60);
        addRecord(accountno, name, address);
        copyCurrent = copyCurrent->next;
    }
}

/*************************************************
//
//  Function name: operator=
//
//  DESCRIPTION:   Overrides the = operator to copy the data over from another llist
//
//  Parameters:    copy (const llist&): The other llist to copy the data from
//
//  Return values:  a llist reference. 
//
// **********************************************/
llist& llist::operator=(const llist& copy)
{
    strncpy(filename, copy.filename, 20);

    int accountno;
    char name[30];
    char address[60];
    struct record* copyCurrent = copy.start;

    while(copyCurrent != NULL)
    {
        accountno = copyCurrent->accountno;
        strncpy(name, copyCurrent->name, 30);
        strncpy(address, copyCurrent->address, 60);
        addRecord(accountno, name, address);
        copyCurrent = copyCurrent->next;
    }

    return *this;
}

/*************************************************
//
//  Function name: addRecord
//
//  DESCRIPTION:   Adds a record to the database.
//
//  Parameters:    accountno (int): The account number of the record
//                  name (char*): The name in the record
//                  address (char*): The address in the record
//
//  Return values:  none
//
// **********************************************/

void llist::addRecord(int accountno, char *name, char *address)
{
#ifdef DEBUGMODE
    std::cout << std::endl;
    std::cout << "===>DEBUG Called llist::addRecord" << std::endl;
    std::cout << "===>DEBUG Accountno = " << accountno << std::endl;
    std::cout << "===>DEBUG Name = \"" << name << "\"" << std::endl;
    std::cout << "===>DEBUG Address = \"" << address << "\"" << std::endl;
#endif

    // initialize the new record and store on heap
    struct record *newRecord = new struct record();
    newRecord->accountno = accountno;
    strncpy(newRecord->name, name, 30);
    strncpy(newRecord->address, address, 60);
    newRecord->next = NULL;

    if (start == NULL)
    {
        start = newRecord;
    }
    else if (accountno >= start->accountno)
    {
        newRecord->next = start;
        start = newRecord;
    }
    else
    {
        // search for the correct place to add a record
        struct record *current = start;
        struct record *previous;
        while (accountno <= current->accountno && current->next != NULL)
        {
            previous = current;
            current = current->next;
            if (current != NULL && accountno >= current->accountno)
            {
                previous->next = newRecord;
                newRecord->next = current;
            }
        }

        // One last manual check if we reach the end of the list
        if (current->next == NULL)
        {
            if (accountno >= current->accountno)
            {
                previous->next = newRecord;
                newRecord->next = current;
            }
            else
            {
                current->next = newRecord;
            }
        }
    }
}

/*************************************************
//
//  Function name: findRecord
//
//  DESCRIPTION:   Finds a record in the database.
//
//  Parameters:    accountno (int): The account number of the record to find
//
//  Return values:  0 (int): Successfully found the record
//                  -1 (int): Couldn't find the record
//
// **********************************************/
int llist::findRecord(int accountno)
{
#ifdef DEBUGMODE
    std::cout << std::endl;
    std::cout << "===>DEBUG Called findRecord" << std::endl;
    std::cout << "===>DEBUG accountno = " << accountno << std::endl;
#endif

    int result;
    struct record *current = start;
    while (current != NULL && accountno != current->accountno)
    {
        current = current->next;
    }
    if (current != NULL)
    {
        std::cout << "=====Found Record=====" << std::endl;
        std::cout << "accountno = " << current->accountno << std::endl;
        std::cout << "name = \"" << current->name << "\"" << std::endl;
        std::cout << "address = \"" << current->address << "\"" << std::endl;
        result = 0;
    }
    else
    {
        std::cout << "Could not find a record with the accountno = " << accountno << std::endl;
        result = -1;
    }

    return result;
}

/*************************************************
//
//  Function name: printAllRecords
//
//  DESCRIPTION:   Prints all the records in the database.
//
//  Parameters:    None
//
//  Return values:  None
//
// **********************************************/
void llist::printAllRecords()
{
#ifdef DEBUGMODE
    std::cout << std::endl;
    std::cout << "===>DEBUG Called printAllRecords" << std::endl;
#endif

    struct record *current = start;
    if (start == NULL)
    {
        std::cout << std::endl;
        std::cout << "There are no records in the database" << std::endl;
    }
    while (current != NULL)
    {
        std::cout << std::endl;
        std::cout << "Accountno = " << current->accountno << std::endl;
        std::cout << "Name = \"" << current->name << "\"" << std::endl;
        std::cout << "Address \"" << current->address << "\"" << std::endl;
        std::cout << std::endl;
        current = current->next;
    }
}

/*************************************************
//
//  Function name: deleteRecord
//
//  DESCRIPTION:   Deletes a record in the database.
//
//  Parameters:    accountno (int): The account number of the record to delete
//
//  Return values:  0 (int): Successfully deleted the record(s)
//                  -1 (int): Couldn't find the record(s)
//
// **********************************************/
int llist::deleteRecord(int accountno)
{
#ifdef DEBUGMODE
    std::cout << std::endl;
    std::cout << "===>DEBUG Called deleteRecord" << std::endl;
    std::cout << "===>DEBUG accountno = " << accountno << std::endl;
#endif

    int result;
    struct record *current = start;
    struct record *previous = NULL;
    struct record *toDelete = NULL;

    if (start == NULL)
    {
        std::cout << "Couldn't find the record to delete" << std::endl;
        result = -1;
    }
    else if (accountno == start->accountno)
    {
        while (current != NULL && accountno == current->accountno)
        {
            toDelete = current;
            current = current->next;
            delete toDelete;
        }
        start = current;
        result = 0;
    }
    else
    {
        // keep iterating to the end, or if matching accountno is encountered
        current = start;
        while (current != NULL && accountno != current->accountno)
        {
            previous = current;
            current = current->next;
        }

        if (current != NULL)
        {
            // keep deleting records until the accountno doesn't match
            while (current != NULL && accountno == current->accountno)
            {
                toDelete = current;
                current = current->next;
                delete toDelete;
            }
            previous->next = current;
            result = 0;
        }
        else
        {
            result = -1;
        }
    }
    return result;
}

/*************************************************
//
//  Function name: readfile
//
//  DESCRIPTION:   Reads database data from a text file and rebuilds the linked list database.
//
//  Parameters:    None
//
//  Return values:  0 (int): Successfully read from database file and created linked list database.
//                  -1 (int): Error occurred when opening the database file and read the data.
//
// **********************************************/
int llist::readfile()
{
#ifdef DEBUGMODE
    std::cout << "===>DEBUG Called readfile" << std::endl;
#endif

    // use ifstream, open the file and read each record's data and add the record
    int result;
    std::ifstream ifs(filename, std::ifstream::in);
    if (ifs.good())
    {
        bool doneReading = false;
        int accountno;
        char name[30];
        char address[60];
        while (!doneReading)
        {
            ifs.get();
            if (ifs.good())
            {
                ifs >> accountno;
                ifs.get();
                ifs.getline(name, 30, '\n');
                ifs.getline(address, 60, '~');
                addRecord(accountno, name, address);
            }
            else
            {
                doneReading = true;
            }
        }
        result = 0;
    }
    else
    {
        result = -1;
    }
    return result;
}

/*************************************************
//
//  Function name: writefile
//
//  DESCRIPTION:   Writes current linked list data to a database text file so that
//                  the data persists between sessions.
//
//  Parameters:    None
//
//  Return values:  0 (int): Successfully wrote to the database text file.
//                  -1 (int): Error occurred when writing to the database text file.
//
// **********************************************/
int llist::writefile()
{
#ifdef DEBUGMODE
    std::cout << "===>DEBUG Called writefile" << std::endl;
#endif

    int result;
    // loop through the database and write each record's data to a file
    std::ofstream ofs(filename, std::ofstream::out);
    if (ofs.is_open())
    {
        struct record *current = start;
        while (current != NULL)
        {
            ofs << '~';
            ofs << current->accountno << std::endl;
            ofs << current->name << std::endl;
            ofs << current->address << "~";
            current = current->next;
        }
        ofs.close();
        result = 0;
    }
    else
    {
        result = -1;
    }

    return result;
}

/*************************************************
//
//  Function name: cleanup
//
//  DESCRIPTION:   Frees memory being used on the heap by the database
//
//  Parameters:    None
//
//  Return values:  None
//
// **********************************************/
void llist::cleanup()
{
#ifdef DEBUGMODE
    std::cout << "===>DEBUG Called cleanup" << std::endl;
#endif

    // loop through the list and delete each record
    struct record* current = start;
    struct record* toDelete;

    while(current != NULL)
    {
        toDelete = current;
        current = current->next;
        delete toDelete;
    }
    start = NULL;
}

/*************************************************
//
//  Function name: operator<<
//
//  DESCRIPTION:   Overrides the << operator to write to a std::ostream
//
//  Parameters:     os (std::ostream&): The os to write the llist's data to.
//                  list (const llist&): The other llist to copy the data from
//
//  Return values:  a std::ostream reference
//
// **********************************************/
std::ostream& operator<<(std::ostream& os, const llist& list)
{
    struct record* current = list.start;

    while(current != NULL)
    {
        os << std::endl;
        os << "Accountno = " << current->accountno << std::endl;
        os << "Name = \"" << current->name << "\"" << std::endl;
        os << "Address = \"" << current->address << "\"" << std::endl;
        os << std::endl;
        current = current->next;
    }

    return os;
}
