#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <json/json.h>

using namespace std;

// Function to decode a number from a given base to base 10
long long decodeValue(const string &value, int base) {
    long long result = 0;
    for (char digit : value) {
        result = result * base + (isdigit(digit) ? digit - '0' : digit - 'a' + 10);
    }
    return result;
}

// Function to perform Lagrange interpolation and find the constant term
long long lagrangeInterpolation(const vector<pair<int, long long>> &points, int k) {
    long long constant = 0;
    
    for (int i = 0; i < k; i++) {
        long long xi = points[i].first;
        long long yi = points[i].second;

        long long term = yi;
        for (int j = 0; j < k; j++) {
            if (i != j) {
                long long xj = points[j].first;
                term *= xj;
                term /= (xi - xj);
            }
        }
        constant += term;
    }

    return constant;
}

int main() {
    // Read input from a JSON file
    string filename;
    cout << "Enter the JSON file path: ";
    cin >> filename;

    ifstream file(filename);
    if (!file.is_open()) {
        cerr << "Error opening file." << endl;
        return 1;
    }

    Json::Value root;
    file >> root;

    int n = root["keys"]["n"].asInt();
    int k = root["keys"]["k"].asInt();

    vector<pair<int, long long>> points;
    for (auto key : root.getMemberNames()) {
        if (key != "keys") {
            int x = stoi(key);
            int base = root[key]["base"].asInt();
            string value = root[key]["value"].asString();
            long long y = decodeValue(value, base);
            points.emplace_back(x, y);
        }
    }

    // Sort the points to ensure consistent interpolation
    sort(points.begin(), points.end());

    // Find the constant term using Lagrange interpolation
    long long secret = lagrangeInterpolation(points, k);

    cout << "The secret (constant term) is: " << secret << endl;

    return 0;
}
