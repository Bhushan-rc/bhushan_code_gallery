#include<iostream>
#include<vector>
#include<algorithm>

class CheckGreater {

    private:
    int val = 0;
    
    public:
    CheckGreater(int _val) : val(_val) {}

    bool operator () (int _val) {

        return _val > val;
    }
};

class DivisibleBy {

    private:
    int val = 0;
    
    public:
    DivisibleBy(int _val) : val(_val) {}

    bool operator () (int _val) {

        int res = (val > 0) ? (_val % val) : 0;
        return (res == 0);
    }
};

int main() {

    std::vector<int> numlist = {10, 20, 30, 40, 50};
    std::cout << "\n elements in numlist :";
    for(auto &ele : numlist) {
        
        std::cout << "  " << ele;
    }

    int param = 25;
    int count = std::count_if(numlist.begin(), numlist.end(), CheckGreater(param));
    std::cout << "\n numlist contains " << count << " elements greater than " << param;

    param = 4;
    count = std::count_if(numlist.begin(), numlist.end(), DivisibleBy(param));
    std::cout << "\n numlist contains " << count << " elements divisible by " << param;

    return 0;
}