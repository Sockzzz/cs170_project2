//
//  problem.cpp
//  cs170_project2
//
//  Created by Marshall Jones on 11/21/22.
//

#include "problem.hpp"


problem::problem(){
    
    features = 0;
    file_name = "";
    
}

problem::problem(int count, string file){
    
    features = count;
    file_name = file;
        
}

bool problem::is_in(vector<int> cf, int i){
    
    for(int j = 0; j < cf.size(); ++j){
        if(cf.at(j) == i)
            return true;
    }
    
    return false;
    
}

//builds search tree. this section was modeled off of the prof's slides
void problem::build_tree(){
    
    vector<int> current_features;
    int score = 0;
    int toAdd;
    
    
    //busy looking line but basically the conversion equates to the total number of features
        //file_data is the vector containing all data lines from the file
            //.at(0) represents the first entry
                //-> features is the vector that holds all the features for the given data entry
                    //size() gives us the number of features for that entry (all entries)
    unsigned long runs = file_data.at(0)->features.size();
    
    
    
    for(int i = 0; i < runs; ++i){
        
        cout << "On the " << i+1 << "th level of the search tree:" << endl;
        score = 0;
        toAdd = -1;
        
        
        for(int j = 0; j < runs; ++j){
            
            //helper function so i can have a cleaner line here
            if(is_in(current_features, j+1))
                continue;
            
            cout << "- Considering adding the " << j+1 << " feature" << endl;
            int temp_score = rand(); //to fill in with k cross
            
            if(temp_score > score){
                toAdd = j+1;
                score = temp_score;
            }
            
        }
        
        cout<< "On level " << i+1 << " the " << toAdd << " feature was added to the set" << endl << endl;
        current_features.push_back(toAdd);
        
    }
    
}


//debug checker
void problem::print_all_data(){
    
    for(int i = 0; i < file_data.size(); ++i){
        
        //print the classifier for the current file_data stub
        cout << "ID: " << file_data.at(i)->id << endl;
        cout << "Classifier: " << file_data.at(i)->classifier << endl;
        cout << "Data: ";
        
        //a bit strenuous to read but the intuition is:
            //for the given file_data entry [some stub*]
                //print out all the features
        for(int j = 0; j < file_data.at(i)->features.size(); ++j){
            cout << file_data.at(i)->features.at(j) << " ";
        }
        
        cout << endl << endl;
        
    }
    
}

//debug checker
void problem::print_first_data(){
    
    cout << "Classifier: " << file_data.at(0)->classifier << endl;
    
    for(int i = 0; i < file_data.at(0)->features.size(); ++i){
    
        cout<< file_data.at(0) -> features.at(i) << " ";
        
    }
    
    cout << endl << endl;
    
}

//debug checker
void problem::print_final_data(){
    
    int size = file_data.size() - 1.0;
    
    cout << "Classifier: " << file_data.at(size)->classifier << endl;
    
    for(int i = 0; i < file_data.at(size)->features.size(); ++i){
        cout<< file_data.at(0) -> features.at(i) << " ";
    }
    
}


