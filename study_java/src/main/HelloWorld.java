package main;

import java.util.Scanner;

class HelloWorld {
    public static void main(String[] args) {
    	// Khoi tao doi tuong scanner
    	Scanner sc = new Scanner(System.in);
    	
    	// Khoi tao doi tuong HinhChuNhat
        HinhChuNhat hcn = new HinhChuNhat();
        
        // Nhap va gan gia tri chieu dai
        System.out.print("Nhap chieu dai: ");
        float chieuDai = sc.nextFloat();	
        		
        hcn.setChieuDai(chieuDai);
        
        // Nhap va gan gia tri chieu rong
        System.out.print("Nhap chieu rong: ");
        float chieuRong = sc.nextFloat();
        hcn.setChieuRong(chieuRong);
        
        // In ket qua thong qua function toString cua doi tuong HinhChuNhat
        System.out.println("=>> Thong tin hinh chu nhat <<=");
        System.out.println(hcn.toString());
    }
}
