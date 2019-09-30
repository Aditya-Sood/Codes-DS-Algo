class Solution {
    
    class Alphabet {
        char alp; //alphabet
        int freq = 0;
        int ind = -1;
        
        public Alphabet(char a, int fr, int in)
        {
            this.alp = a;
            this.freq = fr;
            this.ind = in;
        }
    }
    
    class AlpComparator implements Comparator<Alphabet> {
        
        @Override
        public int compare(Alphabet a, Alphabet b) {

            int res = -(a.freq-b.freq);
            return (res != 0) ? res : (a.ind - b.ind);
        }
    }
    
    PriorityQueue<Alphabet> getUniFreq(String word) {
        
        char[] wordarr = word.toCharArray();
        Arrays.sort(wordarr);
        
        //System.out.println(wordarr);
        
        PriorityQueue<Alphabet> wrdUniqAlpQ;
        wrdUniqAlpQ = new PriorityQueue<Alphabet>(1, new AlpComparator());
        
        char curr = wordarr[0];
        int fr = 1, ind = -1;
        for(int i = 1; i < wordarr.length; i++) {
            
            if(wordarr[i] == curr) {
                fr++;
            }
            else {
                Alphabet temp = new Alphabet(curr, fr, ind);
                wrdUniqAlpQ.add(temp);
                
                System.out.println(temp.alp + " with " + temp.freq);
                
                curr = wordarr[i];
                fr = 1;
                ind = i;
            }
        }
        
        Alphabet temp = new Alphabet(curr, fr, ind);
        wrdUniqAlpQ.add(temp); //For the last character
        System.out.println(temp.alp + " with " + temp.freq);
        //System.out.println("");
        
        return wrdUniqAlpQ;
    }
    
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        
        PriorityQueue<Alphabet> pttrUniqAlpQ, wrdUniqAlpQ;
        pttrUniqAlpQ = getUniFreq(pattern);
        System.out.println("#\n");
        int totalUniAlp = pttrUniqAlpQ.size();
       
        ArrayList<Alphabet> pttrUniqAlpArrayList = new ArrayList<Alphabet>(totalUniAlp);
        while(!pttrUniqAlpQ.isEmpty())
            pttrUniqAlpArrayList.add(pttrUniqAlpQ.poll());
        
        // for(int i = 0; i < totalUniAlp; i++)
        // {
        //     Alphabet a = pttrUniqAlpArrayList.get(i);
        //     System.out.println(a.alp + " with " + a.freq);
        // }
        
        List<String> res = new ArrayList<String>();
        boolean match = true;
        int k;
        char[] patarr = pattern.toCharArray();
        int m = patarr.length;
        //Comparing for each work
        outer:
        for(k = 0; k < words.length; k++) {
            
            match = true;
            
            String word = words[k];
            
            char[] wordarr = word.toCharArray();
            wrdUniqAlpQ = getUniFreq(word);
            
            System.out.println(word);
            
            if(pttrUniqAlpArrayList.size() != wrdUniqAlpQ.size()) { //Unequal num of unique alphabets
                System.out.println("Unequal unique characters");
                continue;
            } 
            
            //Traverse pque without poll
            inner:
            for(int i = 0; i < totalUniAlp; i++) {
                
                Alphabet wa = wrdUniqAlpQ.poll(), pa = pttrUniqAlpArrayList.get(i);
                
                if(pa.freq != wa.freq) { //Permutation possible -> Same frequency
                    System.out.println("Freq mismatch of " + wa.alp + " for " + pa.alp);
                    match = false;
                    break inner;
                }
                else
                    System.out.println(wa.alp + " freqmatch " + pa.alp);
                
                //Along with same freq, same positions
                char p = pa.alp, w = wa.alp;
                for(int j = 0; j < m; j++) {
                    if(patarr[j] == p) {
                        if(w != wordarr[j]) {
                            System.out.println(w + " not for " + p);
                            match = false;
                            break inner;
                        }
                    }
                }
                
                System.out.println("Match: " + match);
                
            }
            
            
            if(match)
                res.add(word);
            
            System.out.println("***");
        }
        
        return res;
    }
}

