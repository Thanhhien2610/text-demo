package tuan4ThanhHien;

import java.text.NumberFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.Date;
import java.util.Locale;

public class ThucPham {
    //Khai báo các thuộc tính cần thiết cho bài toán
    private int maHang;
    private String tenHang;
    private double donGia;
    private Date ngaySanXuat, hangSuDung;

    //Khởi tạo constructor có tham số
    public ThucPham(int maHang, String tenHang, double donGia, Date ngaySanXuat, Date hangSuDung) {
        this.maHang = maHang;
        this.tenHang = tenHang;
        this.donGia = donGia;
        this.ngaySanXuat = ngaySanXuat;
        this.hangSuDung = hangSuDung;
    }

    //Khởi tạo constructor mặc định
    public ThucPham() {
    }

    //-------------------begin getter and setter-----------------------
    public int getMaHang() {
        return maHang;
    }

    public void setMaHang(int maHang) {
        this.maHang = maHang;
    }

    public String getTenHang() {
        return tenHang;
    }

    public void setTenHang(String tenHang) {
        this.tenHang = tenHang;
    }

    public double getDonGia() {
        return donGia;
    }

    public void setDonGia(double donGia) {
        this.donGia = donGia;
    }

    public Date getnSX() {
        return ngaySanXuat;
    }

    public void setnSX(Date nSX) {
        this.ngaySanXuat = nSX;
    }

    public Date gethSD() {
        return hangSuDung;
    }

    public void sethSD(Date hSD) {
        this.hangSuDung = hangSuDung;
    }

    //-------------------end getter and setter-----------------------
    @Override
    //khởi tạo phương thức toString
    public String toString() {
        //sử dung phương thức Locale để biến đổi theo tiền tệ việt nam
        Locale localeVN = new Locale("vi", "VN");
        NumberFormat numberFormat = NumberFormat.getCurrencyInstance(localeVN);
        String str = numberFormat.format(donGia);
        // sử dụng phương thức SimpleDateFormat để biến đổi ngày tháng năm theo dạng "dd/MM/yyyy"
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd/MM/yyyy");
        String str1 = simpleDateFormat.format(ngaySanXuat);
        String str2 = simpleDateFormat.format(hangSuDung);
        return "Thông tin về thực phẩm: \n" +
                "Mã hàng : " + maHang +
                "\nTên hàng : '" + tenHang +
                "\nĐơn giá : " + str +
                "\nNgày sản xuất : " + str1 +
                "\nHạn sử dụng : " + str2
                ;
    }

    //Khởi tạo phương thức để nhập năm tháng ngày sản xuất
    public void setNSX(int year, int month, int day) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(year, month - 1, day);
        this.ngaySanXuat = calendar.getTime();
    }

    //Khởi tạo phương thức để nhập hạn sử dụng
    public void setHSD(int year, int month, int day) {
        Calendar calendar = Calendar.getInstance();
        calendar.set(year, month - 1, day);
        this.hangSuDung = calendar.getTime();
    }

    //khởi tạo phương thức kiểm tra tên hàng không được để trống
    public boolean kiemTraTenHang(boolean k) {
        if (this.tenHang == "" || this.tenHang.isEmpty()) {
            System.out.println("Tên hàng không được để trống : ");
        } else {
            k = false;
        }
        return k;
    }

    //khởi tạo hàm kiểm tra ngày hết hạn không được nhỏ hơn ngày sản xuất
    public boolean kiemTraNgay(boolean t) {
        if (this.getnSX().compareTo(this.gethSD()) < 0) {
            t = false;
        } else {
            System.out.println("Ngày hết hạn không được nhỏ hơn ngày sản xuất : ");
        }
        return t;
    }

    //khởi tạo phương thức kiểm tra hạn sử dụng của sản phẩm đã hết hạn hay còn hạn
    public void kiemTraHSD() {
        Date today = new Date();
        today.getTime();
        SimpleDateFormat simpleDateFormat = new SimpleDateFormat("dd/MM/yyyy");
        String st = simpleDateFormat.format(today);
        if (this.gethSD().compareTo(today) < 0) {
            System.out.println("Hôm nay là ngày " + st + ", hàng hóa đã hết hạn ");
        } else {
            System.out.println("Hôm nay là ngày " + st + ", hàng hóa vẫn còn hạn ");
        }
    }
}