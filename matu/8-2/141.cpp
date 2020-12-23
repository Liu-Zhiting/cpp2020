#include <iostream>
#include <cstring>
using namespace std;

int sumOfGradeA = 0,sumOfGradeB = 0,sumOfGradeC = 0,count = 0;

class Student{
    private:
        char num[10],name[12];
        int gradeA,gradeB,gradeC;
    public:
        Student(char* name,char* num,int gradeA,int gradeB,int gradeC)
        {
            strcpy(this->name,name);
            strcpy(this->num,num);
            this->gradeA = gradeA;
            this->gradeB = gradeB;
            this->gradeC = gradeC;

            sumOfGradeA += gradeA;
            sumOfGradeB += gradeB;
            sumOfGradeC += gradeC;
            count++;
        }

        void display()
        {
            cout << this->num << " " << this->name << " " << this->gradeA << " " << this->gradeB << " " << this->gradeC << endl;
        }

        double average1()
        {
            if(0 == count)
                return 0;
            return ((double)sumOfGradeA) / count;
        }

        double average2()
        {
            if (0 == count)
                return 0;
            return ((double)sumOfGradeB) / count;
        }

        double average3()
        {
            if (0 == count)
                return 0;
            return ((double)sumOfGradeC) / count;
        }
};

int main(){
	Student *stu1,*stu2,*stu3;
	char name1[12],name2[12],name3[12];
	char num1[10],num2[10],num3[10];
	int grade1[3],grade2[3],grade3[3];
	cin>>num1>>name1>>grade1[0]>>grade1[1]>>grade1[2];
	cin>>num2>>name2>>grade2[0]>>grade2[1]>>grade2[2];
	cin>>num3>>name3>>grade3[0]>>grade3[1]>>grade3[2];
	stu1 = new Student(name1,num1,grade1[0],grade1[1],grade1[2]);
	stu2 = new Student(name2,num2,grade2[0],grade2[1],grade2[2]);
	stu3 = new Student(name3,num3,grade3[0],grade3[1],grade3[2]);

	stu1->display();
	stu2->display();
	stu3->display();

    cout<<"The average grade of course1:"<<stu2->average1()<<endl;
	 cout<<"The average grade of course2:"<<stu2->average2()<<endl;
	  cout<<"The average grade of course3:"<<stu2->average3()<<endl;
	  return 0;
}