//
//  main.cpp
//  cs170_project2
//
//  Created by Marshall Jones on 11/19/22.
//

/*
 
 Project Objectives
    [ ] open, read, and store file contents

 
 
 */
#include "problem.hpp"


problem* extractData(){
    
    
    //Greeting and Open File
    ifstream myfile;
    string filename;

    
    /*
    cout << "Hello Professor, please enter the name of the data txt file you which to read in: " << endl;
    
    cin >> filename;
    cout << endl;
    */
    
    myfile.open("data.txt");
    
    while(!myfile.is_open()){
        cout << "File not found, please try again: ";
        cin >> filename;
        cout << endl;
    }
    
    //Annoying as a user but might make more clever in the future
    cout << "IMPORTANT: For correct file reading, how many features exist for the given classifiers: ";
    
    
    int class_count;
    cin >> class_count;
    
    //first initialization of problem object
    problem* toGive = new problem(class_count, filename);
    
    //temp variables for the following loops:
        //mimi is the float thats read in at every point
        //line is the given line of data in the file
    float mimic;
    string line;
    int id_inc = 1;
    
    
    //Intuition
        //Until the file is done being scanned
            //get a line from the file
            //create a new entry, put the first thing from the line as the classifier for the data stub
            //then follow a loop using the features.size as a barrier, inputting data
    while(!myfile.eof()){
        
        stub* entry = new struct stub;
        
        entry->id = id_inc;
        ++id_inc;
        
        myfile >> entry->classifier;
        
        for(int i = 0; i < toGive->features; ++i){
            myfile >> mimic;
            entry->features.push_back(mimic);
        }
        
        toGive -> file_data.push_back(entry);
        
        getline(myfile, line);
        
    }
    
    //over read by one entry, sloppy but effective fix
    toGive -> file_data.pop_back();
    toGive -> total_entries = toGive -> file_data.size();
    
    myfile.close();
    
    return toGive;
    
    
}
/*----------------------------------------------------------------*/

int main(int argc, const char * argv[]) {
    
    //not fully reading in data properly
    problem* initial = extractData();
    initial -> print_all_data();
    initial -> build_tree();

    return 0;
}
