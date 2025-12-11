class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {


        int len = buildings.size();

        vector<int> lowestYforX(n+1,1e9);
        vector<int> highestYforX(n+1,-1);
        vector<int> leftXforY(n+1,1e9);
        vector<int> rightXforY(n+1,-1);

        int x0 = buildings[0][0]; 
        int y0 =  buildings[0][1];

        lowestYforX[0]=highestYforX[0]=y0;

        leftXforY[0]=rightXforY[0]=x0;


        for(int i=0;i<len;i++)
        {
            int x = buildings[i][0]; 
            int y = buildings[i][1];

            lowestYforX[x]=min(lowestYforX[x],y);
            highestYforX[x]=max(highestYforX[x],y);

            leftXforY[y]=min(leftXforY[y],x);
            rightXforY[y]=max(rightXforY[y],x);
        }

        int ans=0;
        for(int i=0;i<len;i++)
        {
            int x = buildings[i][0]; int y = buildings[i][1];


            if(x > leftXforY[y] && x< rightXforY[y] && y>lowestYforX[x] && y<highestYforX[x]) {
                ans++;
            }
            

            
        }
        return ans;
        
    }
};