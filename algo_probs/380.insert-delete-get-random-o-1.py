#
# @lc app=leetcode id=380 lang=python3
#
# [380] Insert Delete GetRandom O(1)
#

# @lc code=start
class RandomizedSet:

    def __init__(self):
        """
        Initialize your data structure here.
        """
        self.data = []
        #dict DA map the index of data to the data it self
        self.lookuptable = {}
        

    def insert(self, val: int) -> bool:
        """
        Inserts a value to the set. Returns true if the set did not already contain the specified element.
        """
        if val not in self.lookuptable or self.lookuptable[val] == -1:
            self.data.append(val)
            self.lookuptable[val] = len(self.data) - 1
            return True    
        return False

    def remove(self, val: int) -> bool:
        """
        Removes a value from the set. Returns true if the set contained the specified element.
        """
        if val in self.lookuptable and self.lookuptable[val] != -1:
            idx = self.lookuptable[val]
            #swap the last element in the map with the current element so
            # we dont need to change the index
            self.data[idx] = self.data[-1]
            self.lookuptable[self.data[idx]] = idx
            self.lookuptable[val] = -1
            self.data.pop()
            return True
        else:
            return False
    def getRandom(self) -> int:
        """
        Get a random element from the set.
        """
        if len(self.data) != 0:
            return self.data[random.randrange(0,len(self.data))]


# Your RandomizedSet object will be instantiated and called as such:
# obj = RandomizedSet()
# param_1 = obj.insert(val)
# param_2 = obj.remove(val)
# param_3 = obj.getRandom()
# @lc code=end

