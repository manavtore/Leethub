class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> city;
        for(const auto& a:paths){
           city.insert(a[0]);
        }
        for(const auto& a:paths){
            const string& dest=a[1];
            if(city.find(dest)==city.end()){
                return dest;
            }
        }

         return "";
    }
};