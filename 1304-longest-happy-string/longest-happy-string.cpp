class Solution {
public:
    string longestDiverseString(int a, int b, int c) {

        priority_queue<pair<int, char>> pq;
        
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string str = "";
        while(!pq.empty()){
            auto [count1,ch1] = pq.top();
            pq.pop();

            if(str.length() >= 2  && str[str.length()-1]==ch1 && str[str.length()-2]==ch1){
                if(pq.empty()) break;
                auto[count2,ch2] = pq.top();

                
                pq.pop();
                str +=ch2;
                if(--count2 > 0){
                    pq.push({count2,ch2});
                }

                pq.push({count1,ch1});

            }else{
                str +=ch1;
                if(--count1 > 0){
                    pq.push({count1,ch1});
                }
            }
        }

        return str;
    }
};