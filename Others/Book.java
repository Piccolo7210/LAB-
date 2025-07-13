package Grocery;
import java.util.*;
class Book{
	private String title;
	private String author;
	private int chapnum;
	private int pagenum;
	private String isbn;
	public Book(String title,String author,int chapnum,int pagenum,String isbn) {
		this.title =title;
		this.author = author;
		this.chapnum = chapnum;
		this.pagenum = pagenum;
		this.isbn=isbn;
	}
	public Book() {
		this.title ="";
		this.author = "";
		this.chapnum = 0;
		this.pagenum = 0;
		this.isbn="";
	}
	public Book(String title,String author) {
		this.title =title;
		this.author = author;
		this.chapnum = 0;
		this.pagenum = 0;
		this.isbn="";
	}
	public String gettitle() {
		return title;
	}
	public String getisbn() {
		return isbn;
	}
	public String getauthor() {
		return author;
	}
	public int getchapnum() {
		return chapnum;
	}
	public int getpagenum() {
		return pagenum;
	}
	public void settitle(String title) {
		this.title=title;
	}
	public void setisbn(String isbn) {
		this.isbn=isbn;
	}
	public void setauthor(String author) {
		this.author=author;
	}
	public void setchapnum(int chapnum) {
		this.chapnum=chapnum;
	}
	public void setpagenum(int pagenum) {
		this.pagenum=pagenum;
	}
	public double average() {
		double average = pagenum/chapnum;
		return average;
	}
public class bookmain {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Book java = new Book("Java","Herbart Scheild",5,1000,"ISBN-26-12-2016-15-12");
		double avg= java.average();
		System.out.println("Title: "+java.gettitle()+"\n"+"Author: "+java.getauthor()+"\n"+"Number of Chapters: "+java.getchapnum()+"\n"+"Number of Pages: "+java.getpagenum()+"\n"+"Average number of pages per chapter: "+avg);		System.out.println("ISBN: "+java.getisbn());
		
	}

}
}
