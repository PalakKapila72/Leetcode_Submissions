class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        int n=s.size();
        vector<string> ans;
        long long hash=0;
        unordered_map<char,int> mp1;
        mp1['A']=1,mp1['C']=2,mp1['T']=3,mp1['G']=4;
        unordered_map<long long,int> mp2;
        for(int i=0;i<10;i++){
            hash=hash+mp1[s[i]]*pow(4,9-i);

        }
        mp2[hash]=1;
        for(int i=10;i<n;i++){
            hash=hash-mp1[s[i-10]]*pow(4,9);
            hash=hash*4;
            hash=hash+mp1[s[i]];
            if(mp2[hash]==1){ans.push_back(s.substr(i-9,10));}
            mp2[hash]++;
            
        }
        
        return ans;
    }
};