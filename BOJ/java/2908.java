import java.util.Scanner;
public class Main {
	public static void main(String[]args) {		
		Scanner sc = new Scanner(System.in);		
		int A1=sc.nextInt();
		int A2=sc.nextInt();
	
				int q=A1/100; 
				int w=A1%100/10; 
				int e=A1%10;
			
				int z=A2/100; 
				int x=A2%100/10; 
				int c=A2%10;
        
		    	A1=e*100+10*w+q;
		    	A2=c*100+10*x+z;
		    	
		    	if(A1>A2) {
		    		System.out.println(A1);		    					
			}
		    	if(A2>A1) {
		    		System.out.println(A2);		
		    	}
			}
		}		
