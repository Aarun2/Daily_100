#include <iostream>
#include <vector>
#include <map>
#include <array>

using namespace std;

    map<array<int, 4>, int> blocks;
    void add_blocks(vector<int>& rect) {
        int left_x = rect[0];
        int left_y = rect[1];
        int right_x = rect[2];
        int right_y = rect[3];
        int cur_x = left_x;
        int cur_y = left_y;
        if ((left_x == right_x) && (left_y == right_y)) {
            return;
        }
        if (((left_x + 1) <= right_x) && ((left_y + 1) <= right_y)) {
            array<int, 4> a = {left_x, left_y, left_x+1, left_y+1};
            if (blocks[a] != 1) {
                blocks[a] = 1;
                vector<int> rec1;
                rec1.push_back(left_x+1);
                rec1.push_back(left_y+1);
                rec1.push_back(right_x);
                rec1.push_back(right_y);
                add_blocks(rec1);
            }
        }
        if (((left_x + 1) < right_x) && (left_y < right_y)) {
            vector<int> rec2;
            rec2.push_back(left_x+1);
            rec2.push_back(left_y);
            rec2.push_back(right_x);
            rec2.push_back(right_y);
            add_blocks(rec2);
            // rec call
        }
        if ((left_x < right_x) && ((left_y + 1) < right_y)) {
            vector<int> rec3;
            rec3.push_back(left_x);
            rec3.push_back(left_y+1);
            rec3.push_back(right_x);
            rec3.push_back(right_y);
            add_blocks(rec3);
            // rec call
        }
        
    }
    int rectangleArea(vector<vector<int>>& rectangles) {
        for (auto it = rectangles.begin() ; it != rectangles.end(); ++it) {
            add_blocks(*it);
        }
        // add_blocks((*rectangles.begin()));
        int count = 0;
        

        for (auto &pair: blocks) {
            // cout << "Reached Here" << endl;
            array<int, 4> rect = pair.first;
            count++;
        }
        /*
        for (int i = 0; i < 4; i++) {
                cout << rect[i] << " ";
            }
            cout << endl;
            */
        
        cout << count << endl;
        return count;
    }
    int main () {
        // [[0,0,2,2],[1,0,2,3],[1,0,3,1]]
        // vector<int> vect{ 10, 20, 30 };
        // vector<vector<int>> rectangles {{0,0,1000000000,1000000000}};
        vector<vector<int>> rectangles {{0,0,2,2},{1,0,2,3},{1,0,3,1}};
        rectangleArea(rectangles);
        return 0;
    }
