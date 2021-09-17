import java.util.Hashtable;

class Solution {
    public int[] twoSum(int[] nums, int target) {
        //hashtable table(key: number, value: index):
        //for (i=0;i<N; i++):
        // if target - num in table, return num index and target index
        // else put num in the table. 
        int[] ans = new int[2];
        Hashtable<Integer, Integer> ht = new Hashtable<Integer, Integer>();
        
        for (int i=0;i<nums.length; i++){
            if(ht.get(target - nums[i])!=null){
                ans[0] = ht.get(target - nums[i]);
                ans[1] = i;
                break;
            }else{
                ht.put(nums[i], i);
            }
        }
        return ans;
    }
}