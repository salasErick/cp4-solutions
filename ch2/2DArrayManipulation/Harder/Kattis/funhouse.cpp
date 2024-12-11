#include <bits/stdc++.h>
#include <utility>
#include <vector>

using namespace std;

enum Direction {DOWN = 0,UP = 1, LEFT = 2, RIGHT = 3};

pair<int, int> getDoor(const vector<vector<char>>& room) {
    int i = room.size();
    int j = room[0].size();
    pair<int,int> door;
    for(int x = 0; x < j; x++) {
        if(room[0][x] == '*') {
            door = {0,x};
        }
        else if(room[i-1][x] == '*') {
            door = {i-1,x};
        }
    }
    for(int y = 0; y < i; y++) {
        if(room[y][0] == '*') {
            door = {y, 0};
        } else if(room[y][j-1] == '*') {
            door = {y, j-1};
        }
    }
    return door;
}

void printRoom(const vector<vector<char>>& room, int T) {
    cout << "HOUSE " << T << "\n";
    for(int i = 0; i < room.size(); i++) {
        for(int j = 0; j < room[0].size(); j++) {
            cout << room[i][j];
        }
        cout << "\n";
    }
}

// This is considering that doors can't be at corners
Direction getDirection(pair<int, int>& door, vector<vector<char>>& room) {
    int length = room.size(), width = room[0].size(); 
    Direction direction = DOWN;
    if(door.first > 0 && door.second == 0) {
        direction = RIGHT;
    } else if(door.first > 0 && door.second == width-1) {
        direction = LEFT;
    } else if(door.first == 0 && door.second > 0) {
        direction = DOWN;
    } else if(door.first == length-1 && door.second > 0) {
        direction = UP;
    }
    return direction;
}

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int numHouse = 1;
    while(true) {
        int w; cin >> w;
        int l; cin >> l;
        if(!w && !l) {
            break;
        }
        vector<vector<char>> room(l, vector<char>(w));
        for(int i = 0; i < l; i++) {
            for(int j = 0; j < w; j++) {
                cin >> room[i][j];
            }
        }
        pair<int, int> door = getDoor(room);
        Direction direction = getDirection(door, room);
        bool found = false;
        int startx = door.first, starty = door.second;
        while(!found) {
            switch(direction) {
                case DOWN:
                    startx++;
                    break;
                case UP:
                    startx--;
                    break;
                case RIGHT:
                    starty++;
                    break;
                case LEFT:
                    starty--;
                    break;
            }
            if(room[startx][starty] == '\\') {
                if(direction == UP) {
                    direction = LEFT;
                } else if(direction == DOWN) {
                    direction = RIGHT;
                } else if(direction == LEFT) {
                    direction = UP;
                } else if(direction == RIGHT) {
                    direction = DOWN;
                }
            }
            if(room[startx][starty] == '/') {
                if(direction == UP) {
                    direction = RIGHT;
                } else if(direction == DOWN) {
                    direction = LEFT;
                } else if(direction == LEFT) {
                    direction = DOWN;
                } else if(direction == RIGHT) {
                    direction = UP;
                }
            }
            if(room[startx][starty] == 'x') {
                room[startx][starty] = '&';
                found = true;
            }
        }
        printRoom(room, numHouse);
        numHouse++;
    }
    return 0;
}
