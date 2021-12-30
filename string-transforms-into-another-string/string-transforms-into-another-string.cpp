class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1 == str2) return true;
        
        unordered_map<char, char> conversionMappings;
        
        unordered_set<char> uniqueCharInStr2;
        
        for (int i = 0; i <str1.size(); i++){
            if (conversionMappings.find(str1[i]) == conversionMappings.end()){
                conversionMappings[str1[i]] = str2[i];
                uniqueCharInStr2.insert(str2[i]);
            }else if(conversionMappings[str1[i]] != str2[i]){
                return false;
            }
        }
        
        if (uniqueCharInStr2.size()<26)
            return true;
        
        return false;
    }
};