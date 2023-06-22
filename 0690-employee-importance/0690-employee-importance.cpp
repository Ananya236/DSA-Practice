/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

// int getIndex(vector<Employee*> employees, int id){
//     int n = employees.size();
//     for(int i=0; i<n; i++){
//         if(employees[i]->id == id){
//             return i;
//         }
//     }
//     return 0;
// }

// void dfs(vector<int> &vis, vector<Employee*> employees, int id, int &total_imp){
//     int emp = getIndex(employees, id);
//     vis[emp]=1;
//     total_imp+= employees[emp]->importance;
    
//     for(auto e: employees[emp]->subordinates){
//         if(!vis[getIndex(employees,e)]){
//             dfs(vis,employees,e,total_imp);
//         }
//     }
// }

// class Solution {
// public:
//     int getImportance(vector<Employee*> employees, int id) {
//         int n = employees.size();
//         vector<int> vis(n,0);
//         int total_imp = 0;      
        
//         dfs(vis, employees, id, total_imp);
        
//         return total_imp;
//     }
// };


void dfs(vector<int> &vis, vector<int> id_index, vector<Employee*> employees, int id, int &total_imp){
    int emp = id_index[id];
    vis[emp]=1;
    total_imp+= employees[emp]->importance;
    
    for(auto e: employees[emp]->subordinates){
        if(!vis[id_index[e]]){
            dfs(vis,id_index,employees,e,total_imp);
        }
    }
}

class Solution {
public:
    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        vector<int> vis(n,0);
        int total_imp = 0; 
        
        vector<int> id_index(2001, -1);
        for(int i=0; i<n; i++){
            id_index[employees[i]->id] = i;
        }
        
        dfs(vis, id_index, employees, id, total_imp);
        
        return total_imp;
    }
};