class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
         if (image.empty() || image[0].empty())
           return image;
        
         int m = image.size();
         int n = image[0].size();

         if (sr < 0 || sr >= n || sc < 0 || sc >= n)
           return image;
        
         int origin = image[sr][sc];
         if (origin == color)
           return image;
         
         stack<pair<int, int>> st;
         st.push({sr, sc});

         while(!st.empty())
         {
           auto [r, c] = st.top();
           st.pop();

           if (r < 0 || r >= m || c < 0 || c >= n)
             continue;
        
           if (image[r][c] != origin)
             continue;
    
            image[r][c] = color;

            st.push({r+1, c});
            st.push({r-1, c});
            st.push({r, c+1});
            st.push({r, c-1});
         }

         return image;
    }

};