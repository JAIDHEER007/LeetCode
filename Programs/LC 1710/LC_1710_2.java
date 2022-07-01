import java.util.Arrays;
import java.util.Scanner;
import java.util.Comparator;
import java.lang.Math;
import java.io.File;
import java.io.FileNotFoundException; 

class Solution{
    public int maximumUnits(int[][] boxTypes, int truckSize) {
        int n = boxTypes.length; 
        Arrays.sort(boxTypes, new Comparator<int[]>(){
            public int compare(int[] i1, int[] i2){
                return Integer.compare(i2[1], i1[1]); 
            }
        });

        // for(int i = 0; i < n; ++i){
        //     System.out.println(boxTypes[i][0] + " " + boxTypes[i][1]); 
        // }

        int totalUnits = 0; 

        for(int i = 0 ; i < n; ++i){
            int unitsChosen = boxTypes[i][1]; 
            int boxChosen = Math.min(boxTypes[i][0], truckSize); 
            truckSize -= boxChosen; 

            totalUnits += (boxChosen * unitsChosen); 
        }

        return totalUnits; 
    }
}

public class LC_1710_2{
    public static void main(String args[]){
        Solution solObj = new Solution(); 

        int nInputs = 2; 
        String fileName = "input%d.txt"; 
        for(int fileCounter = 1; fileCounter <= nInputs; ++fileCounter){
            System.out.println(String.format("======== TestCase %d ========", fileCounter)); 
            try{
                Scanner sc = new Scanner(new File(String.format(fileName, fileCounter))); 
                // ===== START =====
                
                int n = sc.nextInt(); 
                
                int[][] boxTypes = new int[n][2];
                for(int i = 0; i < n; i++){
                    boxTypes[i][0] = sc.nextInt(); 
                    boxTypes[i][1] = sc.nextInt(); 
                }

                // for(int i = 0; i < n; ++i){
                //     System.out.println(boxTypes[i][0] + " " + boxTypes[i][1]); 
                // }

                int truckSize = sc.nextInt(); 

                System.out.println(solObj.maximumUnits(boxTypes, truckSize)); 

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