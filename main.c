#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
struct gg{
    char Cid[10][30];
    char grade[5][30];
}g;

struct student {
    char Index[20];
    char Name[50];
    char Department[50];
    int no_of_courses;
    int no_of_students;
    float GPA;
    struct gg g;
}stu;

struct cvalue{
    char couid[50];
    char cname[50];
    int creditval;
}cc;



void enter(){
    FILE *creditvalue;

    float gval=0;
    int k;
    FILE *fsc;
    fsc = fopen("studentsinfo.txt","a");
    if(fsc==NULL){
        fsc = fopen("studentsinfo.txt","w");
    }

    printf("\nPlease Enter The Details of Students and Courses");
    printf("\nHow many students :");
    scanf("%d",&k);
    fflush(stdin);

    float total_cvalues=0;
    float total_gval=0;
    float GPA=0;

    for (int v = 0; v <k ; ++v) {


        printf("\nEnter The Student Index NO :");
        gets(stu.Index);
        printf("\nEnter The Name of Student :");
        gets(stu.Name);
        printf("\nEnter The Name of Department :");
        gets(stu.Department);
        printf("\nHow Many Courses You Followed :");
        scanf("%d", &stu.no_of_courses);
        fflush(stdin);

        for (int i = 0; i < stu.no_of_courses; ++i) {

            printf("\nEnter Course ID :");
            gets(stu.g.Cid[i]);
            creditvalue = fopen("credit.txt", "r");
            while(fread(&cc,sizeof(struct cvalue),1,creditvalue)){
                int k= strcmp(stu.g.Cid[i],cc.couid);

                if (k==0) {

                    printf("\n***** Who Absent for the Course Please Type \"AB\" For Grade Section *****");
                    printf("\nGrade of The Course :");
                    gets(stu.g.grade[i]);
                    total_cvalues=total_cvalues+cc.creditval;
                    if (strcmp(stu.g.grade[i],"A")==0) {
                        gval = 4*cc.creditval;
                    } else if (strcmp(stu.g.grade[i],"B")==0) {
                        gval = 3*cc.creditval;
                    } else if (strcmp(stu.g.grade[i],"C")==0) {
                        gval = 2.5*cc.creditval;
                    } else if (strcmp(stu.g.grade[i],"D")==0) {
                        gval = 1.5*cc.creditval;
                    } else if (strcmp(stu.g.grade[i],"E")==0){
                        gval = 0;
                    }
                    else{
                        gval = 0;
                    }

                    total_gval = total_gval + gval;
                    gval=0;
                    fclose(creditvalue);
                    break;
                }

            }
            fclose(creditvalue);
        }
        GPA=total_gval/total_cvalues;
        stu.GPA=GPA;
        fwrite(&stu, sizeof(struct student), 1, fsc);
        printf("\n\nStudent and Courses Details have Created Successfully");
        getch();
    }
    fclose(fsc);

}
void displays(){


    FILE *fsc;
    fsc = fopen("studentsinfo.txt","r");
    if(fsc==NULL){
        printf("Cant create file");
    }
    while(fread(&stu,sizeof(struct student),1,fsc)){
        printf("\n--------------------------------------------");
        printf("\n Index = %s",stu.Index);
        printf("\n Name = %s",stu.Name);
        printf("\n Department = %s",stu.Department);
        printf("\n No of courses = %d",stu.no_of_courses);
        for(int i=0; i<stu.no_of_courses; i++){
            printf("\n Course ID = %s ",stu.g.Cid[i]);
            printf("\n Grade = %s ",stu.g.grade[i]);
        }
        printf("\n GPA = %.2f",stu.GPA);
        printf("\n--------------------------------------------");
    }
    fclose(fsc);
}
void modify(){

    FILE *creditvalue;
    float gval=0;
    int check;
    char no[20];
    FILE *fsc,*fsc1;
    struct student stu;
    printf("\nTo Modify ");
    printf("\n");
    printf("\nPlease Enter The Old Index number of student :");
    scanf("%s",&no);
    fflush(stdin);
    fsc=fopen("studentsinfo.txt","r+");
    fsc1= fopen("copy.txt","a+");
    if(fsc==NULL){
        printf("cant open file");
    }
    while(fread(&stu,sizeof(struct student),1,fsc)) {
        check = strcmp(stu.Index, no);
        if (check != 0) {
            fwrite(&stu, sizeof(struct student), 1, fsc1);
        }
    }
    struct student stu1;
    printf("\nEnter New The Index No :");
    gets(stu1.Index);
    printf("\nEnter The New Name of student :");
    gets(stu1.Name);
    printf("\nEnter The New Department : ");
    gets(stu1.Department);
    printf("\nHow Many Courses You Followed :");
    scanf("%d", &stu1.no_of_courses);
    fflush(stdin);

    float total_cvalues=0;
    float total_gval=0;
    float GPA=0;

    for (int i = 0; i <stu1.no_of_courses; ++i) {

        printf("\nEnter The New Course ID :");
        gets(stu1.g.Cid[i]);
        creditvalue = fopen("credit.txt", "r");
        while(fread(&cc,sizeof(struct cvalue),1,creditvalue)){
            int k= strcmp(stu1.g.Cid[i],cc.couid);

            if (k==0) {

                printf("\n***** Who Absent for the Course Please Type \"AB\" in Grade Section *****");
                printf("\nGrade of The Course :");
                gets(stu1.g.grade[i]);
                total_cvalues=total_cvalues+cc.creditval;
                if (strcmp(stu1.g.grade[i],"A")==0) {
                    gval = 4*cc.creditval;
                } else if (strcmp(stu1.g.grade[i],"B")==0) {
                    gval = 3*cc.creditval;
                } else if (strcmp(stu1.g.grade[i],"C")==0) {
                    gval = 2.5*cc.creditval;
                } else if (strcmp(stu1.g.grade[i],"D")==0) {
                    gval = 1.5*cc.creditval;
                } else if (strcmp(stu1.g.grade[i],"E")==0){
                    gval = 0;
                }
                else{
                    gval = 0;
                }

                total_gval = total_gval + gval;
                gval=0;
                fclose(creditvalue);
                break;
            }

        }
        fclose(creditvalue);
    }
    GPA=total_gval/total_cvalues;
    stu1.GPA=GPA;

    fwrite(&stu1,sizeof(struct student),1,fsc1);
    fclose(fsc);
    fclose(fsc1);
    remove("studentsinfo.txt");
    rename("copy.txt","studentsinfo.txt");
    printf("\n\n\t Record Updated");


}


