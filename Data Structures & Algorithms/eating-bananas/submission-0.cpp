class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h)
    {
        int right = 0;

        for(int num : piles)
        {
            right = max(right, num);
        }

        int left = 1;

        int result = INT_MAX;

        while(left <= right)
        {
            int k = (left + right)/2;

            int hrs = 0;

            for(int num : piles)
            {
                hrs += (num + k - 1) / k;
            }

            if(hrs <=  h)
            {
                result = min(result, k);
                right = k - 1;
            }
            else
            {
                left = k + 1;
            }


        }

        return result;


    }

};
