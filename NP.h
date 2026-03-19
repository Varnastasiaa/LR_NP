#pragma once
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include <nlohmann/json.hpp>
using namespace std;

vector<double> generateVector(int n){
    vector<double> v;
    for(int i = 0; i < n; i++){
        double number = rand() % 100 + 1;
        v.push_back(number);
    }
    return v;
}

void writeVector(const vector<double>& v, const string& filename){
    ofstream file(filename);
    for(int i = 0; i < (int)v.size(); i++){
        file << v[i] << " ";
    }
}

vector<double> SumGroups(const vector<double>& v, int n){
    vector<double> sum;
    for(int i = 0; i < (int)v.size(); i += n){
        double s = 0;
        for(int j = i; j < i + n && j < (int)v.size(); j++){
            s += v[j];
        }
        sum.push_back(s);
    }
    return sum;
}

double SumVector(const vector<double>& v){
    double s = 0;
    for(int i = 0; i < (int)v.size(); i++){
        s += v[i];
    }
    return s;
}

vector<double> deleteCopy (const vector<double>& v){
    vector<double> result;
    for(int i = 0; i < (int)v.size(); i++){
        bool found = false;
        for(int j = 0; j < (int)result.size(); j++){
            if(v[i] == result[j]){
                found = true;
            }
        }
        if(!found){
            result.push_back(v[i]);
        }
    }
    return result;
}

int sumindex(const vector<double>& sum){
    int index = 0;
    for(int i = 1; i < (int)sum.size(); i++){
        if(sum[i] > sum[index]){
            index = i;
        }
    }
    return index;
}

void print(const vector<double>& w1, const vector<double>& w2, double s2, double s3, int index, int copy, int countA, int countB){
    ofstream out("result.json");
    if(!out.is_open()){
        cerr << "Cannot open result.json for writing\n";
        return;
    }

    nlohmann::json result = {
        {"w1", w1},
        {"w2", w2},
        {"s2", s2},
        {"s3", s3},
        {"max group", index},
        {"copy", copy},
        {"countA", countA},
        {"countB", countB}
    };

    out << result.dump(4) << '\n';
}
