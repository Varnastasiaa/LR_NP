#include "NP.h"
#include <cassert>

void testGenerateVector() {
    srand(1);
    vector<double> v = generateVector(20);
    assert(v.size() == 20);
    for (int i = 0; i < (int)v.size(); i++) {
        assert(v[i] >= 1);
        assert(v[i] <= 100);
    }
}

void testSumGroups() {
    vector<double> v = {1, 2, 3, 4, 5};
    vector<double> sum = SumGroups(v, 2);
    assert(sum.size() == 3);
    assert(sum[0] == 3);
    assert(sum[1] == 7);
    assert(sum[2] == 5);
}

void testSumVector() {
    vector<double> v = {1.5, 2.5, 3.0};
    double s = SumVector(v);
    assert(s == 7.0);
}

void testDeleteCopy() {
    vector<double> v = {5, 2, 5, 3, 2, 1};
    vector<double> out = deleteCopy(v);
    assert(out.size() == 4);
    assert(out[0] == 5);
    assert(out[1] == 2);
    assert(out[2] == 3);
    assert(out[3] == 1);
}

void testSumIndex() {
    vector<double> v = {10, 40, 25};
    assert(sumindex(v) == 1);
    vector<double> tie = {50, 50, 10};
    assert(sumindex(tie) == 0);
}

void testPrint() {
    vector<double> w1 = {1, 2, 3};
    vector<double> w2 = {3, 2, 1};
    print(w1, w2, 6.0, 6.0, 1, 0, 3, 2);

    ifstream in("result.json");
    assert(in.is_open());

    nlohmann::json j;
    in >> j;

    assert(j["w1"].size() == 3);
    assert(j["w2"].size() == 3);
    assert(j["s2"] == 6.0);
    assert(j["s3"] == 6.0);
    assert(j["max group"] == 1);
    assert(j["copy"] == 0);
    assert(j["countA"] == 3);
    assert(j["countB"] == 2);
}

int main() {
    testGenerateVector();
    testSumGroups();
    testSumVector();
    testDeleteCopy();
    testSumIndex();
    testPrint();

    cout << "Усі юніт-тести пройдено успішно.\n";
    return 0;
}
