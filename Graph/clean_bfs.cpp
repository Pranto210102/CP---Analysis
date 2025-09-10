    vector<int> dis(10000, 1e6+1);

     queue<int> q;
     vector<int>vis(10000 , 0);

     q.push(0);
     dis[0] = 0;

     while(!q.empty()){
          int cur_node = q.front();
          q.pop();

          if(vis[cur_node])continue;
          vis[cur_node] = 1;

          for(auto v : g[cur_node]){
              int next_node = v;

              if(dis[next_node]> dis[cur_node] + 1){
                 dis[next_node] = dis[cur_node] + 1;

                 q.push(next_node);
              }
          }
     }
