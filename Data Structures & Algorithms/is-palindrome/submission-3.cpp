class Solution {
public:
    bool isPalindrome(string s) {
        deque<char> q;
        for(auto c: s){
            if((c>='a' && c<='z') || (c>='A' && c<='Z') || (c>='0' && c<='9'))
                q.push_back(tolower(c));
        }
        while(q.size() > 1){
            // cout << q.front() << " " << q.back() << endl;
            if(q.front() != q.back())
                return false;
            q.pop_front();
            q.pop_back();
        }
        return true;
    }
};
