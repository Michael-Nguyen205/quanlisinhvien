
#include <iostream>
#include <string>

using namespace std;


class Student {
private:
    string studentId;
    string studentName;
    int cccd;
    string gender;
    string date;
    static int constructorCount;
//    int absentCount; // Số buổi nghỉ
//    int presentCount; // Số buổi có mặt đi học

public:
    Student() {
         constructorCount++;
//         absentCount = 0;
//         presentCount = 0;
     }

    Student(string id, string name, int cccd, string gender, string date)
        : studentId(id), studentName(name), cccd(cccd), gender(gender), date(date) {
        constructorCount++;
    }

    string getStudentId() const {
        return studentId;
    }

    void setStudentId(string id) {
        studentId = id;
    }

    string getStudentName() const {
        return studentName;
    }

    void setStudentName(string name) {
        studentName = name;
    }

    int getCccd() const {
        return cccd;
    }

    void setCccd(int id) {
        cccd = id;
    }

    string getGender() const {
        return gender;
    }

    void setGender(string gen) {
        gender = gen;
    }

    string getDate() const {
        return date;
    }

    void setDate(string dob) {
        date = dob;
    }
    
//    int getAbsentCount() const {
//          return absentCount;
//      }
//
//      void increaseAbsentCount() {
//          absentCount++;
//      }
//
//      int getPresentCount() const {
//          return presentCount;
//      }
//
//      void increasePresentCount() {
//          presentCount++;
//      }

    static int getConstructorCount() {
        return constructorCount;
    }
    
    
    
};



int Student::constructorCount = 0; // Khởi tạo biến static



class Course {
private:
   
    string courseName;
    int LimitCourseDay;
    int TotalCourseDay; // tổng số buổi học của lớp này
    
public:
    string courseId;
    static int sizeCourse;
    
    // Constructors
    Course() {
        sizeCourse++;
        cout<<sizeCourse<<endl;
        TotalCourseDay = 0; // Khởi tạo giá trị cho TotalCourseDay
    }
    
    Course(string id, string name, int total) : courseId(id), courseName(name), TotalCourseDay(total) {
        sizeCourse++;
    }
    
    // Destructor
    ~Course() {
        // Giảm kích thước mỗi khi đối tượng Course bị hủy
    }
    
    // Getter và Setter cho courseId
    string getCourseId() const {
        return courseId;
    }
    
    void setCourseId(string id) {
        courseId = id;
    }
    
    // Getter và Setter cho courseName
    string getCourseName() const {
        return courseName;
    }
    
    void setCourseName(string name) {
        courseName = name;
    }
    
    // Getter và Setter cho TotalCourseDay
    int getTotalCourseDay() const {
       return TotalCourseDay;
    }
    
    void setTotalCourseDay(int total) {
        TotalCourseDay = total;
    }
    
    // Getter cho sizeCourse
    static int getTotalCourseCount() {
        return sizeCourse;
    }
};

// Khởi tạo biến static
int Course::sizeCourse = 0;







class AttendanceRecord {
private:
    Student student;
    string status;    // lưu trữ điểm danh
    Course course;
    int day;   // ngày điểm danh
    int numDays;  //phế
//    int absentCount; // Số buổi nghỉ
//    int presentCount; // Số buổi có mặt đi học
  
public:
    
    static int totalAtten;
   
    AttendanceRecord() {
        status = "";
        numDays = 0;
    }
    
    
    void setCourse(const Course& cours) {
        course = cours;
    }
    
    
    
    AttendanceRecord(Student std ,Course cous,int Day) {
        student = std;
        course = cous;
        day = Day;
//        numDays = days;
//        status = '';
       
    }
    
    void setDay(int Day) {
        day = Day;
    }
    
    int getDay() const { //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
        return day;
    }
    
    string getAttendance() const { //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
            return status;
    }
    
 
    Course getCourse() const {
        return course;
    }
    Student getStudent() const {
        return student;
    }
    
    
   
    
    void setAttendanceForDay(int Day, char Status) {
        if (Day >= 0) {
            status = Status;
            day = Day;
//            if(Status == 'A') {
//                student.increaseAbsentCount(); // Tăng số buổi nghỉ của sinh viên
//            } else if (Status == 'P') {
//                student.increasePresentCount(); // Tăng số buổi có mặt của sinh viên
//            }
        } else {
            cout << "Invalid day." << endl;
        }
       
    }
    
 
    ~AttendanceRecord() {
    }
};
int AttendanceRecord::totalAtten = 0; // Khởi tạo biến static





