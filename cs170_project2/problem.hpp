//
//  problem.hpp
//  cs170_project2
//
//  Created by Marshall Jones on 11/21/22.
//

#ifndef problem_hpp
#define problem_hpp

#include <stdio.h>
#include <fstream>
#include <string>
#include <iostream>
#include <vector>

using namespace std;

//struct for storing a single data entry
struct stub{
    
    float classifier;
    vector<float> features;
    
};

//class for cleaner managment of given data and searches
class problem{
    
public:
    
    int features;
    string file_name;
    vector<stub*> file_data;
    
    
    problem();
    problem(int features, string file);
    
    //for debugging to make sure the data was stored properly
    void print_all_data();
    void print_first_data();
    void print_final_data();
    
    
};

#endif /* problem_hpp */
