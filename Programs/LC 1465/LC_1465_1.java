// Runtime: 16ms
// Faster Than: 98.49%
// Memory Usage: 51.9Mb
// Less Than: 86.61%

import java.util.Arrays;
import java.util.Scanner;
import java.util.Comparator;
import java.lang.Math;
import java.io.File;
import java.io.FileNotFoundException; 

class Solution {
    public int maxArea(int h, int w, int[] horizontalCuts, int[] verticalCuts) {
        // Sorting the horizontalCuts and verticalCuts
        Arrays.sort(horizontalCuts); 
        Arrays.sort(verticalCuts);

        // Start value for correct cut length
        int start = 0; 

        // Finding the maxVertical Cut
        int maxVcut = Integer.MIN_VALUE;
        for(int cut:verticalCuts){
            maxVcut = Math.max(maxVcut, (cut - start)); 
            start = cut; 
        }
        maxVcut = Math.max(maxVcut, (w - start)); 

        start = 0; 
        // Finding the maxHorizontal Cut
        int maxHcut = Integer.MIN_VALUE;
        for(int cut:horizontalCuts){
            maxHcut = Math.max(maxHcut, (cut - start)); 
            start = cut; 
        }
        maxHcut = Math.max(maxHcut, (h - start)); 

        return (int)(((long)(maxHcut) * (long)(maxVcut)) % 1000000007);        
    }
}

// Replace The className with fileName
public class LC_1465_1{
    public static void main(String args[]){
        Solution solObj = new Solution(); 

        // Number of inputs
        int nInputs = 4; 
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
                int h = sc.nextInt(), w = sc.nextInt(); 

                int hcCnt = sc.nextInt(); 
                int[] horizontalCuts = new int[hcCnt]; 
                for(int i = 0 ; i < hcCnt; ++i)
                    horizontalCuts[i] = sc.nextInt(); 

                int vcCnt = sc.nextInt(); 
                int[] verticalCuts = new int[vcCnt]; 
                for(int i = 0 ; i < vcCnt; ++i)
                    verticalCuts[i] = sc.nextInt(); 
                
                System.out.println(solObj.maxArea(h, w, horizontalCuts, verticalCuts)); 
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