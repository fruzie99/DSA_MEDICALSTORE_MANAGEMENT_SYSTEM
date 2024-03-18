

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>


#define MAX 1000
int cch=0;
int cid=0;
int tot=0;
int billno=0;
int counter=0;
int count=0;
char stack_med[100][MAX];
int stack_quat[MAX];
long long int stack_pho[MAX];
int stack_id[MAX];
int customer();
int seller();
int checkpho(long long int phone);
int pres();
int medicine();
int pri_med();




struct customer {
    char nam[100];
    long long int phone;
    int cusid;
    int age;
    struct customer* next;
};


struct medicine {
    int medid;
    int cost;
    int stock;
    char name[100];
    struct medicine* next;
};


struct customer* heado = NULL;
struct medicine* head = NULL;




int password()
{
    printf("**********************************ENTER PASSWORD********************************\n");
    printf("                              enter '0' to exit\n");
    int i,j=0;
        printf("        PASSWORD:");


    scanf("%d",&i);
    if(i==0)
        main();
    if(i==251263)
        return 0;
    while(i!=251263&&j<5)
    {
        printf("*******************************RE-ENTER PASSWORD********************************\n");
    printf("                              enter '0' to exit\n");
    j++;
    printf("        PASSWORD:");
        scanf("%d",&i);
if(i==0)
        main();
    if(i==251263)
        return 0;
    }
    if(j>=5)
    {
        printf("           TOO MANY INCORRECT ATTEMPTS\n");
        printf("     BETTER LUCK NEXT-TIME...SORRY! ACCESS DENIED\n\n\n");
        main();
    }
}
int pop()
{
   counter--;
    return 0;
}




void displayListCus() {
    struct customer* temp = heado;
    printf("Customer list:\n");


    while (temp != NULL) {
        printf("Name: %s       ", temp->nam);
        printf("Phone number: %lld       ", temp->phone);
        printf("Customer ID: %d       ", temp->cusid);
        printf("Age: %d\n", temp->age);
        printf("\n");
        temp = temp->next;
    }
}
int add_cus(char* input,long long int pho) {
    FILE *file;
char email[100];


    int cusid;
    int age;




    file = fopen("customer", "a");


    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }




    fprintf(file, "%s\n", input);






    fprintf(file, "%lld\n", pho);
cusid=cid+10;
    fprintf(file, "%d\n", cusid);


    printf("Enter the age: ");
    scanf("%d", &age);
    fprintf(file, "%d\n", age);


    fclose(file);
    insertNodeCus(&heado,input,pho,cusid,age );
    printf("Input stored in the file successfully.\n");


    return 0;
}


int billino()
{


FILE *file;
    char line[100];


    int num5,num,num1,num2,num3,num4;
    //int quantity;
    //int cost;


    file = fopen("CUSTOM", "r");


    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
while (fgets(line, sizeof(line), file) != NULL) {


            strtok(line, "\n");
        fscanf(file, "%d %d %d %d %d %d",&num5, &num, &num1, &num2, &num3,&num4);
        fgetc(file);


    }


billno=num5++;
billno=num5+1;
fclose(file);
return 0;
}


