class MedianFinder {
public:

    vector<int> stream;
    double median;
    MedianFinder() {
        median = 0;
    }
    
    void addNum(int num) {
        stream.push_back(num);
        sort(stream.begin(), stream.end());
    }
    
    double findMedian() {
        int size = stream.size();
        int mid = size/2;
        if( size % 2 == 0)
        {
            // even elements [1,2,3,4] median = (stream[1]+stream[2])/2
            median = (stream[mid-1] + stream[mid]) / (double)2;
            return median;
        } else {
            // odd elements [1,2,3,4,5], mid is the median
            return stream[mid];
        }

    }
};

