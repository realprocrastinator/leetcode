#
# @lc app=leetcode id=609 lang=python3
#
# [609] Find Duplicate File in System
#

# @lc code=start
class Solution:
    def findDuplicate(self, paths: List[str]) -> List[List[str]]:
        output = collections.defaultdict(list)
        dup_cnt = collections.defaultdict(int)
        # traverse each path
        for path in paths: 
            # path split
            path_file = path.split()
            directory = path_file[0]
            # store the path name
            if len(path_file) > 1:
                # traverse the files using regex to get the content
                for file in path_file[1:]:
                    idx = file.find("(")
                    name = directory + "/" + file[:idx]
                    content = re.search('(?<=\().*?(?=\))',file).group()
                    # buil the dic tionary key is content , value is path
                    output[content].append(name)
                    dup_cnt[content] += 1
            else:
                print("no content")
        
        # traverse the value in the output dict
        List = [output.get(k) for k in output.keys() if dup_cnt[k] > 1]
        return List
        
# @lc code=end

