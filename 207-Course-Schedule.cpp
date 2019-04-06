class Solution {
public:
    bool has_circle(vector<vector<int>>& edges, vector<bool>& visited, vector<bool>& visiting, int node) {
        if(visiting[node])
            return true;
        visited[node] = true;
        visiting[node] = true;
        int n = edges[node].size();
        for(int i = 0; i < n; ++i) 
            if(has_circle(edges, visited, visiting, edges[node][i]))
                return true;
        visiting[node] = false;
        return false;
    }
    
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        vector<vector<int>> edges(numCourses);
        int len_edge = prerequisites.size();
        for(int i = 0; i < len_edge; ++i)
            edges[prerequisites[i].first].push_back(prerequisites[i].second);
        
        vector<bool> visited(numCourses, false);
        vector<bool> visiting(numCourses, false);
        int node = 0;
        while(node < numCourses) {
            if(!visited[node] && has_circle(edges, visited, visiting, node))
                return false;
            node++;
        }
        return true;
    }
};