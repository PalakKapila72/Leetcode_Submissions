class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> mp;
        int n=s.size();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        string st="";
        while(!mp.empty()){
        int maxfreq=0;
        char maxchar;
            for(auto it:mp){
                if(it.second>maxfreq){
                    maxfreq=it.second;
                    maxchar=it.first;
                }
            }
                for(int i=0;i<maxfreq;i++){
                    st.push_back(maxchar);

                }
                mp.erase(maxchar);
            
        }

        
        return st;

    }
};