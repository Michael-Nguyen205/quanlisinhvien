#include <iostream>
#include <string>

using namespace std;

class User {
private:
    string username;
    string password;
    string fullName;
    string gender;
    string address;
    string phoneNumber;
    string dob; // Ngày sinh
    string subcode;
    bool isLoggedIn;
    int adminCode; // Mã admin

public:
    // Default constructor
    User() : isLoggedIn(false) {}

    // Public constructor
    User(string uname, string pwd, string name, string g, string addr, string phone, string birth, int code)
            : username(uname), password(pwd), fullName(name), gender(g), address(addr), phoneNumber(phone),
              dob(birth), isLoggedIn(false), adminCode(code) {}



    void login(string uname, string pwd) {
        if (uname == username && pwd == password) {
            isLoggedIn = true;
            cout << "Đăng nhập thành công!" << endl;
        } else {
            cout << "Đăng nhập không thành công. Vui lòng thử lại!" << endl;
        }
    }

    void logout() {
        isLoggedIn = false;
        cout << "Đăng xuất thành công!" << endl;
    }

    bool isLogged() const {
        return isLoggedIn;
    }

    int getAdminCode() const { // Phương thức để lấy giá trị của mã admin
        return adminCode;
    }

    // Method to check credentials
    bool checkCredentials(string uname, string pwd) const {
        return (uname == username && pwd == password);
    }

    static User
    createUser(string uname, string pwd, string name, string g, string addr, string phone, string birth, int code, string sub) {
        return User(uname, pwd, name, g, addr, phone, birth, code);
    }

    // Phương thức để in thông tin của tài khoản
    void viewInfo() const {
        cout << "Thông tin tài khoản:" << endl;
        cout << "Tên đăng nhập: " << username << endl;
        cout << "Họ và tên: " << fullName << endl;
        cout << "Giới tính: " << gender << endl;
        cout << "Địa chỉ: " << address << endl;
        cout << "Số điện thoại: " << phoneNumber << endl;
        cout << "Ngày sinh: " << dob << endl;
        cout << "Mã admin: " << adminCode << endl;
        cout << "Mã lớp học: " << subcode << endl;
    }
};

void doSomething(User& user) {
    if (user.isLogged()) {
        cout << "Thực hiện một công việc cho user." << endl;
    } else {
        cout << "Vui lòng đăng nhập trước khi thực hiện công việc." << endl;
    }
}