class AttendanceManager {
private:
    AttendanceRecord* records;
    int hehe;  // phế
    int numberAttendanceManager = 0;
    int numDays;//phế
    
public:
    AttendanceManager() : records(nullptr), hehe(0), numDays(0) {}
    
    AttendanceManager(int dh, int days) : hehe(dh), numDays(days) {
        records = new AttendanceRecord[100];
    }
    
    
    
    
    
    ~AttendanceManager() {

    }
    
    
    void addStudent(const Student& student, const Course& course) {
        // Kiểm tra xem sinh viên đã tồn tại trong danh sách chưa
//        bool exists = false;
//        for (int i = 0; i < number; ++i) {
//            if (records[i].getStudent().getStudentId() == student.getStudentId()) {
//                exists = true;
//                break;
//            }
//        }

//        if (!exists) {
            
            
            for (int i = 0; i < course.getTotalCourseDay(); ++i) {
                // Thêm sinh viên vào danh sách nếu chưa tồn tại
                records[numberAttendanceManager] = AttendanceRecord(student, course,i ) ;
                numberAttendanceManager++;
            }
//        } else {
//            cout << "Student with ID " << student.getStudentId() << " already exists." << endl;
//        }
    }

    
    
    
    void printStudentTableHeader() {
        cout << "==============================================================================\n";
        cout << "| MSV        | Student Name | CCCD        | Gender | Date of Birth |\n";
        cout << "==============================================================================\n";
    }

    void printStudentTableRow(const string& id, const string& name, int cccd, const string& gender, const string& dob) {
        cout << "| " << id << string(11 - id.length(), ' ') << "| ";
        cout << name << string(13 - name.length(), ' ') << "| ";
        cout << cccd << string(12 - to_string(cccd).length(), ' ') << "| ";
        cout << gender << string(7 - gender.length(), ' ') << "| ";
        cout << dob << string(14 - dob.length(), ' ') << "|\n";
    }

    void ListStudent() {
        cout << "List of Students:" << endl;
        printStudentTableHeader();

        for(int i = 0; i < numberAttendanceManager; i++) {
            // Kiểm tra xem sinh viên có mã bị trùng không
            bool duplicate = false;
            for(int j = 0; j < i; j++) {
                if(records[i].getStudent().getStudentId() == records[j].getStudent().getStudentId()) {
                    duplicate = true;
                    break;
                }
            }

            // Nếu không trùng mã thì in ra thông tin sinh viên
            if(!duplicate) {
                // Lấy thông tin sinh viên
                string id = records[i].getStudent().getStudentId();
                string name = records[i].getStudent().getStudentName();
                int cccd = records[i].getStudent().getCccd();
                string gender = records[i].getStudent().getGender();
                string dob = records[i].getStudent().getDate();
                
                // In thông tin sinh viên
                printStudentTableRow(id, name, cccd, gender, dob);
            }
        }
        
        cout << "==============================================================================\n";
    }

    
    
    

    
    void inputAttendanceforday(int day , Course course, int numCourses)  {
        if (day >= 0 && day < numDays) {
            char status;
            cout << " nhập P nếu có mặt A nếu vắng" << day + 1 << ":" << endl;
            for (int i = 0; i < numberAttendanceManager; i++) {
                if(course.courseId==records[i].getCourse().courseId && day== records[i].getDay() ){
                    cout << "quản lí điểm danh thứ : "<<i<<endl;
                    cout << "Thông tin ngày và môn điểm danh , "  << ": "
                    << "Lớp" << records[i].getCourse().courseId << ": "<<"ngày"<< day << endl;
                    cout << "Student "<<  records[i].getStudent().getStudentName() << ":";
                    cin >> status;
                    records[i].setAttendanceForDay(day, status);
                };
            }
        } else {
            cout << "Invalid day." << endl;
        }
    }
    
    
    
    
    

    
    void printStudentTableHeader1() {
        cout << "==================================================================================\n";
        cout << "| MSV        | Student Name | CCCD        | Gender | Date of Birth | Attendances |\n";
        cout << "==================================================================================\n";
    }

