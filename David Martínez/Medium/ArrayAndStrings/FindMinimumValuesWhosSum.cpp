#include <iostream>
#include <vector>

using namespace std;

        /*
        info
            input: integer k
            
            output: min number of fibonacci numners whose sum is equal to k
            
            constraints:
                - we can always find such fib number that sum up to k
                - k is between 1 and a billion
                
        example
        k = 7
        -> 2
        1, 1, 2, 3, 5, 6, 13, ...
        5+2
        
        k = 10
        -> 2
            2 + 8 = 10
            
        brute force
            memoization
            
            time: O(k)
            extra space: O(k)
            /create array of fib sequence
            while we havent surpassed k 
                get next fib seq. number
                
            time: O(k*k)
            extra space: O(k*k)
            /get min numbers whose sum is equal to k
            use tabulation
                
        optimize
            best case running time: O(k*k)
            can memory be improved?
            
        walkthrough
            create fib sequence array
            get the min numbers sum
            
            test
                number is exacte on the fib sequence
                number is a billion
        */
class Solution {
    
private:
    vector<int> fibSeq;
    
    void createFibSeqList(int k){
        

        
        //iterative
        //add first number of fib sequence
        fibSeq.push_back(0);
        
        fibSeq.push_back(1);
        
        //index after first 2 elements are added
        int i = 1;
        
        while(fibSeq[i] < k){
            
            //get next value
            int next = fibSeq[i] + fibSeq[i-1];
            
            //add next value
            fibSeq.push_back(next);
            
            i++;
        }
        
        return;
        
    }
  
    
public:
    int findMinFibonacciNumbers(int k) {

        //recursive
        int f1 = 0, f2 = 1; //first and second element in fibonacci

        //get a value that is greater,
        //ther pevious value, fits the number we are looking for (f1)
        //then we substract that value from k, and look for the next value that fits
        
        while (f2 <= k) {   //while f2 is less or equal to K
            swap(f1, f2);   //f2 now has the value of f1, and f1 of f2
            f2 += f1;   //now we add f2 to f1
        }
        
        return 1 + (k == f1 ? 0 : findMinFibonacciNumbers(k - f1));
        /*
        //create fibonacci sequence array
        createFibSeqList(k);
        
        //get count of min numbers sum that gets me k
        int count = 0;
        
        for(int i = fibSeq.size() - 1; i >= 0; i--){
            
            if(k >= fibSeq[i]){
                k -= fibSeq[i];
                count++;
            }
            
            if(k <= 0) return count;
        }
        
        return count;
        */
        /*
        //get count of min numbers sum that gets me k
        int dp[fibSeq.size()+1][k+1];
        
        for(int i = 0; i <= fibSeq.size(); i++){
            for(int j = 0; j <= k; j++){
                
                if(j == 0){
                    dp[i][j] = 0;
                }else if(i == 0){
                    dp[i][j] = 1e9 + 1;
                }else if(fibSeq[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }else{
                    dp[i][j] = min(dp[i-1][j - fibSeq[i-1]] + 1, dp[i-1][j]);
                }
            }
        }
        return dp[fibSeq.size()][k];
        */
    }
};

/*
tiempo: ???
complexity:
    time: O(n)
    extra space: O(1)
    There is a limit to how much elements the fibonacci array will contain

Me gustó el approach al problema, lo dividí de manera correcta y lo comprendí bien
La creación del array inicial fue sencillo de hacer y comprender
La parte que me causo ruido fue la de conseguir la minima cantidad de numeros, que me dieran la suma
    al parecer si aseguran que existe la manera de hacer el numero siempre y tienes el mismo patron siempre
    Puedes usar metodo greedy bien.

Implemente dp, pero consumia mucha memoria. Talvez un approach diferente puede llegar a ser más eficiente

Overall. Buen entendimiento del problema y buena performance.

La pense de más, al estar preocupado por una manera de chacer si existe la suma siempre.
Sabiendo que podría tener un numero que no esta dentro de la secuencies, pero aún aí debiendo
de seguir avanzando


*/