void print_courses(){

    FILE *creditvalue;
    creditvalue = fopen("credit.txt", "w");
    if (creditvalue == NULL) {
        printf("cant create file");
    }
    struct cvalue c0 = {"100", "Programming", 3};
    struct cvalue c1 = {"101", "App Lab", 5};
    struct cvalue c2 = {"102", "Maths", 2};
    struct cvalue c3 = {"103", "Physics", 3};
    struct cvalue c4 = {"104", "EICT", 6};
    struct cvalue c5 = {"105", "PHP", 4};
    struct cvalue c6 = {"106", "SQL", 3};
    struct cvalue c7 = {"107", "C++", 5};
    struct cvalue c8 = {"108", "Java", 1};
    struct cvalue c9 = {"109", "C#", 2};

    fwrite(&c0, sizeof(struct cvalue), 1, creditvalue);
    fwrite(&c1, sizeof(struct cvalue), 1, creditvalue);
    fwrite(&c2, sizeof(struct cvalue), 1, creditvalue);
    fwrite(&c3, sizeof(struct cvalue), 1, creditvalue);
    fwrite(&c4, sizeof(struct cvalue), 1, creditvalue);
    fwrite(&c5, sizeof(struct cvalue), 1, creditvalue);
    fwrite(&c6, sizeof(struct cvalue), 1, creditvalue);
    fwrite(&c7, sizeof(struct cvalue), 1, creditvalue);
    fwrite(&c8, sizeof(struct cvalue), 1, creditvalue);
    fwrite(&c9, sizeof(struct cvalue), 1, creditvalue);


    fclose(creditvalue);

}
void coucre(){

    FILE *creditvalue;
    creditvalue = fopen("credit.txt", "r");
    if (creditvalue == NULL) {
        printf("cant open file");
    }
    while (fread(&cc,sizeof (struct cvalue),1,creditvalue)){
        printf("\n--------------------");
        printf("\n Index = %s",cc.couid);
        printf("\n Name = %s",cc.cname);
        printf("\n Credit Value = %d",cc.creditval);
        printf("\n--------------------");

    }
    fclose(creditvalue);


}

void searchs(){
    char stuID[35];
    FILE *fsc;
    fsc = fopen("studentsinfo.txt","r");
    if(fsc==NULL){
        printf("Cant create file");
    }
    printf("Enter Student Index :");
    scanf("%s",&stuID);
    fflush(stdin);
    while(fread(&stu,sizeof(struct student),1,fsc)){

        if(strcmp(stuID,stu.Index)==0){
            printf("\n--------------------------------------------");
            printf("\n Index = %s",stu.Index);
            printf("\n Name = %s",stu.Name);
            printf("\n Department = %s",stu.Department);
            printf("\n No of courses = %d",stu.no_of_courses);
            for(int i=0; i<stu.no_of_courses; i++){
                printf("\n Course ID = %s ",stu.g.Cid[i]);
                printf("\n Grade = %s ",stu.g.grade[i]);
            }
            printf("\n GPA = %.2f",stu.GPA);
            printf("\n--------------------------------------------");

        }

    }
    fclose(fsc);


}

int main() {
    print_courses();
    int chno;
    do {
        printf("\n######################### Student System ###########################");
        printf("\n");
        printf("\n1-Enter Student Details and Courses Details") ;
        printf("\n2-Display All Students Details and Course Details With GPA Value");
        printf("\n3-Modify Student Details and Course Details");
        printf("\n4-All Courses ID's,Names and Credits Values");
        printf("\n5-Search Students Details One by One");
        printf("\n0-Exit");
        printf("\n");
        printf("\n#####################################################################");

        printf("\n\nEnter Your Chosen Number(0-5) :");
        scanf("%d",&chno);

        switch (chno) {
            case 1:
                enter();
                break;
            case 2:
                displays();
                break;
            case 3:
                modify();
                break;
            case 4:
                coucre();
                break;
            case 5:
                searchs();
                break;

        }

    } while (chno!=0);
    return 0;
}
