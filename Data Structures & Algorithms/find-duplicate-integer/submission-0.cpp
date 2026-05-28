class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // PHASE 1: Find the intersection point of the two runners.
        // We use a do-while loop to ensure they take at least one step 
        // before we check if they have collided.
        do {
            slow = nums[slow];           // Tortoise takes 1 step
            fast = nums[nums[fast]];     // Hare takes 2 steps
        } while (slow != fast);

        // PHASE 2: Find the entrance to the cycle (the duplicate number).
        // Reset the slow pointer back to the starting line.
        slow = nums[0];

        // Now both runners move at the exact same speed (1 step at a time).
        // The math guarantees they will collide exactly at the cycle entrance.
        while (slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        // They collided at the duplicate number! Return either one.
        return slow;
    }
};