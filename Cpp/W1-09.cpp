class Solution {
public:
    vector<vector<int>> img;
    int col;
    int source_col;
    int m;
    int n;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        img = image;
        m = img.size();
        n = img[0].size();
        col = color;
        source_col = image[sr][sc];
        if(col!=source_col)
            fillCell(sr,sc);
        return img;
    }
    
    void fillCell(int r, int c){
        img[r][c] = col;
        if( (r!=0) && (img[r-1][c]==source_col)){
            fillCell(r-1,c);
        }
        if( (c!=0) && (img[r][c-1]==source_col)){
            fillCell(r,c-1);
        }
        if((r!=img.size()-1) && (img[r+1][c]==source_col)){
            fillCell(r+1,c);
        }
        if( (c!=img[0].size()-1) && (img[r][c+1]==source_col) ){
            fillCell(r,c+1);
        }
    }
};
