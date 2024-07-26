class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        int matrix[n][n];
        memset(matrix, 9999, sizeof(matrix));
        for(int i = 0; i < edges.size(); i++) {
            matrix[edges[i][0]][edges[i][1]] = edges[i][2];
            matrix[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int k = 0; k < n; k++) {
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(i==j) {
                    matrix[i][j]=0;
                }
                else if(matrix[i][k] + matrix[k][j] < matrix[i][j]){
                    matrix[i][j]=matrix[i][k] + matrix[k][j];
                }
            }
        }
        }
        int index = -1, mini = 9999;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i!=j && matrix[i][j]<= distanceThreshold) {
                    count++;
                }
            }
            if(count <= mini) {
                mini=count;
                index = i;
            }
        }
        return index;
    }
};