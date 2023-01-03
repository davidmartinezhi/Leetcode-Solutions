#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        /*
            info
                input: array of n strings "strs", all the same length
                output: number of columns to delete

                Details:
                    putting words on top of each other
                    letters must be arranged in lexicographical order
                    if not, delete that column

                constraints:
                    * array size is in range 1 and 100
                    * array strings can have length between 1 and 1,000
                    * strings consist of lowercase english letters

            example
                strs = ["cba","daf","ghi"]
                "cba"
                "daf"
                "ghi"

                -> 1, column on index 1 is not sorted

                strs = ["a","b"]
                "a"
                "b"

                -> 0

                strs = ["zyx","wvu","tsr"]
                "zyx"
                "wvu"
                "tsr"

                -> 3

            brute force
                for each column, traverse every row O(n*m) runtime
                    create a string with those letters O(n+m) memory
                    create aux sorted string O(n+m) memory and O((n+m) log (n+m)) runtime
                    if they don't match, add 1 to columns to delete

                complexity:
                    runtime: O((n*m)*((n+m) log (n+m)))
                    extra space: O(n+m)

            optimize
                best conceibable runtime: O(n*m)

                for each column, traverse every row
                    have int to know the current value position of col letter in rows
                    if row is smaller, add to col to delete and advance

                complexity:
                    runtime: O(n*m)
                    extra space: O(1)

            test
                * no columns to delete
                * all columns to delete
                * columns to delete exist
        */

        /*
        strs = [
            "a",
            "b",
            ]

            col = 0
            row = 0

            letterIdx = -1

            colsToDelete = 0

        */

        //declare variables
        int colsToDelete = 0;
        int n = strs.size(); //size rows
        int m = strs[0].size(); //size columns

        //for each column
        for(int col = 0; col < m; col++){

            //integer helper variable
            int lowerLetterIdx = -1;

            //for each row
            for(int row = 0; row < n; row++){

                //get letter
                int letterIdx = strs[row][col] - 'a';

                //cout << strs[row][col] << " idx: " << strs[row][col] - 'a' << endl;

                //if it's not in sorted order
                if(lowerLetterIdx > letterIdx){
                    
                    //add to columns to delete
                    colsToDelete++;
                    break;                    
                }

                //update letter Idx
                lowerLetterIdx = letterIdx;

            }
        }

        //return
        return colsToDelete;
    }
};

/*


Estuvo bueno el problema, llevo casi 2 meses sin hacer ejercicios de leetcode
pero saco a la luz mucha agilides mental y entre en la zona bastante rápido

Tuve como punto ciego el no distingir que el length the cols y rows era diferente cuando
aplique la solución. En la teoría lo saque bastante rapido.

Por partes

-Planeación buena
    -entendí todo rapido

-Ejemplos
    -utilize ejemplos que me dio leetcode, si pense en ejemplos para tests pero 
     no los apliqué
    -Pero si los recorrí para entender como se comportaba la info que nos daban
     y poder sacar una solución

Brute Force
    -Comence con la solución optima, pero me obligue a sacar esta respuesta
    -Es bueno para demostrar conocimiento, solo que me consumio tiempo.
        Si ya se un approach optimo, debería de solo mencionar brute froce rapido y
        saltarme al bueno.

Optimize
    -Buen BCR y muy veloz como lo saque
    -Saqué el walkthrough y de ahí la complejidad

Test
    -Le di muy rapido a los test y muy genericos

Podría solo mencionas brute force y optimize, con complejidad
Luego dejar la solución hasta el walkthrough. Para poder dedicarle más tiempo
a una ruta más optima y su viabilidad.

Darle más rapido al brute force,
hacer notas en optimize, pero walkthrough debe ser su propia cosa y de ahí voy sacando lo de test
tambíen anotar tests desde que estoy en el inicio con la info de input, output, requisitos y constraints.

*/