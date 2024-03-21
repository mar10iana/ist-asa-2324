#include <iostream>
#include <vector>

// Function to parse input data for slab dimensions and piece types
void parse(int& slabWidth, int& slabHeight, 
    std::vector<std::vector<int>>& pieces) {
    
    int numberTypes;
    
    // Check if input for slab dimensions is valid, return if not
    if (!(std::cin >> slabWidth >> slabHeight) 
        || slabWidth <= 0 || slabHeight <= 0)
        return;

    // Check if input for number of types is valid, return if not
    if (!(std::cin >> numberTypes) || numberTypes <= 0)
        return;

    // Resize table pieces and initialize with 0
    pieces.resize(slabWidth + 1, std::vector<int>(slabHeight + 1, 0));

    // Read each piece type
    for (int i = 0; i < numberTypes; ++i) {
        
        int w, h, p;

        // Check if input for piece type values is valid, return if not
        if (!(std::cin >> w >> h >> p) || w <= 0 || h <= 0 || p < 0)
            return;

        // Skip piece if its price is 0
        if(p == 0)
            continue;

        // Store price if piece fits within the slab dimensions
        if(w <= slabWidth && h <= slabHeight)
            pieces[w][h] = p;

        // Do the same for rotated dimensions if non-square
        if(w != h && h <= slabWidth && w <= slabHeight)
            pieces[h][w] = p;
    }
}

// Function to calculate the maximum price obtainable by cutting the slab
int getMaxPrice(int slabWidth, int slabHeight, 
    const std::vector<std::vector<int>>& pieces) {
    
    // Resize table DP and inicialize with 0
    std::vector<std::vector<int>> dp(slabWidth + 1, 
        std::vector<int>(slabHeight + 1, -1));

    // Loop through each possible dimension
    for (int w = 1; w <= slabWidth; ++w) {
        for (int h = 1; h <= slabHeight; ++h) {
            
            // Skip if already calculated
            if(dp[w][h] != -1)
                continue;
            
            // Initial price is the price of the piece that fits exactly
            // 0 if no such piece exists
            int maxPrice = pieces[w][h];

            // Try cutting the slab vertically
            for (int cut = 1; cut <= w/2; ++cut) {
                maxPrice = std::max(maxPrice, dp[cut][h] + dp[w - cut][h]);
            }

            // Try cutting the slab horizontally
            for (int cut = 1; cut <= h/2; ++cut) {
                maxPrice = std::max(maxPrice, dp[w][cut] + dp[w][h - cut]);
            }

            // Update DP table with the max price found
            dp[w][h] = maxPrice;

            // Update DP for rotated dimensions if non-square
            if(w != h && h <= slabWidth && w <= slabHeight)
                dp[h][w] = maxPrice;
        }
    }

    // Return the maximum price for the given slab dimensions
    return dp[slabWidth][slabHeight];
}

// Main function
int main() {

    // Improve I/O efficiency
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    
    // Variables for slab dimensions
    int slabWidth, slabHeight;

    // Table to store piece prices
    std::vector<std::vector<int>> pieces;

    // Parse input
    parse(slabWidth, slabHeight, pieces);

    // Validate input, print 0 and return if invalid
    if(slabWidth <= 0 || slabHeight <= 0 || pieces.empty()) {
        std::cout << 0 << std::endl;
        return 0;
    }

    // Calculate and print the maximum price
    int maxPrice = getMaxPrice(slabWidth, slabHeight, pieces);
    std::cout << maxPrice << std::endl;

    return 0;
}
