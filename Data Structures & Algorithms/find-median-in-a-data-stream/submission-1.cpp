class MedianFinder {
public:
    // maxHeap stores the LEFT half (smaller numbers)
    priority_queue<int> maxHeap;

    // minHeap stores the RIGHT half (larger numbers)
    priority_queue<int, vector<int>, greater<int>> minHeap;

    MedianFinder() {
        // nothing needed here
    }
    
    void addNum(int num) {

        // Step 1: Always push into maxHeap first
        // (we assume number belongs to left half initially)
        maxHeap.push(num);

        // Step 2: Move the largest of left side to right side
        // This ensures ordering: maxHeap <= minHeap
        minHeap.push(maxHeap.top());
        maxHeap.pop();

        // Step 3: Balance sizes
        // maxHeap is allowed to have at most 1 extra element
        if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }
    
    double findMedian() {

        // Case 1: Odd number of elements
        // maxHeap has one extra element
        if (maxHeap.size() > minHeap.size()) {
            return maxHeap.top();
        }

        // Case 2: Even number of elements
        // median is average of two middle values
        return (maxHeap.top() + minHeap.top()) / 2.0;
    }
};