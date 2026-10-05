class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> A = nums1, B = nums2;
        int total = A.size() + B.size();
        if(A.size() > B.size())
            swap(A, B);
        int half = (total + 1) / 2, l = 0, r = A.size(), a, b, aleft, aright, bleft, bright;
        while(l <= r){
            a = (l + r) / 2;
            b = half - a;
            aleft = a>0? A[a-1]: INT_MIN;
            aright = a<A.size()? A[a]: INT_MAX;
            bleft = b>0? B[b-1]: INT_MIN;
            bright = b<B.size()? B[b]: INT_MAX;
            if(aleft<=bright && bleft<=aright){
                if(total % 2)
                    return max(aleft, bleft);
                else
                    return (max(aleft, bleft) + min(aright, bright)) / 2.0;
            } else if(aleft > bright)
                r = a - 1;
            else
                l = a + 1;
        }
        return -1;
    }
};
