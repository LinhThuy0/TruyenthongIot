                                                    BÀI THỰC HÀNH BLUETOOTH SỬ DỤNG TRÊN nRF Connect


Chủ đề: Truyền thông IoT

Nội dung:
1. Thực hành Bluetooth với tập lệnh AT [https://github.com/LinhThuy0/TruyenthongIot/tree/main/BLE/THBLE_AT](https://github.com/LinhThuy0/TruyenthongIot/tree/main/BLE/THBLE_AT).
2. Thực hành Bluetooth giao tiếp giữa hai HC_05 [https://github.com/LinhThuy0/TruyenthongIot/tree/main/BLE/THBLE_GIAOTIEP](https://github.com/LinhThuy0/TruyenthongIot/tree/main/BLE/THBLE_GIAOTIEP).
3.  Thực hành điều khiển LED thông qua ứng dụng nRF Connect [https://github.com/LinhThuy0/TruyenthongIot/tree/main/BLE/THBLE_nRF](https://github.com/LinhThuy0/TruyenthongIot/tree/main/BLE/THBLE_nRF).
4.   Thực hành Bluetooth với DHT11  [https://github.com/LinhThuy0/TruyenthongIot/tree/main/BLE/THBLE_DHT11](https://github.com/LinhThuy0/TruyenthongIot/tree/main/BLE/THBLE_DHT11).


I. GIỚI THIỆU BÀI THỰC HÀNH

  Bài thực hành số 5 tìm hiểu cách sử dụng Bluetooth trong hệ thống IoT. Thông qua các bài tập làm quen với việc cấu hình module Bluetooth, trao đổi dữ liệu nối tiếp UART, điều khiển thiết bị từ xa và truyền dữ liệu cảm biến lên giao diện Web.
  
  Bluetooth là công nghệ truyền thông không dây tầm gần. Trong các hệ thống IoT, Bluetooth có thể được dùng để kết nối vi điều khiển với máy tính hoặc điện thoại, gửi lệnh điều khiển và nhận dữ liệu cảm biến. HC-05/HC-06 thường giao tiếp với vi điều khiển qua UART bằng hai đường TX và RX. BLE là phiên bản Bluetooth Low Energy, được thiết kế để giảm năng lượng tiêu thụ cho các thiết bị phù hợp.

1.1. Mục tiêu học tập
+ Tìm hiểu nguyên lý hoạt động và kiến trúc truyền thông Bluetooth trong IoT.
+ Tìm hiểu quy trình ghép nối, kết nối và trao đổi dữ liệu giữa module Bluetooth với thiết bị điều khiển.
+ Biết cách sử dụng lệnh AT Command để cấu hình module HC-05 như tên thiết bị, mật khẩu, tốc độ baud và vai trò master/slave.
+ Biết mô phỏng giao tiếp Bluetooth HC-05/HC-06 trong Proteus thông qua cổng COM ảo và Virtual Terminal.
+ Biết sử dụng ứng dụng nRF Connect để gửi lệnh bật/tắt LED.
+ Biết mô hình truyền dữ liệu cảm biến DHT11 qua UART để hiển thị dữ liệu theo thời gian thực.

1.2. THIẾT BỊ VÀ PHẦN MỀM CẦN CHUẨN BỊ

+ Kit vi điều khiển ESP32-S3 : Phát sóng BLE và xử lý lệnh điều khiển.
+ LED RGB NeoPixel tích hợp (GPIO 48): Hiển thị màu sắc tương ứng với lệnh nhận được.
+ Cáp USB: Nạp chương trình từ máy tính và cấp nguồn cho ESP32-S3.
+ Điện thoại thông minh Android/iOS: Chạy ứng dụng nRF Connect để kết nối và gửi lệnh.
+ Arduino IDE: Biên dịch và nạp mã nguồn cho ESP32-S3.
+ Thư viện Adafruit_NeoPixel: Điều khiển LED RGB NeoPixel.
+ Proteus 8 Professional:	Thiết kế mạch và mô phỏng giao tiếp.
+ Virtual Serial Port Driver	Tạo cặp cổng COM ảo để trao đổi dữ liệu.
+ Virtual Terminal trong Proteus	Nhập và quan sát dữ liệu nối tiếp.

II.NGUYÊN LÝ HOẠT ĐỘNG

2.1 Thực hành Bluetooth với tập lệnh AT

- CÁCH THỰC HIỆN.

1. Mở Proteus chuẩn bị linh kiện Arduino,Virtual Terminal, module HC-05 và dây nối theo sơ đồ .
 [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_AT/THBLE_IMG1%20.png](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_AT/THBLE_IMG1%20.png).
2.  Mở Arduino IDE và tải các thư viện Adafruit_NeoPixel hỗ trợ .
3. Tải Virtual Serial Port Driver để hỗ trợ cổng COM ảo[https://download.com.vn/download/virtual-serial-port-driver-44945?linkid=1#google_vignette](https://download.com.vn/download/virtual-serial-port-driver-44945?linkid=1#google_vignette).
4. Kết nối cổng COM ảo>
  <img width="407" height="280" alt="image" src="https://github.com/user-attachments/assets/b2f20208-d115-4976-93fd-6264de1c791b" />

5. Viết code sử dụng các lênh AT trên Arduino IDE rồi xuất file .hex  [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_AT/THBLE_AT/THBLE_AT.ino](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_AT/THBLE_AT/THBLE_AT.ino) .
6 . Vào Proteus nạp file .hex vào Arduino sau đó chạy chương trình.
8.  Hiển thị cửa sổ Ternimal sau đó nhập các lệnh AT vào  [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_AT/THBLE_IMG2.png](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_AT/THBLE_IMG2.png) .

-Kết quả: Lệnh kiểm tra cơ bản trả về phản hồi hợp lệ.Các tham số thay đổi được phản ánh đúng theo phản hồi hoặc khi quét thiết bị.
-Chú ý: Nếu không có phản hồi, kiểm tra chế độ AT, dây TX/RX, nguồn cấp, cổng COM và baud rate.

-VIDEO THỰC HÀNH:[https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_AT/THBLE_AT_VIDEOKQ.mp4](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_AT/THBLE_AT_VIDEOKQ.mp4)

2.2 Thực hành Bluetooth giao tiếp giữa hai HC_05

1. Chuẩn bị các linh kiện trên Proteus- 2 Arduino, 2 HC_05, 2LED, 2 RES300, 1 Virtual Terminal[https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_IMG1.png](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_IMG1.png).
2. Điều chỉnh cổng ảo.Tại HC_05 số 1 chỉnh cổng ảo về COM1
<img width="717" height="394" alt="image" src="https://github.com/user-attachments/assets/5ba10bca-730e-4d08-8e32-031118ea1904" />

3. Mở phần mềm Arduino IDE và tạo hai file mới viết code tương ứng với GUILENH và NHANLENH
  
4. Tại Proteus bấm <img width="20" height="15" alt="image" src="https://github.com/user-attachments/assets/00a21102-ce3c-4dbe-b81a-f76b74b237d6" /> để chạy chương trình.
5. Sau khi chạy sẽ hiển thị cửa sổ Terminal. Sử dụng các câu lệnh để điều khiển như: A:Cảnh báo ,B: Hoạt động bình thương, E: Tắt cả hai LED [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_IMG2.png](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_IMG2.png).

-Kết quả: Dữ liệu nhập từ một đầu được truyền qua mô hình Serial và xuất hiện ở đầu nhận tương ứng

-VIDEO THỰC HÀNH: [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_VIDEO.mp4](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_VIDEO.mp4).

2.3 Thực hành điều khiển LED thông qua ứng dụng nRF Connect.
1. Chạy phần mềm Arduino IDE và viết code điều khiển sau đó xuất file .hex [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_nRF/BTH_BLE/BTH_BLE_nRF.ino](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_nRF/BTH_BLE/BTH_BLE_nRF.ino).
2. Cắm cáp USB nạp code dạng type C một đầu vào cổng Com một đầu vào  ESP32 [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_nRF/THBLE_IMG2.jpg](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_nRF/THBLE_IMG2.jpg).
3. Sau khi nạp file .hex vào ESP32 thì mở điện thoại đã tải sẵn ứng dụng nRF Connect .
4. Trên giao diện của nRF tìm kiếm thiết bị của mình bằng BLE_NAME đã cài trong code [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_nRF/THBLE_IMG1.jpg](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_nRF/THBLE_IMG1.jpg).
5. Sau khi tìm thấy thì kết nối, sau đó sử dụng các câu lệnh điều khiển LED: A: Đỏ, B:
Xanh, C: Vàng, D:Cam, E:Hồng.

-VIDEO THỰC HÀNH: [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_nRF/THBLE_VIDEO.mp4](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_nRF/THBLE_VIDEO.mp4).

2.4. Thực hành Bluetooth với DHT11

-CÁCH THỰC HÀNH:
1. Chuẩn bị các linh kiện trên Proteus- Arduino,  HC_05, DHT11, 1 Virtual Terminal [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_DHT11/THBLE_DHT11IMG2.png](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_DHT11/THBLE_DHT11IMG2.png).
2. Mở phần mềm Arduino IDE và tạo hai file mới viết code sau đó xuất file .hex .
3. Nạp file .hex vào Arduino trên Proteus rồi chạy chương trình [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_DHT11/THBLE_DHT11IMG1.png](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_DHT11/THBLE_DHT11IMG1.png) .

-Kết quả:[https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_DHT11/THBLE_DHT11VIDEO.mp4](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_DHT11/THBLE_DHT11VIDEO.mp4) . 

III. SƠ ĐỒ NGUYÊN LÝ HOẠT ĐỘNG

-Nguyên lý hoạt động bài thực hành BLE với lệnh AT.
<img width="353" height="358" alt="image" src="https://github.com/user-attachments/assets/edbbef68-4308-44fc-b495-5d704215371c" />

                                            
-Nguyên lý hoạt động thực hành Bluetooth giao tiếp giữa hai HC_05.
<img width="290" height="296" alt="image" src="https://github.com/user-attachments/assets/4a7d1f15-543b-4b98-869a-fef382d7c973" />


-Nguyên lý hoạt động thực hành điều khiển LED thông qua ứng dụng nRF Connect.
<img width="320" height="254" alt="image" src="https://github.com/user-attachments/assets/b702d986-252a-42ff-b46a-249902a3f3b7" />

-Nguyên lý hoạt động thực hành Bluetooth với DHT11.
<img width="275" height="239" alt="image" src="https://github.com/user-attachments/assets/b3656330-c390-42cf-9eb7-ac7915be9a99" />

IV.LỖI THƯỜNG GẶP VÀ CÁCH KHẮC PHỤC

<img width="377" height="376" alt="image" src="https://github.com/user-attachments/assets/496f6a27-b9cc-4912-8a1a-5efc0f9f812b" />




V. KẾT LUẬN

Qua bài thực hành số 5,em đã làm quen với truyền thông Bluetooth trong IoT qua bốn nội dung: cấu hình HC-05 bằng AT Command, mô phỏng truyền nhận dữ liệu Serial trong Proteus, điều khiển LED bằng giao diện Web và xây dựng luồng dữ liệu cảm biến DHT11 lên Web.
Kiến thức quan trọng cần nắm là sự khác nhau giữa Bluetooth và UART, cách nối chéo TX/RX, vai trò của baud rate, cách kiểm tra dữ liệu ở từng bước và vai trò của backend Node.js/WebSocket trong ứng dụng Web. Khi thực hiện, cần kiểm tra lần lượt từ phần cứng hoặc mô phỏng, cổng COM, dữ liệu Serial đến giao diện để xác định đúng vị trí phát sinh lỗi.

 VI.Tài LIỆU THAM KHẢO.
- BTH5_BLUETOOTH.pdf – Bài tập thực hành Truyền thông trong IoT, Bài thực hành số 5: Bluetooth & BLE.
- Arduino:[https://www.arduino.cc/](https://www.arduino.cc/) . 
- GitLab – Bluetooth assignments:[https://gitlab.com/iot-communication-assignment/course-2526/bluetooth-assignments.git](https://gitlab.com/iot-communication-assignment/course-2526/bluetooth-assignments.git) .
-nRF Connect for Mobile:[ https://www.nordicsemi.com/Products/Development-tools/nRF-Connect-for-Mobile]( https://www.nordicsemi.com/Products/Development-tools/nRF-Connect-for-Mobile).


