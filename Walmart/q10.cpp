 double radius, x, y;
    Solution(double radius, double x_center, double y_center) {
        radius = radius;
        x = x_center;
        y = y_center;
    }
    
    vector<double> randPoint() {
        double theta = (double)rand() / RAND_MAX * 2 * M_PI,
            hyp = sqrt((double)rand() / RAND_MAX) * radius,
            base = cos(theta) * hyp,
            per = sin(theta) * hyp;
        return vector<double>{x + base, y + per};
    }