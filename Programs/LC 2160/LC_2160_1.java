import java.util.Arrays;
import java.util.Scanner;
import java.util.Comparator;
import java.lang.Math;
import java.rmi.activation.UnknownObjectException;
import java.io.File;
import java.io.FileNotFoundException; 

class Solution {
    public int minimumSum(int num) {
        int arr[] = new int[10]; 

        while(num != 0){
            ++arr[num % 10];
            num /= 10; 
        }

        boolean startWithNum1 = true; 

        int num1 = 0, num2 = 0; 
        for(int i = 0; i < 10; ++i){
            while(arr[i] != 0){
                if(startWithNum1)
                    num1 = (num1 * 10) + i; 
                else
                    num2 = (num2 * 10) + i; 
                startWithNum1 = !startWithNum1; 
                --arr[i]; 
            }
        }

        return (num1 + num2); 
    }
}

// Replace The className with fileName
public class LC_2160_1{
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
                int n = sc.nextInt(); 

                System.out.println(solObj.minimumSum(n));

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