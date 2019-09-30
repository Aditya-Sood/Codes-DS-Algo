/*https://leetcode.com/problems/reveal-cards-in-increasing-order/*/

class Solution {
    public int[] deckRevealedIncreasing(int[] deck) {
        
        Arrays.sort(deck);
        int n = deck.length;
        int[] res = new int[n];
        
        LinkedList<Integer> avail, end;
        //To store the list of available card positions in the final deck (not assigned card yet)
        avail = new LinkedList<Integer>();
        //To store the list of card positions shifted to the rear of the deck
        end = new LinkedList<Integer>();
        
        for(int i = 0; i < n; i++)
            avail.add(i);
        
        int curr = 0; //Index of sorted-deck card to be added next
        
        //As long as there's an available final-deck position and a card in the sorted-deck
        while(curr < n && !avail.isEmpty())
        {
            int avlsize = avail.size();
            
            //List of available res positions
            for(int i = 0; i < avlsize; i++)
                System.out.print(avail.get(i)+" ");
            System.out.print('\n');
            
            //Current state of res
            for(int i = 0; i < n; i++)
                System.out.print(res[i]+" ");
            System.out.print('\n');
            
            //Traversing available list
            //Add element in the even indexed card-positions (given by avail)
            //Shift the odd indexed card-positions to the end list
            for(int i = 0; i < avlsize; i += 2)
            {
                res[avail.get(i)] = deck[curr++];
                
                if(i+1 == avlsize && avlsize > 1 && !end.isEmpty())
                {
                    int temp = end.remove(0);
                    end.add(temp);
                }
                else if(i+1 != avlsize)
                    end.add(avail.get(i+1));
            }
            
            avail = end;
            end = new LinkedList<Integer>();
        }
        //Total loop complexity: O(n)
        //As the whole deck is traversed only once
        
        return res;
    }
}