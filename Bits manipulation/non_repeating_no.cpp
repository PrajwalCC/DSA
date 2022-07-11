// GFG 
sort(v.begin(),v.end()); 
vector <int> a;
        
        for(int i=0; i<v.size(); i++){
            if(i==0){
               if(v[0]!=v[1]){
                  a.push_back(v[0]);
                   
               }
            }

            else if(i== v.size()-1 ){
               if( v[v.size()-1] != v[v.size()-2] ){
                   a.push_back(v[v.size()-1]);
               }
            }
    
            else{
                if(v[i]!=v[i+1] || v[i] != v[i-1]){
                    a.push_back(v[i]);
                }
            }
        }
        
        return a;