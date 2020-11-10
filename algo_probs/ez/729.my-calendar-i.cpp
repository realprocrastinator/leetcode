/*
 * @lc app=leetcode id=729 lang=cpp
 *
 * [729] My Calendar I
 */

// @lc code=start
class compare {
public:
    // comparison     
};

class MyCalendar {
public:
    MyCalendar(): data_{std::set<std::pair<int, int>>{}} {
    }
    
    bool book(int start, int end) {
        if (data_.empty()) {
            data_.insert(std::make_pair(start, end));
            return true;
        }
        
        // we need to find lower bound in the tree, if first < end, return false
        // find the high bound of the tree, if  end
        auto it = data_.lower_bound(std::make_pair(start,end));
        if (it == data_.end()) {
            // reach the end;
            if (start >= (--it)->second) {
                data_.insert(std::make_pair(start, end));
                return true;    
            }
        }
        
        if (it == data_.begin()) {
            std::cout << it->first << '\n';
            if (end <= it->first) {
                // add to head
                data_.insert(std::make_pair(start, end));
                return true;
            }
            
            if (start >= it->second ) {
                if (++it == data_.end()) {
                    data_.insert(std::make_pair(start, end));
                    return true;
                } else if (end <= it->first) {
                    data_.insert(std::make_pair(start, end));
                    return true;
                }
            }
        }
        
        if (end <= it->first) {
            if (start >= (--it)->second) {
                data_.insert(std::make_pair(start, end));
                return true;
            }
        }
        
        if (start >= it->second) {
            if (++it == data_.end()) {
                data_.insert(std::make_pair(start, end));
                return true;
            } else if (end <= it->first) {
                data_.insert(std::make_pair(start, end));
                return true;
            }
        }
        
        // other case overlap!
        return false;
    }
private:
    // usign a set pair(start, end)
    std::set<std::pair<int, int>> data_;
    
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
// @lc code=end

