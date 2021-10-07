class Solution {
public:
//     vector<string> explore(string curWord, unordered_set<string> & dict){
//         vector<string> ans;
//         int len = curWord.size();
//         for (int i = 0; i < len; i++){
//             char curChar = curWord[i];
//             for (int j = 0; j<26; j++){
//                 curWord[i] = 'a' + j;
//                 if (curWord[i]!=curChar){
//                     if(dict.find(curWord)!=dict.end()){
//                         ans.push_back(curWord);
//                         cout<<"hit word "<<curWord<<endl;
//                     }
                        
//                 }
//             }
//             curWord[i] = curChar;
//         }
//         return ans;
//     }
    
    
//     void rebuildans(vector<vector<string>> &ans,map<string, string>& pred, vector<string> &lastWords, string &endWord)
//     {
//         for (auto lastWord:lastWords){
//             string curWord = lastWord;
//             vector<string> curAns;
//             curAns.push_back(endWord);
//             while (curWord.compare("1")!=0){
//                 curAns.push_back(curWord);
//                 curWord = pred[curWord];
//                 cout<<curWord<<endl;
//             }
//             reverse(curAns.begin(),curAns.end());
//             ans.push_back(curAns);
//         }
        
//     }
    

//     vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
//         vector<vector<string>> ans;
//         unordered_set<string> dict(wordList.begin(), wordList.end());
//         //check if endword exists in the wordlist
//         if(dict.find(endWord)==dict.end())
//             return ans;
//         //BFS
//         queue<string> q;
//         q.push(beginWord);
//         map<string,int> visited;// 1 == visited. 0 == not visited.
//         map<string, string> pred;
//         pred[beginWord] = "1"; // this is the end of the search.
//         vector<string> lastWords;
//         bool lvfound= false;
//         while(q.empty()!=true && lvfound==false){
//             int qSize = q.size();
//             for (int i = 0; i <qSize; i++){
//                 string curWord = q.front();
//                 cout<<curWord<<endl;
//                 q.pop();
//                 //build the word and explore each 
//                 vector<string> nextWords = explore(curWord, dict);
//                 visited[curWord]=1;
//                 for (auto nextWord:nextWords){
//                     //check if it is the answer. if it is the answer, we push it back to the last word list. 
//                     if (nextWord.compare(endWord)==0){
//                         lastWords.push_back(curWord);
//                         lvfound=true;
//                         break;
//                     }else{
//                     //if it is not answer, prep next round. 
//                         cout<<"current visited results "<<visited[nextWord]<<endl;
//                         if (visited[nextWord]!=1){
//                             q.push(nextWord);
//                             if (pred.find(nextWord)==pred.end())
//                                 pred[nextWord] = curWord;
//                         }
//                     }
//                 }
//             }
//         }
        
        
//         rebuildans(ans, pred, lastWords, endWord);
        
//         return ans;
//     }
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st (wordList.begin(),wordList.end());
        unordered_set<string> visited;
        vector<vector<string>> ans;
        queue<vector<string>> q;
        q.push({beginWord});
        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto curr_path = q.front();
                q.pop();
                string last = curr_path.back();
                for(int i = 0 ; i < last.size() ; ++i){
                    auto temp = last;
                    for(char ch = 'a' ; ch <= 'z' ; ++ch){
                        temp[i] = ch;
                        if(st.find(temp) != st.end()){
                            auto new_path = curr_path;
                            new_path.push_back(temp);
                            visited.insert(temp);
                            if(temp == endWord)
                                ans.push_back(new_path);
                            else
                                q.push(new_path);
                        }
                    }
                }
            }
            for(auto& str : visited)
                    st.erase(str);
        }
        return ans;
    }
};