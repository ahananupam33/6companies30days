class Solution {
public:
    double radius, x_center, y_center;
    Solution(double radius, double x_center, double y_center) {
        this->radius = radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    double random(){
        return (double)rand() / RAND_MAX; // for generating random points between 0 to 1
    }
    
    vector<double> randPoint() {
        vector<double> ans;
        double len = (sqrt(random()))*radius;
        double deg = random() * M_PI * 2;
        
        ans.push_back(x_center + len*cos(deg));
        ans.push_back(y_center + len*sin(deg));
        return ans;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */