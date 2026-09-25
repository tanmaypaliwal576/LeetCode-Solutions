class Solution {
public:
    void dfs(vector<vector<int>>& image, int r, int c, int oldColor, int newColor)
    {
        // Out of bounds
        if(r < 0 || r >= image.size() || c < 0 || c >= image[0].size())
            return;

        // If the color is different, stop
        if(image[r][c] != oldColor)
            return;

        // Change the color
        image[r][c] = newColor;

        // Move up
        dfs(image, r - 1, c, oldColor, newColor);

        // Move down
        dfs(image, r + 1, c, oldColor, newColor);

        // Move left
        dfs(image, r, c - 1, oldColor, newColor);

        // Move right
        dfs(image, r, c + 1, oldColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color)
    {
        int oldColor = image[sr][sc];

        // If both colors are same, nothing needs to be done
        if(oldColor == color)
            return image;

        dfs(image, sr, sc, oldColor, color);

        return image;
    }
};