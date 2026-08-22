class Solution {
private:

    struct pairHash {
        size_t operator()(const pair<int, int>& p) const {
            return hash<int>()(p.first) ^ hash<int>()(p.second);
        }
    };

    void dfs(vector<vector<int>>& image,
             int sr,
             int sc,
             int color,
             int originalColor,
             unordered_map<pair<int, int>, bool, pairHash>& visited) {

        // Base case
        if (sr < 0 || sr >= image.size() ||
            sc < 0 || sc >= image[0].size()) {
            return;
        }

        if (visited[{sr, sc}] || image[sr][sc] != originalColor) {
            return;
        }

        visited[{sr, sc}] = true;
        image[sr][sc] = color;

        // Up
        if (sr - 1 >= 0 && !visited[{sr - 1, sc}]) {
            dfs(image, sr - 1, sc, color, originalColor, visited);
        }

        // Down
        if (sr + 1 < image.size() && !visited[{sr + 1, sc}]) {
            dfs(image, sr + 1, sc, color, originalColor, visited);
        }

        // Left
        if (sc - 1 >= 0 && !visited[{sr, sc - 1}]) {
            dfs(image, sr, sc - 1, color, originalColor, visited);
        }

        // Right
        if (sc + 1 < image[0].size() && !visited[{sr, sc + 1}]) {
            dfs(image, sr, sc + 1, color, originalColor, visited);
        }
    }

public:

    vector<vector<int>> floodFill(vector<vector<int>>& image,
                                   int sr,
                                   int sc,
                                   int color) {

        int originalColor = image[sr][sc];

        if (originalColor == color) {
            return image;
        }

        unordered_map<pair<int, int>, bool, pairHash> visited;

        dfs(image, sr, sc, color, originalColor, visited);

        return image;
    }
};