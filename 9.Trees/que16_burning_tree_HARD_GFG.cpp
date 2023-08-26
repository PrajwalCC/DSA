// https://practice.geeksforgeeks.org/problems/burning-tree/1

void mapChildToParent(Node* root, map<Node*, Node*>& m){
    queue<Node*> q;
    q.push(root);
    
    while(!q.empty()){
        Node* curr = q.front();
        q.pop();
        
        if(curr->left){
            Node* left = curr->left;
            m[left] = curr;
            q.push(left);
        }
        if(curr->right){
            Node* right = curr->right;
            m[right] = curr;
            q.push(right);
        }
    }
    
}

int solve(Node* targetNode, map<Node*, Node*>& m, set<Node*> visited){
    queue<Node*> q;
    q.push(targetNode);
    visited.insert(targetNode);
    
    int ansTime = 0;
    
    while(!q.empty()){
        
        int sizeOfQueue = q.size();
        
        while(sizeOfQueue--){
            
            Node* curr = q.front();
            q.pop();
            
            if(m.find(curr) != m.end() && visited.find(m[curr]) == visited.end()){
                Node* parent = m[curr];
                q.push(parent);
                visited.insert(parent);
            }
            
            if(curr->left){
                Node* left = curr->left;
                if(visited.find(left) == visited.end()){
                    q.push(left);
                    visited.insert(left);
                }
            }
            
            if(curr->right){
                Node* right = curr->right;
                if(visited.find(right) == visited.end()){
                    q.push(right);
                    visited.insert(right);
                }
            }
            
        }
        
        ansTime = ansTime + 1;
    }
    
    return ansTime - 1;
}

int minTime(Node* root, int target) 
{
    // Your code goes here
    set<Node*> visited;
    map<Node*, Node*> m;
    mapChildToParent(root, m);
    
    Node* targetNode = NULL;

    // Find the actual node in the binary tree with the target value
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        if (curr->data == target) {
            targetNode = curr;
            break;
        }
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    
    if (!targetNode)
        return -1; // Target node not found
    
    return solve(targetNode, m, visited);
}