#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "Student.h"
#include "Exept.h"

int main()
{
    setlocale(LC_ALL, "");
    string file_name = "student.bin";
    fstream file;
    file.exceptions(ifstream::failbit | ifstream::badbit);

    try
    {
        // Write student to file
        file.open(file_name, ios::binary | ios::out);;
        cout << "-------------STUDENT 1 ----------------" << endl;
        try
        {
            Student st{ "Alex","Kovalev", 18};
            st.show();
            st.serialize(file);
            file.close();
        }
        catch (const IncorrectValueException& ex)
        {
            cout << "ERROR: " << ex.what() << endl;
        }


        // Read student from file
        file.open(file_name, ios::binary | ios::in);

        cout << "-------------STUDENT 2 ----------------" << endl;
        Student st2;
        st2.deserialize(file);
        st2.show();
        file.close();
    }
    catch (const std::exception& ex)
    {
        cout << ex.what();
    }
}
