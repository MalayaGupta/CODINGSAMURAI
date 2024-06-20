/*
 Description : Student Grade Calculator
 Programmer : Malaya Gupta
 Date : 18 June 2024 
*/
#include <iostream>
#include <iomanip>
using namespace std;

//Student Class containing students' personal info and marks
//Used for inputting, validating and displaying student data
//Base Class
class student{
	protected:
		//Personal info
		char first_name[15];
        char last_name[15];
		long long roll_no;
		char course[10];
		char section;
		//Student marks
		int practical_marks;
		int internal_marks, quiz_score, assignment_score;
		int credit_score;
		int ext_exam_marks;
	public:
		void read_student_info();
        bool check_student_info();
		void show_student_info();		
};

//Result Class containing final result and grade of students
//Used for calculating and displaying result
//Inherits from Student Class
class result : public student{
	private:
		char grade;
		float student_marks;
		float percentage;
		static int max_marks;
	public:
		void cal_result();
		void show_student_result();			
};

//Defining Member Functions

//Inputs students' personal info and marks
void student :: read_student_info(){
	cout<<"Enter Student's First Name : ";
	cin>>first_name;
    cout<<"Enter Student's Last Name : ";
	cin>>last_name;
	cout<<"Enter Student Roll No. : ";
	cin>>roll_no;
	cout<<"Enter Course : ";
	cin>>course;
	cout<<"Enter Section : ";
	cin>>section;
	
	cout<<"Enter Quiz Score (out of 20) : ";
	cin>>quiz_score;
	cout<<"Enter Assignment Score (out of 30) : ";
	cin>>assignment_score;
	cout<<"Enter Practical Marks (out of 100) : ";
	cin>>practical_marks;
	cout<<"Enter External Examination Marks (out of 400) : ";
	cin>>ext_exam_marks;
	cout<<"Enter Student Credit Score (out of 5) : ";
	cin>>credit_score;
}

//Validates students' data
//Exception Handling using try-catch block
//Returns a boolean value.
bool student :: check_student_info(){
    try{
        if(assignment_score > 30 || assignment_score < 0 || quiz_score > 20 || quiz_score < 0){
            throw 3;
        }
        if(practical_marks > 100 || practical_marks < 0){
            throw 'c';
        }
        if(ext_exam_marks > 400 || ext_exam_marks < 0){
            throw 4.56;
        }
        if(credit_score > 5 || credit_score < 0){
            throw true;
        }

    }
    catch(int i){
        cout<<"Invalid Quiz or Assignment Score. Try Again"<<endl;
        return false;
    } 
    catch(char e){
        cout<<"Invalid Practical Marks. Try Again"<<endl;
        return false;
    } 
    catch(double f){
        cout<<"Invalid External/ Theory Exam Marks. Try again"<<endl;
        return false;
    }
    catch(bool g){
        cout<<"Invalid Credit Score. Try again"<<endl;
        return false;
    }
    return true;
}

//Displays student info and marks
//Formatting done using setw(), left and right
void student :: show_student_info(){
	cout<<left<<setw(16)<<"Student Name"<<right<<setw(2)<<":"<<setw(1)<<" "<<first_name<<" "<<last_name<<endl;
	cout<<left<<setw(16)<<"Student Roll No."<<right<<setw(2)<<":"<<setw(1)<<" "<<left<<setw(25)<<roll_no<<endl;
	cout<<left<<setw(16)<<"Course"<<right<<setw(2)<<":"<<setw(1)<<" "<<left<<setw(25)<<course<<endl;
	cout<<left<<setw(16)<<"Section"<<right<<setw(2)<<":"<<setw(1)<<" "<<left<<setw(25)<<section<<endl;
	internal_marks = quiz_score + assignment_score;
    cout<<"______________________________________________"<<endl;
	cout<<"|"<<left<<setw(11)<<"Internal"<<"|"<<setw(12)<<"Practical"<<"|"<<setw(11)<<"External"<<"|"<<setw(7)<<"Credits"<<"|"<<endl;
    cout<<"|"<<left<<setw(11)<<internal_marks<<"|"<<setw(12)<<practical_marks<<"|"<<setw(11)<<ext_exam_marks<<"|"<<setw(7)<<credit_score<<"|"<<endl;
    cout<<"----------------------------------------------"<<endl;
}

