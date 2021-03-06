/*
 * @lc app=leetcode id=779 lang=c
 *
 * [779] K-th Symbol in Grammar
 */

// @lc code=start


int kthGrammar(int N, int K){
    /* N rows then we have 2^(N-1) bits */
    /* the first half --> ones complement --> second half */
    /* we caculate the offset and then do the binary search */ 
    uint32_t idx = K;
    uint32_t mid = (1 << (N - 1)) / 2;
    if (mid == 0){
        // base case
        return 0;
    }
    if (idx > mid ){
        // right
        uint32_t offset = idx - mid;
        return (~kthGrammar(N - 1,offset) & 0x00000001);
    }else{
        // left
        return (kthGrammar(N - 1,idx) & 0x00000001);
    }
}
// @lc code=end

