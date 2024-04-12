///************************
//Immanuel Braxton
//3 / 29 / 2024
//Project 3.3 two files into one.cpp
//This program reads two input files whose lines are ordered by a key data field and merges them into one output file using the same key field
// .This program will read each input file until completion and the files have been merged successfully in an outfile.
//*************************

#include <iostream> 

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
            //cout << str1 << str2 << endl;

            if (str1 < str2) //compare the two strings from the files writing the smaller one
            {
                Outfile << str1 << endl;
                getline(TextFile1, str1);

            }
            else
            {
                Outfile << str2 << endl;
                getline(TextFile2, str2);
                //cout << str2 << str1 << endl;


            }

            
            
        }
           

        while (!TextFile1.eof())// if file1 is eof write list of file2
        {
            Outfile << str1 << endl;
            getline(TextFile1, str1);
        }


        while (!TextFile2.eof())// if file2 is eof write list of file1
        {
            Outfile << str2 << endl;
            getline(TextFile2, str2);

        }
           
           
           
                                                                            

            TextFile1.close(); ////close infile 
            TextFile2.close(); //close infile 


            Outfile.close(); //close outfile  

            return 0;
}