//Static Data Member Definition
int result :: max_marks = 100;

//Calculates Total Marks, Percentage and Grade.
//Using Weighted Mean Method
/* Weights are :
quiz_score, assignment_score, credit_score : 0.1 (each)
practical_marks : 0.4, ext_exam_marks : 0.3 */
void result :: cal_result(){
    float quiz_per, prac_per, ext_per, credit_per, assignment_per;
    quiz_per = ((float)quiz_score/20)*100;
    assignment_per = ((float)assignment_score/30)*100;
    prac_per = ((float)practical_marks/100)*100;
    ext_per = ((float)ext_exam_marks/400)*100;
    credit_per = ((float)credit_score/5)*100;
	student_marks = ((quiz_per*0.1) + (assignment_per*0.1) + (prac_per*0.4) + (ext_per*0.3) + (credit_per*0.1));
    percentage = student_marks;
    if(percentage >= 80){
        grade = 'A';
    }
    else if(percentage < 80 && percentage >= 60){
        grade = 'B';
    }
    else if(percentage < 60 && percentage >= 40){
        grade = 'C';
    }
    else if(percentage < 40 && percentage >= 33){
        grade = 'D';
    }
    else if(percentage < 33){
        grade = 'F';
    }
}

//Displays Student Result along with remarks
void result ::show_student_result(){
    cout<<endl<<"Marks Obtained : "<<fixed<<setprecision(2)<<student_marks<<"\tMaximum Marks : "<<max_marks<<endl;
    cout<<"Percentage : "<<fixed<<setprecision(2)<<percentage<<"%"<<endl;
    cout<<"Grade : "<<grade<<endl;
    cout<<"Remarks : ";
     if(grade == 'A'){
        cout<<"Excellent"<<endl;
    }
    else if(grade == 'B'){
        cout<<"Good"<<endl;
    }
    else if(grade == 'C'){
        cout<<"Satisfactory"<<endl;
    }
    else if(grade == 'D'){
        cout<<"Pass"<<endl;
    }
    else if(grade == 'F'){
        cout<<"Fail"<<endl;
    }
}

//Main function
int main(){
    int num;
    cout<<"STUDENT GRADE CALCULATOR"<<endl;
    cout<<"Enter number of Students' Data you want to input : ";
    cin>>num;

    //Dynamically allocated array of Objects of Result Class.
    //Each Object represents a Student.
	result* s = new result[num];

    //Loop to input student data
    for(int i = 0; i < num; i++){
        cout<<"STUDENT "<<(i+1)<<endl;
        s[i].read_student_info();
    }

    //Loop to validate data, calculate and display result.
    for(int i = 0; i < num; i++){
        cout<<"_______________________________________________________"<<endl;
        cout<<endl<<"STUDENT "<<(i+1)<<" RESULT"<<endl;
        if(s[i].check_student_info()){
            s[i].cal_result();
            s[i].show_student_info();
            s[i].show_student_result();
        }
    }
    cout<<"_________________________________________________________"<<endl;

    //Displays a common Grading System for comparison with Students' Result.
    cout<<endl<<"GRADING SYSTEM"<<endl<<endl;
    cout<<left<<setw(7)<<"Grade"<<left<<setw(11)<<"Percentage"<<endl;
    cout<<left<<setw(7)<<"A"<<left<<setw(11)<<"80-100"<<endl;
    cout<<left<<setw(7)<<"B"<<left<<setw(11)<<"60-80"<<endl;
    cout<<left<<setw(7)<<"C"<<left<<setw(11)<<"40-60"<<endl;
    cout<<left<<setw(7)<<"D"<<left<<setw(11)<<"33-40"<<endl;
    cout<<left<<setw(7)<<"F"<<left<<setw(11)<<"0-33"<<endl;

    cout<<"_________________________________________________________"<<endl;

    return 0;
}