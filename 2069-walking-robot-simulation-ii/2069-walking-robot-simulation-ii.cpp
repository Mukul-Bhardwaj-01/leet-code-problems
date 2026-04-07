class Robot {
public:
    vector<int> currPos = {0,0};
    string currDir = "East";
    int h, w;
    vector<vector<int>> grid;
    Robot(int width, int height) {
        w = width; h = height;
        grid = vector<vector<int>>(width, vector<int>(height,0));
    }
    void step(int num) {
        int steps = num % (2*(h - 2 + w));
        if(steps == 0 && num > 0) steps = 2*(h - 2 + w);
        while(steps > 0) {
            if(currDir == "East") {
                if(currPos[0] + 1 >= w) currDir = "North";
                else {
                    currPos[0]++;
                    steps--;
                }
            }
            else if(currDir == "West") {
                if(currPos[0] - 1 < 0) currDir = "South";
                else {
                    currPos[0]--;
                    steps--;
                } 
            }
            else if(currDir == "North") {
                if(currPos[1] + 1 >= h) currDir = "West";
                else {
                    currPos[1]++;
                    steps--;
                }
            }
            else {
                if(currPos[1] - 1 < 0) currDir = "East";   
                else {
                    currPos[1]--;
                    steps--;
                } 
            }
        }
    }
    
    vector<int> getPos() {
        return currPos;
    }
    
    string getDir() {
        return currDir;
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */