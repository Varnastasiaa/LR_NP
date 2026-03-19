#include "NP.h"

int main(){

    srand(time(0));
    int n;
    cout << "Enter the number of elements: " << flush;
    cin >> n;
    if(n <= 0){
        cout << "Invalid number of elements\n";
        return 1;
    }

    vector<double> v = generateVector(n);
    cout << "Generated vector: ";
    for(int i = 0; i < (int)v.size(); i++){
        cout << v[i] << " ";
    }
    cout << '\n';
    writeVector(v, "a.txt");

    int k;
    cout << "Enter the group size: " << flush;
    cin >> k;
    if(k <= 0){
        cout << "Invalid group size\n";
        return 1;
    }

    vector<double> sum = SumGroups(v, k);
    cout << "Group sums: ";
    for(int i = 0; i < (int)sum.size(); i++){
        cout << sum[i] << " ";
    }
    cout << '\n';
    writeVector(sum, "b.txt");
    double s2 = SumVector(sum);

    vector<double> w1 = v;
    for(int i = 0; i < (int)w1.size(); i++){
        for(int j = i + 1; j < (int)w1.size(); j++){
            if(w1[i] > w1[j]){
                double temp = w1[i];
                w1[i] = w1[j];
                w1[j] = temp;
            }
        }
    }

    vector<double> w2 = v;
    for(int i = 0; i < (int)w2.size(); i++){
        for(int j = i + 1; j < (int)w2.size(); j++){
            if(w2[i] < w2[j]){
                double temp = w2[i];
                w2[i] = w2[j];
                w2[j] = temp;
            }
        }
    }

    vector<double> nocopy = deleteCopy(v);
    double s3 = SumVector(nocopy);
    int index = sumindex(sum);

    int countA = (int)v.size();
    int countB = (int)sum.size();
    int copy = (int)(v.size() - nocopy.size());

    print(w1, w2, s2, s3, index, copy, countA, countB);
    return 0;
}
