import serial
import time

# Cấu hình cổng serial
ser = serial.Serial('/dev/cu.usbmodem1201', 9600)
time.sleep(2)

mode = 1

def set_mode(mode):
    ser.write(str(mode).encode())

try:
    while True:
        user_input = input("Nhập chế độ (1, 2, 3, hoặc 'exit'): ")

        if user_input.lower() == 'exit':
            break

        try:
            new_mode = int(user_input)
            if 1 <= new_mode <= 3:
                mode = new_mode
                set_mode(mode)
                print(f"Đã chuyển sang chế độ {mode}") #Thông báo đã chuyển chế độ
            else:
                print("Chế độ không hợp lệ. Vui lòng nhập 1, 2 hoặc 3.")

        except ValueError:
            print("Lỗi: Vui lòng nhập số.")



except KeyboardInterrupt:
    ser.close()
    print("Đã dừng chương trình.")

except serial.SerialException as e:
    print(f"Lỗi Serial: {e}")
finally:
    ser.close()
    print("Cổng Serial đã đóng.")