int main() {

    const int MAX_USERS = 100;
    User users[MAX_USERS]; // Mảng tối đa 100 tài khoản
    int numberOfUsers = 0; // Số lượng tài khoản hiện tại

    //Thêm tài khoản người dùng vào mảng
    users[numberOfUsers++] = User::createUser("u", "12", "Name 1", "Male", "Address 1", "123456789", "01/01/2000", 12345, "Sub 1");
    users[numberOfUsers++] = User::createUser("user2", "password2", "Name 2", "Female", "Address 2", "987654321", "02/02/2001", 67890, "Sub 2");
    users[numberOfUsers++] = User::createUser("user3", "password3", "Name 3", "Male", "Address 3", "555555555", "03/03/2002", 12345, "Sub 3");


    int adminCode; // Mã admin

    int choice;
    int userIndex = -1; // Khai báo userIndex ở ngoài vòng lặp

    do {
        cout << "Chào mừng bạn đến với hệ thống đăng nhập và đăng kí!" << endl;
        cout << "1. Đăng nhập" << endl;
        cout << "2. Đăng kí" << endl;
        cout << "3. Xem thông tin tài khoản" << endl;
        cout << "Nhập lựa chọn của bạn: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                bool found = false;
                string loginUname, loginPwd;
                do {
                    cout << "Nhập tên đăng nhập để đăng nhập hoặc nhập 0 để quay lại menu: ";
                    cin >> loginUname;
                    if (loginUname == "0") { // Kiểm tra nếu người dùng nhập 0 để quay lại menu chính
                        cout << "Quay lại menu chính." << endl;
                        break; // Thoát khỏi vòng lặp và quay lại menu chính
                    }
                    cout << "Nhập mật khẩu để đăng nhập: ";
                    cin >> loginPwd;

                    // Tìm tài khoản và đăng nhập
                    userIndex = -1; // Reset userIndex

                    for (int i = 0; i < numberOfUsers; ++i) {
                        if (users[i].isLogged()) {
                            continue; // Bỏ qua tài khoản đã đăng nhập
                        }
                        if (users[i].checkCredentials(loginUname, loginPwd)) {
                            users[i].login(loginUname, loginPwd);
                            found = true;
                            userIndex = i;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Tài khoản không tồn tại hoặc mật khẩu không chính xác. Nhập lại hoặc chọn 0 để quay lại menu:" << endl;
                    }
                } while (!found);

                // Nếu người dùng đã chọn 0 để quay lại menu, không thực hiện các lựa chọn khác
                if (loginUname == "0") {
                    break;
                }


                // Switch-case structure để thực hiện các hành động dựa trên lựa chọn của người dùng
                do {
                    cout << "1. Thực hiện công việc" << endl;
                    cout << "2. Đăng xuất" << endl;
                    cout << "3. Thoát" << endl;
                    cout << "4. xem tài khoản" << endl;
                    cout << "Nhập lựa chọn: ";
                    cin >> choice;

                    switch (choice) {
                        case 1:
                            doSomething(users[userIndex]);
                            break;
                        case 2:
                            users[userIndex].logout();
                            break;
                        case 3:
                            cout << "Quay lại menu chính." << endl;
                            break;
                        case 4: {
                            cout << " xem tài khoản." << endl;
                            cout << "Giá trị mới của userIndex: " << userIndex << endl;
                            if (userIndex != -1) { // Kiểm tra xem người dùng đã đăng nhập chưa
                                users[userIndex].viewInfo(); // Hiển thị thông tin của tài khoản người dùng đã đăng nhập
                            } else {
                                cout << "Bạn cần đăng nhập để xem thông tin tài khoản của mình." << endl;
                            }
                            break;
                        }

                        default:
                            cout << "Lựa chọn không hợp lệ. Vui lòng chọn lại." << endl;
                    }
                } while (choice != 2);
                break;
            }
            case 2: {
                string uname, pwd, confirmPwd, name, gender, addr, phone, birth, sub;
                do {
                    cout << "Nhập tên đăng kí hoặc bấm 0 để thoát: ";
                    cin >> uname;

                    if (uname == "0") {
                        cout << "Quay lại menu chính." << endl;
                        break; // Thoát khỏi vòng lặp và quay lại menu chính
                    }

                    // Nhập mật khẩu
                    cout << "Nhập mật khẩu: ";
                    cin >> pwd;

                    // Nhập lại mật khẩu và kiểm tra khớp
                    cout << "Nhập lại mật khẩu: ";
                    cin >> confirmPwd;
                    if (pwd != confirmPwd) {
                        cout << "Mật khẩu không khớp. Vui lòng thử lại." << endl;
                    }

                    // Nếu người dùng đã nhập 0 để thoát, không thực hiện các bước nhập tiếp theo
                    if (uname == "0") {
                        break;
                    }

                    // Nhập họ tên
                    cout << "Nhập họ tên: ";
                    cin.ignore(); // Xóa kí tự newline từ lần nhập trước
                    getline(cin, name);

                    // Nhập giới tính
                    cout << "Nhập giới tính: ";
                    cin >> gender;

                    // Nhập địa chỉ
                    cout << "Nhập địa chỉ: ";
                    cin.ignore(); // Xóa kí tự newline từ lần nhập trước
                    getline(cin, addr);

                    // Nhập số điện thoại
                    cout << "Nhập số điện thoại: ";
                    cin >> phone;

                    // Nhập ngày sinh
                    cout << "Nhập ngày sinh (dd/mm/yyyy): ";
                    cin >> birth;

                    // Nhập mã admin
                    cout << "Nhập mã admin: ";
                    cin >> adminCode;

                    cout << "Nhập mã lớp học: ";
                    cin >> sub;

                    // Kiểm tra mã admin
                    if (adminCode != 12345 && adminCode != 67890) { // Thay 12345 và 67890 bằng các mã admin mà bạn muốn
                        cout << "Mã admin không chính xác. Vui lòng thử lại." << endl;
                        return 0;
                    }

                    // Tạo tài khoản mới và thêm vào mảng users
                    users[numberOfUsers++] = User::createUser(uname, pwd, name, gender, addr, phone, birth, adminCode, sub);
                    cout << "Đăng kí tài khoản mới thành công!" << endl;

                } while (true); // Sử dụng vòng lặp vô hạn để quay lại menu chính sau khi hoàn thành một lựa chọn

                break;
            }
            case 3: {
                string viewUname;
                cout << "Nhập tên đăng nhập của tài khoản bạn muốn xem thông tin: ";
                cin >> viewUname;

                bool found = false;
                for (int i = 0; i < numberOfUsers; ++i) {
                    if (users[i].isLogged()) {
                        continue; // Bỏ qua tài khoản đã đăng nhập
                    }
                    if (users[i].checkCredentials(viewUname, "")) {
                        users[i].viewInfo();
                        found = true;
                        break;
                    }
                }
                if (!found) {
                    cout << "Tài khoản không tồn tại hoặc bạn không có quyền xem thông tin của tài khoản này." << endl;
                }
                break;
            }
            default:
                cout << "Lựa chọn không hợp lệ." << endl;
        }
    } while (true); // Sử dụng vòng lặp vô hạn để quay lại menu chính sau khi hoàn thành một lựa chọn

    return 0;
}
