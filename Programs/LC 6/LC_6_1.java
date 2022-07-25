import java.util.Scanner;
import java.io.File;
import java.io.FileNotFoundException; 

class Solution{
    public String convert(String s, int numRows) {
        if(numRows == 1) return s; 

        String[] rows = new String[numRows]; 

        for(int i = 0; i < numRows; ++i)
            rows[i] = ""; 

        int rowNum = 1; 
        boolean increasing = true; 

        int n = s.length(); 
        for(int i = 0; i < n; ++i){
            if(rowNum == 1) increasing = true; 
            else if(rowNum == numRows) increasing = false; 

            rows[rowNum - 1] += (s.charAt(i) + ""); 
            rowNum = (increasing)?(rowNum + 1):(rowNum - 1); 
        }

        String res = ""; 
        for(int i = 0; i < numRows; ++i)
            res += rows[i]; 
        
        return res; 
    }
}

// Replace The className with fileName
public class LC_6_1{
    public static void main(String args[]){
        Solution solObj = new Solution(); 

        // Number of inputs
        int nInputs = 5; 
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
                String s = sc.nextLine(); 
                int numRows = sc.nextInt(); 

                System.out.println(s);
                System.out.println(numRows); 

                System.out.println(solObj.convert(s, numRows)); 
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