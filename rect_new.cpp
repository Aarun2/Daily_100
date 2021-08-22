#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;

long long get_overlap(vector<int>& rect1, vector<int>& rect2) {
        int s1_x = rect1[0];
        int s1_y = rect1[1];
        
        int s2_x = rect2[0];
        int s2_y = rect2[1];
        
        int t1_x = rect1[2];
        int t1_y = rect1[3];
        
        int t2_x = rect2[2];
        int t2_y = rect2[3];
        
        long long x_op = 0;
        long long y_op = 0;
        
        if ((s1_x >= s2_x) && (s1_x < t2_x)) { // overlop with 1 in 2
            if (t1_x >= t2_x)
                x_op = t2_x - s1_x;
            else
                x_op = t1_x - s1_x;
        }
        else if ((s2_x >= s1_x) && (s2_x < t1_x)) { // overlop with 2 in 1
            if (t2_x >= t1_x)
                x_op = t1_x - s2_x;
            else
                x_op = t2_x - s2_x;
        }
        
        if ((s1_y >= s2_y) && (s1_y < t2_y)) { // overlop with 1 in 2
            if (t1_y >= t2_y)
                y_op = t2_y - s1_y;
            else
                y_op = t1_y - s1_y;
        }
        else if ((s2_y >= s1_y) && (s2_y < t1_y)) { // overlop with 2 in 1
            if (t2_y >= t1_y)
                y_op = t1_y - s2_y;
            else
                y_op = t2_y - s2_y;
        }
        return x_op * y_op;
}

long long get_area(vector<int>& rect) {
    //((*it[2]) - (*it[0])) * ((*it[3]) - (*it[1])) 
    long long ret = (rect[2] - rect[0]) * (rect[3] - rect[1]);
    return ret;
}

int rectangleArea(vector<vector<int>>& rectangles) {
        long long tot = 0;
        for (vector<vector<int>>::iterator it = rectangles.begin() ; it != rectangles.end(); ++it) {
            tot += get_area(*it);
            // cout << get_area(*it) << endl;
            for (vector<vector<int>>::iterator it1 = it+1 ; it1 != rectangles.end(); ++it1) {
                tot -= get_overlap(*it, *it1);
                cout << get_overlap(*it, *it1) << endl;
            }
        }
        cout << tot << endl;
        return tot;
}

int main () {
        // [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
        // vector<int> vect{ 10, 20, 30 };
        // vector<vector<int>> rectangles {{0,0,1000000000,1000000000}};
        vector<vector<int>> rectangles {{0,0,2,2},{1,0,2,3},{1,0,3,1}};
        rectangleArea(rectangles);
        //vector<int> rect1 = {0,0,2,2};
        //vector<int> rect2 = {1,0,2,3};
        //vector<int> rect3 = {1,0,3,1};
        //cout << get_overlap(rect1, rect3) << endl;
        
        
        return 0;
}