    void printStudentTableRow1(const string& id, const string& name, int cccd, const string& gender, const string& dob, string At) {
        cout << "| " << id << string(11 - id.length(), ' ') << "| ";
        cout << name << string(13 - name.length(), ' ') << "| ";
        cout << cccd << string(12 - to_string(cccd).length(), ' ') << "| ";
        cout << gender << string(7 - gender.length(), ' ') << "| ";
        cout << dob << string(14 - dob.length(), ' ') << "| ";
        cout << At << string(12 - At.length(), ' ') << "|\n";
    }
    
    
    void viewTottalAttendancesOnCourseId(Course course, int totalCourseDays) {
        cout << "Attendance for course " << course.getCourseName() << ":" << endl;
        cout << "Total number of attendance days: " << totalCourseDays << endl; // In tổng số ngày điểm danh

        for (int i = 0; i < totalCourseDays; i++) {
            cout << "Attendance for day " << i + 1 << ":" << endl;
            printStudentTableHeader1();

            for (int j = 0; j < numberAttendanceManager; j++) {
                if (records[j].getCourse().getCourseId() == course.getCourseId() && i  == records[j].getDay()) {
                    string id = records[j].getStudent().getStudentId();
                    string name = records[j].getStudent().getStudentName();
                    int cccd = records[j].getStudent().getCccd();
                    string gender = records[j].getStudent().getGender();
                    string dob = records[j].getStudent().getDate();
                    string At = records[j].getAttendance();

                    // In thông tin sinh viên
                    printStudentTableRow1(id, name, cccd, gender, dob, At);
                }
            }
            cout << "----------------------------------------------------------------------------------" << endl;
        }
    }


    
    void viewAttendancesOnDayOncourseIdOnDay(int day , Course course, int numCourses)  {
        if (day >= 0 && day < numDays) {
            char status;
            cout << " thông tin điểm danh của các sinh viên môn " <<course.getCourseName() <<"ngày thứ :"<< day << endl;
            printStudentTableHeader1();
            for (int i = 0; i < numberAttendanceManager; i++) {
                if(course.courseId==records[i].getCourse().courseId && day==records[i].getDay()){
                    string id = records[i].getStudent().getStudentId();
                    string name = records[i].getStudent().getStudentName();
                    int cccd = records[i].getStudent().getCccd();
                    string gender = records[i].getStudent().getGender();
                    string dob = records[i].getStudent().getDate();
                    string At = records[i].getAttendance();

                    // In thông tin sinh viên
                    printStudentTableRow1(id, name, cccd, gender, dob, At);
//                    cout << records[i].getAttendance() << endl;
                    
                };
            
            }
        } else {
            cout << "Invalid day." << endl;
        }
    }
    
    
    
    
    
    
    void printAllAttendanceRecords() {
        cout << "All Attendance Records:" << endl;
        cout << "==============================================================" << endl;
        for (int i = 0; i < numberAttendanceManager; i++) {
            cout << "Record " << i + 1 << ":" << endl;
            cout << "Student ID: " << records[i].getStudent().getStudentId() << endl;
            cout << "Student Name: " << records[i].getStudent().getStudentName() << endl;
            cout << "Course ID: " << records[i].getCourse().getCourseId() << endl;
            cout << "Attendance Status: " << records[i].getAttendance() << endl;
            cout << "Day: " << records[i].getDay() << endl;
            cout << "--------------------------------------------------------------" << endl;
        }
        cout << "==============================================================" << endl;
    }
    

    
    void printAttendanceSummaryForStudent(string courseId, string studentId, int totalCourseDays) {
        int absentCount = 0;
        string studentName;
        string studentGender;
        int studentCccd;
        string studentDob;

        // Tìm thông tin sinh viên
        for (int i = 0; i < numberAttendanceManager; i++) {
            if (records[i].getCourse().getCourseId() == courseId && records[i].getStudent().getStudentId() == studentId) {
                if (records[i].getAttendance() == "A") {
                    absentCount++;
                }

                // Lấy thông tin của sinh viên
                studentName = records[i].getStudent().getStudentName();
                studentGender = records[i].getStudent().getGender();
                studentCccd = records[i].getStudent().getCccd();
                studentDob = records[i].getStudent().getDate();
                break; // Vì thông tin sinh viên chỉ cần lấy 1 lần
            }
        }
        
        // Tính tỉ lệ số buổi nghỉ
        double absentPercentage = (static_cast<double>(absentCount) / totalCourseDays) * 100;

        // Kiểm tra nếu tỉ lệ vượt quá 30%
        if (absentPercentage > 30) {
            cout << "==============================================================" << endl;
            cout << "Thông báo: Sinh viên " << studentId << " - " << studentName << " đã vắng quá 30% số buổi học." << endl;
            cout << "Thông tin sinh viên:" << endl;
            cout << "Tên: " << studentName << endl;
            cout << "Giới tính: " << studentGender << endl;
            cout << "CCCD: " << studentCccd << endl;
            cout << "Ngày sinh: " << studentDob << endl;
            cout << "Tổng số ngày vắng mặt: " << absentCount << " trên tổng " << totalCourseDays << " buổi học." << endl;
            cout << "Tỉ lệ vắng mặt: " << absentPercentage << "%" << endl;
            cout << "==============================================================" << endl;
        } else {
            cout << "==============================================================" << endl;
            cout << "Sinh viên " << studentId << " không vượt quá 30% số buổi học." << endl;
            cout << "Tỉ lệ vắng mặt: " << absentPercentage << "%" << endl;
            cout << "---------------------------------------------------------------" << endl;
            cout << "Thông tin sinh viên:" << endl;
            cout << "Tên: " << studentName << endl;
            cout << "Giới tính: " << studentGender << endl;
            cout << "CCCD: " << studentCccd << endl;
            cout << "Ngày sinh: " << studentDob << endl;
            cout << "Tổng số ngày vắng mặt: " << absentCount << " trên tổng " << totalCourseDays << " buổi học." << endl;
            cout << "Tỉ lệ vắng mặt: " << absentPercentage << "%" << endl;
            cout << "==============================================================" << endl;
        }
    }


    

    
    
    
    
    
    void printStudentTableHeader2() {
        cout << "==================================================================================\n";
        cout << "| MSV        | Student Name | CCCD        | Gender | Date of Birth | TotalAbsenes|\n";
        cout << "==================================================================================\n";
    }

