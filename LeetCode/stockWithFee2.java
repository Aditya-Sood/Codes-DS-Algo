public static void main(String args[]) {

}

int maxProfit(int[] arr, int l, int r) {
	if(l >= r) return 0;

	int max = l, min = r;

	for(int i = l+1; i <= r; i++) {
		if(arr[i] > arr[max])
			max = i;
	}

	for(int j = l+1, j < max; j++) {
		if(arr[j] < arr[min])
			min = j;
	}

	int profit = arr[max] - arr[min];


	return (profit + maxProfit(arr, l, min-1) + maxProfit(arr, max+1, r));
}

class Solution {
public:
    int maxReturns(vector<int>& arr, int l, int r, int fee) {
        if(l >= r) return 0;
        
        int max = l, min = l; // Assuming first as both
        
        for(int i = l+1; i <= r; i++) { // Interval max
            if(arr[max] < arr[i]) {
                max = i;
            }
        }
        for(int j = max-1; j > l; j--) { // Min closest before max
            if(arr[min] > arr[j]) {
                min = j;
            }
        }
        
        int profit = (arr[max] - arr[min] - fee);
        profit = (profit > 0) ? profit : 0;
        
        return (profit + maxReturns(arr, l, min-1, fee) + maxReturns(arr, max+1, r, fee)); // Top-down approach
    }
    
    
    
    int maxProfit(vector<int>& prices, int fee) {
        return maxReturns(prices, 0, prices.size()-1, fee);
    }
};