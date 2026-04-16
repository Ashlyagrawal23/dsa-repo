class MedianFinder {
public:
    priority_queue<int> leftMax; // smaller half
    priority_queue<int, vector<int>, greater<int>> rightMin; // larger half

    MedianFinder() {
        
    }
    
    void addNum(int num) {
        // Step 1: push into max heap
        leftMax.push(num);

        // Step 2: move largest of left half to right half
        rightMin.push(leftMax.top());
        leftMax.pop();

        // Step 3: balance sizes
        if (rightMin.size() > leftMax.size()) {
            leftMax.push(rightMin.top());
            rightMin.pop();
        }
    }
    
    double findMedian() {
        if (leftMax.size() > rightMin.size()) {
            return leftMax.top();
        }
        
        return (leftMax.top() + rightMin.top()) / 2.0;
    }
};