    void printStudentTableRow2(const string& id, const string& name, int cccd, const string& gender, const string& dob, int totalAbsent) {
        cout << "| " << id << string(11 - id.length(), ' ') << "| ";
        cout << name << string(13 - name.length(), ' ') << "| ";
        cout << cccd << string(12 - to_string(cccd).length(), ' ') << "| ";
        cout << gender << string(7 - gender.length(), ' ') << "| ";
        cout << dob << string(14 - dob.length(), ' ') << "| ";
        cout << totalAbsent << string(12 - to_string(totalAbsent).length(), ' ') << "|\n";
    }

    void printAttendanceSummaryDayForCouse(Course course, int totalCourseDays) {
        int absentCount = 0;
        int totalStudent=0;
        
        cout <<  endl;
        cout <<  endl;
        cout << "List of Students:" << endl;
        printStudentTableHeader2();

        for(int i = 0; i < numberAttendanceManager; i++) {
            int absentCountStudent = 0;
            // Kiểm tra xem sinh viên có mã bị trùng không
            bool duplicate = false;
            for(int j = 0; j < i; j++) {
                if(records[i].getStudent().getStudentId() == records[j].getStudent().getStudentId()) {
                    duplicate = true;
                    break;
                }
            }

            // Nếu không trùng mã thì in ra thông tin sinh viên
            if(!duplicate) {
                // Đếm số buổi nghỉ của sinh viên
                if (records[i].getAttendance() == "A") {
                    absentCount++;
                    absentCountStudent++;
                }
                // Lấy thông tin sinh viên
                string id = records[i].getStudent().getStudentId();
                string name = records[i].getStudent().getStudentName();
                int cccd = records[i].getStudent().getCccd();
                string gender = records[i].getStudent().getGender();
                string dob = records[i].getStudent().getDate();
            

                // In thông tin sinh viên
                printStudentTableRow2(id, name, cccd, gender, dob,absentCountStudent);
                totalStudent++;
            }
        }
        
        // Tính tỷ lệ vắng mặt
        double absentPercentage = (static_cast<double>(absentCount) / totalCourseDays) * 100;

        // In thống kê vắng mặt
        // In thống kê vắng mặt
        cout << "==================================================================================\n";
        cout << "| Absentee Summary                                                               |\n";
        cout << "==================================================================================\n";
        cout << "| Total number of students: " << totalStudent << string(53 - to_string(totalStudent).length(), ' ') << "|\n";
        cout << "| Total number of days: " << totalCourseDays << string(57 - to_string(totalCourseDays).length(), ' ') << "|\n";
        cout << "| Total number of absences: " << absentCount << string(53 - to_string(absentCount).length(), ' ') << "|\n";
        cout << "| Percentage of absences: " << absentPercentage << "%" << string(61 - to_string(absentPercentage).length(), ' ') << "|\n";
        cout << "===================================================================================\n";

    }


};