/*
class Solution {
    
    class Alphabet {
        char alp; //alphabet
        int freq = 0;
        
        public Alphabet(char a, int fr)
        {
            this.alp = a;
            this.freq = fr;
        }
    }
    
    class AlpComparator implements Comparator<Alphabet> {
        
        @Override
        public int compare(Alphabet a, Alphabet b) {
            return -(a.freq-b.freq);
        }
    }
    
    PriorityQueue<Alphabet> getUniFreq(String word) {
        
        char[] wordarr = word.toCharArray();
        Arrays.sort(wordarr);
        
        //System.out.println(wordarr);
        
        PriorityQueue<Alphabet> wrdUniqAlpQ;
        wrdUniqAlpQ = new PriorityQueue<Alphabet>(1, new AlpComparator());
        
        char curr = wordarr[0];
        int fr = 1;
        for(int i = 1; i < wordarr.length; i++) {
            
            if(wordarr[i] == curr) {
                fr++;
            }
            else {
                Alphabet temp = new Alphabet(curr, fr);
                wrdUniqAlpQ.add(temp);
                
                //System.out.println(temp.alp + " with " + temp.freq);
                
                curr = wordarr[i];
                fr = 1;
            }
        }
        Alphabet temp = new Alphabet(curr, fr);
        wrdUniqAlpQ.add(temp); //For the last character
        //System.out.println(temp.alp + " with " + temp.freq);
        //System.out.println("");
        
        return wrdUniqAlpQ;
    }
    
    public List<String> findAndReplacePattern(String[] words, String pattern) {
        
        PriorityQueue<Alphabet> pttrUniqAlpQ, wrdUniqAlpQ;
        pttrUniqAlpQ = getUniFreq(pattern);
        //System.out.println("#\n");
        int totalUniAlp = pttrUniqAlpQ.size();
       
        ArrayList<Alphabet> pttrUniqAlpArrayList = new ArrayList<Alphabet>(totalUniAlp);
        while(!pttrUniqAlpQ.isEmpty())
            pttrUniqAlpArrayList.add(pttrUniqAlpQ.poll());
        
        // for(int i = 0; i < totalUniAlp; i++)
        // {
        //     Alphabet a = pttrUniqAlpArrayList.get(i);
        //     System.out.println(a.alp + " with " + a.freq);
        // }
        
        List<String> res = new ArrayList<String>();
        boolean match = true;
        int k;
        char[] patarr = pattern.toCharArray();
        int m = patarr.length;
        //Comparing for each work
        outer:
        for(k = 0; k < words.length; k++) {
            
            match = true;
            
            String word = words[k];
            
            char[] wordarr = word.toCharArray();
            wrdUniqAlpQ = getUniFreq(word);
            
            //System.out.println(word);
            
            if(pttrUniqAlpArrayList.size() != wrdUniqAlpQ.size()) { //Unequal num of unique alphabets
                //System.out.println("Unequal unique characters");
                continue;
            } 
            
            //Traverse pque without poll
            inner:
            for(int i = 0; i < totalUniAlp; i++) {
                
                Alphabet wa = wrdUniqAlpQ.poll(), pa = pttrUniqAlpArrayList.get(i);
                
                if(pa.freq != wa.freq) { //Permutation possible -> Same frequency
                    //System.out.println("Freq mismatch of " + wa.alp + " for " + pa.alp);
                    match = false;
                    break inner;
                }
                //else
                    //System.out.println(wa.alp + " freqmatch " + pa.alp);
                
                //Along with same freq, same positions
                char p = pa.alp, w = wa.alp;
                for(int j = 0; j < m; j++) {
                    if(patarr[j] == p) {
                        if(w != wordarr[j]) {
                            //System.out.println(w + " not for " + p);
                            match = false;
                            break inner;
                        }
                    }
                }
                
                //System.out.println("Match: " + match);
                
            }
            
            
            if(match)
                res.add(word);
            
            //System.out.println("***");
        }
        
        return res;
    }
}
*/