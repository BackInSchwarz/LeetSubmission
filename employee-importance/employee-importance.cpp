/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
public:
    
    int sum;
    unordered_map<int, int> id2ind;
    
    void dfs(vector<Employee*> & employees, int index){
        
        sum += employees[index]->importance;
        
        for (int subID: employees[index]->subordinates ){
            dfs(employees, id2ind[subID]);
        }
        
        return;
    }
    
    int getImportance(vector<Employee*> employees, int id) {
        
        sum = 0;
        
        for (int i=0;i<employees.size();i++){
            id2ind[employees[i]->id] = i;
        }
        
        dfs(employees, id2ind[id]);
        
        return sum;
    }
};