int main() {
    

    AttendanceManager manager(3, 10);
    
    
    int numCourses = 2; // bình thường là sẽ nhập
        Course* courses = new Course[numCourses]; // Tạo mảng động của các đối tượng Course

  
        for (int i = 0; i < numCourses; ++i) {
            string courseId = "C00" + to_string(i + 1);
            string courseName = "Course " + to_string(i + 1);
            int TotalCourseDay = 10 + i;
            courses[i].setCourseId(courseId);
            courses[i].setCourseName(courseName);
            courses[i].setTotalCourseDay(TotalCourseDay);
        }
    
    
    Student student1("S001", "Alice", 123456789, "Female", "2000-01-01");
    Student student2("S002", "Bob", 234567890, "Male", "2000-02-02");
    Student student3("S003", "Charlie", 345678901, "Male", "2000-03-03");

    
    for (int i = 0; i < numCourses; i++) {
            manager.addStudent(student1,courses[i]);
            manager.addStudent(student2,courses[i]);
            manager.addStudent(student3,courses[i]);
            
    }
    
    

    
    int choice;
    int day;
    string courseid ;
    string msv;
    string name;
    char status;
    
//    cout << " ĐÂY LÀ TỔNG SỐ LỚP " << Course::sizeCourse ; cout << "Total attendance: " << AttendanceRecord::totalAtten << endl;
    
    do {
        cout  << endl;
        cout  << endl;
        cout  << endl;
//        cout << "Total attendance: " << AttendanceRecord::totalAtten << endl;
        cout << "===============================" << endl;
        cout << "|Attendance Management System |" << endl;
        cout << "===============================" << endl;
        cout << "1. điểm danh cho 1 ngày nào đó chọn lớp " << endl;
        cout << "2. thông tin điểm danh ủa môn học trong ngày nào đó" << endl;
        cout << "3. Thông tin điểm danh sinh viên trong tổng các ngày" << endl;
        cout << "4. Filter students by attendance status for a day" << endl;
        cout << "6. Thông tin các sinh viên " << endl;
        cout << "7. xem toàn bộ mã điểm danh" << endl;
        cout << "8. in thông tin điểm danh các ngày cho 1 sinh viên học lớp ..." << endl;
        cout << "9.  thống kê điểm danh của các sinh viên trong lớp học" << endl;

        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        
        
        

        switch (choice) {
                

                
            case 1:
                cout << "Nhập ngày :";
                cin >> day;
                cout << "Nhập mã lớp :";
                cin >> courseid;

                
                for(int i = 0 ; i < numCourses ;i++)
                    if(courses[i].courseId == courseid){
                        manager.inputAttendanceforday(day - 1, courses[i] ,numCourses); // Adjusted index

                    };
                break;
                
                
            case 2:
                cout <<"Nhập ngày :";
                cin >> day;
                cout << "Nhập mã lớp :";
                cin >> courseid;
                
                for(int i = 0 ; i < numCourses ;i++)
                    if(courses[i].courseId == courseid){
                        manager.viewAttendancesOnDayOncourseIdOnDay(day - 1, courses[i] ,numCourses); // Adjusted index

                    };
                break;
                
                
                
            case 3:
                cout << " nhập mã lớp ";
                cin >> courseid;
                for(int i = 0 ; i < numCourses ;i++){
                    if(courses[i].courseId == courseid){
                        manager.viewTottalAttendancesOnCourseId(courses[i], courses[i].getTotalCourseDay());
                    };
                }
                
                break;
                
                
                
            case 6:
                manager.ListStudent(); // Adjusted index
                break;
                
            case 7:
                manager.printAllAttendanceRecords();
                break;

            case 8:
                cout << "Enter course ID: ";
                cin >> courseid;
                cout << "Enter student ID: ";
                cin >> msv;
                
                for(int i = 0 ; i < numCourses ;i++){
                    if(courses[i].courseId == courseid){
                        manager.printAttendanceSummaryForStudent(courseid, msv, courses[i].getTotalCourseDay());

                    };
                }
                break;
                
            case 9:
                cout << "Enter course ID: ";
                cin >> courseid;
                
                for(int i = 0 ; i < numCourses ;i++){
                    if(courses[i].courseId == courseid){
                        manager.printAttendanceSummaryDayForCouse(courses[i] , courses[i].getTotalCourseDay());

                    };
                }
                break;
                
            case 5:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 5." << endl;
        }
    } while (choice != 5);
    return 0;
}
