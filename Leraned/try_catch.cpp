#include <stdexcept>
#include<bits/stdc++.h>
using namespace std;
template<typename T>
void Test(T e) {
    throw e;
}

int main() {
    try {
        runtime_error re{"RE found !"};
        string CE = "String error";
        int IE = 20;
        // Test(CE);
        Test(re);
        // Test(IE);
    }
    catch(int ex) {
        cout<< "Integer Error " << ex <<endl;
    }
    catch(string ex) {
        cout<< ex <<endl;
    }
    catch(runtime_error ex) {
        cout<< ex.what() <<endl;
    }
    catch(...) {
        cout<< "For all errors" <<endl;
    }
}