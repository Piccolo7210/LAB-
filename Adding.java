package Grocery;
import java.util.*;
public class elementadding {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner sc = new Scanner(System.in);
		
		String[] itemnames = {"apples","bananas","bread","milk"};
		int length;
		length = itemnames.length+2;
		String[] itemnames2 = new String[length];
		for(int i=0;i<length;i++) {
			if(i<=3) {
				itemnames2[i] = itemnames[i];	
			}
			else if(i==4) {
				itemnames2[i]=sc.next();
			}
			else {
				itemnames2[i]=sc.next();
			}
			
		}
		for(String x : itemnames2) {
			System.out.println(x);
		}
		length=0;
		int[] itemquantities = {3,2,1,2};
		length = itemquantities.length+2;
		int[] itemquantities2 = new int[length+2];
		for(int i=0;i<length;i++) {
			if(i<=3) {
				itemquantities2[i] = itemquantities[i];	
			}
			else if(i==4) {
				itemquantities2[i]=sc.nextInt();
			}
			else {
				itemquantities2[i]=sc.nextInt();
			}
			
		}
		
		float[] itemprices = {1.99f,0.99f,2.49f,2.39f};
		length = 0;
		boolean[] itemonsale = {false,false,true,true};
	}

}
