import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException; 

class Solution{
    public int romanToInt(String s) {
        int sum = 0; 
        int prevNum = -1; 

        for(int i = 0; i < s.length(); ++i){
            int rn = 0; 

            switch(s.charAt(i)){
                case 'M': rn = 1000; break; 
                case 'D': rn = 500; break; 
                case 'C': rn = 100; break; 
                case 'L': rn = 50; break; 
                case 'X': rn = 10; break; 
                case 'V': rn = 5; break; 
                case 'I': rn = 1; break; 
            }

            if(prevNum == -1)
                sum = rn; 
            else{
                if(prevNum < rn){
                    sum -= prevNum; 
                    sum += (rn - prevNum); 
                }else
                    sum += rn; 
            }

            prevNum = rn; 
        }

        return sum; 
    }
}

// Replace The className with fileName
public class LC_13_1{
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
                String s = sc.next(); 
                System.out.println(solObj.romanToInt(s)); 

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