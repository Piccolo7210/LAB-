package Grocery;

public class searching {
	public static void main(String[] args) 
	{
		int index=-1,i;
		boolean flag=false;
		String[] itemnames = {"apples","bananas","bread","milk"};
		String key = "banana";
		for( i=0;i<itemnames.length;i++)
		{
			if(itemnames[i]== key) {
				flag=true;
				index = i;
				break;
			}
		}
		
		if(flag)
		{
			System.out.println("Index: "+index);
		}
		else {
			System.out.println("Could not find the item");
		}
	}
	
}
