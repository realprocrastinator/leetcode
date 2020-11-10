/*
 * @lc app=leetcode id=1472 lang=cpp
 *
 * [1472] Design Browser History
 */

// @lc code=start
class BrowserHistory {

private:
    string _url = "";
    multimap<int,string> _path;
    int pos = 0;
    int cur = -1;
public:
    
    BrowserHistory(string homepage) {
        _url = homepage;
        if (!_url.empty()) {
            ++cur;
            pos = cur;
            _path.emplace(pos,_url);
        }
    }
    
    void visit(string url) {
        if (!url.empty()) {
            if (cur != pos){
                for (int i = 1 ; i <= pos - cur; i++){
                    cout << "remove " << cur + i << _path.find(cur+i)->second << endl;
                    _path.erase(cur + i);
                }
                
                pos = ++cur;
            } else {
                cur = ++pos;
            }
            
            _path.emplace(pos,url);
            
        }
    }
    
    string back(int steps) {
        if (steps > cur){
            steps = cur;
        }
        
        cur -= steps;
        
        return _path.find(cur)->second;
    }
    
    string forward(int steps) {
        if (steps > pos - cur){
            steps = pos - cur;
        }
        
        cur += steps;
        
        return _path.find(cur)->second;  
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */
// @lc code=end

