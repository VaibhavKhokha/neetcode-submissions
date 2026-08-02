class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target)
    {

        if(matrix.empty() || matrix[0].empty())
        {
            return false;
        }

        int left_outer = 0;
        int right_outer = matrix.size() - 1;

        while(left_outer <= right_outer)
        {
            int center_outer = (left_outer + right_outer) / 2;

            if(matrix[center_outer][0] == target)
            {
                return true;
            }
            else if(matrix[center_outer][0] < target)
            {
                if(center_outer == matrix.size() - 1 || matrix[center_outer + 1][0] > target)
                {
                    int left = 0;
                    int right = matrix[center_outer].size() -1 ;

                    while(left <= right)
                    {
                        int center = (left + right) / 2;

                        if(matrix[center_outer][center] == target)
                        {
                            return true;
                        }
                        else if(matrix[center_outer][center] > target)
                        {
                            right = center - 1;
                        }
                        else
                        {
                            left = center + 1;
                        }

                    }

                    return false;

                }
                else
                {
                    left_outer = center_outer + 1;
                    continue;
                }
            }
            else
            {
                right_outer = center_outer - 1; 
            }

        }

        return false;

    }
    
};
