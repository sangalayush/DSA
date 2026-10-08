class Solution {
public:
    void  dfs(vector<vector<int>> &image, int row, int col, int oldcolor, int newcolor){
        int rows= image.size();
        int cols= image[0].size();
        if(row<0 || row>=rows || col<0 || col>= cols)
            return;
        if(image[row][col]!= oldcolor)
            return;
        image[row][col]= newcolor;
        //check for upper adjacent pixel
        dfs(image,row-1,col,oldcolor,newcolor);
        //check for lower adjacent pixel
        dfs(image,row+1,col,oldcolor,newcolor);
        //check for left adjacent pixel
        dfs(image,row,col-1,oldcolor,newcolor);
        //check for right adjacent pixel
        dfs(image,row,col+1,oldcolor,newcolor);        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int oldcolor= image[sr][sc];
        if(image[sr][sc]== color)
            return image;
        dfs(image,sr,sc,oldcolor,color);
        return image;
    }
};
//T.C.->O(R*C)-> where R is number of rows in the image and C is the number of columns.
//S.C.->O(R*C)->bcs in worst case the stack could have R*C dfs recurssive calls.
