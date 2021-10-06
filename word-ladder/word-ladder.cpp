class Solution {
public:
//     int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
//         //construct dictionary from wordlist
//         map<string, vector<string>> graph;
//         vector<string> totalList = wordList;
//         totalList.push_back(beginWord);
//         for (string startword:totalList){
//             // cout<<startword<<endl;
//             vector<string> nextwords(0);
//             for (string compword:wordList){
//                 int diffcount = 0;
//                 for (int i = 0; i<startword.length();i++){
//                     if (compword.compare(i,1,startword,i,1)!=0)
//                         diffcount+=1;
//                 }
//                 // cout<<compword<<" "<<diffcount<<endl;
//                 if (diffcount==1)
//                     nextwords.push_back(compword);
//             }
//             if (nextwords.size()>0){
//                 graph[startword] = nextwords;
//                 // for (string nextword:nextwords){
//                 //     cout<<startword<<" "<<nextword<<endl;
//                 // }
//             }
//         }
        
//         // in case endword not in wordlist.
//         if (graph.find(endWord) == graph.end())
//             return 0;
//         // in case beginword does not have match.
//         if (graph.find(beginWord) == graph.end())
//             return 0;
//         //breadth first search
//         queue<string> q;
//         q.push(beginWord);
//         int count = 1;
//         vector<string> explored;
//         while (q.empty()!=true){
//             int qsize = q.size();
//             count +=1;
//             for (int i = 0; i <qsize;i++){
//                 vector<string> nextwords = graph[q.front()];
//                 for (string nextword: nextwords){
//                     if (nextword.compare(endWord)==0)
//                         return count;
//                     else{
//                         if (find(explored.begin(), explored.end(), nextword)==explored.end())
//                             q.push(nextword);
//                     }
//                 }
//                 explored.push_back(q.front());
//                 q.pop();
//             }
            
//         }
        
//         return 0;
//     }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        queue<string> todo;
        todo.push(beginWord);
        int ladder = 1;
        while (!todo.empty()) {
            int n = todo.size();
            for (int i = 0; i < n; i++) {
                string word = todo.front();
                todo.pop();
                if (word == endWord) {
                    return ladder;
                }
                dict.erase(word);
                for (int j = 0; j < word.size(); j++) {
                    char c = word[j];
                    for (int k = 0; k < 26; k++) {
                        word[j] = 'a' + k;
                        if (dict.find(word) != dict.end()) {
                            todo.push(word);
                        }
                     }
                    word[j] = c;
                }
            }
            ladder++;
        }
        return 0;
    }
};