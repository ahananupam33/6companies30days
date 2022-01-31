class Solution {
public:
    bool winnerOfGame(string colors) {
        int n = colors.length();
        // Bob wins as Alice can't make a move
        if(n <= 2)return false;
        
        // We check how many moves each of them can make in all
        int a = 0, b = 0;
        for(int i=1; i<n-1; i++){
            if(colors[i]==colors[i-1] && colors[i]==colors[i+1]){
                if(colors[i]=='A')
                    a++;
                else
                    b++;
            }
        }
        if(a <= b)
            return false;
        else
            return true;
        
    }
};