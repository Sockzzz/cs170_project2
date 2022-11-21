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

void problem::print_all_data(){
    
    for(int i = 0; i < file_data.size(); ++i){
        
        //print the classifier for the current file_data stub
        cout << "Classifier: " << file_data.at(i)->classifier << endl;
        cout << "Data: " << endl;
        
        //a bit strenuous to read but the intuition is:
            //for the given file_data entry [some stub*]
                //print out all the features
        for(int j = 0; j < file_data.at(i)->features.size(); ++j){
            cout << file_data.at(i)->features.at(j) << " ";
        }
        
        cout << endl << endl;
        
    }
    
}

void problem::print_first_data(){
    
    cout << "Classifier: " << file_data.at(0)->classifier << endl;
    
    for(int i = 0; i < file_data.at(0)->features.size(); ++i){
    
        cout<< file_data.at(0) -> features.at(i) << " ";
        
    }
    
    cout << endl << endl;
    
}

void problem::print_final_data(){
    
    int size = file_data.size() - 1.0;
    
    cout << "Classifier: " << file_data.at(size)->classifier << endl;
    
    for(int i = 0; i < file_data.at(size)->features.size(); ++i){
        cout<< file_data.at(0) -> features.at(i) << " ";
    }
    
}


