class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        priority_queue<int> qmax;
        priority_queue<int, vector<int>, greater<int>> qmin;
        for(int i=0; i<2; i++){
            for(auto j: nums1){
                if((qmax.empty() && qmin.empty()) || j<qmax.top())
                    qmax.push(j);
                else
                    qmin.push(j);
                
                if(qmax.size() > qmin.size()+1){
                    qmin.push(qmax.top());
                    qmax.pop();
                }
                else if(qmin.size() > qmax.size()+1){
                    qmax.push(qmin.top());
                    qmin.pop();
                }
            }
            swap(nums1, nums2);
        }
        if(qmax.size() != qmin.size())
            return qmax.size()>qmin.size()? qmax.top(): qmin.top();
        else
            return (double)(qmax.top() + qmin.top()) / 2.0;
    }
};
