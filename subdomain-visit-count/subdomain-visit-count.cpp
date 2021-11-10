class Solution {
public:
    
    
    int findCount(string & cpdomain){
//         int len=0;
//         for (int i =0;i<cpdomain.length();i++){
//             if (i==' '){
//                 len = i-1;
//             }
//         }
        
        // std::string::size_type sz;
        
        return stoi(cpdomain);
        
    }
    
    string findDomain(string & cpdomain){
        int start=0;
        for (int i =0;i<cpdomain.length();i++){
            if (cpdomain[i]==' '){
                start = i+1;
            }
        }
        
        return cpdomain.substr(start);
    }
    
    
    void updateHM(string& strDomain, map<string,int>& HM, int & count){
        HM[strDomain]= HM[strDomain]+ count;
        for (int i = 0;i<strDomain.length();i++){
            if (strDomain[i]=='.'){
                HM[strDomain.substr(i+1)]+=count;
            }
        }
    }
    
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        //break down each cout-paired domain
        map<string,int> HM;
        for (auto cpdomain:cpdomains){
            int count = findCount(cpdomain);
            string strDomain = findDomain(cpdomain);
            updateHM(strDomain, HM, count);
        }
            //figure out the format. format 1 d1.d2  format 2 d1.d2.d3. 
        
        vector<string> ans;
        
        for (auto const&[key, value]:HM){
            string curAns = to_string(value) + ' ' + key;
            ans.push_back(curAns);
        }
        
        return ans;
    }
};