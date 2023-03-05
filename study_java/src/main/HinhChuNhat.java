package main;

public class HinhChuNhat {
	private float chieuDai;
	private float chieuRong;
	
	public void setChieuDai(float chieuDai) {
		this.chieuDai = chieuDai;
	}
	
	public void setChieuRong(float chieuRong) {
		this.chieuRong = chieuRong;
	}
	
	public float getChieuDai() {
		return this.chieuDai;
	}
	
	public float getChieuRong() {
		return this.chieuRong;
	}
	
	public float tinhDienTich() {
		return this.chieuDai * this.chieuRong;
	}
	
	public float tinhChuVi() {
		return (this.chieuDai + this.chieuRong) * 2;
	}
	
	public String toString() {
		return new String
				("Chieu dai: " + this.getChieuDai() + "\n" +
				"Chieu rong: " + this.getChieuRong() + "\n" +
				"Dien tich: " + this.tinhDienTich()	 + "\n" +	
				"Chu vi: "+ this.tinhChuVi());
	
	}
}
