#include "NP.h"

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

bool test_generate_vector_size() {
    srand(1);
    vector<double> v = generateVector(10);
    return v.size() == 10;
}

bool test_generate_vector_range() {
    srand(1);
    vector<double> v = generateVector(30);
    for (double x : v) {
        if (x < 1 || x > 100) {
            return false;
        }
    }
    return true;
}

bool test_sum_groups_basic() {
    vector<double> got = SumGroups(vector<double>{1, 2, 3, 4, 5}, 2);
    vector<double> expected = {3, 7, 5};
    return got == expected;
}

bool test_sum_vector_basic() {
    return SumVector(vector<double>{1.5, 2.5, 3.0}) == 7.0;
}

bool test_delete_copy_basic() {
    vector<double> got = deleteCopy(vector<double>{5, 2, 5, 3, 2, 1});
    vector<double> expected = {5, 2, 3, 1};
    return got == expected;
}

bool test_sum_index_basic() {
    return sumindex(vector<double>{10, 40, 25}) == 1;
}

bool test_print_json_basic() {
    vector<double> w1 = {1, 2, 3};
    vector<double> w2 = {3, 2, 1};
    print(w1, w2, 6.0, 6.0, 1, 0, 3, 2);

    ifstream in("result.json");
    if (!in.is_open()) {
        return false;
    }

    nlohmann::json j;
    in >> j;

    return j["w1"].size() == 3 &&
           j["w2"].size() == 3 &&
           j["s2"] == 6.0 &&
           j["s3"] == 6.0 &&
           j["max group"] == 1 &&
           j["copy"] == 0 &&
           j["countA"] == 3 &&
           j["countB"] == 2;
}

int run_named_test(const string& name) {
    if (name == "generate_vector_size") return test_generate_vector_size() ? 0 : 1;
    if (name == "generate_vector_range") return test_generate_vector_range() ? 0 : 1;
    if (name == "sum_groups_basic") return test_sum_groups_basic() ? 0 : 1;
    if (name == "sum_vector_basic") return test_sum_vector_basic() ? 0 : 1;
    if (name == "delete_copy_basic") return test_delete_copy_basic() ? 0 : 1;
    if (name == "sum_index_basic") return test_sum_index_basic() ? 0 : 1;
    if (name == "print_json_basic") return test_print_json_basic() ? 0 : 1;
    cerr << "Unknown test: " << name << "\n";
    return 2;
}

int main(int argc, char** argv) {
    if (argc == 2) {
        return run_named_test(argv[1]);
    }

    vector<string> tests = {
        "generate_vector_size",
        "generate_vector_range",
        "sum_groups_basic",
        "sum_vector_basic",
        "delete_copy_basic",
        "sum_index_basic",
        "print_json_basic"
    };

    int failed = 0;
    for (const string& t : tests) {
        int code = run_named_test(t);
        if (code == 0) {
            cout << "[PASS] " << t << "\n";
        } else {
            cout << "[FAIL] " << t << "\n";
            failed++;
        }
    }

    return failed == 0 ? 0 : 1;
}
