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
    
    int id;
    float classifier;
    vector<float> features;
    
};

//class for easier managment of given data and searches
class problem{
    
public:
    
    int features; //number of features for a classification
    string file_name; //saving file name
    vector<stub*> file_data; //represents the vector of stub pointers that encapsulates data
    unsigned long total_entries; //total number of complete data points
    
    
    problem();
    problem(int features, string file);
    
    void build_tree(); //forward selection
    void build_tree2(); //backward elimination
    //i got lazy with the renaming, might make more robust later
    
    vector<float> purgeData(vector<float> x, vector<int> features);
    vector<int> purgeFeatures(vector<int> list, vector<int> remove);
    
    float giveScore(vector<int> features);
    float give_distance(vector<float> x, vector<float> y);
    
    //for debugging to make sure the data was stored properly
    void print_all_data();
    void print_first_data();
    void print_final_data();
    
    bool is_in(vector<int> cf, int i);
    
};



/* Notes
 
 
 accuracy_calc() {
 
    for every row in the data [classifier + features] {
        
        current_c = current classifier at row i
        current_d = set of all features at row i
 
        nn = inf
        nl = inf
 
        for(every row in the data set)
            {if were on the same row skip}
        
            next_current_d = set of all features at row k
        
            distance = current_c - next_current_d
            distance = sum(distance) //all the elements of distance added up
            distance = distance^2
 
            if(distance < nn){
                nn = distance
                nl = row k
                nnl = label at row k
            }
 
        }//inner for end
 
        if(current_c == nnl){
            correctly_classified ++
 
        }
 
    }//outer for end
 
    accuracy = correctly_classified/number_of_data_rows
 } //func end
 
        
 
 
 */

#endif /* problem_hpp */