int add_pre(int cusid,char* input,int medid,int quantity,int cost) {
    FILE *file;


    file = fopen("CUSTOM", "a");


    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }


    fprintf(file, "%s\n", input);
        fprintf(file, "%d\n", billno);
    fprintf(file, "%d\n", cusid);
    fprintf(file, "%d\n", medid);
    fprintf(file, "%d\n", quantity);
    fprintf(file, "%d\n", cost);
        fprintf(file, "%d\n", quantity*cost);
        tot=tot+quantity*cost;




    fclose(file);


    printf("Input stored in the file successfully.\n");


    return 0;
}
int bill(int cusid) {
     FILE* file;
    char line[100];
    int num1, num2, num3, num4,num,num5;


    file = fopen("CUSTOM", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }


    printf("           BILL DETAILS:\n\n");
    printf(" __________________________________________________________________\n");
    printf("|                                                                  |\n");
    printf("|  Name                Medicine-ID  Quantity   Cost   Total Cost   |\n");
    printf("|------------------------------------------------------------------|\n");


    while (fgets(line, sizeof(line), file) != NULL) {


            strtok(line, "\n");
        fscanf(file, "%d %d %d %d %d %d",&num5, &num, &num1, &num2, &num3,&num4);
        fgetc(file);
    if(num==cusid&&billno==num5)
        printf("|  %-19s %-12d %-11d %-7d %-10d |\n", line, num1, num2, num3, num4);


    }
        printf("|------------------------------------------------------------------|\n");


  printf("|             TOTAL BILL= %-6d                                   |\n",tot);


    printf("|__________________________________________________________________|");
printf("\n\n\n\n");
    fclose(file);
    return 0;
}
int cusdata(int cusid) {
     FILE* file;
    char line[100];
    int num1, num2, num3, num4,num,num5;


    file = fopen("CUSTOM", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }
int i=0,j=0;
   printf(" __________________________________________________________________\n");
    printf("|                                                                  |\n");
printf("|***************************YOUR BILLS*****************************|\n");
    strtok(line, "\n");
        fscanf(file, "%d %d %d %d %d %d",&num5, &num, &num1, &num2, &num3,&num4);
        fgetc(file);
    if(num==cusid)
    {
        printf("|__________________________________________________________________|");
        j++;
        printf("\n\n   BILL NUMBER: %d\n",j);
         printf(" __________________________________________________________________\n");
    printf("|                                                                  |\n");
    printf("|  Name                Medicine-ID  Quantity   Cost   Total Cost   |\n");
    printf("|------------------------------------------------------------------|\n");


        printf("|  %-19s %-12d %-11d %-7d %-10d |\n", line, num1, num2, num3, num4);
        i=num5;
    }
    while (fgets(line, sizeof(line), file) != NULL) {


            strtok(line, "\n");
        fscanf(file, "%d %d %d %d %d %d",&num5, &num, &num1, &num2, &num3,&num4);
        fgetc(file);
    if(num==cusid)
    {




        if(i!=num5)
    {
        printf("|__________________________________________________________________|");
        j++;
        printf("\n\n   BILL NUMBER: %d\n",j);
         printf(" __________________________________________________________________\n");
    printf("|                                                                  |\n");
    printf("|  Name                Medicine-ID  Quantity   Cost   Total Cost   |\n");
    printf("|------------------------------------------------------------------|\n");


    }
        printf("|  %-19s %-12d %-11d %-7d %-10d |\n", line, num1, num2, num3, num4);
        i=num5;
    }


    }


    printf("|__________________________________________________________________|");
printf("\n\n\n\n");


    fclose(file);
    return 0;
}
int add_med() {
    FILE *file;
    char input[100];


    int medid;
    int stock;
    int cost;


    file = fopen("a", "a");


    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }




    printf("Enter the Name:");
    scanf(" %[^\n]s", input);
    fprintf(file, "%s\n", input);


    printf("Enter the medicine id:");
    scanf("%d", &medid);
    fprintf(file, "%d\n", medid);


    printf("Enter the stock: ");
    scanf("%d", &stock);
    fprintf(file, "%d\n", stock);


    printf("Enter the cost: ");
    scanf("%d", &cost);
    fprintf(file, "%d\n", cost);


    fclose(file);


    printf("Input stored in the file successfully.\n");


    return 0;
}
void updateStockInFileCus() {
    FILE* file;
    struct customer* temp = heado;


    file = fopen("customer", "a");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }


    while (temp != NULL) {
        fprintf(file, "%s\n", temp->nam);
        fprintf(file, "%lld %d %d\n", temp->phone, temp->cusid, temp->age);
        cid=temp->cusid;
        temp = temp->next;
    }


    fclose(file);
    printf("\n%d\n",cid);
}


