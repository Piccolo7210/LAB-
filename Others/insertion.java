package Grocery;
import java.util.*;
public class inserting {
	public static void main(String[] args) 
	{
		Scanner sc = new Scanner(System.in);
		String[] itemnames = {"apple","bananas","bread","milk"};
		int loc;
		System.out.println("Enter the Index : ");
		loc= sc.nextInt();
		int length = itemnames.length +1;
		String[] item = new String[length];
		for(int i=0;i<length;i++) {
			if(i<itemnames.length) {
				item[i]=itemnames[i];
			}
		}
		
		for(int i=length-1;i>loc;i--) {
			item[i]=item[i-1];
		}
		item[loc]= sc.next();
		for(String x : item) {
			System.out.println(x);
		}
	}
	
	
}
