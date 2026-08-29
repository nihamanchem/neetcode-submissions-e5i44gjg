class CountSquares {
public:
    map<pair<int,int>,int> ptfreq;
    
    void add(vector<int> point) {
        ptfreq[{point[0],point[1]}]++;   
    }
    
    int count(vector<int> point) {
        int px=point[0];
        int py=point[1];
        int res=0;
        for(auto &[p,freq]: ptfreq){
            int x=p.first;
            int y=p.second;
            if(x==px && y!=py) {
                int d= y-py;
                res+=freq*ptfreq[{x+d,py}]*ptfreq[{x+d,y}];
                res+=freq*ptfreq[{x-d,py}]*ptfreq[{x-d,y}];
            }
        }
        return res;
    }
};
