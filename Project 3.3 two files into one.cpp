// Project 3.3 two files into one.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream> 

#include <iomanip> //includes manipulators (that take parameters, strings are left justified, numbers are right justified)

#include <string>

#include <fstream> //fstream header

using namespace std;

int main()
{ 
   ifstream TextFile1, TextFile2;
   ofstream Outfile;

        TextFile1.open("TextFile1.txt"); //open file
        TextFile2.open("TextFile2.txt"); //open file
        
        Outfile.open("OutputFile"); //open  Outfile

  
        if (!TextFile1 || !TextFile2)
        {
            cout << "could not open file" << endl;
            return 1;
        }

        string str1, str2;

        getline(TextFile1, str1);
        getline(TextFile2, str2);

        

        while (!TextFile1.eof() && !TextFile2.eof())//if data is there, if eof write remaining lines from file
        {


            if (str1 < str2) //compare the two strings from the files writing the smaller one
            {
                cout << str1 << endl;
                getline(TextFile1, str1);
                if (TextFile1.eof())
                    cout << str1 << endl;
            }
            else
            {
                cout << str2 << endl;
                getline(TextFile2, str2);
                if (TextFile2.eof())
                    cout << str2 << endl;
            }

           
            

            while (TextFile1.eof() || TextFile2.eof())//if data is there, if eof write remaining lines from file
            {
            
                if (TextFile1.eof())// if file1 is eof write list of file2
                {                   
                    cout << str2 << endl;
                    getline(TextFile2, str2);
                }
                else if (TextFile2.eof())// if file2 is eof write list of file1
                {                  
                    getline(TextFile1, str1);
                    cout << str1 << endl;
                }
            }
           
           
        }

                                                                        

            TextFile1.close(); ////close infile 
            TextFile2.close(); //close infile 


            Outfile.close(); //close outfile  

            return 0;
}