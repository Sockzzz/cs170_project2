//
//  problem.cpp
//  cs170_project2
//
//  Created by Marshall Jones on 11/21/22.
//

#include "problem.hpp"
#include <limits>
#include <cmath>


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

float problem::give_distance(vector<float> x, vector<float> y){
    
    float toReturn = 0.00;
    
    for(int i = 0; i < x.size(); ++i){
        
        toReturn = toReturn + pow((x.at(i)-y.at(i)), 2);
        
    }
    
    toReturn = sqrt(toReturn);

    return toReturn;
}

//purges feature list of elements that are not being considered, returns an edited version
vector<float> problem::purgeData(vector<float> x, vector<int> features){
    
    //copy of given stub
    vector<float> edit = x;

    //iterate thru the whole data stub
    for(int i = 0; i < edit.size(); ++i){
        
        //decides if we can keep the data or not; re-initialize
        bool toTest = false;
        //check if feature in the list
        for(int k = 0; k < features.size(); ++k){
            
            //to keep the data in the current column, the cc needs to be a feature were testing
            int curr_feature = features.at(k) - 1;
            
            //if we have a match we can keep the data
            if(i == curr_feature)
                toTest = true;
            
        }
        
        //if the column didnt pass, overwrite it
        if(!toTest)
            edit.at(i) = 0;
        
    }

    
    
    return edit;
}


float problem::giveScore(vector<int> cfeatures){// instead of pick need to pass in just the features we want to test not the entire list of features
    
    /*
    cout << "Scoring algorithm was provided with the following features to test: " << endl;
    for(int i = 0; i < cfeatures.size(); ++i){
        cout << cfeatures.at(i) << endl;
    }
    */
    
    float score = 0.0;

    for(int i = 0; i < total_entries; ++i){
        
        float current_c = file_data.at(i)->classifier;
        vector<float> current_row = file_data.at(i)->features;
        //actual form of the data we want to focus on
        vector<float> current_f = purgeData(current_row, cfeatures);
        
        /*
        cout << "Data within a sample stub: " << endl;
        for(int i = 0; i < current_f.size(); ++i){
            cout << current_f.at(i) << endl;
        }
        cout<<endl;
        */
        
        float nn = std::numeric_limits<float>::max();
        float nl = std::numeric_limits<float>::max();
        
        for(int k = 0; k < total_entries; ++k){
            
            if(i == k)
                continue;
            
            float next_current_c = file_data.at(k)->classifier;
            vector<float> next_current_row = file_data.at(k)->features;
            //actual form of the next data we want to focus on
            vector<float> next_current_f = purgeData(next_current_row, cfeatures);
            
            
            
            float distance = give_distance(current_f, next_current_f);
            
            if(distance < nn){
                nn = distance;
                nl = next_current_c;
            }
            
        }
        
        if(current_c == nl)
            ++score;
    }
    
    float accuracy = score/total_entries;

    return accuracy;

}

//builds search tree. this section was modeled off of the prof's slides
void problem::build_tree(){
    
    vector<int> best_set;
    float high_score = 0.0;
    
    vector<int> current_features; //holds current considered features
    float score = 0.0;
    int toAdd;
    
    
    //busy looking line but basically the conversion equates to the total number of features
        //file_data is the vector containing all data lines from the file
            //.at(0) represents the first entry
                //-> features is the vector that holds all the features for the given data entry
                    //size() gives us the number of features for that entry (all entries)
    unsigned long runs = file_data.at(0)->features.size();
    
    
    
    for(int i = 0; i < runs; ++i){
        
        cout << "On the " << i+1 << "th level of the search tree:" << endl;
        score = 0.0;
        toAdd = -1;
        
        
        for(int j = 0; j < runs; ++j){
            
            //helper function so i can have a cleaner line here
            if(is_in(current_features, j+1))
                continue;
            
            cout << "- Considering adding the " << j+1 << " feature" << endl;
            vector<int> potential = current_features;
            potential.push_back(j+1);
            
            
            
            float temp_score = giveScore(potential);
           
            
            if(temp_score > score){
                toAdd = j+1;
                score = temp_score;
            }
            
        }
        
        cout<< "On level " << i+1 << " the " << toAdd << " feature was added to the set with score: " << score << endl << endl;
        current_features.push_back(toAdd);
        
        if(score > high_score){
            best_set = current_features;
            high_score = score;
        }
        
    }
    
    cout << "The best set of features were :" << endl;
    for(int i = 0; i < best_set.size(); ++i){
        cout << best_set.at(i) << endl;
    }
    cout << "The highest accuracy was: " << high_score << endl;
    
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


