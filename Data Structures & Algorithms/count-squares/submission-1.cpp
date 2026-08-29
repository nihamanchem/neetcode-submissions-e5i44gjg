class CountSquares {
public:

    map<pair<int,int>, int> points;

    void add(vector<int> point) {
        points[{point[0], point[1]}]++;
    }

    int count(vector<int> point) {

        int x = point[0];
        int y = point[1];

        int ans = 0;

        for (auto &[p, freq] : points) {

            int x2 = p.first;
            int y2 = p.second;

            // Need another point with same x
            if (x2 != x || y2 == y)
                continue;

            int d = y2 - y;

            // Square to the right
            ans += freq
                * points[{x + abs(d), y}]
                * points[{x + abs(d), y2}];

            // Square to the left
            ans += freq
                * points[{x - abs(d), y}]
                * points[{x - abs(d), y2}];
        }

        return ans;
    }
};