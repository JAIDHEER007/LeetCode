import java.io.File;
import java.io.FileNotFoundException;
import java.util.Collections;
import java.util.HashMap;
import java.util.Scanner; 

class Solution{
    public String intToRoman(int num) {
        HashMap<Integer,String> map = new HashMap<Integer,String>();
        map.put(1, "I");
        map.put(5, "V");
        map.put(10, "X");
        map.put(50, "L");
        map.put(100, "C");
        map.put(500, "D");
        map.put(1000, "M"); 

        System.out.println(map.get(10));  
        String result = ""; 

        int tens = 1; 

        while(num != 0){
            int rem = num % 10; 

            String romanDigit = ""; 
            switch (rem){
                case 0: break; 
                case 4:
                    romanDigit = map.get(tens) + map.get(5 * tens);
                    break; 
                case 9: 
                    romanDigit = map.get(tens) + map.get(tens * 10);
                    break; 
                default:
                    int centerPoint = (5 * tens); 
                    if((rem * tens) < centerPoint){
                        // number is less than centerPoint
                        // repeat the starting tens 'rem' times
                        romanDigit = String.join("", Collections.nCopies(rem, map.get(tens))); 
                    }else{
                        // number is greator than centerPoint
                        // (rem - 5) tens to centerpoint
                        romanDigit = (map.get(centerPoint) + String.join("", Collections.nCopies(rem - 5, map.get(tens)))); 
                    }
            }

            result = romanDigit + result; 

            tens *= 10; 
            num /= 10;
            
        }


        return result; 
    }
}

// Replace The className with fileName
public class LC_12_1{
    public static void main(String args[]){
        Solution solObj = new Solution(); 

        // Number of inputs
        int nInputs = 6; 
        String fileName = "input%d.txt"; 
        for(int fileCounter = 1; fileCounter <= nInputs; ++fileCounter){
            System.out.println(String.format("======== TestCase %d ========", fileCounter)); 
            try{
                Scanner sc = new Scanner(new File(String.format(fileName, fileCounter))); 
                // Use sc.next() for reading string upto space
                // Use sc.nextLine() for reading string upto new line character 
                // Use sc.nextInt() for reading a single integer. delimted by space
                // Use sc.nextFloat(), sc.nextDouble() for reading float and double values. 
                // Use sc.hasNext() to check if next token is present. Can be used in while loop for unknown input sizes
                
                // ===== START =====
                int n = sc.nextInt(); 

                System.out.println(n);
                System.out.println(solObj.intToRoman(n)); 

                // ===== END =====
                sc.close(); 
            }
            catch(FileNotFoundException exp){
                System.out.println("File Not Found"); 
            }
            catch(Exception exp){
                System.out.println(exp);
            }
        }
    }
}