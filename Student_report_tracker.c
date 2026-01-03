    #include <stdio.h>
    #include <string.h>
    #include <stdlib.h>

    struct student{
        char name[100];
        int roll_num;
        int phy;
        int chem;
        int maths;
        float percentage;
    };

    int main()
    {
        char cond[10];
        int count;
        printf("enter the number of students in your class : ");
        scanf("%d", &count);

        struct student *s = malloc(count*sizeof(struct student));
        if (s == NULL) {
            printf("Memory reallocation failed\n");
            free(s);
            return 1;
        }

        printf("\n------ENTER THE DETAILS OF THE STUDENTS------\n");
        for(int i=0;i<count;i++)
        {
            printf("\nEnter the name of student : ");
            scanf(" %[^\n]", s[i].name);
            printf("Enter the roll number of %s : ",s[i].name);
            scanf("%d", &s[i].roll_num);
            printf("Enter the marks of PHYSICS (out of 100): ");
            scanf("%d", &s[i].phy);
            printf("Enter the marks of CHEMISTRY (out of 100): ");
            scanf("%d", &s[i].chem);
            printf("Enter the marks of MATHS (out of 100): ");
            scanf("%d", &s[i].maths);

            if (s[i].phy < 0 || s[i].phy > 100 || s[i].chem < 0 || s[i].chem > 100 || s[i].maths < 0 || s[i].maths > 100)
            {
                printf("INVALID MARKS! Try again.\n");
                i--; 
                continue;
            }
        }

        printf("\nARE THERE ANY STUDENTS LEFT TO ADD ? ");
        scanf("%s", cond);
        strlwr(cond);
        if(strcmp(cond,"yes")==0)
        {
            
            int new_count;
            printf("Enter the total number of students (including the previous ones) : ");
            scanf("%d", &new_count);
            
            if (new_count > count)
            {
                struct student *temp = realloc(s,new_count*sizeof(struct student));
                if (temp == NULL) {
                    printf("Memory reallocation failed\n");
                    free(temp);
                    return 1;
                }
                s=temp;

                printf("\n\nEnter the details of the remaining %d students---\n", new_count-count);

                for(int i=count;i<new_count;i++)
                {
                    printf("\nEnter the name of student : ");
                    scanf(" %[^\n]", s[i].name);
                    printf("Enter the roll number of %s : ",s[i].name);
                    scanf("%d", &s[i].roll_num);
                    printf("Enter the marks of PHYSICS (out of 100): ");
                    scanf("%d", &s[i].phy);
                    printf("Enter the marks of CHEMISTRY (out of 100): ");
                    scanf("%d", &s[i].chem);
                    printf("Enter the marks of MATHS (out of 100): ");
                    scanf("%d", &s[i].maths);

                    if (s[i].phy < 0 || s[i].phy > 100 || s[i].chem < 0 || s[i].chem > 100 || s[i].maths < 0 || s[i].maths > 100)
                    {
                        printf("INVALID MARKS! Try again.\n");
                        i--;
                        continue;
                    }

                }
                count = new_count;
            }
        }
        int final_count;
        final_count = count;

        FILE *ptr;
        if (ptr == NULL) {
            printf("File error\n");
            free(s);
            return 1;
        }

        ptr = fopen("data.txt","w");

        fprintf(ptr,"----------THE STUDENT LIST ACCORDING TO PERCENTAGE----------\n\n");

        float result[final_count];

        for (int i = 0; i < final_count; i++)
        {
            result[i] = ((s[i].chem + s[i].phy + s[i].maths) / 300.0f) * 100;
        }

        for(int i = 0; i < final_count - 1; i++)
        {
            for(int j = 0; j < final_count - i - 1; j++)
            {
                if(result[j] < result[j + 1])
                {
                    float temp = result[j];
                    result[j] = result[j + 1];
                    result[j + 1] = temp;
                
                    struct student tempStudent = s[j];
                    s[j] = s[j + 1];
                    s[j + 1] = tempStudent;
                }
            }
        }

        for(int i = 0; i < final_count; i++)
        {
            fprintf(ptr,"RANK %d : %s roll num %d → %.2f%%\n",i + 1, s[i].name,s[i].roll_num, result[i]);
        }

        fclose(ptr);
        free(s);
        return 0;
    }