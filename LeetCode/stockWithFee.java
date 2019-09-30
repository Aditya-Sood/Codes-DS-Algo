class Solution {
    public int maxProfit(int[] prices, int fee) {
        
        /*Find all existing sets of incremental periods*/
        
        ArrayList<Integer> low, high;
        
        low = new ArrayList<Integer>();
        high = new ArrayList<Integer>();
        
        int currmin = 0;
        int n = prices.length;
        
        for(int i = 1; i < n; i++)
        {
            if(i == n-1)
            {
                if(prices[currmin] < prices[i] || prices[currmin] < prices[i-1])
                {
                    low.add(currmin);                    
                    
                    int val = (prices[i] > prices[i-1]) ? i : i-1;
                    high.add(val);
                }
                    
                break;
            }
            
            if(prices[i-1] > prices[i])
            {
                if(prices[currmin] < prices[i-1])
                {
                    low.add(currmin);                    
                    high.add(i-1);
                    
                    currmin = i;
                }
            }
            
            if(prices[currmin] > prices[i])
                currmin = i;
        }
        
        
        for(int i = 0; i < low.size(); i++)
            System.out.print(prices[low.get(i)] + " ");
            
        System.out.print("\n");
        
        for(int i = 0; i < high.size(); i++)
            System.out.print(prices[high.get(i)] + " ");
        
        /*Obtain max profit possible*/
        int incr = low.size();
        
        if(incr == 0)   return 0;
        
        // System.out.print(incr + " *\n");
        
        int[] max = new int[incr];
        
        //Max profit for last increment
        int lastpr = prices[high.get(incr-1)] - prices[low.get(incr-1)] - fee;
        
        max[incr-1] = (lastpr > 0) ? lastpr : 0;
        
        for(int i = incr-2; i > -1; i--)
        {
            int pr = 0;
            
            for(int j = i; j < incr-1; j++)
            {
                int temp = (prices[high.get(j)] - prices[low.get(i)] - fee) + max[j+1];
                
                if(temp > pr)
                    pr = temp;
            }
            
            if((prices[high.get(incr-1)] - prices[low.get(i)] - fee) > pr)
                pr = (prices[high.get(incr-1)] - prices[low.get(i)] - fee);
            
            max[i] = pr;
        }
        
        System.out.print("\n");
        
        for(int i = 0; i < incr; i++)
            System.out.print(max[i] + " ");
        
        return max[0];               
    }
}

/*
class Solution {
    public int maxProfit(int[] prices, int fee) {
        
        ArrayList<Integer> low, high;
        
        low = new ArrayList<Integer>();
        high = new ArrayList<Integer>();
        
        int currmin = 0;
        int n = prices.length;
        
        for(int i = 2; i < n; i++)
        {
            if(i == n-1)
            {
                if(prices[currmin] < prices[i] || prices[currmin] < prices[i-1])
                {
                    int val = (prices[i] > prices[i-1]) ? i : i-1;
                    if((prices[val]-prices[currmin]) > fee)
                    {
                        low.add(currmin);                    
                        high.add(val);
                    }
                }
                    
                break;
            }
            
            if(prices[i-1] > prices[i])
            {
                if(prices[currmin] < prices[i-1] && (prices[i-1]-prices[currmin]) > fee)
                {                    
                    low.add(currmin);                    
                    high.add(i-1);
                    
                    currmin = i;
                }
            }
            
            if(prices[currmin] > prices[i])
                currmin = i;
        }
            
        for(int i = 0; i < low.size(); i++)
            System.out.print(prices[low.get(i)] + " ");
            
        System.out.print("\n");
        
        for(int i = 0; i < high.size(); i++)
            System.out.print(prices[high.get(i)] + " ");
        
        return 0;
               
    }
}
*/