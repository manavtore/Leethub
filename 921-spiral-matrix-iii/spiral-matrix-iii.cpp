class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
    vector<vector<int>> result;
    int totalCells = rows * cols;
    result.push_back({rStart, cStart});  
    

    vector<int> directions = {0, 1, 0, -1, 0};  
    int steps = 0; 
    int dirIndex = 0; 
    
    while (result.size() < totalCells) {
        if (dirIndex == 0 || dirIndex == 2) {
            ++steps;  
        }
        
        for (int i = 0; i < steps; ++i) {
            rStart += directions[dirIndex];
            cStart += directions[dirIndex + 1];
            

            if (rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                result.push_back({rStart, cStart});
            }
        }
        

        dirIndex = (dirIndex + 1) % 4;
    }
    
    return result;
}
    
};