void insertNodeCus(struct customer** heado, char* line, long long int num1, int num2, int num3) {
    struct customer* newNode = (struct customer*)malloc(sizeof(struct customer));
    strcpy(newNode->nam, line);
    newNode->phone = num1;
    newNode->cusid = num2;
    newNode->age = num3;
    newNode->next = NULL;
    if(count>=50)
        pop();
    stack_pho[count]=newNode->phone;
    stack_id[count]=newNode->cusid;
    count++;


    if (*heado == NULL) {
        *heado = newNode;
    } else {
        struct customer* temp = *heado;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


int import_customer() {
    FILE* file;
    char line[100];
    long long int num1;
    int num2, num3;


    file = fopen("customer", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }


   while (fgets(line, sizeof(line), file) != NULL) {
        strtok(line, "\n");
        fscanf(file, "%lld %d %d", &num1, &num2, &num3);
        fgetc(file);
cid=num2;
        insertNodeCus(&heado, line, num1, num2, num3);
   }


    fclose(file);


    return 0;
}


void displayList() {
    struct medicine* temp = head;






    printf("                    MEDICINE DETAILS\n");
    printf("    ______________________________________________________\n");
    printf("   |                                                      |\n");
    printf("   |    Name                Medicine-ID  Stock    Cost    |\n");
    printf("   |------------------------------------------------------|\n");




while (temp != NULL) {
                printf("   |    %-19s %-11d %-9d %-6d  | \n", temp->name, temp->medid, temp->stock, temp->cost);


        temp = temp->next;
    }
            printf("   |______________________________________________________|\n");


}


void updateStockInFile() {
    FILE* file;
    struct medicine* temp = head;


    file = fopen("a", "w");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return;
    }


    while (temp != NULL) {
        fprintf(file, "%s\n", temp->name);
        fprintf(file, "%d %d %d\n", temp->medid, temp->stock, temp->cost);
        temp = temp->next;
    }


    fclose(file);
}


void insertNode(struct medicine** head, char* line, int num1, int num2, int num3) {
    struct medicine* newNode = (struct medicine*)malloc(sizeof(struct medicine));
    strcpy(newNode->name, line);
    newNode->medid = num1;
    newNode->stock = num2;
    newNode->cost = num3;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct medicine* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}


int import_medicine() {
    FILE* file;
    char line[100];
    int num1, num2, num3;


    file = fopen("a", "r");
    if (file == NULL) {
        printf("Error opening the file.\n");
        return 1;
    }


    while (fgets(line, sizeof(line), file) != NULL) {
        strtok(line, "\n");
        fscanf(file, "%d %d %d", &num1, &num2, &num3);
        fgetc(file);


        insertNode(&head, line, num1, num2, num3);
    }
    fclose(file);


    return 0;
}


int main() {
    int k;
    import_customer();
    import_medicine();


    int cho1;


    do {
        printf("\n           ");
        for (int i = 0; i < 40; i++)
            printf("-*");
        printf("\n                                       WELCOME TO OUR STORE");
        printf("\n");
        printf(" ");
        printf("           ");
        for (int i = 0; i < 39; i++)
            printf("-*");
        printf("\n\n");
        printf("Choose your option based on the following options: \n");
        printf("\nEnter 1->If you are a customer\n\nEnter 2->If you are a seller\n\nEnter 3->If you want to exit\n\n\n");
        printf("enter your choice: ");
        scanf("%d", &cho1);


        switch (cho1) {
            case 1:
                customer();
                break;
            case 2:
                password();
                seller();
                break;
            case 3:
                printf("\nTHANK YOU\n");
                updateStockInFileCus();
                updateStockInFile();
                exit(0);
            default:
                printf("Enter a valid choice\n");
        }
    } while (cho1 != 3);


    return 0;
}


int customer() {


    int cho2;
    do {
        printf("\n           ");
        for (int i = 0; i < 40; i++)
            printf("-*");
        printf("\n                                               CUSTOMER");
        printf("\n");
        printf(" ");
        printf("           ");
        for (int i = 0; i < 39; i++)
            printf("-*");
        printf("\n\n");
        printf("Choose your option based on the following options: \n");
        printf("\nEnter 1->If you want to buy some medicines\n\nEnter 2->If you want to know your purchase history\n\nEnter 3->If you want to exit\n\n\n");
        printf("Enter your choice: ");
        scanf("%d", &cho2);


        switch (cho2) {
            case 1:
                printf("Enter your name: ");
                char name[100];
                scanf(" %[^\n]s", name);
                long long int pho;
                printf("\nEnter your phone number: ");
                scanf("%lld", &pho);
                checkpho(pho);
                if (checkpho(pho)) {
                        printf("     CUSTOMER FOUND\n");
                    printf("Enter prescription\n");
                    pres(checkpho(pho));
                } else {
                     add_cus(name,pho);
                    displayListCus();


                    pres(cid+10);
                }
                break;
            case 2:
                {
                    int cu_id;
                    long long int phonen;


                    printf("Enter your phone number: ");
                    scanf("%lld", &phonen);
                    cu_id=checkpho(phonen);
                    if(checkpho(phonen))
                    {
                        cusdata(cu_id);
                    }
                    break;
                }
            case 3:
                printf("\nTHANK YOU\n");
                return 0;
            default:
                printf("Enter a valid choice\n");
        }
    } while (cho2 != 3);


    return 0;
}


int seller() {
    int cho1;
    do {
        printf("\n           ");
        for (int i = 0; i < 40; i++)
            printf("-*");
        printf("\n                                               SELLER");
        printf("\n");
        printf(" ");
        printf("           ");
        for (int i = 0; i < 39; i++)
            printf("-*");
        printf("\n\n");
        printf("Enter your choice based on the following options: \n");
        printf("\nEnter 1->If you want to view medicine list\n\nEnter 2->If you want to update the medicines stock\n\nEnter 3->If you want to see the customers data\n\nEnter 4->If you want to see the purchase history \n\nEnter 5->If you want to exit\n\n\n");
        printf("Enter your choice: ");
        scanf("%d", &cho1);


        switch (cho1) {
            case 1:
                printf("View medicines data\n");
                displayList();
                break;
            case 2:
                printf("Medicine update\n");
                pri_med();
                break;
            case 3:
                printf("Customers data\n");
                displayListCus();
                break;
            case 4:


                  medicine();
                break;
            case 5:
                printf("THANK YOU\n");
                return 0;
            default:
                printf("Enter a valid choice\n");
        }
    } while (cho1 != 5);


    return 0;
}


int medicine() {
      struct customer* ptr;
    ptr = (struct customer*)malloc(sizeof(struct customer));


    ptr = heado;
    while (ptr!=NULL) {
         printf("Name: %s       \n", ptr->nam);
        printf("Phone number: %lld       \n", ptr->phone);
        printf("Customer ID: %d       \n", ptr->cusid);
        printf("Age: %d\n", ptr->age);
        printf("\n");


                    cusdata(ptr->cusid);
        ptr = ptr->next;


                }
    return 0;
}
int pri_med_fp(int code,int data) {
    int a, b;
    struct medicine* ptr;
    ptr = (struct medicine*)malloc(sizeof(struct medicine));


    ptr = head;
    while (ptr->medid != code) {
        ptr = ptr->next;
    }
    ptr->stock = ptr->stock - data;
    updateStockInFile();




    return 0;
}


int pri_med() {
    int a, b;
    struct medicine* ptr;
    ptr = (struct medicine*)malloc(sizeof(struct medicine));
    printf("Print medicine\n");
    displayList();
    printf("\n-+-+-+MEDICINE UPDATE+-+-+-\n");
    printf("Enter the medicine ID: ");
    scanf("%d", &a);
    ptr = head;
    while (ptr->medid != a) {
        ptr = ptr->next;
    }
    printf("Enter the amount of stock to be added: ");
    scanf("%d", &b);
    ptr->stock = ptr->stock + b;
    updateStockInFile();
    displayList();


    return 0;
}


int checkpho(long long int phone) {
    int i;
    for(i=0;i<count;i++)
    {
        if (stack_pho[i]==phone)
        {
        return stack_id[i];
        }
    }
    printf("%lld\n", phone);
    return 0;
}


int pres(int cusid) {
    billno++;
    int i=0,j;
    printf("\n           **********MEDICINE LIST********\n");
    displayList();
    printf("\n\n       -+-+-+ENTER YOUR PRESCRIPTION+-+-+-\n\n");
     while (1) {
            cch=i;
        printf("Enter medicine name (type 'end' to finish (or) type 'del' to remove the last item): ");
        scanf("%s", stack_med[i]);
        if (strcmp(stack_med[i], "end") == 0)
            break;
        if(strcmp(stack_med[i], "del") == 0)
        {
            i--;
            stack_quat[i]=0;
            continue;
        }
        printf("Enter quantity: ");
        scanf("%d", &stack_quat[i]);


        i++;
    }
    billino();


     struct medicine *ptr= (struct medicine*)malloc(sizeof(struct medicine));
         ptr = head;
for (j = 0; j < i; j++) {


    while (ptr != NULL && strcmp(ptr->name, stack_med[j]) != 0) {
        ptr = ptr->next;
    }
    if (ptr == NULL) {
        printf("Medicine %s not found in the list.\n", stack_med[j]);
    } else {
        printf("Medicine: %s - Cost: %d\n", ptr->name, ptr->cost);
        add_pre(cusid,ptr->name,ptr->medid,stack_quat[j],ptr->cost);
        pri_med_fp(ptr->medid,stack_quat[j]);
    }
    ptr = head;
}
bill(cusid);
    return 0;
}
