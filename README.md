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
3. Mở phần mềm Arduino IDE và tạo hai file mới viết code tương ứng với GUILENH [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_HC05GUILENH/THBLE_HC05GUILENH.ino](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_HC05GUILENH/THBLE_HC05GUILENH.ino) và NHANLENH [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_HC05NHANLENH/THBLE_HC05NHANLENH.ino](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_HC05NHANLENH/THBLE_HC05NHANLENH.ino)
4. Tại Proteus bấm <img width="20" height="15" alt="image" src="https://github.com/user-attachments/assets/00a21102-ce3c-4dbe-b81a-f76b74b237d6" /> để chạy chương trình.
5. Sau khi chạy sẽ hiển thị cửa sổ Terminal. Sử dụng các câu lệnh để điều khiển như: A:Cảnh báo ,B: Hoạt động bình thương, E: Tắt cả hai LED [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_IMG2.png](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_IMG2.png).

-Kết quả: Dữ liệu nhập từ một đầu được truyền qua mô hình Serial và xuất hiện ở đầu nhận tương ứng

-VIDEO THỰC HÀNH: [https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_VIDEO.mp4](https://github.com/LinhThuy0/TruyenthongIot/blob/main/BLE/THBLE_GIAOTIEP/THBLE_VIDEO.mp4).

Bước 2 – Tạo cặp cổng COM ảo
1. Cài phần mềm Virtual Serial Port Driver tương thích với hệ điều hành.
2. Mở phần mềm và tạo một cặp COM ảo, ví dụ COM1 và COM2.
3. Kiểm tra cặp COM đã được tạo thành công.
4. Không chọn trùng cổng COM đang được phần mềm khác sử dụng.
Bước 3 – Tạo mạch trong Proteus
1. Tạo một dự án mô phỏng mới.
2. Thêm hai module Bluetooth HC-05 và HC-06 từ thư viện.
3. Thêm hai Virtual Terminal để quan sát và nhập dữ liệu.
4. Kết nối TX/RX theo hướng truyền nhận chéo: TX của thiết bị nối đến RX của đầu nhận, RX nối đến TX của đầu truyền.
5. Thực hiện kết nối theo mô hình và thuộc tính linh kiện mà thư viện mô phỏng hỗ trợ.
Bước 4 – Cấu hình thuộc tính
1. Mở thuộc tính HC-05 và gán cổng COM ảo thứ nhất, ví dụ COM1.
2. Mở thuộc tính HC-06 và gán cổng COM ảo thứ hai, ví dụ COM2.
3. Đặt các thông số Serial giống nhau ở hai đầu. Tài liệu sử dụng ví dụ 9600 baud, 8 data bits, parity None, 1 stop bit.
4. Kiểm tra cặp COM ảo đã liên kết với nhau.
Bước 5 – Chạy mô phỏng
1. Nhấn Play trong Proteus.
2. Mở hai cửa sổ Virtual Terminal.
3. Nhập một chuỗi thử nghiệm ở Terminal thứ nhất, ví dụ 12345678.
4. Quan sát xem dữ liệu có xuất hiện ở đầu còn lại hay không.
5. Thử gửi dữ liệu theo chiều ngược lại.
6. Nếu dữ liệu không truyền được, kiểm tra COM, baud rate, nối chéo TX/RX và cấu hình thuộc tính module.

4. SƠ ĐỒ NGUYÊN LÝ HOẠT ĐỘNG

Điện thoại mở ứng dụng nRF Connect.

Quét và kết nối với thiết bị BLE có tên LINH_BLE.

Điện thoại ghi ký tự A, B, C, D hoặc E vào Characteristic.

ESP32-S3 nhận dữ liệu trong callback onWrite.

Chương trình phân tích ký tự lệnh và chọn màu tương ứng.

Thư viện NeoPixel cập nhật LED RGB tích hợp.

Giải thích: Điện thoại đóng vai trò BLE Client, gửi lệnh đến ESP32-S3. ESP32-S3 đóng vai trò BLE Server, quảng bá dịch vụ, nhận dữ liệu ghi vào Characteristic và điều khiển LED.

5. CÁC THÔNG SỐ CẤU HÌNH BLE

Thông số

Giá trị

Ý nghĩa

Tên Bluetooth

LINH_BLE

Tên hiển thị khi quét trên điện thoại.

Chân LED

GPIO 48

Chân dữ liệu LED NeoPixel tích hợp trên bo mạch được sử dụng trong bài.

Service UUID

12345678-1234-1234-1234-1234567890ab

Mã định danh dịch vụ BLE tùy chỉnh.

Characteristic UUID

12345678-1234-1234-1234-1234567890ac

Mã định danh đặc trưng nhận lệnh ghi.

Characteristic cần được cấu hình thuộc tính Write và/hoặc Write Without Response phù hợp với cách ghi được ứng dụng nRF Connect sử dụng.

6. HƯỚNG DẪN THỰC HIỆN TỪNG BƯỚC

6.1. Nạp chương trình vào ESP32-S3

Mở Arduino IDE.

Vào Tools → Manage Libraries..., tìm Adafruit NeoPixel và nhấn Install nếu thư viện chưa được cài.

Kết nối ESP32-S3 với máy tính bằng cáp USB có hỗ trợ truyền dữ liệu.

Trong Tools → Board, chọn đúng loại bo mạch ESP32-S3 đang sử dụng. Chọn đúng cổng COM trong Tools → Port.

Mở tệp mã nguồn BTH_BLE_nRF.ino.

Nhấn Upload để biên dịch và nạp chương trình. Nếu không nạp được, kiểm tra cáp USB, cổng COM, board và chế độ BOOT theo hướng dẫn của bo mạch.

Mở Serial Monitor, đặt baud rate 115200 để theo dõi thông báo khởi động và trạng thái BLE.

6.2. Kết nối và điều khiển bằng nRF Connect

Bật Bluetooth trên điện thoại và mở ứng dụng nRF Connect for Mobile.

Trong tab Scanner, tìm thiết bị có tên LINH_BLE. Nhấn Connect.

Sau khi kết nối, mở rộng danh sách dịch vụ và tìm Service UUID kết thúc bằng 90ab.

Tìm Characteristic UUID kết thúc bằng 90ac, kiểm tra đặc tính có hỗ trợ Write hoặc Write Without Response.

Nhấn biểu tượng ghi dữ liệu (Write). Chọn định dạng UTF-8 hoặc Text nếu phiên bản ứng dụng hiển thị tùy chọn này.

Nhập một ký tự lệnh: A, B, C, D hoặc E. Nhấn Write để gửi.

Quan sát LED RGB và Serial Monitor. Lặp lại với các lệnh còn lại để kiểm tra đủ năm màu.

7. BẢNG KIỂM TRA KẾT QUẢ

Lần thử

Ký tự gửi

Màu LED mong đợi

Thông báo Serial Monitor mẫu

1

A hoặc a

Đỏ

Nhan lenh: A / LED mau DO

2

B hoặc b

Xanh lá

Nhan lenh: B / LED mau XANH LA

3

C hoặc c

Vàng

Nhan lenh: C / LED mau VANG

4

D hoặc d

Cam

Nhan lenh: D / LED mau CAM

5

E hoặc e

Hồng

Nhan lenh: E / LED mau HONG

Kết quả kỳ vọng: Mỗi khi gửi một ký tự hợp lệ từ điện thoại, LED thay đổi sang màu tương ứng mà không làm mất kết nối BLE. Nội dung Serial Monitor phụ thuộc cách viết thông báo trong chương trình.

8. GIẢI THÍCH CÁC LỆNH VÀ HÀM QUAN TRỌNG

Đoạn mã / Hàm

Ý nghĩa

#define LED_PIN 48

Khai báo chân dữ liệu điều khiển LED NeoPixel.

BLEDevice::init("LINH_BLE")

Khởi tạo BLE và đặt tên thiết bị.

server->createService(SERVICE_UUID)

Tạo dịch vụ BLE với UUID đã khai báo.

PROPERTY_WRITE | PROPERTY_WRITE_NR

Cho phép Client ghi dữ liệu theo các phương thức tương ứng; tên hằng cụ thể phụ thuộc thư viện BLE được dùng.

BLECharacteristicCallbacks

Lớp callback xử lý sự kiện của Characteristic.

onWrite(...)

Được gọi khi Client ghi dữ liệu vào Characteristic.

pCharacteristic->getValue()

Lấy dữ liệu nhận được dưới dạng chuỗi/byte.

value[0]

Đọc ký tự đầu tiên làm lệnh điều khiển; cần kiểm tra dữ liệu không rỗng trước khi đọc.

led.setPixelColor(...) và led.show()

Thiết lập màu RGB và cập nhật màu ra LED.

9. VIDEO VÀ TỆP THỰC HÀNH

Các tệp có thể đi kèm tài liệu:

THBLE_IMG1.jpg: Giao diện ghi giá trị (Write Value) trong nRF Connect.

THBLE_IMG2.jpg: Trạng thái nạp chương trình trên Arduino IDE và LED trên ESP32-S3.

THBLE_VIDEO.mp4: Video minh họa quá trình quét, kết nối và điều khiển LED.

BTH_BLE_nRF.ino: Mã nguồn Arduino cho bài thực hành BLE.

README.md: Tài liệu hướng dẫn sử dụng.

Lưu ý: Các tệp được liệt kê ở trên là tài liệu dự kiến đi kèm; nội dung Word này không tự chứa các ảnh/video nếu người dùng chưa cung cấp các tệp đó.

10. CÁC LỖI THƯỜNG GẶP VÀ CÁCH KHẮC PHỤC

Hiện tượng

Nguyên nhân cần kiểm tra

Cách xử lý

Không tìm thấy LINH_BLE

ESP32-S3 chưa chạy chương trình, chưa cấp nguồn hoặc chưa quảng bá BLE.

Kiểm tra nạp code, cáp USB, Serial Monitor và bật Bluetooth trên điện thoại.

Kết nối được nhưng không thấy Service

UUID không khớp hoặc dịch vụ chưa được thêm/khởi động.

Đối chiếu SERVICE_UUID, lệnh start() và cấu hình advertising.

Không tìm thấy Characteristic

CHAR_UUID sai hoặc Characteristic chưa được thêm vào Service.

Kiểm tra UUID kết thúc bằng 90ac và cấu hình service.

Gửi lệnh nhưng LED không đổi màu

Sai kiểu dữ liệu, ký tự không hợp lệ, hoặc callback không xử lý dữ liệu.

Gửi một ký tự A–E dưới dạng UTF-8/Text; xem Serial Monitor.

Lỗi Adafruit_NeoPixel

Chưa cài thư viện hoặc tên thư viện chưa đúng.

Mở Library Manager và cài Adafruit NeoPixel.

LED không sáng dù đã nhận lệnh

Bo mạch dùng loại LED/chân khác, cấu hình thứ tự màu hoặc mức sáng không phù hợp.

Xác minh model bo mạch, GPIO LED tích hợp, kiểu GRB/RGB và nguồn cấp.

11. CÂU HỎI VÀ ĐÁP ÁN VẤN ĐÁP

Câu 1. Tại sao đây là bài truyền thông Bluetooth Low Energy (BLE)?

Trả lời: Vì ESP32-S3 và điện thoại trao đổi dữ liệu không dây bằng BLE, phù hợp với kết nối tầm ngắn và các lần truyền dữ liệu nhỏ trong hệ thống IoT.

Câu 2. Điện thoại làm gì trong hệ thống?

Trả lời: Điện thoại chạy nRF Connect, quét thiết bị, kết nối BLE và ghi ký tự lệnh vào Characteristic.

Câu 3. ESP32-S3 làm gì?

Trả lời: ESP32-S3 hoạt động như BLE Server, quảng bá dịch vụ, nhận lệnh và điều khiển LED NeoPixel.

Câu 4. Hàm onWrite hoạt động như thế nào?

Trả lời: Callback onWrite được gọi khi Client ghi dữ liệu vào Characteristic. Chương trình đọc dữ liệu và xử lý lệnh trong callback.

Câu 5. Vì sao đọc value[0] thay vì toàn bộ chuỗi?

Trả lời: Vì quy ước lệnh chỉ gồm một ký tự A, B, C, D hoặc E. Cần kiểm tra chuỗi không rỗng trước khi đọc phần tử đầu tiên.

Câu 6. Có cảm biến nào khác trong bài không?

Trả lời: Không. Bài tập tập trung vào giao tiếp BLE và điều khiển LED RGB NeoPixel tích hợp trên bo mạch.

12. KẾT LUẬN

Qua bài thực hành, người học làm quen với cách thiết lập giao tiếp Bluetooth Low Energy giữa ESP32-S3 và điện thoại thông minh thông qua nRF Connect. Nội dung trọng tâm là khởi tạo BLE Server, tạo Service và Characteristic, xử lý dữ liệu ghi bằng callback onWrite, sau đó điều khiển LED RGB NeoPixel theo lệnh nhận được.

Bài thực hành giúp củng cố kiến thức về truyền thông không dây tầm ngắn trong IoT, đồng thời rèn luyện kỹ năng cấu hình môi trường Arduino IDE, kiểm tra lỗi và đánh giá kết quả thực nghiệm.


